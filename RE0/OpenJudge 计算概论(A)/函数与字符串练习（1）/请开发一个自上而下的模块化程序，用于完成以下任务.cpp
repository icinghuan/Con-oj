#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m;
int a[1005],b[1005],c[2005];

void read()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        cin>>a[i];
    for (int i = 0; i < m; ++i)
        cin>>b[i];
}

void ssort()
{
    sort(a,a+n);
    sort(b,b+m);
}

void mmerge()
{
    for (int i = 0; i < m; ++i)
        a[i+n] = b[i];
}

void print()
{
    for (int i = 0; i < n+m; ++i)
        cout<<a[i]<<" ";
}
int main()
{
    read();
    ssort();
    mmerge();
    print();
    return 0;
}
