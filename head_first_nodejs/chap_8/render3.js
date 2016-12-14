var escape = require('./escape');
exports.complie = function(str){
  var tpl = str.replace(/\n/g, '\\n')
  .replace(/<%\s*=\s*([\S]+?)\s*%>/g, function(match, code){
    return "' + escape(" + code + ") + '";
  })
  .replace(/<%\s*-\s*([\S]+?)\s*%>/g, function(match, code){
    return "' + " + code + " + '";
  });

  tpl = "tpl = '" + tpl + "'";
  tpl = 'var tpl = ""; \nwith(obj){' + tpl + '}\nreturn tpl;';
  return new Function('obj', 'escape', tpl);
};

exports.render = function(complied, data){
  return complied(data, escape);
};
