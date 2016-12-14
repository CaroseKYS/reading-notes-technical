var http = require('http');

var server = http.createServer(function(req, res){
  console.log('process ', process.pid, ' handle req.');
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end('Request handled by child, pid is ' + process.pid + '\n');
  if((Math.random()) < 0.5){
    throw new Error("It is an uncaughtException");
  }
});

var worker;
process.on('message', function(msg, tcp){
  if(msg === 'server'){
    worker = tcp;
    worker.on('connection', function(socket){
      server.emit('connection', socket);
    });
  }
});


process.on('uncaughtException', function(err){
  //write log
  console.log(err);
  //send suicide message to master process
  process.send({act: 'suicide'});
  //Stop processing new requests
  worker.close(function(){
    //After disconnecting all link, exit the process
    process.exit(1);
  });

  //exiting after 10 seconds
  setTimeout(function(){
    process.exit(1);
  }, 10000);
});
