#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    char c;
    int a,b;
    cin>>c;
    a = int(c-'0')*10;
    cin>>c;
    a += int(c-'0');
    cin>>c;
    char op = c;
    cin>>c;
    b = int(c-'0')*10;
    cin>>c;
    b += int(c-'0');
    int ans;
    switch (op)
    {
        case '+':
            ans = a+b;
            break;
        case '-':
            ans = a-b;
            break;
        case '*':
            ans = a*b;
            break;
        case '/':
            ans = a/b;
            break;
        case '%':
            ans = a%b;
            break;
    }
    cout<<ans<<endl;
    return 0;
}
