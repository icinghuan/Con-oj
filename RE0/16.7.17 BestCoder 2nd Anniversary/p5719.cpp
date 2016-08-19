#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
int b[MAXN],c[MAXN];
long long m,ans;
const long long mod = 998244353;
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
            scanf("%d",&b[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d",&c[i]);
        ans = 1;
        m = 1;
        if (b[0] != c[0])
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i < n; ++i)
        {
            if (b[i] > b[i-1]||c[i] < c[i-1])
            {
                ans = 0;
                break;
            }
            if (b[i] < b[i-1]&&c[i] > c[i-1])
            {
                ans = 0;
                break;
            }
            if (b[i] < b[i-1]||c[i] > c[i-1])
            {
                continue;
            }
            m = c[i]-b[i]+1-i;
            if (m == 0)
            {
                ans = 0;
                break;
            }
            ans = (ans*m)%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
