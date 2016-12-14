var cp = require('child_process');
var child1 = cp.fork('./sub.js');
var child2 = cp.fork('./sub.js');

var listener = function(data){
  console.log("Master : achieve message : ", data);
};

child1.on('message', listener);
child2.on('message', listener);

setInterval(function(){
  child1.send('Hello, it is father.');
  child2.send('Hello, it is father.');
}, 3000);

