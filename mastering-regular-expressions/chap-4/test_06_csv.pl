$line = 'Ten Thousand,10000, 2710 ,,"10,000","It\'s ""10 Grand"", baby",10K';

while($line =~ m{
    (?:^|,)(?:"((?:[^"]|"")+)"|([^","]*))
  }gx){

  if (defined $1) {
    $field = $1;
  }else {
    $field = $2;
    $field =~ s/""/"/g;
  }
  print "[$field] ";
}
print "\n";