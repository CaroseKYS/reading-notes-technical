/*
 * 测试命令
 * curl -d "a=111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" http://10.1.7.181:1337/
 */
var http = require('http');
var limit = 100;

http.createServer(function(req, res){
  var receive = 0;

  var len = req.headers['content-length'] ? parseInt(req.headers['content-length'], 10) : null;

  if (len && len > limit) {
    console.log('报问题长度%d超过限制%d', len, limit);
    res.writeHead(413, {'Content-Type': 'text/plain; chartset=UTF-8'});
    res.end('请求错误。');
    return;
  }

  req.on('data', function(chunk){
    receive += chunk.length;
    if (receive > limit) {
      req.destroy();
      res.writeHead(413, {'Content-Type': 'text/plain; chartset=UTF-8'});
      res.end('请求错误。');
    };
  });

  req.on('end', function(){
    res.writeHead(200, {'Content-Type': 'text/plain; chartset=UTF-8'});
    res.end('请求接收完成。');
  });
}).listen(1337);