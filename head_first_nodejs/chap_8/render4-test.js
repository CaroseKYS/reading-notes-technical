var render = require('./render4');
var tpl = [
  '<%if(obj.user) { %>',
  '<h2><%=user.name%></h2>',
  '<%} else{%>',
  '<h2>no name user.</h2>',
  '<%}%>',
  '<span>This is a span.</span>'
].join('\n');

var complied = render.complie(tpl);

//console.log(render.render(complied, {user:{name:'kangys'}}));
console.log(render.render(complied, {}));
