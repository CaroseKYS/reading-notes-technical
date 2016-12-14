var render = require('./render');
var tpl = 'Hello <%= name %>.';
var data = {name: 'kangys'};
console.log(render(tpl, data));
