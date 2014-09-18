#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
#define NULL 0
struct student
{
	int num;
	char name[20];
	float score;
	struct student * next;
};
int n;
struct student * CreatLink(void)
{
	struct student * head;
	struct student * p1,* p2;
	n=0;
	p1=p2=(struct student * )malloc(LEN);
	scanf("%d,%s,%f",&p1->num,&p1->name,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%d,%s,%f",&p1->num,&p1->name,&p1->score);
	}
	p2->next=NULL;
	return(head);
}
void PrintLink(struct student * head)
{
    struct student * p;
	printf("\nNow,these %d records are:\n",n);
	p=head;
	if(p!=NULL)
		do
		{
			printf("%d,%s,%f\n",p->num,p->name,p->score);
			p=p->next;
		}
		while(p!=NULL);
}
struct student *SearchId(struct student * head,int num)
{
	struct student * p=head;
	while(p!=NULL)
	{
		if(p->num=num)break;
		p=p->next;
	}
	return p;
}
struct student * InsertNote(struct student * head,struct student * stud)
{
	struct student * p0,* p1,* p2;
	p1=head;
	p0=stud;
	if(head=NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)head=p0;
			else p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n=n+1;
	return(head);
}
struct student * DeleteNote(struct student * head,int num)
{
	struct student * p1,* p2;
	if(head==NULL)
	{
		printf("\nlist null!\n");
		return(head);}
	p1=head;
	while(num!=p1->num&&p1->next==NULL)
	{
		p2=p1;p1=p1->next;
	}
	if(num==p1->num)
	{
		if(p1==head)head=p1->next;
		else p2->next=p1->next;
		printf("delete:%d\n",num);
		n=n-1;
		free(p1);
	}
	else printf("%d not been found!\n",num);
	return(head);
}
void DeleteLink(struct student * head)
{
	struct student * p1,* p2;
    p1=p2=head;
    while(p2!=NULL)
	{
		p2=p2->next;
        free(p1);
        p1=p2;     
	}
}
void main()
{
	struct student * head,* stu;
	int search_num,del_num;
	printf("input records:\n");
    head=CreateLink();
    PrintLink(head);
	printf("\nplease input a number for search:\n");
    scanf("%d",&search_num);
    struct student * p=SearchId(head,search_num);
    printf("\nplease input a inserted num:\n");
	stu=(struct student *)malloc(LEN);
	scanf("%d,%s,%f",&stu->num,&stu->name,&stu->score);
	while(stu->num!=0)
	{
		head=InsertNote(head,stu);
		PrintLink(head);
		printf("input the inserted record:");
		stu=(struct student *)malloc(LEN);
	    scanf("%d,%s,%f",&stu->num,&stu->name,&stu->score);
	}
    printf("\ninput the deleted number:");
	scanf("%d",&del_num);
	while(del_num!=0)
	{
		head=DeleteNote(head,del_num);
		PrintLink(head);
		printf("\ninput the deleted number:");
		scanf("%d",&del_num);
	}
    DeleteLink(head);
}
