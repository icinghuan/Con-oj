#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n;
int pre[1005],in[1005],post[1005];
int l[1005],r[1005];

void preorder(int k)
{
    cout<<' '<<k;
    if (l[k] != 0) preorder(l[k]);
    if (r[k] != 0) preorder(r[k]);
}

void inorder(int k)
{
    if (l[k] != 0) inorder(l[k]);
    cout<<' '<<k;
    if (r[k] != 0) inorder(r[k]);
}

void postorder(int k)
{
    if (l[k] != 0) postorder(l[k]);
    if (r[k] != 0) postorder(r[k]);
    cout<<' '<<k;
}

int fin(int k)
{
    l[k] = fin(
}

int main()
{

    while (scanf("%d",&n) != EOF)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        FOR(i,1,n)
            scanf("%d%d",&pre[i],&in[i]);
        fin(pre[1]);
        /*
        int k1,k2,k3;
        FOR(i,1,n)
        {
            scanf("%d%d%d",&k1,&k2,&k3);
            l[k1] = k2;
            r[k1] = k3;
        }

        cout<<"preorder :";
        preorder(1);
        cout<<endl;
        cout<<"inorder :";
        inorder(1);
        cout<<endl;
        cout<<"postorder :";
        postorder(1);
        cout<<endl;
        */
    }
    return 0;
}
