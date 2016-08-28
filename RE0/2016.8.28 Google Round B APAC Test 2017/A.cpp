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

int l,r;
LL k;
LL ans;

int main()
{
    int T, cas = 1;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        printf("Case #%d: ",cas++);
        k = min(l,r);
        ans = k*(k+1)/2;
        printf("%I64d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
