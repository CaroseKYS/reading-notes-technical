setImmediate(function(){
  console.log('Deferred Execution: setImmediate.');
});
process.nextTick(function(){
  console.log('Deferred Execution: nextTick.');
});

console.log('Formal Execution');
