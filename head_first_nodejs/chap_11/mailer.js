var nodemailer = require('nodemailer');

var smtp_transport = nodemailer.createTransport('SMTP', {
  service: "163",
  auth: {
    user: "kys8823@163.com",
    pass: "Aa123456"
  }
});


var mailOptions = {
  from: "Fred Foo <foo@bar.com>",
  to: "carose.kys@aliyun.com",
  subject: "Hello",
  text: "Hello, world.",
  html: "<p>Hello World.</p>"
};


smtp_transport.sendMail(mailOptions, function(err, res){
  if(err){
    console.log(err);
  }else{
    console.log('Send successfully: ' + res.message);
  }
});
