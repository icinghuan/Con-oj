#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int MAXN = 100000 + 5;
int n,m;
int a[MAXN],s[MAXN];

bool solve()
{
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
        scanf("%d",&a[i]);
    s[0] = 0;
    s[1] = a[1];
    FOR(i,2,n)
        s[i] = s[i-1]+a[i];
    FOR(i,0,n-1)
        FOR(j,i+1,n)
        {
            if ((s[j]-s[i])%m == 0)
                return true;
        }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
