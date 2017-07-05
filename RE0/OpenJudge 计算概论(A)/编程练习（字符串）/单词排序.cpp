#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string str[105];

int main()
{
    string s;
    int k = 0;
    while (cin>>s)
    {
        bool flag = false;
        for (int i = 0; i < k; ++i)
            if (str[i] == s)
                flag = true;
        if (flag)
            continue;
        str[k] = s;
        k++;
    }
    sort(str,str+k);
    for (int i = 0; i < k; ++i)
        cout<<str[i]<<endl;
    return 0;
}
