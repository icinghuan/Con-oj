#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

char s[10];
char ans[10];
int k = 0;
int f[10];

void dfs(int n)
{
    if (n == k)
    {
        cout<<ans<<endl;
    }
    for (int i = 0; i < k; ++i)
        if (f[i] == 0)
    {
        ans[n] = s[i];
        f[i] = 1;
        dfs(n+1);
        f[i] = 0;
    }
}

int main()
{
    char c;
    c = getchar();
    while (c != '\n')
    {
        s[k] = c;
        k++;
        c = getchar();
    }
    //cout<<k<<endl;
    dfs(0);
    return 0;
}
