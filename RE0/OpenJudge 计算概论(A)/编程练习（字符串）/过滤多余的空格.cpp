#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    //cin读入字符串无视空格和回车（空格和回车作为分隔符）
    //和上一题同理，借用cin的特性这道题很容易
    string s;
    while (cin>>s)
    {
        cout<<s<<" ";
    }
    return 0;
}
