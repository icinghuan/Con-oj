#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[105];

int main()
{
    int n;
    cin>>n;
    int k;
    for (int i = 0; i < n; ++i)
    {
        cin>>k;
        *(a+i) = k;
    }
    for (int i = n-1; i >= 0; --i)
    {
        k = *(a+i);
        cout<<k<<" ";
    }
    return 0;
}
