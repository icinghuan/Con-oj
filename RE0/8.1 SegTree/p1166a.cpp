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
const int MAXN = 50000 + 5;
int sum[MAXN<<2];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int p,int add,int l,int r,int rt)
{
    if (l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (l+r)>>1;
    if (p <= m)
        update(p,add,lson);
    else
        update(p,add,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L <= l&&r <= R)
    {
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if (L <= m)
        ret += query(L,R,lson);
    if (R > m)
        ret += query(L,R,rson);
    return ret;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++)
    {
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1,n,1);
        char op[10];
        while (scanf("%s",op))
        {
            if (op[0] == 'E') break;
            int a,b;
            scanf("%d%d",&a,&b);
            if (op[0] == 'A') update(a,b,1,n,1);
            if (op[0] == 'S') update(a,-b,1,n,1);
            if (op[0] == 'Q') printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}
