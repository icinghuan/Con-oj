#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[105][105];

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    int N = n;
    for (int i=1;i<=N-1;++i)
    {
        cout<<a[2][2]<<endl;
        for (int j=1;j<=n;++j)
        {
            int mi = a[j][1];
            for (int k=2;k<=n;++k)
                if (a[j][k] < mi)
                    mi = a[j][k];
            for (int k=1;k<=n;++k)
                a[j][k] -= mi;
        }
        for (int j=1;j<=n;++j)
        {
            int mi = a[1][j];
            for (int k=2;k<=n;++k)
                if (a[k][j] < mi)
                    mi = a[k][j];
            for (int k=1;k<=n;++k)
                a[k][j] -= mi;
        }
        for (int j=1;j<=n;++j)
            for (int k=2;k<=n-1;++k)
                a[j][k] = a[j][k+1];
        for (int j=1;j<=n;++j)
            for (int k=2;k<=n-1;++k)
                a[k][j] = a[k+1][j];
        n--;
    }
    cout<<a[2][2]<<endl;
    return 0;
}
