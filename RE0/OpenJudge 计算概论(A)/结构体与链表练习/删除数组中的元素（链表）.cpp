#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct data)
struct data
{
    int num;
    struct data *next;
};
struct data* creat(int n)//��������
{
    struct data *p1,*p2,*head;
    int i=0;
    p1=head=NULL;
    while(n--)
    {
            i++;
            p1=(struct data*)malloc(LEN);
            if(i==1)
        head=p1;//����ǵ�һ�����,ʹhead=p1,��headָ���¿��ٵĽ��
                        else
        p2->next=p1;//�������,��p2ָ��ǰһ�����,�½���ַ������һ����next
            p2=p1;//ʹp2ָ���½����Ľ��
                        scanf("%d",&p1->num);
    }
                p2->next=NULL;
                return head;
}
struct data * del(int k,struct data *head)//ɾ���ڵ�
{
    struct data *p1,*p2;
    for(p2=p1=head;p1!=NULL;)
    {
        if(p1->num==k)
        {
            if(p1==head)
            {
                head=p1->next;
                free(p1);//l��p1ָ���׽��,���ڶ�������ַ����head
            }
            else
            {
                p2->next=p1->next;
                free(p1);//�����Ǿͽ���һ���ĵ�ַ����ǰһ����ַ
                p1=p2->next;
            }
        }
        else
        {
            p2=p1;
            p1=p1->next;
        }
    }
    return head;
}
int main()
{
    int n,k;
    struct data *p;
    scanf("%d",&n);
    p=creat(n);
    scanf("%d",&k);
    p=del(k,p);
    if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            printf("%d ",p->num);
            p=p->next;
        }
        printf("%d\n",p->num);
    }
    return 0;
}
