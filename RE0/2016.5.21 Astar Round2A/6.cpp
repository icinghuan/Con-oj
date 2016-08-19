#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 100000;
const int MAXM = 100000;

long long ans;
int f[MAXN+5],N,M,A,B;
struct AB
{
    int a;
    int b;
};
AB ab[MAXM+5];

int fa(int A)
{
	if (f[A] == A)
	{
		return A;
	}
	else
	{
		f[A] = fa(f[A]);
	}
}

bool comp(AB k1,AB k2)
{
    if (k1.a != k2.a)
        return k1.a < k2.a;
    else
        return k1.b < k2.b;
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>N>>M;
		for (int i = 1; i <= N; ++i)
			f[i] = i;
		for (int i = 1; i <= M; ++i)
		{
			scanf("%d%d",&ab[i].a,&ab[i].b);
		}
		sort(ab+1,ab+1+M,comp);
		for (int i = 1; i <= M; ++i)
		{
		    A = ab[i].a;
		    B = ab[i].b;
            if (fa(f[A]) < fa(f[B]))
				f[B] = f[A];
		}
		for (int i = 1; i <= N; ++i)
            f[i] = fa(f[i]);
		ans = 0;
		for (int i = 1; i <= N; ++i)
			ans += f[i];
		cout<<ans<<endl;
	}
	return 0;
}
