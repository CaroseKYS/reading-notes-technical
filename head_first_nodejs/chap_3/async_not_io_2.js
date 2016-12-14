setImmediate(function(){
  console.log('Deferred Execution: setImmediate 1st');

  process.nextTick(function(){
    console.log('Insert.');
  });
});

setImmediate(function(){
  console.log('Deferred Execution: setImmediate 2nd.');
});

process.nextTick(function(){
  console.log('Deferred Execution: nextTick 1st.');
});

process.nextTick(function(){
  console.log('Deferred Execution: nextTick 2nd.');
});

console.log('Formal Execution.');
