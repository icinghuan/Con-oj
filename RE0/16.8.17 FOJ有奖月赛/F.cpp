#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)
#define mp(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define CLR(x,k) memset(x,k,sizeof(x))
#define CPY(s,t) memcpy(s,t,sizeof(s))
#define max3(x,y,z) max(max(x,y),z)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
template<typename X>
inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}


using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5;
int E[MAXN][MAXN];
bool S[MAXN]= {};
int dis[MAXN];

int Dijkstra(int src,int des,int N){
    CPY(dis,E[src]);S[src]=1;dis[src]=0;
    for(int i=1,v; i<N; ++i){
        int Min=INF;
        for(int j=1; j<=N; ++j)
            if(!S[j]&&minimize(Min,dis[j]))v=j;
        if(v==des)return dis[v];
        S[v]=1;
        for(int j=1; j<=N; ++j)
            if(!S[j]) minimize(dis[j],dis[v]+E[v][j]);
    }
    return INF;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int s,x1,y1,x2,y2,x,y,z;
        scanf("%d%d%d%d%d",&s,&x1,&y1,&x2,&y2);
        CLR(E,INF);
        FOR(i,1,m)
        {
            scanf("%d%d%d",&x,&y,&z);
            E[x][y] = z;
            E[y][x] = z;
        }
        int k1 = Dijkstra(s,x1,n);
        int k2 = Dijkstra(s,x2,n);
        int k3 = Dijkstra(x1,x2,n);
        int k4 = Dijkstra(y1,y2,n);
        int e1 = Dijkstra(y1,x2,n);
        int e2 = Dijkstra(y2,x1,n);
        int m1 = Dijkstra(x1,y1,n);
        int m2 = Dijkstra(x2,y2,n);
        int a1 = min(k1+m1+e1+m2,k2+m2+e2+m1);
        int a2 = min(k1+k3+m1+k4,k1+k3+m2+k4);
        cout<<min(a1,a2)<<endl;
    }
    return 0;
}
