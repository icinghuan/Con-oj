#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char a[101][101];
    int n, m, sum = 0;
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
             cin >> a[i][j];
        }
    }
    cin >> m;
    for(int d = 1; d <= m; d++)
    {
        for(int i = 0; i < n; i++)
        {
             for(int j = 0; j < n;j++)
             {
                 if(a[i][j] == '!')
                   a[i][j] = '@'; // 将前一天标记的人感染
             }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                 // 将感染人周围的人标记
                if(a[i][j] == '@')
                {
                    if(i + 1 <n && a[i + 1][j] == '.')
                        a[i + 1][j]='!';
                    if(j - 1 >= 0 && a[i][j - 1] == '.')
                           a[i][j - 1] = '!';
                    if(j + 1 < n && a[i][j + 1] == '.')
                           a[i][j + 1]='!';
                    if(i - 1 >= 0 && a[i - 1][j] == '.')
                           a[i - 1][j] = '!';
                }
            }
        }

    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == '@')
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
 }

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

char a[105][105];

int x[105],y[105];

//递归写不出来 = =

int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin>>a[i][j];
    int m;
    cin>>m;
    m--;
    while (m--)
    {
        int kk = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] == '@')
                {
                    x[kk] = i;
                    y[kk] = j;
                    kk++;
                }
        for (int i = 0; i < kk; ++i)
            {
                int ii = x[i];
                int jj = y[i];
                if (a[ii][jj] == '@')
                {
                    if (a[ii+1][jj] == '.') a[ii+1][jj] = '@';
                    if (a[ii][jj+1] == '.') a[ii][jj+1] = '@';
                    if (a[ii-1][jj] == '.') a[ii-1][jj] = '@';
                    if (a[ii][jj-1] == '.') a[ii][jj-1] = '@';
                }
            }
    }
    int k = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == '@')
                k++;
    cout<<k<<endl;
    return 0;
}
*/
