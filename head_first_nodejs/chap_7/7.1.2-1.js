var net = require('net');

var server = net.createServer(function(socket){
  console.log('新连接建立。');

  socket.on('data', function(data){
    console.log('Message come：', data.toString());
    socket.write('你好，现在的时间是: ' + Date.now() + '\n');
  });

  socket.on('end', function(){
    console.log('连接断开');
  });

  socket.write('欢迎光临《深入浅出Node.js》示例:\n');
});

server.listen(8124, function(){
  console.log('server bound');
});

// server.listen('/tmp/echo.sock');