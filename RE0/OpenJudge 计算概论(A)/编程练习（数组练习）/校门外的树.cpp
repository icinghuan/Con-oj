#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[10005];

int main()
{
    int L,m;
    cin>>L>>m;
    for (int i = 0; i <= L; ++i)
        a[i] = 1;
    while (m--)
    {
        int aa,bb;
        cin>>aa>>bb;
        for (int i = aa; i <= bb; ++i)
            a[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= L; ++i)
        if (a[i] == 1)
            ans++;
    cout<<ans<<endl;
    return 0;
}
