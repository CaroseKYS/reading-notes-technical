var http = require('http');
var sessions = {};
var key = 'session_id';
var EXPIRES = 20 * 60 * 1000;

var generate = function(){
  var session = {};

  session.id = (new Date).getTime() + Math.random();
  session.cookie = {
    expire: (new Date).getTime() + EXPIRES
  };
  sessions[session.id] = session;
  return session;
};

http.createServer(function(req, res){

  var id = req.cookies[key];

  if(!id){
    req.session = generate();
  }else{
    var session = sessions[id];
    if(session){
      if(session.cookie.expire > (new Date).getTime()){
        session.cookie.expire = (new Date).getTime + EXPIRE;
        req.session = session;
      }else{
        delete sessions[id];
        req.session = generate();
      }
    }else{
      req.session = generate();
    }
  }

  handle(req, res);
}).listen(1337);
