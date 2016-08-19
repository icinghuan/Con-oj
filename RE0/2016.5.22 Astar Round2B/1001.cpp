#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define LL long long

using namespace std;

const int MAXN = 100005;

int pos[MAXN],fip[MAXN],dep,Tot;
vector<int> E[MAXN];
int Max[MAXN<<2],num[MAXN];
void build(int p=1,int L=1,int R=Tot){
    if(L==R){Max[p]=num[L];return;}
    int mid=(L+R)>>1,lp=p<<1,rp=lp+1;
    build(lp,L,mid);build(rp,mid+1,R);
    Max[p]=max(Max[lp],Max[rp]);
}
void update(int x,int n,int p=1,int L=1,int R=Tot){
    if(L==R){Max[p]=n;return;}
    int mid=(L+R)>>1,lp=p<<1,rp=lp+1;
    if(x<=mid)update(x,n,lp,L,mid);
    else update(x,n,rp,mid+1,R);
    Max[p]=max(Max[lp],Max[rp]);
}
int query(int l,int r,int p=1,int L=1,int R=Tot){
    if(l==L&&r==R)return Max[p];
    int mid=(L+R)>>1,lp=p<<1,rp=lp+1;;
    if(r<=mid)return query(l,r,lp,L,mid);
    else if(l>mid) return query(l,r,rp,mid+1,R);
    else return max(query(l,mid,lp,L,mid),query(mid+1,r,rp,mid+1,R));
}
void dfs(int u){
    fip[++dep]=u;
    num[pos[u]=++Tot]=-dep;
    for(int i=E[u].size()-1;~i;--i){
        dfs(E[u][i]);
        num[++Tot]=num[pos[u]];
    }
}
void init(int r){
    dep=Tot=0;
    dfs(r);
    build();
}
int LCA(int u,int v){
    int l=pos[u],r=pos[v];
    if(l>r)swap(l,r);
    return fip[-query(l,r)];
}

int a[MAXN];
int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
        }

    }
    return 0;
}
