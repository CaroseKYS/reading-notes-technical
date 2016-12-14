var fs = require('fs');
var info = fs.createWriteStream(__dirname + '/info.log', {flags: 'a', mode: '0666'});
var error = fs.createWriteStream(__dirname + '/error.log', {flags: 'a', mode: '0666'});

var logger = new console.Console(info, error);

exports.info = function(msg){
  logger.info(msg);
};

exports.error = function(msg){
  logger.error(msg);
};
