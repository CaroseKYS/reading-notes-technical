var render = require('./render3');
var tpl = 'Hello <%= name%>.';
var data = {name: '<script>alert(1);</script>'};
var complied = render.complie(tpl);
console.log(render.render(complied, data));
