print "Enter a temperature (e.g. 32F, 100C):\n";
$input = <STDIN>;

chomp($input);

if($input =~ m/^([-+]?[0-9]+(\.[0-9]*)?)[ \t]*([CF])$/){
  $InputNum = $1;
  $type = $3;
  print "$InputNum, $type.\n";
  if($type eq "C"){
    $celsius = $InputNum;
    $fahrenheit = ($celsius * 9 / 5) + 32;
  }else{
    $fahrenheit = $InputNum;
    $celsius = ($fahrenheit - 32) * 5 / 9;
  }
  printf "%.2f C is %.2f F.\n", $celsius, $fahrenheit;
}else{
  print "Expecting a number followed by \"C\" or \"F\".\n";
  print "So I don't undstand \"$input\".\n"
}
