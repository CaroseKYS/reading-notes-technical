function compile(src){
  var tpl = src.replace(/<%\s*=\s*([^%>]*)%>/g, function(match, code){
    return "' + obj." + code + " + '";
  });

  tpl = "var tpl = '" + tpl + "'; return tpl;";

  return new Function('obj', tpl);
}

var render = compile("hello <%= user1 %>, hi <%= user2 %>.");

var result = render({
  user1: 'node',
  user2: 'java'
});

console.log(result);