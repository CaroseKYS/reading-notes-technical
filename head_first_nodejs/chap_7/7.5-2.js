process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';
var tls = require('tls');
var fs = require('fs');

var options = {
  key: fs.readFileSync('./keys/client.key'),
  cert: fs.readFileSync('./keys/client.crt'),
  ca: [fs.readFileSync('./keys/ca.crt')],
  requestCert: true
};

var stream = tls.connect({
    host: '127.0.0.1',
    port: 8000
  }, options, function(){
    console.log('client connected ', stream.authorize ? 'authorized' : 'unauthorized');
    process.stdin.pipe(stream);
  });

stream.setEncoding('utf8');
stream.on('data', function(data){
  console.log('-----------------data------------------');
  console.log(data);
  console.log('-----------------data------------------');
});
stream.on('end', function(){
  console.log('-----------------end------------------');
  server.close();
  console.log('-----------------end------------------');
});
stream.on('error', function(err){
  console.log('-----------------err------------------');
  console.log(err);
  console.log('-----------------err------------------');
});
