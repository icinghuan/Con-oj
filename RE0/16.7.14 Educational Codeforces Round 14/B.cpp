#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

void solve()
{
    int L = int('a');
    int K = int('A');
    int f[155][155];
    memset(f,sizeof(f),0);
    f[K][K] = 1;
    f[int('H')][int('H')] = 1;
    f[int('I')][int('I')] = 1;
    f[int('M')][int('M')] = 1;
    f[int('O')][int('O')] = 1;
    f[int('T')][int('T')] = 1;
    f[int('U')][int('U')] = 1;
    f[int('V')][int('V')] = 1;
    f[int('W')][int('W')] = 1;
    f[int('X')][int('X')] = 1;
    f[int('Y')][int('Y')] = 1;
    f[int('o')][int('o')] = 1;
    f[int('v')][int('v')] = 1;
    f[int('w')][int('w')] = 1;
    f[int('x')][int('x')] = 1;
    //f[int('i')][int('i')] = 1;
    //f[int('l')][int('l')] = 1;
    //f[int('m')][int('m')] = 1;
    //f[int('n')][int('n')] = 1;

    f[L+1][L+3] = 1;f[L+3][L+1] = 1;
    f[L+15][L+16] = 1;f[L+16][L+15] = 1;
    string s;
    cin>>s;
    int l = s.length();
    if (l%2 == 0)
    {
        FOR(i,0,l-1)
            if (!f[int(s[i])][int(s[l-i-1])])
            {
                cout<<"NIE"<<endl;
                return;
            }
        cout<<"TAK"<<endl;
        return;
    }
    FOR(i,0,l-1)
        if (!f[int(s[i])][int(s[l-i-1])])
        {
            cout<<"NIE"<<endl;
            return;
        }
    if (!f[int(s[l/2])][int(s[l/2])])
    {
        cout<<"NIE"<<endl;
        return;
    }
    cout<<"TAK"<<endl;
}
int main()
{
    solve();
    return 0;
}
