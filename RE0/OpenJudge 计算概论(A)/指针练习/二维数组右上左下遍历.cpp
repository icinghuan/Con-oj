#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[100][100];

int main()
{
    int row,col;
    cin>>row>>col;
    int k;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
        {
            cin>>k;
            *(*(a+i)+j) = k;
        }
    for (int i = 0; i < col; ++i)
    {
        int j = i;
        int k = 0;
        while (j >= 0&&k < row)
        {
            cout<<*(*(a+k)+j)<<endl;
            k++;
            j--;
        }
    }
    for (int i = 1; i < row; ++i)
    {
        int j = col-1;
        int k = i;
        while (j >= 0&&k < row)
        {
            cout<<*(*(a+k)+j)<<endl;
            k++;
            j--;
        }
    }
    return 0;
}
