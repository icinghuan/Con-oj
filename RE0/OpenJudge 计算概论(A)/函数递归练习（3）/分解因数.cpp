#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int ans;

void dfs(int n,int low)
{
    if (n < low)
        return;
    ans++;
    for (int i = low; i < n; ++i)
        if (n % i == 0)
            dfs(n/i,i);
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int k;
        cin>>k;
        ans = 0;
        dfs(k,2);
        cout<<ans<<endl;
    }
    return 0;
}
