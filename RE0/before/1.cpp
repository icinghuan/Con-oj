#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

string IntToString(int k)
{
	string s = "";
	char c[10];
	int l = 0,r = 0;
	if (k == 0)
        return "0";
	while (k != 0)
	{
		l = k%10;
		c[r] = l+'0';
		r++;
		k = k/10;
	}
	r--;
	for (int i = r; i >= 0; --i)
		s = s+c[i];
    return s;
}

string address(string ip,string mask)
{
	string s = "";
	int k1[5],k2[5];
	int r = 0;
	memset(k1,0,sizeof(k1));
	memset(k2,0,sizeof(k2));
	for (int i = 0; i < ip.length(); ++i)
		if (ip[i] == '.')
			r++;
        else
            k1[r] = k1[r]*10+ip[i]-'0';
	r = 0;
	for (int i = 0; i < mask.length(); ++i)
		if (mask[i] == '.')
			r++;
        else
            k2[r] = k2[r]*10+mask[i]-'0';
	int k[5];
	for (int i = 0; i < 4; ++i)
		k[i] = k1[i]&k2[i];
	for (int i = 0; i < 3; ++i)
		s = s+IntToString(k[i])+'.';
    s = s+IntToString(k[3]);
    return s;
}

string ip[1005],mask[55];
string addr[1005];

void solve()
{
    int T;
	int n,m,ans,r;
	string addrA;
	bool flag;
	cin>>T;
	int cas = 1;
	while (T--)
	{
	    printf("Case #%d:\n",cas++);
        cin>>n>>m;
		for (int i = 0; i < n; ++i)
			cin>>ip[i];
		for (int i = 0; i < m; ++i)
			cin>>mask[i];
        for (int j = 0; j < m; ++j)
        {
            ans = 0;
            r = 0;
            for (int i = 0; i < n; ++i)
            {
                addrA = address(ip[i],mask[j]);
                flag = false;
                for (int k = 0; k < r; ++k)
                    if (addr[k] == addrA)
                    {
                        flag = true;
                        break;
                    }
                if (flag)
                    continue;
                addr[r] = addrA;
                r++;
                ans++;
            }
            printf("%d\n",ans);
        }
	}
}
int main()
{
	solve();
	return 0;
}
