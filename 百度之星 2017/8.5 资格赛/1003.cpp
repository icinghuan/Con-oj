#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<stack>

#define INF 0x3f3f3f3f
#define MAXN 100005
#define MAXM 1005

using namespace std;

int n,m;
int a[MAXN],b[MAXN],k[MAXM],p[MAXM];
int f[1005][15];
long long ans;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(f,0,sizeof(f));
        ans = 0;
        int k1 = 0,k2 = 0,hp = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d",&a[i],&b[i]);
            k1 = max(k1,b[i]);
            hp = max(hp,a[i]);
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d",&k[i],&p[i]);
            //if (d[p] == -1||d[p] < k)
                //d[p] = k;
            k2 = max(k2,p[i]);
        }
        if (k1 >= k2)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i <= 10; ++i)
        {
            for (int j = 1; j <= hp; ++j)
            {
                f[j][i]=INF;
                for (int l = 1; l <= m; ++l)
                {
                    int d = p[l]-i;
                    if(d <= 0)
                        continue;
                    if(d >= j)
                    {
                        f[j][i] = min(f[j][i],k[l]);
                    }
                    else
                    {
                        f[j][i] = min(f[j][i],f[j-d][i]+k[l]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            ans += f[a[i]][b[i]];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
