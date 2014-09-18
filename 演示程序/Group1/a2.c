#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct student 
{
	long num;
	float score;
	char name[20];
    struct student *next;
};

struct student* creatlink()
{
	int n;
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=(struct student*)malloc(sizeof(struct student));
	scanf("%ld%f%s",&p1->num,&p1->score,p1->name);
	head=p1;
	while(n<2)
	{
		n=n+1;
        p2=p1;
		p1=(struct student*)malloc(sizeof(struct student));
		scanf("%ld%f%s",&p1->num,&p1->score,p1->name);
		p2->next=p1;
	}
	p1->next=NULL;
	return(head);
}

void  printlink(struct student *head)
{
    struct student*p;
	printf("\nNow,these records are:\n");
	p=head;
	while(p!=NULL)
	{
          printf("%ld %5.1f %s\n",p->num,p->score,p->name);
		  p=p->next;
	 
	}
}

struct student *searchid(struct student *head,long int number)
{
	struct student *p1;
	p1=head;
	while(p1->num!=number&&p1->next!=NULL)
	{
		p1=p1->next;
	}
	if(p1->num==number)
		return(p1);
	else
		printf("\n查无此人");
	    return(p1);
}


struct student *insert(struct student *head,struct student *stud)
{
	struct student *p0,*p1,*p2;
	p1=head;
	p0=stud;
	if(head=NULL)
	{
		head=p0;p0->next=NULL;
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
			{p1->next=p0;p0->next=NULL;}
	}
	  return(head);
}

struct student*del(struct student *head,long int number)
{
	struct student *p1,*p2;
	if(head==NULL)
	{printf("\nlist null!\n");
	 return(head);
	}
	p1=head;
	while(number!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(number==p1->num)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		free(p1);
		printf("delete:%ld\n",number);
	}
	else
		printf("%ld not been found!\n",number);
	return(head);
}

void deletelink(struct student*head)
{
	struct student*p1,*p2;
	head=p1;
	if(head!=NULL)
	{
		while(p1!=NULL)
		{
			p2=p1;
			p1=p1->next;
			free(p2);
		}
	}
}
void main()
{
	struct student *head,stu,*p;
	long number1;
	long number2;
	printf("input the records:\n");
	head=creatlink();
	printlink(head);
	printf("input the serched number:\n");
	scanf("%ld",&number1);
	p=searchid(head,number1);
	printf("%ld,%5.1f,%s\n",p->num,p->score,p->name);
	printf("input the deleted number:\n");
	scanf("%ld",&number2);
	head=del(head,number2);
	printlink(head);
	printf("input the inserted data:\n");
	scanf("%ld%f%s",&stu.num,&stu.score,stu.name);
	head=insert(head,&stu);
	printlink(head);
	printf("deletelink.\n ");
	deletelink(head);
    scanf("%ld",number1);
}