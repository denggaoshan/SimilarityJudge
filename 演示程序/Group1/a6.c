#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	int num;
	char name[30];
	float score;
	struct student *next;
};

   static int n;
struct student *creat(void)
{
	int i=1;
    struct student *head;
    struct student *p1,*p2;
    n=0;
    p1=p2=(struct student*)malloc(LEN);
    scanf("%d %s %f",&p1->num,p1->name,&p1->score); 
    head=0;
    while(p1->num!=0)
	{
		n=n+1;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
		p1=(struct student*)malloc(LEN);
		scanf("%d %s %f",&p1->num,p1->name,&p1->score);
	}
	p2->next=0;
	return(head);
	
}

void print(struct student*head)
{
	struct student *p;
	printf("\nNow,These records are:\n");
	
	p=head;
	if(head!=0)
		do
		{
			printf("%d %s %f\n",p->num,p->name,p->score);
			p=p->next;
		}while(p!=0);
}
void searchid(struct student *head , long num)
{
	struct student *p1,*p2;
	p1=head;
	while(num!=p1->num&&p1->next!=0)
	{
		p2=p1;
		p1=p1->next ;
	}
	if(num==p1->num)
	printf("%d,%s,%f\n",p1->num,p1->name,p1->score);
	if(num!=p1->num&&p1->next==0)
		printf("查无此人\n");
}
struct student* deletelink(struct student *head)
{
	struct student *p1,*p2;
    p1=p2=head;
	while(p1->next!=0)
    {
		if(p1==head)
		head=p1->next;
	    else
		p2->next=p1->next;
	}
    if(p1->next==0)
		free(p1);
}
void main()
{
	int num;
	struct student *head;
	printf("input records:\n");
	head=creat();
	print(head);
	printf("input numbers:\n");
    scanf("%d",&num);
	searchid(head,num);
	head=deletelink(head);
	print(head);
}



