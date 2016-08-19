#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define LL long long

using namespace std;

const int MAXN = 8005;
int n,a[MAXN],b[MAXN];
int ans[MAXN];
int f[MAXN][MAXN];

int main()
{
	while (scanf("%d",&n) != EOF)
    {
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
            //a[i] = i;
            ans[i] = 1;
        }

        int k = 3,l,o;
        while (k <= n)
        {
            l = 1;
            while (l <= n-k+1)
            {
                FOR(i,l,l+k-1)
                    b[i] = a[i];
                sort(b+l,b+l+k);
                o = (l+l+k-1)/2;
                FOR(i,l,l+k-1)
                    if (a[i] == b[o])
                        ans[i]++;
                l++;
            }
            k += 2;
        }
        FOR(i,1,n-1)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
	}
	return 0;
}
