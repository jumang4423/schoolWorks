#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_1(double, Point, Point);
void  rotate_2(double, Point, Point *);

int main()
{
  double rad, deg;
  Point c = {3.0, 2.0}, a = {6.0, 4.0}, b1,b2;

  printf("回転角度[度]をいれて下さい\n");
  scanf("%lf", &deg);
  rad=deg*M_PI/180;
  printf("Theta %f [deg](%f [rad])\n",deg,rad);
  printf("center   : %f %f\n",c.x,c.y);
  printf("original : %f %f\n",a.x,a.y);
  
  b1 = rotate_1(rad, c, a);
  b2 = a;
  rotate_2(rad, c, &b2);

  printf("rotate_1 : %f %f\n",b1.x,b1.y);
  printf("rotate_2 : %f %f\n",b2.x,b2.y);

  return 0;
}

Point rotate_1(double rad, Point center, Point p)
{
  double prex, prey;
    p.x -=center.x;
    p.y -=center.y;
    prex = p.x;
    prey = p.y;
    p.x = prex*cos(rad) - prey*sin(rad);
    p.y = prex*sin(rad) + prey*cos(rad);
    p.x +=center.x;
    p.y +=center.y;


    return p;
}

void rotate_2(double rad, Point center, Point *p)
{
  double prex, prey;
    p->x -=center.x;
    p->y -=center.y;
    prex = p->x;
    prey = p->y;
    p->x = prex*cos(rad) - prey*sin(rad);
    p->y = prex*sin(rad) + prey*cos(rad);
    p->x +=center.x;
    p->y +=center.y;
}