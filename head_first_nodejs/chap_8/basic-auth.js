var http = require('http');

http.createServer(function(req, res){
  var auth = req.headers['authorization'] || '';
  var parts = auth.split(' ');
  var method = parts[0];
  var encoded = parts[1];
  var decoded = new Buffer(encoded, 'base64').toString('utf-8').split(':');
  var user = decoded[0];
  var pass = decoded[1];
  if (checkUser(user, pass)) {
    res.writeHead(200, {'Content-Type': 'text/plain; charset=utf-8'});
    res.end('你登录成功了');
  }else {
    res.setHeader('WWW-Authenticate', 'Basic realm="Secure Area"');
    res.writeHead(401);
    res.end('请认证!');
  }
}).listen(1337);

function checkUser(user, pass){
  return user === 'kangys' && pass === 'kangys';
}