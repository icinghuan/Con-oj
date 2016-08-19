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
void build(int l,int r,int d)//����  ���������ɽڵ㹹�� �����������һ�ι���  �磺d���l~r��һ���ڵ�
{
    if(l==r) return;
    int mid=(l+r)>>1;//ȡ�м��Ǹ�
    int midd=srted[mid];
    int same=mid-l+1,samed=0,zn=l-1,yn=mid,i;//same��ʶ��Ϊ����Ԫ�ظ���
    //�����ȥ��middС��(һ��������������)  ʣ�µľ���==midd����Ҫ�������ӵĸ���
    //samed���Ѿ��������Ŀ
    //zn��yn�����Һ��ӵĿ�ʼλ��-1��������Ԫ�طֵ��������ӵ��������
    for(i=l;i<=r;++i)
        if(t[d].val[i]<midd) --same;
    for(i=l;i<=r;++i)//�е������  ��ķŵ����  С�ķ�ǰ��    ��ȵĿ����
    {
        if(i==l) t[d].num[i]=0;
        else t[d].num[i]=t[d].num[i-1];
        if(t[d].val[i]<midd)
        {
            ++t[d].num[i];//������ͳ�ƴ�l��i�ж���Ԫ�ؽ���������     ���ǻ�������Ҫ�õ�������
            t[d+1].val[++zn]=t[d].val[i];
        }else if(t[d].val[i]>midd)//�����Һ���
        {
            t[d+1].val[++yn]=t[d].val[i];
        }else
        {
            if(samed<same)//���û������  ���������
            {
                ++samed;
                ++t[d].num[i];
                t[d+1].val[++zn]=t[d].val[i];
            }else//���к������
                t[d+1].val[++yn]=t[d].val[i];
        }
    }
    build(l,mid,d+1);//����������
    build(mid+1,r,d+1);
}
int query(int a,int b,int k,int l,int r,int d)//��d��[l,r]�Ľڵ������[a,b]�еĵ�k��ֵ
{
    if(a==b) return t[d].val[a];
    int mid=(l+r)>>1;
    int sx=t[d].num[a-1],sy=t[d].num[b];
    if(a-1<l) sx=0;
    if(sy-sx>=k)//[a,b]������������Ԫ��>=k
        return query(l+sx,l+sy-1,k,l,mid,d+1);
    else
    {
        int s1=(a==1?0:a-l-sx);
        int s2=(b-a+1)-(sy-sx);
        int nk=k-(sy-sx);//ǰ(sy-sx)���Ԫ������������  ʣ�µ��������������
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
