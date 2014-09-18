#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
//a)创建学生数据结构，含有学号（整型），姓名，成绩（1门即可）。
struct student 
{ 
	int num;
	char name[20];
	float score;
	struct student *next;
};
void main()
{
	struct student *creatlink();
	void printlink(struct student *head);
    void searchid(struct student *head,int m);
    struct student *insertnode(struct student *head,struct student *stud);
    struct student *deletenode(struct student *head,int m);
    struct student *sortid(struct student *head);
    void deletelink(struct student *head);
	struct student *head,*stu;
	int m;
    head=creatlink();
	printlink(head);
	printf("input the student id you want\n");
	scanf("%d",&m);
    searchid(head,m);
	printf("\n\nnow it's going to sort it\n\n");
    sortid(head);
	printlink(head);
	printf("then insert a student record\n ");
    stu=(struct student *)malloc(LEN);
    printf("intput the student's id\n");
	scanf("%d",&stu->num);
	printf("input the student's name\n");
	scanf("%s",stu->name);
	printf("input the student's score\n");
	scanf("%f",&stu->score);
    insertnode(head,stu);
    printlink(head);
    printf("now input the student you want to delete\n");
	scanf("%d",&m);
    deletenode(head,m);
    printlink(head);
    deletelink(head);
}
/*b)	创建链表(CreateLink)，并输入学生数据（3位），每输入一位数据插入一个链表结点。
用户输入的时候，可不按学号排序，但是插入数据时，应根据学号从大到小排序。
例如：依次加入的三位学生的学号分别为14,7,29，则：
第一次加入学号为14的学生数据，第二次加入学号为7的学生数据，
但是插入时应将学号为7的学生放在学号为14的学生之前。
第三次加入学号为29的学生数据，应该放在最后。*/
struct student *creatlink()
{
	struct student *head;
	struct student *p1,*p2;
	int n=0;
	p1=p2=(struct student *)malloc(LEN);
	printf("intput the student's id\n");
	scanf("%d",&p1->num);
	printf("input the student's name\n");
	scanf("%s",p1->name);
	printf("input the student's score\n");
	scanf("%f",&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct student *)malloc(LEN);
    	printf("intput the student's id\n");
	    scanf("%d",&p1->num);
	    printf("input the student's name\n");
	    scanf("%s",p1->name);
	    printf("input the student's score\n");
	    scanf("%f",&p1->score);
	}
	p2->next=NULL;
	free(p1);
	return head;
}
//c)	遍历整个链表(PrintLink)，打印出当前所有学生的数据。
void printlink(struct student *head)
{
	struct student *p;
	printf("\nNow,There records are:\n");
	p=head;
	if(head!=NULL)
		do
		{
			printf("%d %s %.2f\n",p->num,p->name,p->score);
			p=p->next;
		}while(p!=NULL);
}
//d)根据学号查找某个学生数据(SearchId), 如查无此人，应该报告。
void searchid(struct student *head,int m)
{
	struct student *p;
	int f=1;
	p=head;
	if(head!=NULL)
		do
		{
			if(m==p->num)
			{
			     printf("%d %s %.2f\n",p->num,p->name,p->score);
				 f=0;
				 break;
			}
			p=p->next;
		}while(p!=NULL);
		if(f)
			printf("there isn'n a student have the id of %d\n",m);
}
//h)根据学生学号对链表进行排序（SortId），学号小在前，学号大在后。
struct student *sortid(struct student *head)
{
    struct student *insertnode(struct student *head,struct student *stud);
	struct student *p1,*p2=NULL,*p3,*p4;
	if(head==NULL)
	{
		printf("list null!\n");
		return head;
	}
	p1=head;	
	while(p1!=NULL)
	{
		p4=p2;
	    p2=p1;
	    p1=p1->next;
		if(p1!=NULL)
			if(p2->num>p1->num)
			{
			    p3=p1;
			    p1=p1->next;
			    p2->next=p1;
                p3->next=NULL;
                insertnode(head,p3);
			}
	}
			if(p4->num>p2->num)
			{
			    p3=p2;
                p3->next=NULL;
                insertnode(head,p3);
			}
	return head;
}
//e)插入一个新的学生数据（InsertNode），要求插入的位置是按照学号升序排列的。
//想想，这个时候数组是不是就处理不了了，就算数组空间预先分配足够到，插入一个数据，
//其后面的所有的数据要相应地移动，计算量很大。
struct student *insertnode(struct student *head,struct student *stud)
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
			{
				head=p0;
				p0->next=p1;
			}
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
		return (head);
}
//f)根据学号删除一个学生数据(DeleteNode)，此函数应调用SearchId。若删除某个学生，
//记得要用free释放该学生数据，不然造成内存泄露（分配的内存没有回收）。
struct student *deletenode(struct student *head,int m)
{
	struct student *p1,*p2;
	if(head==NULL)
	{
		printf("\nlist null!\n");
		return head;
	}
	p1=head;
	while(m!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(m==p1->num)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		printf("delete:%d\n",m);
	}
	else 
		printf("%d not been found! \n",m);
		return head;
}
//i)	删除整个链表（DeleteLink）。
void deletelink(struct student *head)
{
	struct student *p1,*p2;
	p1=head;
	while(p1!=NULL)
	{
		p2=p1;
		p1=p1->next;
		free(p2);
	}
	free(p1);
}
	  

		 
	