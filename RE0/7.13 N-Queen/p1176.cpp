#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORR(i,a,b) for(int i=a;i>b;--i)

using namespace std;

const int MAX = 100005;
int f[MAX][12],a[MAX][12];

int main()
{
    int n;
    scanf("%d",&n);
    while (n != 0)
    {
        memset(a, 0, sizeof(a));
        memset(f,sizeof(f),0);
        int x, T, i, j, maxT = 0, ans = 0;
		while(n--){
			scanf("%d%d", &x, &T);
			++a[T][x];
			maxT = max(maxT, T);
		}
		f[1][4] = a[1][4];
		f[1][5] = a[1][5];
		f[1][6] = a[1][6];
		for(i = 2; i <= maxT; ++i){
			for(j = 0; j < 11; ++j){
				f[i][j] = f[i - 1][j];
				if(j > 0)
					f[i][j] = max(f[i][j], f[i - 1][j - 1]);
				if(j < 10)
					f[i][j] = max(f[i][j], f[i - 1][j + 1]);
				f[i][j] += a[i][j];
				//printf("%d ", f[i][j]);
			}
			//printf("\n");
		}
		for(i = 0; i < 11; ++i)
				ans = max(ans, f[maxT][i]);
		printf("%d\n", ans);
        scanf("%d",&n);
    }
    return 0;
}
