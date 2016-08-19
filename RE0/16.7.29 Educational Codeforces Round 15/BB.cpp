#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int a[100005],n,kk[31];

int main()
{
    freopen("Bin.txt","r",stdin);
    //freopen("Bout2.txt","w",stdout);
    scanf("%d",&n);
    kk[1] = 2;
    FOR(i,2,30)
        kk[i] = kk[i-1]*2;
    FOR(i,1,n)
        scanf("%d",&a[i]);
    int ans = 0;
    FOR(i,1,n)
        FOR(j,i+1,n)
            FOR(k,1,30)
            {
                if (a[i]+a[j] == kk[k])
                    ans++;
            }
    printf("%d\n",ans);
    fclose(stdin);
    //fclose(stdout);
    return 0;
}
