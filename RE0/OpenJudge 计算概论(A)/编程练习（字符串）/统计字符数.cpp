#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int f[128];

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;//cin读入字符串无视空格和回车（空格和回车作为分隔符）
        for (int i = int('a'); i <= int('z'); ++i)
            f[i] = 0;
        for (int i = 0; i < s.length(); ++i)
            f[int(s[i])]++;
        int ma = 0;
        char c;
        for (int i = int('a'); i <= int('z'); ++i)
            if (ma < f[i])
            {
                c = char(i);
                ma = f[i];
            }
        cout<<c<<" "<<ma<<endl;
    }
    return 0;
}
