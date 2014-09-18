#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define NULL 0
#define LEN sizeof(struct student)
struct student
{
	int number;
	char c[100];
	float score;
	struct student *next;
};
int n;
struct student *create(void)
{
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(LEN);
	printf("请输入数据（学号、姓名、成绩）");
	scanf("%d%s%f",&p1->number,&p1->c,&p1->score);
	head=NULL;
	while(p1->number!=0)
	{
		n++;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		printf("请输入数据（学号、姓名、成绩）");
		scanf("%d%s%f",&p1->number,&p1->c,&p1->score);
	}
	p2->next=NULL;
	return(head);
}
void printlink(struct student *head)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		printf("学号：%d,姓名：%s,成绩：%f\n",p->number,p->c,p->score);
		p=p->next;
	}
}
void searchid(struct student *head,int n)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		if(p->number==n)
		{
			printf("该学生的姓名是%s,该学号学生的成绩为%f\n",p->c,p->score);
			break;
		}
		else
			p=p->next;
	}
	if (p==NULL)
		printf("查无此人\n");
}
struct student * insertnode(struct student *head,struct student *stud)
{
	struct student *p1,*p2,*p3;
	p2=head;
	p1=stud;
	if(head==NULL)
	{
		head=p1;
		p1->next=NULL;
	}
	else
	{
		while((p1->number>p2->number)&&(p2->next!=NULL))
		{
			p3=p2;
			p2=p2->next;
		}
		if(p1->number<=p2->number)
		{
			if(head==p2)head=p1;
			else p3->next=p1;
			p1->next=p2;
		}
		else
		{
			p2->next=p1;
			p1->next=NULL;
		}
	}
		return(head);
}
struct student * deletenote(struct student *head,int number)
{
	struct student *p1,*p2;
	if(head==NULL)
	{
		printf("链表是空表\n");
		return (head);
	}
	p1=head;
	while(number!=p1->number && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(number==p1->number)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
	}
	free(p1);
	return(head);
}
void deletelink(struct student *head)
{
	struct student *p1,*p2;
	p1=p2=head;
	while(p1!=NULL)
	{	
		p1=p1->next;
		free(p2);
		p2=p1;
	}
}
struct student * insertscore(struct student *head,struct student *stud)//为之后的排序做准备//
{
	struct student *p1,*p2,*p3;
	p2=head;
	p1=stud;
	if(head==NULL)
	{
		head=p1;
		p1->next=NULL;
	}
	else
	{
		while((p1->score<p2->score)&&(p2->next!=NULL))
		{
			p3=p2;
			p2=p2->next;
		}
		if(p1->score>=p2->score)
		{
			if(head==p2)head=p1;
			else p3->next=p1;
			p1->next=p2;
		}
		else
		{
			p2->next=p1;
			p1->next=NULL;
		}
	}
		return(head);
}
struct student * insertid(struct student *head,struct student *stud)//为之后的排序做准备//
{
	struct student *p1,*p2,*p3;
	p2=head;
	p1=stud;
	if(head==NULL)
	{
		head=p1;
		p1->next=NULL;
	}
	else
	{
		while((p1->number<p2->number)&&(p2->next!=NULL))
		{
			p3=p2;
			p2=p2->next;
		}
		if(p1->number>=p2->number)
		{
			if(head==p2)head=p1;
			else p3->next=p1;
			p1->next=p2;
		}
		else
		{
			p2->next=p1;
			p1->next=NULL;
		}
	}
		return(head);
}
struct student * sortscore(struct student *h)
{
	int n=0;
	struct student *head;
	struct student *p,*p1;
	p=h;
	p1=(struct student *)malloc(LEN);
	head=NULL;
	while(p!=NULL)
	{
		n++;
		if(n==1)
		{
			p1=NULL;
			head=p1;
		}
		else
			head=insertscore(head,p);
		p=p->next;
		p1=p1->next;
		p1=(struct student*)malloc(LEN);
	}
	p1=NULL;
	return(head);
}
struct student * sortid(struct student *h)
{
	int n=0;
	struct student *head;
	struct student *p,*p1;
	p=h;
	p1=(struct student *)malloc(LEN);
	head=NULL;
	while(p!=NULL)
	{
		n++;
		if(n==1)
		{
			p1=NULL;
			head=p1;
		}
		else
			head=insertid(head,p);
		p=p->next;
		p1=p1->next;
		p1=(struct student*)malloc(LEN);
	}
	p1=NULL;
	return(head);
}
void main()
{
	struct student *head;
	int number1,number2;
	head=create();
	printf("现在的数据为:\n");
	printlink(head);
	printf("请输入要检索的学生的学号");
	scanf("%d",&number1);
	searchid(head,number1);
	printf("请输入要插入的学生数据");
	struct student *p1;
	p1=(struct student *)malloc(LEN);
	scanf("%d%s%f",&p1->number,&p1->c,&p1->score);
	printf("现在的数据为:\n");
	printlink(insertnode(head,p1));
	printf("请输入要删除的学生的学号");
	scanf("%d",&number2);
	printf("现在的数据为:\n");
    printlink(deletenote(head,number2));
	printf("按成绩排序后的数据为:\n");
	printlink(sortscore(head));
	printf("按学号排序后的数据为:\n");
	printlink(sortid(head));
	deletelink(head);
}










		






