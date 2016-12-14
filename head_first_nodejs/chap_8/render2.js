exports.complie = function(str){
  var tpl = str.replace(/<%\s*=\s*([\S]+?)\s*%>/g, function(match, code){
    return "' + obj." + code + " + '";
  });

  tpl = "var tpl = '" + tpl + "'; return tpl;"
  return new Function('obj, escape', tpl);
};

exports.render = function(complied, data){
  return complied(data);
};
