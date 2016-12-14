var assert = require('assert');

assert.ok(100 === 100);
assert.equal(Math.max(1, 100, 23,33), 100, 'dd');
assert.notEqual(Math.max(1, 100, 23,33), 200);
assert.deepEqual({a: 100}, {a: 100});
assert.notDeepEqual(function(){
  return {a: 100};
}, {b: 100});
assert.strictEqual(1, 1);
assert.notStrictEqual(1, '1');
assert.throws(function(){
  throw 'error';
}, /error/);
assert.doesNotThrow(function(){
  console.log('-----doesNotThrow-----');
});
assert.ifError(false);