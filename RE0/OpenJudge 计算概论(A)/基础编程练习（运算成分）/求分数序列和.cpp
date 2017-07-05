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
    double sum = 0;
    double a = 2,b = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum += a/b;
        a = a+b;
        b = a-b;
    }
    printf("%.4lf\n",sum);
    return 0;
}
