{
    count[$1]++;
}
END {
    for(i in count){
	print i,count[i];
    }
}
