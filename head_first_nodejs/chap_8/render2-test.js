var render = require('./render2');
var tpl = 'Hello <%= name %>.';
var data = {name: 'kangys'};
var complied = render.complie(tpl);
console.log(render.render(complied, data));
