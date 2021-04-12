open(IN,"studentlist") or die("no such file!");;
open(OUT,">out.data");
while(<IN>){
chomp;
if(/\d+:\s.+\s(\w)\s(\d+)\s(\d+)$/){
print(OUT $1," ",$2," ",$3,"\n");
$w{$1}+=$3;
$count{$1}++;
}
}
close(IN);

printf(OUT "male average = %.2f kg, ", $w{m}/$count{m});
printf(OUT "female average = %.2f kg\n", $w{f}/$count{f});

close(OUT);
