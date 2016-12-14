var http = require("http");
var options = {
  hostname: '10.1.7.100',
  port: 1337,
  path: '/',
  method: 'POST'
};

var req = http.request(options, function(res) {
  console.log('STATUS: ' + res.statusCode);
  console.log('HEADERS: ' + JSON.stringify(res.headers));
  res.setEncoding('utf8');
  res.on('data', function (chunk) {
    console.log('BODY: ' + chunk);
  });
});

req.on('error', function(e) {
u console.log('problem with request: ' + e.message);
});

console.log(JSON.stringify(http.Agent));
// write data to request body
 req.write('data\n');
 req.write('data\n');
 req.end();
