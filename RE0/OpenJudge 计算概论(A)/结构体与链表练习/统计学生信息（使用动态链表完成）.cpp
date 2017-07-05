#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	char num[50];
	char name[41];
	char n[3];
	char c[100];
	char c1[100];
	char dizhi[50];
	struct node *next;
};
struct node *creat(void)
{
	struct node *head,*p1,*p2;
	head=NULL;
	p1=(struct node*)malloc(sizeof(struct node));
	while(1)
	{

		scanf("%s",p1->num);
		if(strcmp(p1->num,"end")==0)
			break;
		else
		{
		    scanf("%s",p1->name);
		    scanf("%s",p1->n);
		    scanf("%s",p1->c);
		    scanf("%s",p1->c1);
		    scanf("%s",p1->dizhi);
			p1->next=NULL;
		    if(head==NULL)
			   head=p1;
		    else
			   p2->next=p1;
		    p2=p1;
		    p1=(struct node*)malloc(sizeof(struct node));
		}


	}
	return head;
}
struct node *reverse(struct node *head)
{
	struct node *p,*q,*t;
	p=head;
	q=NULL;
	while(p!=NULL)
	{
		t=p->next;
		p->next=q;
		q=p;
		p=t;
	}
	return q;
}
void print(struct node *p1)
{
	struct node *p;
	p=p1;
	while(p!=NULL)
	{

		printf("%s %s %s %s %s %s\n",p->num,p->name,p->n,p->c,p->c1,p->dizhi);
		p=p->next;
	}
}
int main()
{
	struct node *head,*p1;
	head=creat();
	p1=reverse(head);
	print(p1);
	return 0;


}
