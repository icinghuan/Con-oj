#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[35];

int main()
{
    int n;
    cin>>n;
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d",&t);
        a[i] = t;
        while(scanf(",%d",&t))
        {
            if (a[i] < t)
                a[i] = t;
        }
        if (a[i] > m)
            m = a[i];
    }
    cout<<m<<endl;
    bool dot = false;
    for (int i = 1; i <= n; ++i)
        if (m == a[i])
        {
            if (dot)
            {
                cout<<","<<i;
            }
            else
            {
                cout<<i;
                dot = true;
            }
        }
    cout<<endl;
    return 0;
}
