$url = "http://www.leshui365.com";
# $url = "http://localhost:3000/user?dialog=true";

if($url =~ m{^http://([^/:]*)(?::(\d+))?(/.*)?$}i){
  my $host = $1;
  my $port = $2;
  my $path = $3;
  print "Host: $host\n";
  print "Port: $port\n";
  print "Path: $path\n";
} else {
  print "Not a http url.";
}