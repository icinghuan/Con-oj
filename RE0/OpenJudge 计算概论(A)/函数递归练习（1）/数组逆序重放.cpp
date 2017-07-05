#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[105];

void reverses(int i,int j)
{
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    if (j - i == 1||i == j)
    {
        return;
    }
    else
    {
        reverses(i+1,j-1);
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>a[i];
    reverses(0,n-1);
    for (int i = 0; i < n-1; ++i)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    return 0;
}
