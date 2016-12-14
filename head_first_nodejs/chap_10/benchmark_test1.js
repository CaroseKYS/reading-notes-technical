var Benchmark = require('benchmark');

var suite = new Benchmark.Suite();

var arr = [0, 1, 2, 3, 4, 5, 6, 7];

suite.add('nativeMap', function(){
  return arr.map(callback);
}).add('customMap', function(){
  var ret = [];
  for(var i = 0; i < arr.length; i++){
    ret.push(callback(arr[i], i, arr));
  }
  return ret;
}).on('cycle', function(event){
  console.log(String(event.target));
}).on('complete', function(){
  console.log('Faster is ', this.filter('fastest').map('name'));
}).run({'async': true});

