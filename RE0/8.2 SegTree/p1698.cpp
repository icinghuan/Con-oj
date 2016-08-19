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
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

using namespace std;

const int INF=0x3f3f3f3f;
const double D_INF=1e100;
const double eps= 1e-8;
const int MAXN = 100000 + 5;
int sum[MAXN<<2];
int col[MAXN<<2];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if (col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = (m-(m>>1))*col[rt];
        sum[rt<<1|1] = (m>>1)*col[rt];
        col[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    col[rt] = 0;
    sum[rt] = 1;
    if (l == r)
    {
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l&&r <= R)
    {
        col[rt] = c;
        sum[rt] = c*(r-l+1);
        return;
    }
    PushDown(rt,r-l+1);
    int m = (l+r)>>1;
    if (L <= m)
        update(L,R,c,lson);
    if (R > m)
        update(L,R,c,rson);
    PushUp(rt);
}
int main()
{
    int T,n,m;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas,sum[1]);
    }
    return 0;
}
