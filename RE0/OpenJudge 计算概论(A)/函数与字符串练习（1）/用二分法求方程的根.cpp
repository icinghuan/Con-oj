#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    double a,b,e;
    cin>>e;
    a = -10;
    b = 10;
    double eps = 1e-10;
    while (b-a-e > eps)//因为输出精度为8位所以eps取到10足够，用b-a > e会出现e = 0时无限循环的情况
    {
        double t = (a+b)/2;
        if ((2*a*a*a-4*a*a+3*a-6)*(2*t*t*t-4*t*t+3*t-6) <= 0.0)
            b = t;
        else
            a = t;
        //cout<<a<<" "<<b<<endl;
        //cout<<b-a<<endl;
    }
    double ans = (a+b)/2;
    printf("%.8lf",ans);
    return 0;
}
