#include"stdio.h"
#include"stdlib.h"
struct student
{
	int num;
	char name[20];
	float score;
	struct student *next;
};
struct student *creat()
{
	struct student *p1,*p2,*p3,*head;
	p1=p2=p3=(struct student *)malloc(sizeof(struct student));
	printf("输入第一位学生的数据\n");
	scanf("%d,%s,%f",p1->num,p1->name,p1->score);
	printf("输入第二位学生的数据\n");
	scanf("%d,%s,%f",p2->num,p2->name,p2->score);
	printf("输入第三位学生的数据\n");
	scanf("%d,%s,%f",p3->num,p3->name,p3->score);
	if(p1->num > p2->num)
	{
		if(p1->num > p3->num)
		{
			if(p2->num > p3->num)
			{
				head=p3;
				p3->next=p2;
				p2->next=p1;
				p1->next=NULL;
			}
			else
			{
				head=p2;
				p2->next=p3;
				p3->next=p1;
				p1->next=NULL;
			}
		}
		else
		{
			head=p3;
			p3->next=p1;
			p1->next=p2;
			p2->next=NULL;
		}
	}
	else
	{
		if(p2->num > p3->num)
		{
			if(p1->num > p3->num)
			{
				head=p3;
				p3->next=p1;
				p1->next=p2;
				P2->next=NULL;
			}
			else
			{
				head=p1;
				p1->next=p3;
				p3->next=p2;
				p2->next=NULL;
			}
		}
		else
		{
			head=p1;
			p1->next=p2;
			p2->next=p3;
			p3->next=NULL;
		}
	}
    return(head);
}
void print(struct student *head)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d,%s,%f",p->num,p->name,p->score);
		p=p->next;
	}
}
struct student search(struct student *head,int a)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		if(p->num==a)
			printf("%d,%s,%f",p->num,p->name,p->score);
		else
		{
			if(p->next==NULL)
				printf("无此人")；
				else
				p=p->next;
		}
	}
}
struct student *insert(struct stuent *head,struct student *stud)
{
	struct student *p0,*p1,*p2;
	p0=stud;
	p1=head;
	while(p0->num > p1->num && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->num<=p1->num)
	{
		if(head=p1)
		{
			head=p0;
			p0->next=p1;
		}
		else
		{
			p2->next=p0;
			p0->next=p1;
		}
	}
	else
	{
		p1->next=p0;
		p0->next=NULL;
	}
	return(head);
}
struct student *del(struct student *head,int num);
{
	struct student*p1,*p2;
	while(p1->num!=num && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if(head==p1)
		{
			head=p1->next;
			free(p1);
		}
        else
		{
			p2->next=p1->next;
			free(p1);
		}
	}
	else
		printf("查无此人");
	return(head);
}
void deletelink(struct studnet *head)
{
	struct student *p1,*p2;
	p1=head;
	while(p1->next!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	free(p1);
}
void main()
{
	struct student *a,*b;
	int x,y;
	b=(struct student *)malloc(sizeof(struct student));
    a=creat();
    print(a);
	printf("请输入第四名学生的数据\n");
	scanf("%d,%s,%f",b->num,b->name,b->score);
	a=insert(a,b);
	print(a);
	printf("请输入想要查找的学生的学号\n");
	scnaf("%d",&x);
	search(a,x);
	printf("输入想要删除学生的学号\n");
	scanf("%d",&y);
	a=del(a,y);
	print(a);
	deletelink(a);
	printf("链表已删除")；
}
