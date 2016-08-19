#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

char c[105];
int l = 0;
bool flag = false;
int e = 0;
int k = 0;

void del(int k)
{
	FOR(i,k,l-1)
		c[i] = c[i+1];
	l--;
}

void add(int k)
{
	FORR(i,l+1,k+1)
		c[i] = c[i-1];
	c[k] = '0';
	l++;
}

void kk1()
{
	FOR(i,1,l)
		if (c[i] == 'e')
			e = i;
	k = e-1;
	while (c[k] == '0')
	{
		del(k);
		k--;
	}
	if (c[k] == '.')
		del(k);
}

void kk2()
{
	FOR(i,1,l)
		if (c[i] == 'e')
			e = i;
	k = e+1;
	if (c[k] == '-')
		k++;
	while ((k < l)&&(c[k] == '0'||c[k] == '+'))
		del(k);
}

void in()
{
    l = 0;
    char ch;
	while (scanf("%c",&ch) != EOF)
	{
		l++;
		c[l] = ch;
	}
}

void solve()
{
	k = 1;
	if (c[k] == '-')
		k = 2;
	while (c[k] == '0'||c[k] == '+')
		del(k);
	if (c[k] == '.'||c[k] == 'e')
		add(k);
	//0001   000e  000.

	FOR(i,1,l)
		if (c[i] == '.')
			flag = true;
	if (flag)
		kk1();
	//1.0000e   0.100e

	kk2();
	//1e003 1e-05

	FOR(i,1,l)
		printf("%c",c[i]);
	printf("\n");
}

int main()
{
    freopen("1.txt","r",stdin);
	in();
	solve();
	fclose(stdin);
	return 0;
}
