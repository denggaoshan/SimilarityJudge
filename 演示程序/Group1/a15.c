#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)
struct student
{
	int id;
	char name[10];
	float score;
	struct student *next;
};
struct student *Creatlink(void)  
{
	struct student *head;
	struct student *p1,*p2;
	int n=0;
	p1=p2=(struct student *)malloc(LEN);
	scanf("%d%s%f",&p1->id,p1->name,&p1->score);
	head=NULL;
	while(n<=1)
	{
		n++;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%d%s%f",&p1->id,p1->name,&p1->score);
	}
	p2->next=p1;
	p1->next=NULL;
	return(head);
}
struct student *Sortid(struct student *head)
{
	struct student *a[5],*p,*temp;
	int i,j,n=0;
	p=head;
	for(i=0;p!=NULL;i++)
	{
		n++;
		a[i]=p;
		p=p->next;
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]->id>a[j+1]->id)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	head=a[0];
	for(i=0;i<n-1;i++)
	{
		a[i]->next=a[i+1];
	}
	a[n-1]->next=NULL;
	return(head);
}
struct student *Sortscore(struct student *head)
{
	struct student *a[5],*p,*temp;
	int i,j,n=0;
	p=head;
	for(i=0;p!=NULL;i++)
	{
		n++;
		a[i]=p;
		p=p->next;
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]->score>a[j+1]->score)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	head=a[0];
	for(i=0;i<n-1;i++)
	{
		a[i]->next=a[i+1];
	}
	a[n-1]->next=NULL;
	return(head);
}
void Printlink(struct student *head)
{
	struct student *p;
	printf("The students' messages:\n");
	p=head;
	if(head!=NULL)
		do
		{
			printf("id=%d,name=%s,score=%f\n",p->id,p->name,p->score);
			p=p->next;
		}while(p!=NULL);
}
struct student *Searchid(struct student *head,int id)
{
	struct student *p1,*p2,*temp;
	p1=head;
	while(id!=p1->id&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(id==p1->id)
	{
		temp=p1;
		return(temp);
	}
	else
	{
		printf("this student's data isn't exist!\n");
	}
}
struct student *Deletenode(struct student *head,int id)
{
	struct student *p1,*p2,*p0;
	p1=head;
	p0=Searchid(head,id);
	while(p0!=p1&&p1!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1==p0)
	{
		if(head==p0)
			head=p1->next;
		else
			p2->next=p1->next;
		free(p1);
	}
	else
		printf("don't find\n");
	return(head);
}
struct student *Insertnode(struct student *head,struct student *stu)
{
	struct student *p1,*p2,*p0;
	p1=head;
	p0=stu;
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->id>p1->id)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->id<=p1->id)
		{
			if(head==p1)
				head=p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}		
	}
	return(head);
}
void Deletelink(struct student *head)
{
	struct student *p,*q;
	p=head;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
int main()
{
	struct student *head,*stu;
	int id;
	printf("Please input the data:\n");
	head=Creatlink();
	Printlink(head);
	printf("please input the deleted student's id:");
	scanf("%d",&id);
	head=Deletenode(head,id);
	Printlink(head);
	printf("please input another student message:");
	stu=(struct student *)malloc(LEN);
	scanf("%d%s%f",&stu->id,stu->name,&stu->score);
	head=Insertnode(head,stu);
	Printlink(head);
	printf("after sorting by id:\n");
	head=Sortid(head);
	Printlink(head);
	printf("after sorting by score:\n");
	head=Sortscore(head);
	Printlink(head);
	Deletelink(head);
	return 0;
}