#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m;
char c;
bool a[105][105];
bool f[105][105];
int num_one,num_zero,cnt;

const int dirx[4] = {-1,0,1,0};
const int diry[4] = {0,1,0,-1};

void dfs(int x,int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int tx = x+dirx[i];
        int ty = y+diry[i];
        if (!f[tx][ty])
        {
            if (a[tx][ty])
            {
                f[tx][ty] = true;
                cnt++;
                dfs(tx,ty);
            }
        }
    }
}

bool yes_dir[4];
bool flag;

void ddfs(int x,int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int tx = x+dirx[i];
        int ty = y+diry[i];
        if (tx == 0||tx == n+1||ty == 0||ty == m+1)
        {
            flag = false;
            continue;
        }
        /*if (a[tx][ty])
        {
            cout<<i<<endl;
            yes_dir[i] == true;
        }*/
        if (!f[tx][ty])
        {
            if (!a[tx][ty])
            {
                f[tx][ty] = true;
                ddfs(tx,ty);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        num_one = 0;
        int bx = -1;
        int by = -1;
        //num_zero = 0;
        for (int i = 1;i <= n;++i)
        {
            c = getchar();
            for (int j = 1;j <= m;++j)
            {
                c = getchar();
                if (c == '1')
                {
                    a[i][j] = true;
                    num_one++;
                    if (bx == -1)
                    {
                        bx = i;
                        by = j;
                    }
                }
                //else
                    //num_zero++;
            }
        }
        //cout<<num_one<<endl;
        //cout<<num_zero<<endl;
        if (bx == -1)
        {
            printf("-1\n");
            continue;
        }
        cnt = 1;
        f[bx][by] = true;
        dfs(bx,by);
        if (cnt != num_one)
        {
            printf("-1\n");
            continue;
        }
        int ans = 0;
        for (int i = 1;i <= n;++i)
        {
            for (int j = 1;j <= m;++j)
            {
                if (!f[i][j])
                {
                    //cout<<"find: "<<i<<" "<<j<<endl;
                    //memset(yes_dir,0,sizeof(yes_dir));
                    flag = true;
                    ddfs(i,j);
                    /*for (int e = 0; e < 4; ++e)
                        if (!yes_dir[e])
                        {
                            cout<<"e = "<<e<<endl;
                            flag = false;
                        }*/
                    if (flag)
                        ans++;
                }

            }
        }
        //cout<<ans<<endl;
        if (ans == 0)
            printf("1\n");
        if (ans == 1)
            printf("0\n");
        if (ans > 1)
            printf("-1\n");
    }
    return 0;
}
