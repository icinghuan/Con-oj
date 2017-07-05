#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string s[105];
int f[105];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
        cin>>s[i];
    for (int i = 0; i < m; ++i)
    {
        int wxd = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int k = j+1; k < n; ++k)
                if (s[i][j] > s[i][k])
                    wxd++;
        }
        f[i] = wxd;
    }
    for (int i = 0; i < m; ++i)
        for (int j = m-1; j >= i+1; --j)
            if (f[j] < f[j-1])
            {
                string tmps = s[j];
                s[j] = s[j-1];
                s[j-1] = tmps;
                int tmp = f[j];
                f[j] = f[j-1];
                f[j-1] = tmp;
            }
    for (int i = 0; i < m; ++i)
        cout<<s[i]<<endl;
    return 0;
}
