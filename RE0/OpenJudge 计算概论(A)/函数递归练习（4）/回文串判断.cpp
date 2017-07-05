#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

string s;

bool isPalindrome(int a,int b)
{
    if (a == b||a > b)
        return true;
    if (s[a] == s[b])
        return isPalindrome(a+1,b-1);
    else
        return false;
}

int main()
{
    cin>>s;
    if (isPalindrome(0,s.length()-1))
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
