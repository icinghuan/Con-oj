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
int a[MAXN],b[MAXN];

void solve(int i)
{
    int k = 1;
    FORR(j,i-1,1)
    {
        if (a[j] >= a[i])
        {
            k++;
            if (k > b[i])
                b[i] = k;
            if (b[j] < b[i])
            {
                b[j] = b[i];
                solve(j);
            }
            break;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        FOR(i,1,n)
            scanf("%d",&a[i]);
        b[1] = 1;
        ma = a[1];
        FOR(i,2,n)
        {
            if (a[i-1] >= a[i])
            {
                b[i] = 1;
            }
            else
            {
                b[i] = b[i-1]+1;
                solve(i);
            }
        }
        FOR(i,1,n-1)
            printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
    return 0;
}
