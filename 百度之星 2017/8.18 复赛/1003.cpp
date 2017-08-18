#include<cstdio>
#include<iostream>

using namespace std;

long long a[10005]= {0},b[10005]={0};

const int NUM=1000000007;

int main()
{
    int T;
    scanf("%d",&T);
    int n;
    while (T--)
    {
        scanf("%d",&n);
        b[1]=1;
        for (int i=2; i<=n; i++)
            b[i]=(b[i-1]*2%NUM);
        a[1]=1;
        a[2]=6;
        for (int i=3; i<=n; i++)
            a[i]=(2*a[i-1]+b[i]+4*a[i-2])%NUM;
        long long sum=4*a[n];
        for (int i=2; i<n; i++)
        {
            sum+=((8*b[n-i]*a[i-1])%NUM+(8*a[n-i]*b[i-1])%NUM)%NUM;
            sum %= NUM;
        }
        if(n==1)  sum=2 ;
        printf("%I64d\n",sum);
    }
    return 0;
}
