#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<ctime>

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b,ans = 0;
    while(n--)
    {
        cin>>a>>b;
        if (a > b)
            ans++;
        if (a < b)
            ans--;
    }
    if (ans == 0)
        cout<<"Friendship is magic!^^"<<endl;
    if (ans > 0)
        cout<<"Mishka"<<endl;
    if (ans < 0)
        cout<<"Chris"<<endl;
    return 0;
}
