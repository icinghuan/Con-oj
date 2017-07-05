#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

//http://blog.csdn.net/ruoruo_cheng/article/details/52906428

char s[22], t[22];
bool f[22][22];

int main()
{
    scanf("%s %s", s+1, t+1);
    int m = strlen(s+1), n = strlen(t+1);
    f[0][0] = true;
    for (int i = 1; s[i] == '*'; ++i)
        f[i][0] = true;
    for (int i = 1; s[i]; ++i)
        for (int j = 1; t[j]; ++j) {
            if (s[i] == '?')
                f[i][j] = f[i-1][j-1];
            else if (s[i] == '*')
                f[i][j] = f[i-1][j] || f[i-1][j-1] || f[i][j-1];
            else
                f[i][j] = f[i-1][j-1] && (s[i] == t[j]);
        }
    puts(f[m][n] ? "matched" : "not matched");
    return 0;
}
