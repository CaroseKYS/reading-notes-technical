$letter = "Dear =FIRST=,\nYou have been chosen to win a brand new =TRINKET=! Free!\nChould you yse another =TRINKET= in the =FAMILY= household.\nYes =SUCKER=, I bet you could! Just respond by ...";

$given = "TOM";
$family = "Cruise";
$wunderprize = "100% genuine faux diamond";

$letter =~ s/=FIRST=/$given/g;
$letter =~ s/=FAMILY=/$family/g;
$letter =~ s/=SUCKER=/$given $family/g;
$letter =~ s/=TRINKET=/fabulous $wunderprize/g;

print "$letter\n";
