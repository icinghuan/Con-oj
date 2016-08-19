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
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))

using namespace std;

typedef long long LL;

LL sum;

int main()
{
    int T, a;
    scanf("%d",&T);
    sum = 0;
    while(T--)
    {
        scanf("%d",&a);
        sum += a-1;
        if (sum%2 == 0)
            puts("2");
        else
            puts("1");
    }
    return 0;
}
