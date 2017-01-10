$html = "dfd <a href='http://www.cnblogs.com/danbo'>TCP/IP Deatil I</a>";

while($html =~ m{<a\b([^>]*)>(.*?)</a>}ig){
  my $guts = $1;
  my $link = $2;

  if($guts =~ m{
    \b href
    \s* = \s*
    (?:
      "([^"]*)"
      |
      '([^']*)'
      |
      ([^'">\s]+)
    )
  }xi){
    my $url = $+;
    print "$url with link test: $link\n";
  }
}