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

void solve()
{
    int n, k;
    scanf("%d",&n);
    k = 0;
    while (n != 1)
    {
        if (k == 0)
        {
            printf("I hate that ");
            k = 1;
        }
        else
        {
            printf("I love that ");
            k = 0;
        }
        n--;
    }
    if (k == 0)
    {
            printf("I hate it\n");
            k = 1;
    }
    else
    {
        printf("I love it\n");
        k = 0;
    }
}

int main()
{
    solve();
    return 0;
}
