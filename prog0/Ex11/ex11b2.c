#include <stdio.h>
#define INIT_CREDIT 100000 

int payment(double, int);
int fee(int);

int main()
{
  int balance = INIT_CREDIT;
  int activity, debit_yen, payment_yen, fee_yen;
  double rate = 0.0;

  while (1)
  {
    printf("\nBalance: %d yen\n", balance);
    printf("Input payment(- local currency) or income(+ yen) >> ");
    scanf("%d", &activity);
    if (activity == 0) 
    {
      break;
    } 
    else if (activity > 0) 
    {
        debit_yen = activity;
    } 
    else 
    {
        printf("Input exchange rate (yen/local) >> ");
        scanf("%lf", &rate);
        payment_yen = payment(rate, -activity);
        fee_yen = fee(payment_yen);
        debit_yen = - (payment_yen + fee_yen);
        printf("fee: %d yen\n", fee_yen);
    }
    balance += debit_yen;
  }
  printf("\nBalance: %d yen\n", balance);

  return 0;
}

int payment(double x, int y)
{
    int res;
    res=x*y;
    return res;
}

int fee(int z)
{
    double res2, ten;
    res2=(double)(z)*0.03;
    if(res2<10)
    {
        res2=(double)10;

    }
    else if(res2>=10)
    {
        ten=(int)(res2/10);
        res2=ten*10;
    }
    return res2;
}