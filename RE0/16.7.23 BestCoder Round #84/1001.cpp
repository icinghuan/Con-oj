#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n,m,k,l,ans;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        ans = 0;
        if (m >= 30)
            m = 29;
        k = 1;
        FOR(i,1,m)
            k *= 2;
        FORR(i,m,1)
        {
            l = n/k;
            n = n-l*k;
            ans += l;
            k /= 2;
        }
        ans += n;
        printf("%d\n",ans);
    }
    return 0;
}
