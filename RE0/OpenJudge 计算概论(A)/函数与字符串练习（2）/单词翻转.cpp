#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

char ss[505];

int main()
{
    string s;
    getline(cin,s);
    int k = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
        {
            ss[k] = s[i];
            k++;
        }
        else
        {
            for (int i = k-1; i >= 0; --i)
                cout<<ss[i];
            k = 0;
            cout<<" ";
        }
    }
    if (k != 0)
    {
        for (int i = k-1; i >= 0; --i)
            cout<<ss [i];
    }
    return 0;
}
