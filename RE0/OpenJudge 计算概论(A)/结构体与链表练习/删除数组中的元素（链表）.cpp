#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct data)
struct data
{
    int num;
    struct data *next;
};
struct data* creat(int n)//创建链表
{
    struct data *p1,*p2,*head;
    int i=0;
    p1=head=NULL;
    while(n--)
    {
            i++;
            p1=(struct data*)malloc(LEN);
            if(i==1)
        head=p1;//如果是第一个结点,使head=p1,让head指向新开辟的结点
                        else
        p2->next=p1;//如果不是,令p2指向前一个结点,新结点地址赋给上一个的next
            p2=p1;//使p2指向新建立的结点
                        scanf("%d",&p1->num);
    }
                p2->next=NULL;
                return head;
}
struct data * del(int k,struct data *head)//删除节点
{
    struct data *p1,*p2;
    for(p2=p1=head;p1!=NULL;)
    {
        if(p1->num==k)
        {
            if(p1==head)
            {
                head=p1->next;
                free(p1);//l若p1指向首结点,将第二个结点地址赋给head
            }
            else
            {
                p2->next=p1->next;
                free(p1);//若不是就将下一结点的地址赋给前一结点地址
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
