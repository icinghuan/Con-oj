#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const long long mod = (long long)1<<32;
long long ans,tmp,tmpp;
long long n,m;

int main()
{
	cin>>n>>m;
	ans = m;
	if (n>=2)
    {
        tmp = (m*(m-1))%mod;
		ans = (ans+tmp)%mod;
    }
	FOR(i,3,n)
	{
		if (i%2 == 1)
        {
            tmpp = tmp;
            tmp = tmp*m%mod;
			ans = (ans+tmp)%mod;
        }
		else
        {
			tmp = tmpp*(m-1)%mod;
			tmp = tmp*(m+1)%mod;
			ans = (ans+tmp)%mod;
        }
	}
	cout<<ans<<endl;
	return 0;
}
