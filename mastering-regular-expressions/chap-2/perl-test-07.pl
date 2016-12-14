$var = "jeff and JEff and JEFF and jeFF";
$var =~ s/\bjeff\b/Jeff/ig;
print "result is: $var\n";
