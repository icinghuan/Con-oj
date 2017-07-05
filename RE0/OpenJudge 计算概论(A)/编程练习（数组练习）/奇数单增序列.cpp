#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[505];

int main()
{
    int n;
    cin>>n;
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin>>t;
        if (t % 2 == 1)
            a[k++] = t;
    }
    sort(a,a+k);
    for (int i = 0; i < k-1; ++i)
        cout<<a[i]<<",";
    cout<<a[k-1]<<endl;
    return 0;
}
