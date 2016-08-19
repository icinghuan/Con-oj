#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

class bin_Tree
{
public:
	int n;
	int a[1000];
	int l_son(int i) { return 2*i; }
	int r_son(int i) { return 2*i+1; }
	int root(int i) { if (i == 1) return 0 else return i/2; }
	void in();
private:

};

void bin_Tree::in()
{
	cin>>n;
	FOR(i,1,n);
}

int main()
{
	bin_Tree t;
	
	return 0;
}