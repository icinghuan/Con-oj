#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>b;--i)

using namespace std;

long long a[10005];
string s;

int main()
{
	while(cin>>s)
    {
	int n = 0, k = 0;
	bool flag = true;
	FOR(i,0,s.length())
	{
        if (s[i] == '5')
        {
            if (flag)
                continue;
            a[n] = k;
            k = 0;
            n++;
            //cout<<i<<endl;
            flag = true;
            continue;
        }
        if (s[i] != '5')
            flag = false;
	    if (s[i] == '0'&&flag)
            continue;
        k = k*10+s[i]-'0';
	}
    if (k != 0||n == 0)
    {
        a[n] = k;
        n++;
    }
	sort(a,a+n);
	FOR(i,0,n-1)
        cout<<a[i]<<' ';
    if (n != 0)
        cout<<a[n-1]<<endl;
    }
	return 0;
}
