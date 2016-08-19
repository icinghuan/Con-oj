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

const int N = 100000 + 5;
int n,a[N],d[N],dd[N];
long long ans;

int main()
{
    freopen("1002.txt","w",stdout);
    int T = 1;
    srand(time(0));
    cout<<T<<endl;
    while(T--)
    {
        n = 100000;
        cout<<n<<endl;
        FOR(i,1,n)
            cout<<rand()%10000+1<<' ';
        cout<<endl;

    }
    fclose(stdout);
    return 0;
}
