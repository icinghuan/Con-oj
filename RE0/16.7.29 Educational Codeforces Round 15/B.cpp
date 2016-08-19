#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int a[100005],n,kk[32];

int bin1(int l,int r,int k)
{
    int mid;
    while (l < r)
    {
        mid = (l+r)>>1;
        if (a[mid] < k)
            l = mid+1;
        else
            r = mid;
    }
    if (l+1 == r&&a[r] == k)
        l++;
    if (a[l] == k)
        return l;
    else
        return 0;
}

int bin2(int l,int r,int k)
{
    int mid;
    while (l+1 < r)
    {
        mid = (l+r)>>1;
        if (a[mid] > k)
            r = mid-1;
        else
            l = mid;
    }
    if (l+1 == r&&a[r] == k)
        l++;
    if (a[l] == k)
        return l;
    else
        return 0;
}

int main()
{
    //freopen("Bin.txt","r",stdin);
    scanf("%d",&n);
    kk[1] = 2;
    FOR(i,2,30)
        kk[i] = kk[i-1]*2;
    FOR(i,1,n)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int f,m,ff;
    long long ans = 0;
    FOR(i,1,n-1)
        FOR(j,1,30)
        {
            ff = kk[j]-a[i];
            f = bin2(i+1,n,ff);
            if (!f)
                continue;
            ans += f-bin1(i+1,n,ff)+1;
        }
    printf("%I64d\n",ans);
    //fclose(stdin);
    return 0;
}
