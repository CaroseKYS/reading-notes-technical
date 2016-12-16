my $need_close_anchor = 0;

$html = "<a htef='http://www.leshui365.com'>点这里</a>";
while (not $html =~ m/\G\z/gc) {
  if($html =~ m/\G(\w+)/gc){
    print "$1\n";
  }elsif ($html =~ m/\G[^<>&\w]+/gc) {
    print "elsif 1\n";
  }elsif($html =~m/\G<img\s+([^>]+)>/gci){
    print "elsif 2\n";
  }elsif(not $need_close_anchor and $html =~m/\G<A\s+([^>]+)>/gci){
    $need_close_anchor = 1;
    print "elsif 3\n";
  }elsif($need_close_anchor and $html =~ m{\G</A>}gci){
    $need_close_anchor = 0;
    print "elsif 4\n";
  }elsif($html =~ m/\G&(#\d+<\w+);/gc){
    print "elsif 5\n";
  }else{
    my $location = pos($html);
    my ($badstuff) = $html =~ /\G(.{1,12})/s;
    die "unexpected HTML at position $location: $badstuff\n";
  }

  if($need_close_anchor){
    die "Missing final </A>";
  }
}