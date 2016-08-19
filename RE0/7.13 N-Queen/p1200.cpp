#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int main()
{
    char c[205][205];
    string s;
    int n;
    while (scanf("%d",&n) != EOF&&n != 0)
    {
        int k = 0;
        cin>>s;
        FOR(i,0,s.length()-1)
        {
            k = i/n+1;
            if (k%2 == 1)
                c[k][i%n+1] = s[i];
            else
                c[k][n-i%n] = s[i];
        }
        FOR(j,1,n)
            FOR(i,1,k)
                printf("%c",c[i][j]);
        cout<<endl;
    }
    return 0;
}
