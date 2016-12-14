process.on('message', function(data){
  console.log('Child',process.pid, ' : achieve message : ', data);
});

setInterval(function(){
  process.send("Hello, it is child" + process.pid);
}, 5000);
