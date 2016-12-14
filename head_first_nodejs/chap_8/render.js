module.exports = function(str, data){
  var tpl = str.replace(/<%\s*=\s*([\S]+?)\s*%>/g, function(match, code){
    console.log('match: %s, code: %s', match, code);
    return "' + obj." + code + " + '";
  });

  console.log(tpl);
  tpl = "var tpl = '" + tpl + "'; return tpl;"
  console.log(tpl);
  var complier = new Function('obj', tpl);
  return complier(data);
};
