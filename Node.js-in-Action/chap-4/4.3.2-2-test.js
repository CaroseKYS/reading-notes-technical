var fs = require('fs');
var Deferred = require('./4.3.2-2.js');

var readFile = function(file, encoding){
  var deferred = new Deferred();
  fs.readFile(file, encoding, deferred.callback());
  return deferred.promise;
};

readFile('file1.txt', 'utf8')
.then(function(file){
  console.log('file1:', file);
  return readFile('file2.txt', 'utf8');
})
.then(function(file){
  console.log('file2:', file);
});
