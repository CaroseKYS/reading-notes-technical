var net = require('net');
// var client = net.connect({path: '/tmp/echo.sock'});
var client = net.connect({port: 8124}, function(socket){
  console.log('客户端连接成功。');
  client.write('Hello server!\r\n');
});

client.on('data', function(data){
  console.log(data.toString());
  client.end();
});

client.on('end', function(){
  console.log('client is disconnected');
});