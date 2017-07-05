#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[105][105];

bool isRight(int n)
{
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        for (int j = 0; j < n; ++j)
            if (a[i][j] == 1)
                k++;
        if (k % 2 == 1)
            return false;
    }
    for (int j = 0; j < n; ++j)
    {
        int k = 0;
        for (int i = 0; i < n; ++i)
            if (a[i][j] == 1)
                k++;
        if (k % 2 == 1)
            return false;
    }
    return true;
}

void changebit(int x,int y)
{
    if (a[x][y] == 1)
        a[x][y] = 0;
    else
        a[x][y] = 1;
}

int main()
{
    int n;
    cin>>n;
    while (n != 0)
    {
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    cin>>a[i][j];
        if (isRight(n))
            cout<<"OK"<<endl;
        else
        {
            bool bac = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    changebit(i,j);
                    if (isRight(n))
                    {
                        cout<<"Change bit ("<<i+1<<","<<j+1<<")"<<endl;
                        bac = true;
                        break;
                    }
                    changebit(i,j);
                }
                if (bac)
                    break;
            }
            if (!bac)
                cout<<"Corrupt"<<endl;
        }
        cin>>n;
    }
    return 0;
}
