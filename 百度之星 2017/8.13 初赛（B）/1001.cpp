#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

const long long mod = 1000000007;
int n,m,T;
long long a,b,ans;

long long findd(long long x)
{
    long long k = mod-2,anss = 1;
    while(k)
    {
        if (k & 1)
            anss = anss*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return anss;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        if (n < m)
            swap(n,m);
        a = 1;
        b = 1;
        for (int i = n; i >= n-m+1; --i)
            a = a*i%mod;
        for (int i = m; i >= 1; --i)
            b = b*i%mod;
        ans = a*findd(b)%mod;
        cout<<ans<<endl;
        //C(n,m);
    }
    return 0;
}
