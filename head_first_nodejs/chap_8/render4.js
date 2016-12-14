var escape = require('./escape');
exports.complie = function(str){
  var tpl = str.replace(/\n/g, '\\n')
  .replace(/<%\s*=\s*([\S]+?)\s*%>/g, function(match, code){
    return "' + escape(" + code + ") + '";
  })
  .replace(/<%\s*-\s*([\S]+?)\s*%>/g, function(match, code){
    return "' + " + code + " + '";
  })
  .replace(/<%([\s\S]+?)%>/g, function(match, code){
    return "';\n" + code + "\ntpl += '";
  })
  .replace(/\'\n/g, '\'')
  .replace(/\n\'/gm, '\'');
  tpl = "tpl = '" + tpl + "'";
  tpl = tpl.replace(/' '/g, '\'\\n\'');
  tpl = 'var tpl = ""; \nwith(obj || {}){\n' + tpl + '\n}\nreturn tpl;';
  //console.log(tpl);
  return new Function('obj', 'escape', tpl);
};

exports.render = function(complied, data){
  return complied(data, escape);
};
