var util = require('util');
var EventEmitter = require('events');

var Promise = function(){
  EventEmitter.call(this);
};

util.inherits(Promise, EventEmitter);

Promise.prototype.then = function(fullfilledH, errorH, progressH){
  if(util.isFunction(fullfilledH)){
    this.once('success', fullfilledH);
  }

  if(util.isFunction(errorH)){
    this.once('error', errorH);
  }


  if(util.isFunction(progressH)){
    this.on('progress', progressH);
  }

  return this;
};


var Deferred = function(){
  this.status = 'unfullfilled';
  this.promise = new Promise();
};

Deferred.prototype.resolve = function(obj){
  this.status = 'fullfilled';
  this.promise.emit('success', obj);
};

Deferred.prototype.reject = function(err){
  this.status = 'error';
  this.promise.emit('error', err);
};

Deferred.prototype.progress = function(data){
  this.promise.emit('progress', data);
};

module.exports = Deferred;
