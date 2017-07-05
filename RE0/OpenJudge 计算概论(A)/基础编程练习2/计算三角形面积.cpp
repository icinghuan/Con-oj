#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    float a,b,d,e,f,g;
    cin>>a>>b>>d>>e>>f>>g;
    float S = 0.5 * (a*e+d*g+b*f-f*e-a*g-d*b);
    printf("%.2f",S);
    return 0;
}
// A(a,b),B(d,e),C(f,g)可用行列式快速求解S=1/2(ae+dg+bf-fe-ag-db)
