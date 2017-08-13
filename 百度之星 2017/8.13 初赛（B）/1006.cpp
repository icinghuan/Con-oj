#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 100000+5;
int n,m;
long long a[MAXN*4];

struct Part{
    long long l;
    long long r;
} part[MAXN];

bool cmp(Part a,Part b)
{
    if (a.l < b.l)
        return true;
    if (a.l == b.l)
        return a.r < b.r;
    return false;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%I64d%I64d",&part[i].l,&part[i].r);
        sort(part,part+n,cmp);
        //for (int i = 0; i < n; i++)
            //printf("%I64d %I64d\n",part[i].l,part[i].r);
        int cnt = 1;
        a[0] = part[0].l-1;
        for (int i = 0; i < n-1; i++)
        {
            if (part[i].r+1 >= part[i+1].l)//combine
            {
                part[i+1].l = part[i].l;
            }
            else//independence
            {
                a[cnt] = part[i].r-part[i].l+1;
                cnt++;
                a[cnt] = part[i+1].l-part[i].r-1;
                cnt++;
            }
        }
        a[cnt] = part[n-1].r-part[n-1].l+1;
            cnt++;
        long long ans = 0;
        long long k = a[1];
        long long tm = m;
        long long first = 1;
        for (int i = 1; i < cnt-2; i += 2)
        {
            if (tm >= a[i+1])
            {
                k += a[i+1]+a[i+2];
                tm -= a[i+1];
            }
            else
            {
                k += tm;
                if (k > ans)
                    ans = k;
                k = k-tm-a[first+1]-a[first];
                tm += a[first+1];
                first += 2;
            }
        }
        k += tm;
        if (k > ans)
            ans = k;
        /*for (int i = 1; i < cnt; i += 2)
        {
            long long k = a[i];
            long long tm = m;
            for (int j = i+1; j < cnt; j += 2)
            {
                if (tm >= a[j])
                {
                    k += a[j+1]+a[j];
                    tm -= a[j];
                }
            }
            k += tm;
            if (k > ans)
                ans = k;
        }*/
        cout<<ans<<endl;
    }
    return 0;
}
