#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const double PI = 3.141592653589793238;

double dis(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    double l1,l2,l3,th1,th2,th3;
    scanf("%lf%lf%lf",&l1,&l2,&th1);
    th1 = th1*PI/180.0;
    l1 /= 2.0;
    l2 /= 2.0;
    l3 = l1*l1+l2*l2-2*l1*l2*cos(th1);
    l3 = sqrt(l3);
    double ans = l1+l2+l3;
    ans = ans*ans/4.0*PI;
    printf("%0.10f",ans);
	return 0;
}
