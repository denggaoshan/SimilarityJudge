#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	char name[10];
	struct student *next;
};
struct pointers
{
	struct student *p1;
	struct student *p2;
};
int n;
struct student *CreatLink(void)
{
	struct student *head,*p1,*p2;	
	int i=1;
	n=1;
	p1=p2=(struct student*)malloc(LEN);
	scanf("%ld,%f,%s",&p1->num,&p1->score,p1->name);
	head=p1;	
	while(i<3)
	{
		n=n+1;
		i=i+1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		scanf("%ld,%f,%s",&p1->num,&p1->score,p1->name);
		p2->next=p1;
	}
	p1->next=NULL;
	return(head);
}
void PrintLink(struct student *head)
{
	struct student *p;
	printf("\nNow,these %d records are:\n",n);
	p=head;
	while(p!=NULL)
	{
		printf("%ld,%.1f,%s\n",p->num,p->score,p->name);
		p=p->next;
	}
	
}
struct student *InsertNode(struct student *head,struct student *stud)
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
			if(p1==head)
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
		n=n+1;
		return(head);
}
struct student *SearchID(struct student *head)
{
	long id;
	struct student *p1,*p2;
	printf("\nInput the ID you want to search:");
	scanf("%ld",&id);
	p1=p2=head;
    while((p1->num!=id)&&(p1->next!=NULL))
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->num==id)
	{
	    return(p1);
	}
	else
	{
		printf("\n%ld not been found!\n",id);
		return(NULL);
	}
}
struct student *DeleteNode(struct student *head)
{
	long id;
	struct student *p1,*p2;
	printf("\nInput the ID you want to delete:");
	scanf("%ld",&id);
	p1=head;
	while((p1->num!=id)&&(p1->next!=NULL))
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->num==id)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
	}
	n=n-1;
	return(head);
}
void DeleteLink(struct student *head)
{
	struct student *p1,*p2;
	p1=head;
	while(p1!=NULL)
	{
		p2=p1;
		p1=p1->next;
		free(p2);
	}
}
void main()
{
    struct student *head,stud,*p;
	printf("Input the students' records:\n");
	head=CreatLink();
	PrintLink(head);
    printf("\nInput the inserted record:");
    scanf("%ld,%f,%s",&stud.num,&stud.score,stud.name);
	head=InsertNode(head,&stud);
    PrintLink(head);
    p=SearchID(head);
	if(p!=NULL)
	{
		printf("\nThe student's record:%ld,%.1f,%s\n",p->num,p->score,p->name);
	}
    DeleteNode(head);
    PrintLink(head);
   DeleteLink(head);
}