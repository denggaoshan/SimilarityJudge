#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	int id;
	char name[20];
	int score;
	struct student *next;
};

struct student *insertnode_id(struct student *head,struct student *p)
{
	struct student *p1=head,*p2;
	while(p->id>p1->id&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p->id<=p1->id)
	{
		if(head==p1)head=p;
		else 
			p2->next=p;
		p->next=p1;
	}
	else
	{
		p1->next=p;
		p->next=NULL;
	}
	return head;
}

struct student *insertnode_score(struct student *head,struct student *p)
{
	struct student *p1=head,*p2;
	while(p->score<p1->score&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p->score>=p1->score)
	{
		if(head==p1)head=p;
		else 
			p2->next=p;
		p->next=p1;
	}
	else
	{
		p1->next=p;
		p->next=NULL;
	}
	return head;
}

struct student *creatlink(int n)
{
	int i;
	struct student *p1,*head;
	if(n==0)return (head=NULL);
	else
	{
		head=p1=(struct student*)malloc(LEN);
		p1->next=NULL;
		scanf("%d",&p1->id);
		scanf("%s",p1->name);
		scanf("%d",&p1->score);
		putchar('\n');
		for(i=0;i<n-1;i++)
		{
			p1=(struct student*)malloc(LEN);
			scanf("%d",&p1->id);
			scanf("%s",p1->name);
			scanf("%d",&p1->score);
			putchar('\n');
			head=insertnode_id(head,p1);
		}
	return head;
	}
}

void printlink(struct student *head)
{
	struct student *p=head;
	while(p!=NULL)
	{
		printf("%d,%s,%d\n",p->id,p->name,p->score);
		p=p->next;
	}
}

struct student *searchid(struct student *head,int id)
{
	struct student *p0=head,*p1;
	int flag=0;
	while(p0!=NULL)
	{
		if(p0->id==id)
		{
			flag=1;
			p1=p0;
			break;
		}
		p0=p0->next;
	}
	if(flag==0)
		p1=NULL;
	return p1;
}

struct student *deletenode(struct student *head,int id)
{
	struct student *p1=head,*p2=head,*p0;
	p0=searchid(head,id);
	if(p0==NULL)return head;
	else
	{
		if(p0==head)head=p0->next;
		else
		{
			while(p1!=p0)
			{
				p2=p1;
				p1=p1->next;
			}
			p2->next=p1->next;
			free(p1);
		}
		return head;
	}
}

void deletelink(struct student *head)
{
	struct student *p1=head,*p2;
	while(p1!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
}

struct student *sortscore(struct student *head)
{
	struct student *head1,*p1,*p2=head;
	head1=p1=(struct student *)malloc(LEN);
	*p1=*p2;
	p1->next=NULL;
	p2=p2->next;
	while(p2!=NULL)
	{
		p1=(struct student *)malloc(LEN);
		*p1=*p2;
		head1=insertnode_score(head1,p1);
		p2=p2->next;
	}
	deletelink(head);
	return head1;
}

struct student *sortid(struct student *head)
{
	struct student *head1,*p1,*p2=head;
	head1=p1=(struct student *)malloc(LEN);
	*p1=*p2;
	p1->next=NULL;
	p2=p2->next;
	while(p2!=NULL)
	{
		p1=(struct student *)malloc(LEN);
		*p1=*p2;
		head1=insertnode_id(head1,p1);
		p2=p2->next;
	}
	deletelink(head);
	return head1;
}

void main()
{
	int id[2];
	struct student *head,*p[2];

	printf("creat a link\n");
	head=creatlink(3);
	printlink(head);
	putchar('\n');

	printf("please input the information you want to insert\n");
	p[1]=(struct student *)malloc(LEN);
	scanf("%d",&p[1]->id);
	scanf("%s",p[1]->name);
	scanf("%d",&p[1]->score);
	putchar('\n');
	head=insertnode_id(head,p[1]);
	printlink(head);
	putchar('\n');

	printf("please input an id which you want to search\n");
	scanf("%d",&id[0]);
	putchar('\n');
	p[0]=searchid(head,id[0]);
	if(p[0]==NULL)printf("查无此人\n");
	else printf("%d,%s,%d\n",p[0]->id,p[0]->name,p[0]->score);
	putchar('\n');

	printf("please input an id which you want to delete\n");
	scanf("%d",&id[1]);
	putchar('\n');
	head=deletenode(head,id[1]);
	printf("after delete:\n");
	printlink(head);
	putchar('\n');

	printf("sort by score:\n");
	head=sortscore(head);
	printlink(head);
	putchar('\n');

	printf("sort by id:\n");
	head=sortid(head);
	printlink(head);

	deletelink(head);
}

