process.on('message', function(m, server){
  if(m === 'server'){
    server.on('connection', function(socket){
      socket.end('Handled by child ' + process.pid +  "\n");
    });
  }
});
