#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int k;
    if (y % x == 0)
        k = y/x;
    else
        k = y/x+1;
    cout<<n-k<<endl;
    return 0;
}

