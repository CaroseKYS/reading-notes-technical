var assert = require('assert');

/*使用blanket模块的测试*/
var parser = require('../lib');

/*使用jscover模块的测试*/
// var parser = require('../lib-cov');

console.log(parser.parseAsync.toString());

describe('JSON parse', function(){
  it('传入正确的数据, 不应当抛出异常.', function(done){
    parser.parseAsync(JSON.stringify({name: 'ttt'}), function(err, data){
      assert.equal(null);
      done();
    });
  });

  it('传入错误数据, 应当抛出除异常。', function(done){
    parser.parseAsync('{"name": "jack"}}', function(err, data){
      assert.ifError(data);
      assert.notEqual(err, null);
      done();
    });
  });
});