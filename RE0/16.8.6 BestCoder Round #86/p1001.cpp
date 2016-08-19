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

 long long a,sum,b;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        sum = 0;
        int n,m;
        cin>>n>>m;
        FOR(i,1,n)
        {
            scanf("%I64d",&a);
            sum += a;
        }
        FOR(i,1,m)
        {
            scanf("%I64d",&b);
            if (sum < b)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
