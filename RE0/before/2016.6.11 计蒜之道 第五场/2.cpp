#include<iostream>
#include<cstdio>
#include<cmath>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n,m,q;
int att[1005][1005];
int x,a,y,b;
int ans;

int kk(int i)
{
    if (att[i][0] == 0)
        return 1000000;
	int tmp = 1,tmpp = 1;
	bool f = false;
	while (!f)
	{
		f = true;
		tmp = tmpp;
		FOR(j,1,att[i][0])
			if (att[i][j] > tmp)
				f = false;
			else
				tmp++;
		tmpp++;
	}
	return tmpp-1;
}
//第i条队列的最小初始防御点数

void solve()
{
    FOR(i,1,n)
        if (kk(i) != 1000000)
            ans = kk(i);
	int tmp = 0;
	FOR(i,1,n)
	{
		tmp = kk(i);
		if (tmp < ans&&tmp+att[i][0] > ans)
			ans = tmp;
	}
}

int main()
{
	scanf("%d",&n);
	FOR(i,1,n)
	{
		scanf("%d",&m);
		att[i][0] = m;
		FOR(j,1,m)
			scanf("%d",&att[i][j]);
	}
	scanf("%d",&q);
	FOR(k,1,q)
	{
		scanf("%d%d%d%d",&x,&a,&y,&b);
		int btt[1005],ctt[1005],mm = att[y][0];
		FOR(i,1,mm)
            btt[i] = att[y][i];
		FOR(i,1,a)
            att[y][i] = att[x][i];
        att[y][0] = mm-b+a;
        FOR(i,a+1,att[y][0])
            att[y][i] = btt[i-a+b];
        mm = att[x][0];
        FOR(i,1,mm)
            ctt[i] = att[x][i];
		FOR(i,1,b)
            att[x][i] = btt[i];
        att[x][0] = mm-a+b;
        FOR(i,b+1,att[y][0])
            att[x][i] = ctt[i-b+a];

        FOR(i,1,n)
        {
            FOR(j,1,att[i][0])
                cout<<att[i][j]<<' ';
            cout<<endl;
        }

		solve();
		printf("%d\n",ans);
	}
	return 0;
}
