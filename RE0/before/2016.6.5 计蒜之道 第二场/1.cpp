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
    double l1,l2,th;
    scanf("%lf%lf%lf",&l1,&l2,&th);
    th = th*PI/180.0;
    double ans = 0.0;
    double r1 = l1/2.0,r2 = l2/2.0;
    double x1 = l1/2.0,y1 = 0.0,x2 = l2/2.0*cos(th),y2 = l2/2.0*sin(th);
     //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
    double k = (x2-x1)/(y1-y2),bb = (r2*r2-r1*r1+x1*x1-x2*x2+y1*y1-y2*y2)/(2.0*y1-2.0*y2);

    //cout<<k<<' '<<bb<<endl;
    if (k-0.0000001 < 0 && k+0.0000001 > 0)
    {
        if (l1>l2)
            ans = l1*l1/4.0*PI;
        else
            ans = l2*l2/4.0*PI;
    }
    else
    {
        double a,b,c,x3,x4,x5,x6,y3,y4,y5,y6;
        //cout<<x5<<' '<<y5<<endl;
        k = -1.0/k;
        cout<<k<<endl;
        bb = y1-k*x1;
        cout<<bb<<endl;
        a = 1+k*k;
        //cout<<a<<endl;
        b = -2.0*x1-2.0*k*(bb-y1);
        //cout<<b<<endl;
        c = x1*x1+(bb-y1)*(bb-y1)-r1*r1;
        //cout<<c<<endl;
        x3 = (b+sqrt(b*b-4.0*a*c))/2.0,y3 = k*x3+bb;
        x4 = (b-sqrt(b*b-4.0*a*c))/2.0,y4 = k*x4+bb;
        a = 1+k*k;
        b = -2.0*x2-2.0*k*(bb-y2);
        c = x2*x2+(bb-y2)*(bb-y2)-r2*r2;
        x5 = (b+sqrt(b*b-4.0*a*c))/2.0,y5 = k*x5+bb;
        x6 = (b-sqrt(b*b-4.0*a*c))/2.0,y6 = k*x6+bb;
        double d[10];
        //cout<<x3<<' '<<x4<<' '<<y3<<' '<<y4<<endl;
        d[1] = dis(x3,x4,y3,y4);
        d[2] = dis(x3,x5,y3,y5);
        d[3] = dis(x3,x6,y3,y6);
        d[4] = dis(x4,x5,y4,y5);
        d[5] = dis(x4,x6,y4,y6);
        d[6] = dis(x5,x6,y5,y6);
        ans = 0.0;
        for (int i = 1; i <= 6; ++i)
            if (ans < d[i])
                ans = d[i];
        ans = ans*ans/4.0*PI;
    }
    printf("%0.10f",ans);
	return 0;
}
