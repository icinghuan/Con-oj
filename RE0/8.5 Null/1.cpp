//闲来无聊，写个小程序

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

using namespace std;

long long t = 0, k = 123456;
int n;

long long mm()
{
    char c[100];
    FOR(i,1,n)
        c[i] = rand()%10+'0';
    long long m = 0;
    FORR(i,n,1)
        m = m*10+c[i]-'0';
    return m;
}

void game()
{
    //cin>>k;

    //cout<<m<<endl;
    if (mm() == k)
    {
        //cout<<"---------------"<<t<<endl;
        if (t < 100)
            cout<<"---------------"<<t<<endl;
        t = 0;
        k = mm();
        cin.get();
    }
}

int main()
{
    srand(time(0));
    k = mm();
    n = 6;
    while (1)
    {
        t++;
        game();
    }
    return 0;
}
