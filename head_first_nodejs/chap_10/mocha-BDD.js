var assert = require('assert');

describe('Array', function(){
  before(function(){
    console.log('--------before---------');
  });

  describe('#indexOf()', function(){
    it('should return -1 when not present', function(){
      assert.equal([1, 2, 3].indexOf(4), -1);
      // [1, 2, 3].indexOf(4).should.equal(-1);
    });

    /*测试异步代码*/
    it('Async test', function(done){
      this.timeout(6000);
      setTimeout(function(){
        done();
      }, 5000);
    });

    it('should return 0 when param is 1', function(){
      assert.equal([1, 2, 3].indexOf(1), 0);
      // [1, 2, 3].indexOf(4).should.equal(-1);
    });

    it('should return 1 when param is 2', function(){
      assert.equal([1, 2, 3].indexOf(2), 1);
      // [1, 2, 3].indexOf(4).should.equal(-1);
    });
  });

  after(function(){
    console.log('--------after---------');
  });

  beforeEach(function(){
    console.log('--------beforeEach---------');
  });

  afterEach(function(){
    console.log('--------afterEach---------');
  });
});