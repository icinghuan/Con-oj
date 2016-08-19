#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int k = 0, j = 0;
    FOR(i,1,n)
    {
        cin>>k;
        if (k)
            j++;
    }
    if (n == 1&&j)
    {
        cout<<"YES"<<endl;
        return;
    }
    if (n == 1&&!j)
    {
        cout<<"NO"<<endl;
        return;
    }
    if (n == j+1)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
int main()
{
    solve();
    return 0;
}
