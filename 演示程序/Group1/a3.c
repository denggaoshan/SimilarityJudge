#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct LinkNode
{
	int num;
	char name[20];
	int score;
	struct Link *next;
}LinkNode,*LinkPoint;


/*创建并且输入*/
LinkPoint Create()
{
	int num;
	LinkPoint p;
	LinkPoint q1,q2;
	LinkPoint head=(LinkPoint)malloc(sizeof(LinkNode));
	
	if(head==NULL)
		exit(0);

	head->num=-999;
	head->next=NULL;
	
	printf("请输入学生学号\n");

    while(scanf("%d",&num))
	{
		getchar();
		if(num==0)
		break;
		p=(LinkPoint)malloc(sizeof(LinkNode));
		if(p==NULL)
			exit(0);
		p->num=num;
		printf("请输入学生姓名 成绩\n");
		scanf("%s %d",p->name,&p->score);


		/*找位置*/
		q1=head;
		q2=head->next;
		
		while(q2!=NULL)
		{
			if(num > q1->num && num < q2->num)
				break;
			else
			{
				q1=q2;
				q2=q2->next;			
			}
	
		}

	       p->next=q2;
		   q1->next=p;



		printf("请输入学生学号(输入0结束)\n");
	}

	return head;
}

void PrintLink(LinkPoint head)
{
	LinkPoint p;
	p=head->next;
	while(p!=NULL)
	{
		printf("学号%-5d 姓名%-8s 成绩%-5d\n",p->num,p->name,p->score);
		p=p->next;
	}
}

/*寻找学号为num的学生 返回它的指针*/
LinkPoint SearchId(LinkPoint head,int id)
{
	LinkPoint p;

	p=head->next;
	
	while(p!=NULL)
	{
	   if(p->num==id)
	   {
		 break;
	   }
	   p=p->next;
	}
	if(p==NULL)
	{
		printf("not found!\n");
		return NULL;
	}

	return p;
}


/*按学号插入 */
void InsertNode(LinkPoint head,int number, char name[],int score)
{
   LinkPoint p;
   LinkPoint q1,q2;
   int num;

   p=(LinkPoint)malloc(sizeof(LinkNode));
   
   if(p==NULL)
	   exit(0);

   p->num=number;
   strcpy(p->name,name);
   p->score=score;

   /*找位置*/
		q1=head;
		q2=head->next;
		num = p->num;

		while(q2!=NULL)
		{
			if(num > q1->num && num < q2->num)
				break;
			else
			{
				q1=q2;
				q2=q2->next;			
			}
	
		}
	       p->next=q2;
		   q1->next=p;
}




/*删除学生*/
void DeleteNode(LinkPoint head,int num)
{
	LinkPoint del;
	LinkPoint p;

	del =SearchId(head,num);
	if(del == NULL)
	{
		printf("not found!\n");
		return ;
	}
	p=head;
	while(p->next!=del)
	{
		p=p->next;
	}

	p->next=del->next;
	free(del);
}


/*删除整个链表*/
void DeleteLink(head)
{
	LinkPoint p=head;
    LinkPoint q;

	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(head);
	printf("删除成功！\n");
}



int main()
{  
	int num,score;
	char name[10];
	
    LinkPoint head;
    LinkPoint p;

	head=Create();
	PrintLink(head);

	printf("输入查找的学号\n");
    scanf("%d",&num);
	p = SearchId(head,num);
	if(p!=NULL)  //找到了！
	printf("学号%d 姓名%s 成绩%d\n",p->num,p->name,p->score);

	
   printf("请输入插入的学号 姓名 成绩\n");
   scanf("%d %s %d",&num,name,&score);
   InsertNode(head,num,name,score);
   PrintLink(head);

   
   printf("请输入删除的学号\n");
   scanf("%d",&num);
   DeleteNode(head,num);
   PrintLink(head);


		
	

	return 0;
}
