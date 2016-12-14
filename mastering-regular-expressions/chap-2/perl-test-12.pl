$str1 = "This is Jeffs dog and Jeffs cat.";

$str1 =~ s/(?<=\bJeff)(?=s\b)/'/g;

print $str1;
