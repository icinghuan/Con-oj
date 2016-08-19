#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n,d,ans;

void init()
{

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&d);
        ans = 0;
        FOR(i,2,n-1)
        {
            if (kk&&i != d)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
