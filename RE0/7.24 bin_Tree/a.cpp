#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

void Exchg1(int x, int y)
{
 int tmp;
 tmp=x;
 x=y;
 y=tmp;
 printf("Exchg1:x=%d,y=%d\n",x,y);
}
void Exchg2(int &x, int &y)
{
 int tmp;
 tmp=x;
 x=y;
 y=tmp;
 printf("Exchg2:x=%d,y=%d\n",x,y);
}
void Exchg3(int *x, int *y)
{
 int tmp;
 tmp=*x;
 *x=*y;
 *y=tmp;
 printf("Exchg3:x=%d,y=%d\n",*x,*y);
}

int main()
{
 int a=4,b=6;
 Exchg1 (a,b) ;
 printf("a=%d,b=%d\n",a,b);
 Exchg2 (a,b);
 printf("a=%d,b=%d\n",a,b);
 Exchg3(&a,&b) ;
 printf("a=%d,b=%d\n",a,b);
 return 0;
}
