#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define per(i,j,k) for (int i = j; i >= k; i--)
using namespace std;
typedef __int64 LL;
const int low(int x) { return x&-x; }
const double eps = 1e-8;
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int T, tp, p[N], f[N], t;
LL n, ans;

void init()
{
    t = 0;
    rep(i, 2, N - 1)
    {
        if (!f[i]) p[t++] = i;
        for (int j = 0; j < t&&p[j] * i < N; j++)
        {
            f[i*p[j]] = 1;
            if (i%p[j]) break;
        }
    }
}

bool check(int x)
{
    for (int i = 0, j, k = x; i < t; i++)
    {
        for (j = 0; k%p[i] == 0; j++) k /= p[i];
        if (j > 1) return false;
        if (p[i] * p[i] > k) break;
    }
    ans = min(ans, abs(n - 1LL * x*x));
    return true;
}

int main()
{
    init();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &n);
        LL x = (LL)sqrt(1.0*n);
        LL y = x + 1;
        ans = INF;
        while (!check(x) && x >= 2) --x;
        while (!check(y)) ++y;
        printf("%I64d\n", ans);
    }
    return 0;
}
