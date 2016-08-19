#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int N = 8;
int n;
bool fl[20];
int ans[20];
int k = 0;
bool flag;

void dfs()
{
	if (n == N)
	{
	    k++;
	    cout<<"Case #"<<k<<":"<<endl;
		FOR(i,1,N)
		{
			FOR(j,1,N)
			{
				if (j == ans[i])
					cout<<'#';
				else
					cout<<'0';
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	FOR(i,1,N)
	{
		if (!fl[i])
		{
		    flag = false;
			FOR(j,1,n)
				if (i-ans[j] == n-j+1||ans[j]-i == n-j+1)
					flag = true;
            if (flag)
                continue;
			n++;
			fl[i] = true;
			ans[n] = i;
			dfs();
			ans[n] = 0;
			fl[i] = false;
			n--;
		}
	}
}

int main()
{
	n = 0;
	FOR(i,1,N)
	{
		fl[i] = false;
		ans[i] = 0;
	}
	dfs();
	cout<<"The number of N-Queen is : "<<k<<endl;
    return 0;
}
