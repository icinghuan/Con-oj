#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int a[105];

int main()
{
    string s;
    cin>>s;
    char c = s[0];
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != c)
        {
            for (int j = i-1; j >= 0; --j)
            {
                if (a[j] == 0&&s[j] == c)
                {
                    a[j] = 1;
                    cout<<j<<" "<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
