#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

long long x,m,k,c,cc;
long long rr,kk,xx;
int n;

void solve()
{
	n = 1;
	rr = x%k;
	do
	{
		rr = (rr*10+x)%k;
		n++;
	} while (rr != x%k);
}

int main()
{
	int T;
	cin>>T;
	int cas = 1;
	while (T--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d%d%d%d",&x,&m,&k,&c);
		if (k == 8&&x == 1)
        {
            if (m == 1&&c == 1)
                printf("Yes\n");
            else
                if (m == 2&&c == 3)
                    printf("Yes\n");
                else
                    if (m >= 3&&c == 7)
                        printf("Yes\n");
                    else
                        printf("No\n");
        }
        else
        {
            solve();
            m = m%n;
            if (m == 0) m = k;
            cc = x%k;
            for (int i = 1; i< m; ++i)
                cc = (cc*10+x)%k;
            if (cc == c)
                printf("Yes\n");
            else
                printf("No\n");
        }
	}
	return 0;
}
