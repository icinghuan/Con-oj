#include<iostream>
#include<algorithm>

using namespace std;

int a[10];

bool cmp(int x,int y)
{
    if (x % 2 == 0&&y % 2 == 0)
    {//Å¼Êý
        if (x < y)
            return true;
        else
            return false;
    }
    if (x % 2 == 1&&y % 2 == 1)
    {//ÆæÊý
        if (x > y)
            return true;
        else
            return false;
    }
    if (x % 2 == 1&&y % 2 == 0)
        return true;
    return false;
}

int main()
{
    while(cin>>a[0])
    {
        for (int i = 1; i < 10; ++i)
            cin>>a[i];
        sort(a,a+10,cmp);
        for (int i = 0; i < 9; ++i)
            cout<<a[i]<<" ";
        cout<<a[9]<<endl;
    }
    return 0;
}
