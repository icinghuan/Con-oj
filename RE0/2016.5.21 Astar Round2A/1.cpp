#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    long long kk = 1;
    int rr = 0;
    for (int i = 1; i <= 24; ++i)
    {
        rr = kk%23;
        cout<<rr<<endl;
        kk = kk*10+1-*23;
    }
	int x,m,k,c;
	int T;
	cin>>T;
	int cas = 1;
	while (T--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d%d%d%d",&x,&m,&k,&c);

	}
	return 0;
}
