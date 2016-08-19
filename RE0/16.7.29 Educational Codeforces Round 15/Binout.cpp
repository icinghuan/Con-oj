#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<ctime>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int a[100005],n,kk[31];

int main()
{
    freopen("Bin.txt","w",stdout);
    srand(time(0));
    n = 100000;
    cout<<n<<endl;
    FOR(i,1,n)
        cout<<1<<' ';
    fclose(stdout);
}
