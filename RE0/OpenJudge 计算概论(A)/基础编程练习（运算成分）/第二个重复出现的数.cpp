#include <iostream>

using namespace std;

int a[1000];

int main()
{
    int n;cin>>n;
    while (n--)
    {
        int u=0;
        bool d=false;
        int m;
        cin>>m;
        for (int i=0;i<m;i++)
            cin>>a[i];
        for (int i=0;i<m;i++)
        {
            for (int j=i+1;j<m;j++)
            {
                if(a[i]==a[j])
                {
                    a[i]=-1;
                    break;
                }
            }
            if (a[i]==-1)
                break;
        }
        for (int i=0;i<m;i++)
        {
            for (int j=i+1;j<m;j++)
            {
                if(a[i]==a[j])
                {
                    d=true;
                    u=a[i];
                    break;
                }
            }
            if (d) break;
        }
        if (d)
            cout<<u<<endl;
        else
            cout<<"NOT EXIST"<<endl;
    }
    return 0;
}

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[505];

int main()
{
    int m;
    cin>>m;
    while (m--)
    {
        int n;
        cin>>n;
        bool isfind = false;
        bool out = false;
        int first = -1;
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        sort(a,a+n);
        for (int i = 0; i < n; ++i)
        {
            if (out)
                break;
            for (int j = i+1; j < n; ++j)
            {
                if (a[i] == first)
                    break;
                if (a[i] == a[j])
                {
                    if (isfind)
                    {
                        out = true;
                        cout<<a[i]<<endl;
                        break;
                    }
                    else
                    {
                        first = a[i];
                        isfind = true;
                        break;
                    }
                }

            }
        }
        if (!out)
            cout<<"NOT EXIST"<<endl;
    }
    return 0;
}*/
