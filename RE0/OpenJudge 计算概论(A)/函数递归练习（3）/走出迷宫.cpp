#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,m,ans,vis[1000][1000];
char mat[1000][1000],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  ;

struct Point{
    int x,y,k;
};

int Bfs(Point a,Point b) {
    queue<Point> q;
    q.push(a);
    vis[a.x][a.y]=1;
    Point top,next;
    //printf("%d %d\n%d %d\n",a.x,a.y,b.x,b.y);
    while(!q.empty()) {
        top=q.front();q.pop();
        for(int i=0;i<4;i++){
            next.x=top.x+dir[i][0];
            next.y=top.y+dir[i][1];
            next.k=top.k+1;
            //printf("%d %d %c\n",next.x,next.y,mat[next.x][next.y]);
            if(next.x==b.x&&next.y==b.y){
                printf("%d",next.k);
                return 0;
            }
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&vis[next.x][next.y]==0&&mat[next.x][next.y]=='.'){
                q.push(next);
                vis[next.x][next.y]=1;
            }
        }
    }
}

int main() {
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    Point s,t;
    for(int i=0;i<n;i++) {
        scanf("%s",mat[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if(mat[i][j]=='S') {
                s.x=i;
                s.y=j;
                s.k=0;

            }
            if(mat[i][j]=='T') {
                t.x=i;
                t.y=j;
            }
        }
    }
    Bfs(s,t);
    //printf("%d",ans);
    return 0;
}

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

char a[105][105];
int n,m;
int ans[1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int fx[1005],fy[1005];

int bfs()
{
    int x,y;
    int l =0,r = 0;
    while (l <= r)
    {

    x = fx[l];
    y = fy[l];
    for (int i = 0; i < 4; ++i)
    {
        if (a[x+dx[i]][y+dy[i]] == 'T')
        {
            return ans[l]+1;
        }
        if (a[x+dx[i]][y+dy[i]] == '.')
        {
            r++;
            fx[r] = x+dx[i];
            fy[r] = y+dy[i];
            ans[r] = ans[l]+1;
        }
    }
    l++;

    }
}

int main()
{
    cin>>n>>m;
    int sn,sm;
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= m+1; ++j)
            a[i][j] = '#';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin>>a[i][j];
            if (a[i][j] == 'S')
            {
                sn = i;
                sm = j;
            }
        }
    fx[0] = sn;
    fy[0] = sm;
    cout<<bfs()<<endl;
    return 0;
}*/

/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

char a[105][105];
int n,m;
int ans = 0;
int aans[105];
int coun = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int f[105][105];

void dfs(int x,int y)
{
    for (int i = 0; i < 4; ++i)
    {
        if (a[x+dx[i]][y+dy[i]] == 'T')
        {
            aans[coun] = ans+1;
            coun++;
            return;
        }
        if (a[x+dx[i]][y+dy[i]] == '.'&&f[x+dx[i]][y+dy[i]] == 0)
        {
            ans++;
            f[x+dx[i]][y+dy[i]] = 1;
            dfs(x+dx[i],y+dy[i]);
            f[x+dx[i]][y+dy[i]] = 0;
            ans--;
        }
    }
}

int main()
{
    cin>>n>>m;
    int sn,sm;
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= m+1; ++j)
            a[i][j] = '#';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin>>a[i][j];
            if (a[i][j] == 'S')
            {
                sn = i;
                sm = j;
            }
        }
    f[sn][sm] = 1;
    dfs(sn,sm);
    int mi = 1000;
    for (int i = 0; i < coun; ++i)
        if (aans[i] < mi)
            mi = aans[i];
    cout<<mi<<endl;
    return 0;
}
*/
