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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int INF=0x3f3f3f3f;
const double D_INF=1e100;
const double eps= 1e-8;
const int MAXN = 100000 + 5;
int a[MAXN][30];

int main()
{
    int T;
    int cas = 1;
    int n,q;
    int ans;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&q);
        char c = getchar();
        FOR(i,1,n)
        {
            c = getchar();
            FOR(j,0,25)
                a[i][j] = a[i-1][j];
            a[i][c-'A'] = a[i-1][c-'A'] + 1;
        }
        int l,r;
        printf("Case #%d:\n",cas++);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d%d",&l,&r);
            FORR(j,25,0)
                if (a[r][j] - a[l-1][j] > 0)
                    ans = a[r][j] - a[l-1][j];
            printf("%d\n",ans);
        }
    }
    return 0;
}
