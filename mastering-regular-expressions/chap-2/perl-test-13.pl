$text = "The population of 298444215 is growing.";

$text1 = $text;
$text2 = $text;
$text3 = $text;
$text4 = $text;

$text1 =~ s/(?<=\d)(?=(?:\d\d\d)+)/,/g;
$text2 =~ s/(?<=\d)(?=(?:\d\d\d)+\b)/,/g;
$text3 =~ s/(\d)(?=(?:\d\d\d)+(?!\d))/$1,/g;
$text4 =~ s/(\d)((\d\d\d)+\b)/$1,$2/g;

print "$text1\n";
print "$text2\n";
print "$text3\n";
print "$text4\n";
