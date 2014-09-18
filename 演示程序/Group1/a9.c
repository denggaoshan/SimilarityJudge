/*   a   */

#include<stdio.h>
#include<stdlib.h>
struct student
{
	int num;
	char name[20];
	float score;
	struct student * next;
};

int n;
/*   e   */

struct student * InsertNode(struct student * head,struct student * stud)
{
	struct student * p0,* p1,* p2;
	p1=head;
	p0=stud;
	if(head == NULL)
	{
		head=p0;
		p0->next = NULL;
	}
	else
	{
		while ( (p0->num >p1->num) && (p1->next != NULL) )
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num <= p1->num)
		{
			if(head == p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
		    p0->next = NULL;
		}
	}
	return(head);
}

/*   b   */

struct student * CreateLink(void)
{
    int i;
	struct student * head=NULL;
	struct student * p;
	printf("input student's number:");
	scanf("%d",&n);
	i=n;
	while(i--)
	{
	    p=(struct student *)malloc(sizeof(struct student ));
	    printf("input the student:\n");
	    scanf("%d %s %f",&p->num,p->name,&p->score);
	    head=InsertNode(head,p);
	}
	return(head);
}
/*   c   */

void PrintLink(struct student * head)
{
	struct student * p;
	printf("\nNow,these %d students are:\n",n);
	p=head;
	if(head != NULL)
		do
		{
			printf("ID:%d  name:%s  score:%f\n",p->num,p->name,p->score);
			p=p->next;
		} while(p != NULL);
}


/*   d   */

struct student * SearchId(struct student * head,int number)
{
	struct student * p;
	p=head;
	while(p != NULL)
	{
	    if(p->num == number)
	    {
	        break;
	    }
	    p=p->next;
	}
	return p;
}

/*   f   */

struct student * DeleteNode(struct student * head,int number)
{
	struct student * p1,* p2,*p;
	p=SearchId(head,number);
	p1=head;
	p2=p->next;
	if(p==head)
	{
	    head = p->next;
	}
	else
	{
	    while(p1->next != p)
	    {
	        p1=p1->next;
	    }
	    p1->next=p2;
	}
	n=n-1;
	return(head);
}

/*   g   */
/*
struct student (*p) (struct student*,struct student *)
{
    if()
}
*/

struct student * SortId(struct student * head)
{
	struct student * p,* p0,* newhead=NULL;
	p=p0=head;
	while(p != NULL)
	{
	    p0=p0->next;
	     newhead=InsertNode(newhead,p);
	     p=p0;
	}
	p=NULL;
	return(newhead);
}

/*   h   */

struct student * InsertS(struct student * head,struct student * stud)
{
	struct student * p0,* p1,* p2;
	p1=head;
	p0=stud;
	if(head == NULL)
	{
		head=p0;
		p0->next = NULL;
	}
	else
	{
		while ( (p0->score <p1->score) && (p1->next != NULL) )
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->score >= p1->score)
		{
			if(head == p1)
				head = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
		    p0->next = NULL;
		}
	}
	return(head);
}

struct student * Sortscore(struct student * head)
{
	struct student * p,* p0,* newhead=NULL;
	p=p0=head;
	while(p != NULL)
	{
	    p0=p0->next;
	     newhead=InsertS(newhead,p);
	     p=p0;
	}
	p=NULL;
	return(newhead);
}

/*   i   */

void DeleteLink(struct student * head)
{
	struct student * p1,* p2;
	p1=head;
	p2=p1->next;
	while(p2!=NULL)
	{
	    free(p1);
	    head=p2;
	    p1=p2;
	    p2=p1->next;
	}
	free(p1);
}


void main()
{
	struct student * head,stud,*p1,*p2,*p;
    int number1,number2;
	head=CreateLink();
	PrintLink(head);

	printf("\ninput the inserted :\n");
	n=n+1;
	scanf("%d %s %f",&stud.num,stud.name,&stud.score);
	head=InsertNode(head,&stud);
	PrintLink(head);

	printf("\ninput the number you wanna seach:\n");
	scanf("%d",&number1);
	p=SearchId(head,number1);
	if(p != NULL)
	{
	    printf("%d %s %f:\n",p->num,p->name,p->score);
	}
	if(p == NULL)
	{
	    printf("Wrong!\n");
	}

	printf("\ninput the number you wanna delete:\n");
	scanf("%d",&number2);
	head=DeleteNode(head,number2);
	PrintLink(head);

    printf("after sortscore:\n");
	head=Sortscore(head);
	PrintLink(head);

    printf("after sortid:\n");
	head=SortId(head);
	PrintLink(head);

	DeleteLink(head);
	printf("\nFree all ! \nFinish!\n");

}
