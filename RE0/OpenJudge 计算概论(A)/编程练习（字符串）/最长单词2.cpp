#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    int ma = 0;
    string ms;
    while (cin>>s)
    {
        if (s[s.length()-1] == '.')
            s = s.substr(0,s.length()-1);
        if (s.length() > ma)
        {
            ma = s.length();
            ms = s;
        }
    }
    cout<<ms<<endl;
    return 0;
}
