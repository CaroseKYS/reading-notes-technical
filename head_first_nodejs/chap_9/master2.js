var fork = require('child_process').fork;
var cpus = require('os').cpus();

var server = require('net').createServer();
server.listen(1337);

var workers = {};
var createWorker = function(){
  var worker = fork('./worker2.js');
  
  //when child process exits, start a new process
  worker.on('message', function(msg){
    if(msg.act == 'suicide'){
      createWorker();
    }
  });
  worker.on('exit', function(){
    console.log('Worker ', worker.pid , ' exited.');
    delete workers[worker.pid];
  });
  
  //handle forward
  worker.send('server', server);
  workers[worker.pid] = worker;
  console.log('Create worker successfully, the pid is ', worker.pid);
};

for(var i = 0; i < cpus.length; i++){
  createWorker();
}

process.on('exit', function(){
  for(var pid in workers){
    workers[pid].kill();
  }
});
