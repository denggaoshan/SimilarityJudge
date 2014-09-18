#include<stdio.h>
#include<stdlib.h>
#define FULL 0
struct student
{
longnum;
char name[5];
int score;
struct student *next;
};
struct student * createlink()
{
struct student a,b,c,*head;
   scanf("%ld%s%d%ld%s%d%ld%s%d",a.num,a.name,a.score,b.num,b.name,b.score,c.num,c.name,c.score);
head=&a;
a.next=&b;
b.next=&c;
c.next=NULL;
return(head);
}
struct student * printlink(struct student *head)
{
struct student *p;
   p=head;
if(head!=NULL)
   {
	while(p!=NULL)
	   {
		printf("%ld %s %d\n",p->num,p->name,p->score);
		   p=p->next;
	   }
   }
return(head);
}
struct student * searchld(struct student *head,long x)
{
struct student *p;
   p=head;
int a=1;
if(head!=NULL)
   {
while(p!=NULL)
	  {
	if(p->num==x)
		{  printf("%ld %s %d\n",p->num,p->name,p->score);
		     a=0;
		break;
		  }
		  p=p->next;
	  }
	if(a==1)
		printf("%ld not been found!\n",x);
   }
return(head);
}
struct student * insertnode(struct student *head,struct student *stud)
{
struct student *p0,*p1,*p2;
   p1=head;
   p0=stud;
if(head==NULL)
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
struct student *deletenode(struct student *head,longnum)
{
struct student *p1,*p2;
   p1=head;
if(searchld(head,num)==0)
   {
while(num!=p1->num&&p1->next!=NULL)
	  {
	    p2=p1;
		p1=p1->next;
	  }
	if(num==p1->num)
	  {
		if(p1==head)
			head=p1->next;
		else
			  p2->next=p1->next;
		printf("delete:%ld\n",num);
	  }
   }
return(head);
}
struct student *deletelink(struct student *head)
{
struct student *p;
	p=head;
	while(p!=NULL)
	{
	free(p);
	   p=p->next;
	}
	return(head);
}
void main()
{
int num1,num2;
struct student *head;
head=createlink();
printlink(head);
struct student stu;
printf("\ninput the inserted student:");
scanf("%ld%s%d",stu.num,stu.name,stu.score);
head=insertnode(head,&stu);
printlink(head);
printf("\ninput the searched number:");
scanf("%ld",&num1);
searchld(head,num1);
printf("\ninput the deleted number:");
scanf("%ld",&num2);
head=(struct student *)deletenode(head,num2);
printlink(head);
deletelink(head);
}
