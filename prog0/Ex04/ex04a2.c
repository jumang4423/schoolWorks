/* 合格、不合格を判定するプログラム */
/* 作成者：Ryoma OKuda              */
/* 作成日：06/24/2019               */
#include <stdio.h>
int main()
{
 int score;

 printf("点数を入力して下さい ");
 scanf("%d", &score);
 printf("score : %d\n", score);

 printf("方法１による実行例\n");
 /* この行以降に方法１を実現するコードを書いて下さい */
 if (score >= 50) printf("合格\n");
 else if (score < 50) printf("不合格\n");
 
 printf("方法２による実行例\n");
 /* この行以降に方法２を実現するコードを書いて下さい */
 if (score >= 50) printf("合格\n");
 else printf("不合格\n");
 
 return 0;
}
