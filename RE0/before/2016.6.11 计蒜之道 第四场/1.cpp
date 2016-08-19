#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n ;
int a[10005];
long long ans;

int main()
{
	scanf("%d",&n);
	FOR(i,1,n)
		scanf("%d",&a[i]);
	ans = 0;
	for (int i = 1; i <= n; i +=2)
			ans += a[i];
	if (a[n-1] < a[n]&&n%2 == 0)
		ans = ans-a[n-1]+a[n];
	printf("%lld\n",ans);
	return 0;
}
