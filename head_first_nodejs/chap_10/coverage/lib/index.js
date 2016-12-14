exports.parseAsync = function(input, callback){
  setTimeout(function(){
    var result;

    try{
      result = JSON.parse(input);
    } catch (e){
      return callback(e);
    }

    callback(null, callback);
  }, 500);
};