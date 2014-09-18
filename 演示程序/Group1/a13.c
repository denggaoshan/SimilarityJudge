#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)
struct Node{
	int num;
	char name[10];
	double score;
	struct Node * next;
};
typedef struct Node * ListLink;
int numMin(ListLink p1,ListLink p2)
{
	if(p1 == NULL || p2 == NULL)
		return -1;
	else
		return (p1->num < p2->num)? 1:0;
}

int scoreMax(ListLink p1,ListLink p2)
{
	if(p1 == NULL || p2 == NULL)
		return -1;
	else
		return (p1->score > p2->score)? 1:0;
}

ListLink InsertNode(ListLink head,ListLink temp,int (*fp)(ListLink,ListLink))
{
	ListLink p = head,q = head;
	while(p && (*fp)(temp,p) != 1)
		p = p->next;
	if(p == head)
	{
		head = temp;
		temp->next = p;
	}
	else
	{
		while(q->next != p)
			q = q->next;
		temp->next = p;
		q->next = temp;
	}
	return head;
}

ListLink CreateLink()
{
	int Nodenum;
	int inum;
	ListLink head = NULL,p;
	
	printf("Nodenum:");
	scanf("%d",&Nodenum);
	
	while(Nodenum --)
	{
		p = (ListLink) malloc(LEN);
		printf("student's num:");
		scanf("%d",&p->num);
		printf("student's name:");
		scanf("%s",p->name);
		printf("student's score:");
		scanf("%lf",&p->score);

		head = InsertNode(head,p,numMin);
	}
	return head;
}

void PrintLink(ListLink head)
{
	ListLink p = head;
	printf("\nnum\tname\tscore\t\n");
	while(p)
	{
		printf("%d\t",p->num);
		printf("%s\t",p->name);
		printf("%.2lf\t",p->score);
		printf("\n");
		p = p->next;
	}
	return;
}

ListLink Searchid(int inum,ListLink head)
{
	ListLink p = head;
	while(p)
		if(p->num != inum)
			p = p->next;
		else
			return p;
	printf("NO DATA!\n");
	return NULL;
}

ListLink DeleteNode(ListLink head,int inum)
{
	ListLink p,q = head;
	p = Searchid(inum,head);
	if(p == head)
	{
		q = p->next;
		free(p);
	}
	else
	{
		while(q->next != p)
			q = q->next;
		q->next = p->next;
		free(p);
	}
	return q;
}

ListLink SortScore(ListLink head)
{
	ListLink newbase = NULL,where = NULL,p = NULL;
	if(head == NULL)
		return NULL;
	else
		while(head)
		{
			p = (ListLink)malloc(LEN);
			(*p) = (* head);
			newbase = InsertNode(newbase,p,scoreMax);
			head = DeleteNode(head,head->num);
		}
	return newbase;
}

ListLink Sortid(ListLink head)
{
	ListLink newbase = NULL,where = NULL,p = NULL;
	if(head == NULL)
		return NULL;
	else
		while(head)
		{
			p = (ListLink)malloc(LEN);
			(*p) = (* head);
			newbase = InsertNode(newbase,p,numMin);
			head = DeleteNode(head,head->num);
		}
	return newbase;
}

ListLink DeleteLink(ListLink head)
{
	ListLink p;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return NULL;
}

int main()
{
	ListLink head,temp = NULL;
	int inum;
	head = CreateLink();
	PrintLink(head);

	temp = (ListLink)malloc(LEN);
	printf("student's num:");
	scanf("%d",&temp->num);
	printf("student's name:");
	scanf("%s",temp->name);
	printf("student's score:");
	scanf("%lf",&temp->score);
	
	head = InsertNode(head,temp,numMin);
	PrintLink(head);

	printf("the inum of student to search:");
	scanf("%d",&inum);
	temp = Searchid(inum,head);
	
	if(temp)
		printf("temp num:%d\tname:%s\tscore:%.2lf\n",temp->num,temp->name,temp->score);

	printf("Please input the num of student to delete:");
	scanf("%d",&inum);
	head = DeleteNode(head,inum);
	PrintLink(head);

	head = SortScore(head);
	PrintLink(head);

	head = Sortid(head);
	PrintLink(head);

	head = DeleteLink(head);

	return 0;
}