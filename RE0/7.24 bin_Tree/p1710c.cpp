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

void fin(int pa,int pb,int ia,int ib,int la,int lb)
{
	if(pa > pb||ia > ib||la > lb)
        return;
    int paa,pbb,iaa,ibb,laa,lbb;
    int pac,pbc,iac,ibc,lac,lbc;
    char ch = pre[pa];
    FOR(i,ia,ib)
    if (ch == in[i])
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
    post[lb] = ch;
    fin(paa,pbb,iaa,ibb,laa,lbb);
    fin(pac,pbc,iac,ibc,lac,lbc);
}

int main()
{
    //freopen("in.txt","r",stdin);
    while (scanf("%d",&n) != EOF)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        FOR(i,1,n)
            scanf("%d",&pre[i]);
        FOR(i,1,n)
            scanf("%d",&in[i]);
        fin(1,n,1,n,1,n);
        FOR(i,1,n-1)
            printf("%d ",post[i]);
        printf("%d\n",post[n]);
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
    //fclose(stdin);
    return 0;
}

/*
var s1,s2:string;
procedure cre(s1,s2:string);
var s3,s4:string;
    po:integer;
begin
  s3:=s1;
  s4:=s2;
  write(s4[length(s4)]);
  po:=pos(s4[length(s4)],s3);
  s3:=copy(s3,1,po-1);
  s4:=copy(s4,1,length(s3));
  if length(s3)>0 then cre(s3,s4);
  s3:=copy(s1,po+1,length(s1)-po);
  s4:=copy(s2,pos(s4[length(s4)],s2)+1,length(s3));
  if length(s3)>0 then cre(s3,s4);
end;
begin
  readln(s1);
  readln(s2);
  cre(s1,s2);
end.


#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn=1002;
int n,s1[maxn],s2[maxn];

void print(int l1,int r1,int l2,int r2)
{
    int m;
    for(m=0;;m++)
        if(s1[l1]==s2[m])
            break;
    if(m>l2) print(l1+1,l1+m-l2,l2,m-1);
    if(m<r2) print(l1+m-l2+1,r1,m+1,r2);
    printf("%d",s1[l1]);
    if(s1[l1]==s1[0]) printf("\n");
    else printf(" ");
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&s1[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&s2[i]);
        print(0,n-1,0,n-1);
    }
    return 0;
}



#include <iostream>
using namespace std;
const int N=1005;
int pre[N],in[N],post[N];
int n;
void getpost(int pa,int pb,int ia,int ib,int la,int lb)
{
	if(pa>pb||ia>ib||la>lb) return;
	int a,b,i;
	for (i=ia;i<=ib;i++)
	{
		if (in[i]==pre[pa])
		{
			break;
		}
	}
	a=i-ia;b=ib-i;
	post[lb]=in[i];
	getpost(pa+1,pa+a,ia,i-1,la,la+a-1);
	getpost(pb-b+1,pb,i+1,ib,lb-b,lb-1);
}
int main()
{
	while(~scanf("%d",&n))
	{
		for (int i=1;i<=n;i++)
			scanf("%d",&pre[i]);
		for (int i=1;i<=n;i++)
			scanf("%d",&in[i]);
		getpost(1,n,1,n,1,n);
		for (int i=1;i<n;i++)
			printf("%d ",post[i]);
		printf("%d\n",post[n]);
	}
	return 0;
}
*/
