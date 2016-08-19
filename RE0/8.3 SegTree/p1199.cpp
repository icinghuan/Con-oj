#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

const int n = 100000;
int sum[n<<2+5];
int col[n<<2+5];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if (col[rt] != -1)
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = (m-m>>1)*col[rt];
        sum[rt<<1|1] = (m>>1)*col[rt];
        col[rt] = -1;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l&&r <=R)
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
    int n;
    while (~scanf("%d",&n))
    {
        memset(sum,0,sizeof(sum));
        memset(col,-1,sizeof(col));
        int a,b,k;
        char c;
        FOR(i,1,n)
        {
            scanf("%d %d %c",&a,&b,&c);
            if (c == 'w')
                k = 1;
            else
                k = 0;
            update(a,b,k,1,n,1);
        }
        if (!sum[1])
        {
            puts("Oh, my god");
            continue;
        }
        FOR(i,n,n)
    }
    return 0;
}
