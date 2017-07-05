#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    double e = 1;
    double fac;
    for (int i = 1; i <= n; ++i)
    {
        fac = 1;
        for (int j = 2; j <= i; ++j)
            fac *= j;
        e += 1/fac;
    }
    printf("%.10lf",e);
    return 0;
}
