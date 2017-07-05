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
    int T;
    cin>>T;
    while (T--)
    {
        int k,row,col;
        cin>>row>>col;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
            {
                cin>>k;
                *(*(a+i)+j) = k;
            }
        int ans = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (i==0||i==row-1||j==0||j==col-1)
                    ans += *(*(a+i)+j);
        cout<<ans<<endl;
    }
    return 0;
}
