var util = require('util');

var Promise = function(){
  this.queue = [];
  this.isPromise = true;
};

Promise.prototype.then = function(fullfilledH, errorH){
  var handler = {};

  if(util.isFunction(fullfilledH)){
    handler.fullfilled = fullfilledH;
  }

  if(util.isFunction(errorH)){
    handler.error = errorH;
  }
  this.queue.push(handler);
  return this;
};


var Deferred = function(){
  this.promise = new Promise();
};

Deferred.prototype.resolve = function(obj){
  var promise = this.promise;
  var handler;
  
  while((handler = promise.queue.shift())){
    if(handler && handler.fullfilled){
      var ret = handler.fullfilled(obj);
      if(ret && ret.isPromise){
        ret.queue = promise.queue;
        this.promise = ret;
        return;
      }
    }
  }
};

Deferred.prototype.reject = function(err){
  var promise = this.promise;
  var handler;

  while((handler = promise.queue.shift())){
    if(handler && handler.error){
      var ret = handler.error(err);
      if(ret && ret.isPromise){
        ret.queue = promise.queue;
        this.promise = ret;
        return;
      }
    }
  }
};

Deferred.prototype.callback = function(){
  var that = this;
  return function(err, data){
    if(err){
      return that.reject(err);
    }
    that.resolve(data);
  };
};
module.exports = Deferred;
