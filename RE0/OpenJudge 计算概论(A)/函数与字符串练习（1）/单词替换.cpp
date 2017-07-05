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
    int k = 0;
    string s;
    while (cin>>s)
    {
        str[k] = s;
        k++;
    }
    for (int i = 0; i < k-2; ++i)
    {
        if (str[i] == str[k-2])
            str[i] = str[k-1];
    }
    for (int i = 0; i < k-3; ++i)
        cout<<str[i]<<" ";
    cout<<str[k-3]<<endl;
    return 0;
}
