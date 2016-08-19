#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>b;--i)

using namespace std;

long long a[100005],f[100005];

int main()
{
    int T, cas = 1, n;
    cin>>T;
    while (T--)
    {
        cout<<"Case "<<cas++<<":"<<endl;
        memset(f,sizeof(f),0);
        cin>>n;
        FOR(i,0,n)
            cin>>a[i];
        f[0] = a[0];
        long long Max = a[0];
        int j = 0, ii = 0;
        int first = 0, second = 0;
        FOR(i,1,n)
        {
            if (f[i-1] > 0)
            {
                f[i] =  f[i-1]+a[i];
                j = i;
            }
            else
            {
                f[i] = a[i];
                ii = i;
                j = i;
            }
            if (Max < f[i])
			{
				Max = f[i];
				first = ii;
                second = j;
			}
        }
        cout<<Max<<' '<<first+1<<' '<<second+1<<endl;
        if (T)
            cout<<endl;
    }
    return 0;
}
