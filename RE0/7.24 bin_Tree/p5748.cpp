#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int MAXN = 100000+5;
const int INF = 0x3f3f3f3f;
int n,ma;
int a[MAXN],b[MAXN],dp[MAXN];
//1 2 3 4 5 1 2
//1 2 3 4 5 1 2
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        FOR(i,1,n)
            scanf("%d",&a[i]);
        memset(dp,INF,sizeof(dp));
        FOR(i,1,n)
        {
            b[i] = lower_bound(dp, dp+n, a[i]) - dp + 1;
            *lower_bound(dp, dp+n, a[i]) = a[i];
        }
        FOR(i,1,n-1)
            printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
    return 0;
}
