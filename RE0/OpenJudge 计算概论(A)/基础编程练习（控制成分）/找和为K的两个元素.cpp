#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[1005];

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
        cin>>a[i];
    bool isFind = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
            if (a[i] + a[j] == k)
            {
                isFind = true;
                break;
            }
        if (isFind)
            break;
    }
    if (isFind)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
