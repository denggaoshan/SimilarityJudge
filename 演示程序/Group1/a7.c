#include <stdio.h>
#include <stdlib.h>
struct student
{int num;
 char name[20];
 float score;
 struct student *next;
};
 
 int n;int size=sizeof(struct student);

struct student *creatlink(void)
{struct student *head,*p1,*p2;
 n=0;p1=p2=(struct student*)malloc(size);head=0;
 
 printf("please input number name score\n");
    printf("number:");
    scanf("%d",&p1->num);
	printf("name:");
	getchar();
    gets(p1->name);
	printf("score:");
	scanf("%f",&p1->score);
  
  while (p1->num!=0)
  {n=n+1;
   
     if (n==1)     head=p1;
     else p2->next=p1;
   
   p2=p1;
   
   p1=(struct student*)malloc(size);
    printf("number:");
    scanf("%d",&p1->num);
	printf("name:");
	getchar();
    gets(p1->name);
	printf("score:");
	scanf("%f",&p1->score);
  
  }
  p2->next=0;

  printf("**************************************************************************\n");
  return head;	  
}

void print(struct student *head)
{struct student *p;
 printf("These %d records are:\n",n);

 p=head;
    if(n==0)  printf("This is void\n");
	else
        while(p!=0)
		{printf(" number:%d\n name:%s \n score:%.1f\n",p->num,p->name,p->score);
       
	    p=p->next;
		}
}


void searchid(int id,struct student *p)
{
    while (p->num!=id)
	{p=p->next;if(p==0) break;
	}
if (p!=0)
printf(" number:%d\n name:%s \n score:%.1f\n",p->num,p->name,p->score);
else 
printf("can't find the student"); 
}


void deletelink(struct student *p)
{struct student *p1;
	if (p!=0)
	{p1=p;p=p->next;
	free(p1);}
}


struct student* deletenode(int id,struct student *p)
{printf("please confirm it");
	searchid(id,p);struct student *p1,*head=p;

 while (p->num!=id)
	{p1=p;p=p->next;if(p==0) break;
	}
 {if(p==head)
    head=p->next;
    
  else p1->next=p->next;
  n=n-1;
  return head;
 }
}


struct student* sortid (struct student*p1)
{struct student*p2,*newhead;






}



void main()
{struct student* head;
 int id;
 head=creatlink();
 print(head);
 printf("**************************************************************************\n");
 printf("please input the id to find the student:");
 scanf("%d",&id);
 searchid(id,head);
 printf("**************************************************************************\n");
 printf("please input the id to delete the student:");
 scanf("%d",&id);
 head=deletenode(id,head);
 print(head);





deletelink(head);}