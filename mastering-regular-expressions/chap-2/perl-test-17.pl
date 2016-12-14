$/ = ".\n";

while(<>){
  next unless s{
    \b
    ([a-z]+)
    (
      (?:
        \s
        |
        <[^>]+>
      )+
    )
    (\1\b)
  }
  {\e[7m$1\e[m$2\e[7m$3\e[m}igx;

  s/^([^\e]*\n)+//mg;
  s/^/$ARGV: /mg;
  print;
}
