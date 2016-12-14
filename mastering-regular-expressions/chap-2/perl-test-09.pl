$price1 = 100.345673452;
$price2 = 100.340673452;

$price1 =~ s/(\.\d\d[1-9]?)\d*/$1/g;
$price2 =~ s/(\.\d\d[1-9]?)\d*/$1/g;

print "$price1\n";
print "$price2\n";
