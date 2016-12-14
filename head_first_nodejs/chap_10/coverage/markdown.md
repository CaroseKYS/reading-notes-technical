function (input, callback){
  setTimeout(function(){
    var result;

    try{
      result = JSON.parse(input);
    } catch (e){
      return callback(e);
    }

    callback(null, callback);
  }, 500);
}
# TOC
   - [JSON parse](#json-parse)
<a name=""></a>
 
<a name="json-parse"></a>
# JSON parse
传入正确的数据, 不应当抛出异常..

```js
parser.parseAsync(JSON.stringify({name: 'ttt'}), function(err, data){
  assert.equal(null);
  done();
});
```

传入错误数据, 应当抛出除异常。.

```js
parser.parseAsync('{"name": "jack"}}', function(err, data){
  assert.ifError(data);
  assert.notEqual(err, null);
  done();
});
```

