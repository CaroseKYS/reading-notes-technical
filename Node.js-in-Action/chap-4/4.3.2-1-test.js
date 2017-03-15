var Deferred = require('./4.3.2-1.js');

promisify()
.then(
  function(){
    console.log('success1');
  },
  function(){
    console.log('error1');
  }
)
.then(
  function(){
    console.log('success2');
  },
  function(){
    console.log('error2');
  }
);

function promisify(ms){
  ms = ms || 2000;
  var deferred = new Deferred();
  setTimeout(function(){
    var ran = parseInt(Math.random() * 1000);
    if(ran % 2 == 0){
      deferred.resolve({});
    }else{
      deferred.reject();
    }
  }, ms);

  return deferred.promise;
}
