#include <stdio.h>
#include <ctype.h> 

int myatoi(char *);

int main()
{
  char str2[][20]={"  1632",
                   " -13.18",
                   "+48K",
                   " -987,654",
                   "+-55",
                   "x86",
                   "2020/07/24",
                   ""};
  int ival, i;

  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("string:%s\n", str2[i]);
    printf("value:%d\n", ival);
  }
  return 0;
}
/* この後に関数 myatoi を作成する */

int myatoi(char *s)
{
    int ans,i, pm = 1;
    for(i=0; isspace(s[i]); i++);
    if(s[i] == '-') pm = -1;
    if(s[i]>='0' && s[i]<= '9') i--;
    i++;
    for(ans= 0; s[i]>='0' && s[i]<= '9'; i++)
    {
        ans = 10 * ans + (s[i] - '0');
    }
    return ans * pm; 

}