var jstorm = require('./jstorm');

for(var i = 0; i < 100; i++){
  (function(counter){
    jstorm(function(data){
      console.log(counter, ': ', data);
    });
  })(i)
}
