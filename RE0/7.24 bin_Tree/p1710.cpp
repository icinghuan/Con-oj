#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORR(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

int n;
int pre[1005],in[1005],post[1005];

void fin(int pa,int pb,int ia,int ib,int la,int lb)
{
	if(pa > pb||ia > ib||la > lb)
        return;
    int paa,pbb,iaa,ibb,laa,lbb;
    int pac,pbc,iac,ibc,lac,lbc;
    for (int i = ia; i <= ib; ++i)
    if (pre[pa] == in[i])
    {
        paa = pa+1;
        pbb = pa+i-ia;
        iaa = ia;
        ibb = i-1;
        laa = la;
        lbb = la+i-ia-1;

        pac = pb-ib+i+1;
        pbc = pb;
        iac = i+1;
        ibc = ib;
        lac = lb-ib+i;
        lbc = lb-1;
        break;
    }

    post[lb] = pre[pa];
    fin(paa,pbb,iaa,ibb,laa,lbb);
    fin(pac,pbc,iac,ibc,lac,lbc);
    //fin(pa+1,pa+a,ia,i-1,la,la+a-1);
    //fin(pb-b+1,pb,i+1,ib,lb-b,lb-1);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        FOR(i,1,n)
            scanf("%d",&pre[i]);
        FOR(i,1,n)
            scanf("%d",&in[i]);
        fin(1,n,1,n,1,n);
        FOR(i,1,n-1)
            printf("%d ",post[i]);
        printf("%d\n",post[n]);
    }
    return 0;
}
