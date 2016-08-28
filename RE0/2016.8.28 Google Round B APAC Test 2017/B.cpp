#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long LL;

const LL mod = 1000000007;
LL a,b,n,k;
LL ans;

LL pow3(LL x,LL n)
{
    if(n == 0) return 1;
    else
    {
        while((n&1) == 0)
        {
            n >>= 1;
            x = x*x%mod;
        }
    }
    LL result = x%mod;
    n >>= 1;
    while(n != 0)
    {
        x = x*x%mod;
        if((n&1) != 0)
            result = result*x%mod;
        n >>= 1;
    }
    return result%mod;
}

int main()
{
    int T, cas = 1;
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&k);
        printf("Case #%d: ",cas++);
        ans = 0;
        FOR(i,1,n)
            FOR(j,1,n)
                if (i != j)
                {
                    if ((pow3(i,a)+pow3(j,b))%k == 0)
                        ans++;
                }
        printf("%I64d\n",ans);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
