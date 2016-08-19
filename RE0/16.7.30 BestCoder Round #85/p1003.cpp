#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

long long x,k1,k2,m1,m2;
long long ans;

bool isSqr(long long k)
{
    int kk = sqrt(k);
    if (kk*kk == k)
        return true;
    else
        return false;
}

bool isNo(long long k)
{
    int kk = sqrt(k);
    if (kk*kk == k)
        return true;
    FOR(i,4,k/2)
        if (k%i == 0&&isSqr(i))
            return true;
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        cin>>x;
        k1 = sqrt(x);
        k2 = k1+1;
        while (isNo(k1))
            k1--;
        while (isNo(k2))
            k2++;
        m1 = k1*k1;
        m2 = k2*k2;
        if (x-m1<=m2-x)
            cout<<x-m1<<endl;
        else
            cout<<m2-x<<endl;
    }
    return 0;
}
