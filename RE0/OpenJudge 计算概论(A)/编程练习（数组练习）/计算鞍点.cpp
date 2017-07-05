#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[10][10];
int m[10],l[10];

int main()
{
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            cin>>a[i][j];
    for (int i = 1; i <= 5; ++i)
    {
        m[i] = a[i][1];
        for (int j = 2; j <= 5; ++j)
        {
            if (a[i][j] > m[i])
                m[i] = a[i][j];
        }
    }
    for (int j = 1; j <= 5; ++j)
    {
        l[j] = a[1][j];
        for (int i = 2; i <= 5; ++i)
        {
            if (a[i][j] < l[j])
                l[j] = a[i][j];
        }
    }
    bool fin = false;
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            if (a[i][j] == m[i]&&a[i][j] == l[j])
            {
                cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
                fin = true;
            }
    if (!fin)
        cout<<"not found"<<endl;
    return 0;
}
