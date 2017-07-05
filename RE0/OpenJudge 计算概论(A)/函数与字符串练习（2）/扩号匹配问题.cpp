#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int f[105];

int main()
{
    string s;
    while (cin>>s)
    {
        for (int i = 0; i < s.length(); ++i)
            f[i] = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ')')
            {
                for (int j = i-1; j >= 0; --j)
                {
                    if (f[j] == 0&&s[j] == '(')
                    {
                        f[j] = 1;
                        f[i] = 1;
                        break;
                    }
                }
            }
        }
        cout<<s<<endl;
        for (int i = 0; i < s.length(); ++i)
        {
            if (f[i] == 0)
            {
                if (s[i] == '(')
                    cout<<"$";
                else
                    if (s[i] == ')')
                        cout<<"?";
                    else
                        cout<<" ";
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
