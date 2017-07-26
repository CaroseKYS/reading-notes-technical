function* process(){
  yield p1();
  yield p2();
  yield p3();
}

function p1(){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      console.log('p1');
      resolve();
    }, 2000);
  });
}

function p2(){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      console.log('p2');
      resolve();
    }, 2000);
  });
}

function p3(){
  return new Promise(function(resolve, reject){
    setTimeout(function(){
      console.log('p3');
      resolve();
    }, 2000);
  });
}

function run(generator){
  var it = generator();

  function go(result){
    if (result.done) {
      return result.value;
    }

    return result.value.then(function(value){
      return go(it.next(value));
    }).catch(function(reason){
      return go(it.throw(reason));
    });
  }

  go(it.next());
}

run(process);