#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const long long mod = 1073741824;

int n,m;
long long ans;
long long f[50][50];
void solve()
{
    FOR(i,1,40)
    {
        f[i][1] = i+1;
        f[1][i] = i+1;
    }
    FOR(k,2,40)
        FOR(kk,2,40)
        {
            f[k][kk] = f[k-1][kk-1]+2;
            FOR(j,1,kk-1)
                FOR(i,1,k-1)
                    f[k][kk] = (f[k][kk]+k-i+k-i)%mod;
        }
}

int main()
{
    int T;
    scanf("%d",&T);
    solve();
    while (T--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",f[n][m]);
    }
	return 0;
}
