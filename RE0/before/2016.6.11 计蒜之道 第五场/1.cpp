#include<iostream>
#include<cstdio>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

double ans,l,th,ll;
double n,k;
const double PI = 3.141592653589793238;

int main()
{
	cin>>n>>k;
	cin>>l;
	th = ((n-2.0)*180.0)/n;
	th = th*PI/180.0;
	ans = 0;
	FOR(i,0,k)
	{
	    ll = l;
		ans += (n-1.0/2.0)*l;
		l = sqrt((l/2.0)*(l/2.0)+(l/2.0)*(l/2.0)-2*(l/2.0)*(l/2.0)*cos(th));
	}
	ans -= ll/2.0;
	printf("%f",ans);
	return 0;
}
