#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string str[100];

int main()
{
    string s;
    int k = 0;
    while (cin>>s)//cin读入字符串无视空格和回车（空格和回车作为分隔符）
        //借用cin的特性这道题很容易
    {
        str[k] = s;
        k++;
    }
    for (int i = k-1; i >= 0; --i)
        cout<<str[i]<<" ";
    return 0;
}
