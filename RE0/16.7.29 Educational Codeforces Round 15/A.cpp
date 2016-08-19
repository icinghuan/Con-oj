#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int a[100005],n,s,Max;

int main()
{
    scanf("%d",&n);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    s = 1;
    Max = 1;
    FOR(i,2,n)
    {
        if (a[i-1]<a[i])
            s++;
        else
            s = 1;
        if (Max < s)
            Max = s;
    }
    printf("%d\n",Max);
    return 0;
}
