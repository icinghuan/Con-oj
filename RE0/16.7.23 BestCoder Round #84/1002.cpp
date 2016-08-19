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
int a[MAXN],b[MAXN],f[MAXN];



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
            if (a[i-1] < a[i])
                f[i] = f[i-1]+1;
            else
            {
                f[i] = 1;
                FOR(j,i-1,1)
                    if (a[j] < a[i])
                        f[i]++;
            }
        }
        FOR(i,1,n-1)
            printf("%d ",f[i]);
        printf("%d\n",f[n]);
    }
    return 0;
}
