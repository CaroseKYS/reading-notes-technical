var fs = require('fs');
var mime = require('mime');
module.exports = function(res, filepath){
  fs.stat(filepath, function(err, stat){
    var stream = fs.createReadStream(filepath);
    //Set content
    res.setHeader('Content-Type', mime.lookup(filepath));
    //set length
    res.setHeader('Content-Lenght', stat.size);
    //set attachement
    res.setHeader('Content-Disposition', 'attachment; filename="' 
                  + filepath.match(/^.*\/([^/]*\.[^/]*)$/)[1] + '"');
    res.writeHead(200);
    stream.pipe(res);
  });
};
