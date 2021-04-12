while(<>){
chomp;
if(/\d+:\s.+\s(\w)\s(\d+)\s(\d+)$/){
print $1," ",$2," ",$3,"\n";
$w{$1}+=$3;
$count{$1}++;
}
}

printf("male average = %.2f kg, ", $w{m}/$count{m});
printf("female average = %.2f kg\n", $w{f}/$count{f});
