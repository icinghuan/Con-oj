#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int MAXN = 100005;
int n,ma;
int a[MAXN],f[MAXN];
//1 2 3 4 5 1 2
//1 2 3 4 5 1 2
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        FOR(i,1,n)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        f[1] = 1;
        FOR(i,2,n)
        {
            f[i] = 1;
            FOR(j,1,i-1)
                if (a[j] < a[i])
                    f[i]++;

        }
        FOR(i,1,n-1)
            printf("%d ",f[i]);
        printf("%d\n",f[n]);
    }
    return 0;
}
