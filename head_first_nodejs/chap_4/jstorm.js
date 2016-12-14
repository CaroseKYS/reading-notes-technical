var emitter = require('./events_inherits');
var proxy = new emitter();

proxy.setMaxListeners(1000);

var status = 'ready';

var i = 0;
module.exports = function(callback){
  proxy.once('data', function(data){
    callback && callback(data);
  });

  if(status == 'ready'){
    status = 'pending';
    setTimeout(function(){
      proxy.emit('data', 'Data coming.');
      status = 'ready';
    }, 3000);
  }
};
