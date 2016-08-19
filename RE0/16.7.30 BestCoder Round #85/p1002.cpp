#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int MAXN = 100000 + 5;
int n,k;
int a[MAXN];
long long ans;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&k);
        FOR(i,1,n-1)
            scanf("%d",&a[i]);
        sort(a+1,a+n);
        ans = n;
        FOR(i,1,n-k)
            ans += a[i];
        cout<<ans<<endl;
    }
    return 0;
}
