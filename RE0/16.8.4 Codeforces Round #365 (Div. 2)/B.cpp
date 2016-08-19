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

using namespace std;

long long ans = 0;
int n,k;
int c[100000+5];
int cap;
bool f[100000+5];

int main()
{
    scanf("%d%d",&n,&k);
    memset(f,0,sizeof(f));
    FOR(i,1,n)
        scanf("%d",&c[i]);
    FOR(i,1,n-1)
        ans += c[i]*c[i+1];
    ans += c[n]*c[1];
    long long sum = 0, kk;
    FOR(i,1,n)
        sum += c[i];
    FOR(i,1,k)
    {
        scanf("%d",&cap);
        sum -= c[cap];
        f[cap] = true;
        int mm = cap-1;
        if (mm == 0) mm = n;
        kk = sum;
        if (!f[mm])
            kk = kk-c[mm];
        if (cap != n)
            kk = kk-c[cap+1];
        else
            if (!f[1])
                kk = kk-c[1];
        ans += kk*c[cap];
    }
    cout<<ans<<endl;
    return 0;
}
