#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        double a,b,c,d,t;
        double x1,x2;
        scanf("%lf%lf%lf",&a,&b,&c);
        d=b*b-4*a*c;
        if (d>=0) t=sqrt(d); else t=sqrt(-d);
        x1=(-b+t)/(2*a);
        x2=(-b-t)/(2*a);
        if (d>0) printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
            else if (d==0) printf("x1=x2=%.5lf\n",x1);
            else if (d<0)
            {
                if (a>0)
                    if (b!=0)
                        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", (-b)/(2*a),t/(2*a),(-b)/(2*a),t/(2*a));
                    else
                        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", (b)/(2*a),t/(2*a),(b)/(2*a),t/(2*a));
                else
                    if (b!=0)
                        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", (-b)/(2*a),-t/(2*a),(-b)/(2*a),-t/(2*a));
                    else
                        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n", (-b)/(2*a),-t/(2*a),(-b)/(2*a),-t/(2*a));
            }
        }
    return 0;
}

//这题要注意题目里面的一堆条件


/*#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    double eps = 1e-6;//eps = 0.000001
    while (n--)
    {
        double a,b,c;
        cin>>a>>b>>c;
        double ni;
        if (b*b-4*a*c < 0.0)
        {
            ni = sqrt(4*a*c-b*b)/(2*a);
            if (ni < 0.0)
                ni = -ni;
            printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",-b/(2*a),ni,-b/(2*a),ni);
            continue;
        }
        double x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
        double x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
        if (fabs(b*b-4*a*c) <= eps)
            printf("x1=x2=%.5lf\n",x1);
        else
        {
            if (a > 0.0)
                printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
            else
                printf("x1=%.5lf;x2=%.5lf\n",x2,x1);
        }
    }
    return 0;
}*/

