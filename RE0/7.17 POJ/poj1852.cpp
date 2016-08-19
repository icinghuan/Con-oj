#include<cstdio>
#include<iostream>

using namespace std;

const int MAX_N = 1000005;
int L,n;
int x[MAX_N];

void solve()
{
    int minT = 0;
    for (int i = 0; i < n; ++i)
    {
        minT = max(minT, min(x[i],L-x[i]));
    }
    int maxT = 0;
    for (int i = 0; i < n; ++i)
    {
        maxT = max(maxT,max(x[i],L-x[i]));
    }
    printf("%d %d\n",minT,maxT);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&L,&n);
        for (int i = 0; i < n; ++i)
            scanf("%d",&x[i]);
        solve();
    }
    return 0;
}
