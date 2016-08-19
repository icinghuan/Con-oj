#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int MAXN = 2000 + 5;

int Tree[MAXN<<4],num[MAXN];
int Tot,n;

void build(int p=1,int L=1,int R=Tot){
    if(L==R){Tree[p]=num[L];return;}
    int mid=(L+R)>>1;
    build(p<<1,L,mid);
    build(p<<1+1,mid+1,R);
}

void update(int x,int p=1,int L=1,int R=Tot){
    if(L<=p<<1&&R>>p<<+1){Tree[p]=x;return;}
    int mid=(p<<2+1)>>1;
    if (L<mid)
        update(n,p<<1,L,R);
    if (R>mid)
        update(n,p<<1+1,L,R);

}

int main()
{
    while (~scanf("%d",&Tot))
    {
        memset(num,0,sizeof(num));
        memset(Tree,0,sizeof(Tree));
        //build();
        int a,b,k;
        char c;
        FOR(i,1,Tot)
        {
            scanf("%d %d %c",&a,&b,&c);
            if (c == 'w')
                k = 1;
            else
                k = 0;
            update(k,a,b);
        }

    }
    return 0;
}
