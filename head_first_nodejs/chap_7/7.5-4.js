process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';
var https = require('https');
var fs = require('fs');

var options = {
  hostname: '127.0.0.1',
  port: 8000,
  path: '/',
  mathod: 'GET',
  key: fs.readFileSync('./keys/client.key'),
  cert: fs.readFileSync('./keys/client.crt'),
  ca: [fs.readFileSync('./keys/ca.crt')]
};

options.agent = new https.Agent(options);

var req = https.request(options, function(res){
  res.setEncoding('utf-8');
  res.on('data', function(d){
   console.log(d);
  });
});
req.end();

req.on('error', function(e){
  console.log(e);
});
