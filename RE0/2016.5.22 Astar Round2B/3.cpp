#include<iostream>
#include<algorithm>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=8005;
int srted[N];
struct node
{
    int num[N];
    int val[N];
}t[40];
int n,m;
void build(int l,int r,int d)//建树  此树并非由节点构成 而是由数组的一段构成  如：d层的l~r是一个节点
{
    if(l==r) return;
    int mid=(l+r)>>1;//取中间那个
    int midd=srted[mid];
    int same=mid-l+1,samed=0,zn=l-1,yn=mid,i;//same初识化为左孩子元素个数
    //下面减去比midd小的(一定会进入左孩子里边)  剩下的就是==midd并且要进入左孩子的个数
    //samed是已经插入的数目
    //zn、yn是左右孩子的开始位置-1，下面会把元素分到两个孩子的区域里边
    for(i=l;i<=r;++i)
        if(t[d].val[i]<midd) --same;
    for(i=l;i<=r;++i)//有点像快排  大的放到后边  小的放前边    相等的看情况
    {
        if(i==l) t[d].num[i]=0;
        else t[d].num[i]=t[d].num[i-1];
        if(t[d].val[i]<midd)
        {
            ++t[d].num[i];//这里是统计从l到i有多少元素进入了左孩子     这是划分树主要用到的数据
            t[d+1].val[++zn]=t[d].val[i];
        }else if(t[d].val[i]>midd)//进入右孩子
        {
            t[d+1].val[++yn]=t[d].val[i];
        }else
        {
            if(samed<same)//名额还没有用完  放左孩子里边
            {
                ++samed;
                ++t[d].num[i];
                t[d+1].val[++zn]=t[d].val[i];
            }else//方有孩子里边
                t[d+1].val[++yn]=t[d].val[i];
        }
    }
    build(l,mid,d+1);//建左右子树
    build(mid+1,r,d+1);
}
int query(int a,int b,int k,int l,int r,int d)//在d层[l,r]的节点里查找[a,b]中的第k大值
{
    if(a==b) return t[d].val[a];
    int mid=(l+r)>>1;
    int sx=t[d].num[a-1],sy=t[d].num[b];
    if(a-1<l) sx=0;
    if(sy-sx>=k)//[a,b]进入左子树的元素>=k
        return query(l+sx,l+sy-1,k,l,mid,d+1);
    else
    {
        int s1=(a==1?0:a-l-sx);
        int s2=(b-a+1)-(sy-sx);
        int nk=k-(sy-sx);//前(sy-sx)大的元素在左子树里  剩下的在右子树里边找
        return query(mid+1+s1,mid+s1+s2,nk,mid+1,r,d+1);
    }
}
int ans[N];

int main()
{
    int cas=1;
    int i,a,b;
    while(cin>>n)
    {
        for(i=1;i<=n;++i)
        {
            scanf("%d",&srted[i]);
            //srted[i] = i;
            t[0].val[i]=srted[i];
            ans[i]=1;
        }
        sort(srted+1,srted+1+n);
        build(1,n,0);

        int k = 3,l,o;
        while (k <= n)
        {
            l = 1;
            while (l <= n-k+1)
            {
                a = l;
                b = l+k-1;
                o = query(a,b,(a+b)/2-a+1,1,n,0);
                FOR(i,l,l+k-1)
                    if (srted[i] == o)
                        ans[i]++;
                l++;
            }
            k += 2;
        }
        FOR(i,1,n-1)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
