#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<windows.system.h>
#include"tools.h"

noteOne* creat1()
{
	
	int i , n = 0;  //i为想要生成链表数，n为计数器

	char in[20]="NULL"; 

	printf("请输入要生成的链表数:");
	scanf("%d", &i);

	noteOne* head, *p1, * p2;
	head = p2 = p1 = (noteOne*)malloc(sizeof(noteOne));

	if (i == 0)					//检查生成的链表数是否为0	
	{
		head =  p2 = p1 = NULL;
	}
	else
	{
		for (; n < i; n++)		//创建每一个节点都为NULL的链表
		{
			strcpy(p1->date , in ); 
			p1 = (noteOne*)malloc(sizeof(noteOne));
			p2->next = p1;
			p2 = p1;
			

		}

		p2->next = NULL;
		
	}
	

	printf("已为您生成单链表\n");

	return head;

}

noteOne* creat2()		//创建一个双向链表;
{


	int i, n = 0;  //i为想要生成链表数，n为计数器
	char in[20] = "NULL";
	printf("请输入要生成的链表数:");
	scanf("%d", &i);

	noteOne *head, *p1, *p2 ;
	head = p1 = p2 =  (noteOne*)malloc(sizeof(noteOne));
	head->flont = NULL;
	



	if (i == 0)
	{
		head = p1 = p2 =  NULL;
	}
	else
	{
		for (; n < i; n++)
		{
			strcpy(p1->date, in);
			p1 = (noteOne*)malloc(sizeof(noteOne));
			p2->next = p1;
			p1->flont = p2;
			p2 = p1;
		}

	}

	p2 -> next = NULL;


	printf("已为您生成双向链表\n");

	return head;

}

void input(noteOne* head)	//输入数据的函数
{
	noteOne* p = head;
	int a;			//想要在那写入数据
	int i = 1;		//计数器
	int sign = 0;	//标志，是否有所要修改的序号
	char in[40];

	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return;
	}


	if (head == NULL)
	{
	printf("请创建链表\n");
	}
	else
	{
		printf("请输入您想要写入\\修改数据的节点序号\n");
		scanf("%d", &a);
		system("cls");
		

		


		while (p->next != NULL)
		{
			if (i == a)
			{
				sign++;
				printf("请输入内容\n");  //输入内容
				scanf("%s",p->date);
				break;
			}
			i++;
			p = p->next;
			
		}
		if (sign == 0)
		printf("无此序号");
		else
		printf("已储存\n");

	}
	


}

void seek(noteOne* head)	//查找数据的指针
{	
	int flag=0;
	int seek_n;		//所查找的序号
	int i=1;		//节点的序号
	noteOne* p;
	p = head;		
	char forseek[20];
	int choose;		//功能的选择

	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return;
	}

	printf("请输入您查找的方式\n");
	printf("1.根据序号查找\n2.根据内容查找\n");
	scanf("%d",&choose);
	system("cls");

	

	if (head == NULL)
		printf("请先创建链表\n");
		
	else
	{


		switch (choose)
		{
		case 1:
			printf("请输入您所想查找数据的序号\n");
			scanf("%d", &seek_n);
			for (int j = 1; p->next; j++)
			{
				if (j == seek_n)
				{
					flag++;
					printf("%d %s\n", j, p->date);
					break;
				}

				p = p->next;

			}
			if (flag == 0)
				printf("此数据不存在\n");

			break;


		case 2:				//跟据内容查找数据
			printf("请输入您所想查找的数据");
			scanf("%s", forseek);


			while (p->next != NULL)
			{
				if (strcmp(p->date, forseek) == 0)
				{
					flag++;
					printf("%d %s\n", i, p->date);
				}

				i++;
				p = p->next;
			}
			if (flag == 0)
				printf("此数据不存在\n");

			break;
		default:
			printf("输入错误\n");
			break;

		}
		
	}


}

int Total(noteOne* head)
{
	int count = 0;		//数据的个数
	noteOne* p=head;

	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return 0;
	}

	if (head != NULL)
	{
		while (p->next != NULL)
		{
			count++;
			p = p->next;
		}
		
	}
	system("cls");
	return count;
}

void middle(noteOne* head) //查找链表中点的函数
{
	int n = 1;		//记录中点的序号
	int count = 0;  //记录节点个数

	noteOne *p1, *p2, *p3;   //p3是节点数是单数所要用的节点
	 p3 = p1 = p2 = head ;

	if (CircleOrNot(head) == 1)
	 {
		 printf("请将循环链表断开\n");
		 return;
	 }


	 count = Total(head);

	 
	
	if (head == NULL || count == 0 )
	{
		printf("请创建链表\n");
	}
	else
	{
		if (count % 2 != 0)			//判断节点个数是双数还是单数。
		{
			while (p2->next!= NULL)
			{
				p2 = p2->next;
				if (p2->next == NULL)		//会出先上一个命令结束后指针的下一个就是NULL的情况
				break;

				p2 = p2->next;
				
				p1 = p1->next;
				n++;

			}
			printf("此链表的中间节点为序号%d\n", n);
			printf("内容为%s\n", p1->date);

		}
		else if(count != 0 )						//为双数的时候
		{
			
			while (p2->next != NULL)
			{

				p2 = p2->next;
				p2 = p2->next;

				p1 = p1->next;
				if(n!=1)			//p3一个指针比 p1迟一次
				p3 = p3->next;
				n++;

			}
			printf("此链表的中间节点分别为序号%d和%d\n",n-1,n);
			printf("内容分别为%s,%s\n",p3->date,p1->date);



		}
		
	
	
	}


}

noteOne* LinkBE(noteOne* head,int flag)
{
	noteOne * p;
	 p = head;
	 if (CircleOrNot(head) == 1)
		 printf("该链表已是循环链表\n");
	 else
	 {
		 while (p->next != NULL)		//p移动到指针末尾
			 p = p->next;

		 p->next = head;

		 if (flag == 2)  //如果所链接的链表为双向链表
			 head->flont = p;	//将末尾的地址赋值给head->flont
	 }
	return head;
}


int CircleOrNot(noteOne* head)	//判断一个链表是否为循环链表的函数,返回值为0就不是循环链表，返回值是1是循环链表
{

	int flag = 0;
	noteOne *p1, *p2;
	p1 = p2 = head;
	while (p2->next != NULL)
	{
		p2 = p2->next;
		if (p2->next == NULL)
			break;
		p2 = p2->next;

		p1 = p1->next;

		if(p1 == p2)
		{
			flag = 1;
			break;
		}

	}

	return flag;
}

void noCircle(noteOne* head,int flag)  ////将当前的循环指针头和尾断开
{
	if (CircleOrNot(head) == 0)
		printf("该链表不是循环链表\n");

	else
	{
		noteOne* p;
		p = head;
		while (p->next != head)
			p = p->next;

		p->next = NULL;

		if (flag == 2)				//如果为双向链表。加一个步骤
			head->flont = NULL;
	}
}

void cutin(noteOne* head, int flag)			//插入一个接节点
{


	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return;
	}

	noteOne* p1, * p2;
	p1 = p2 = head;
	int n;

	printf("请输入在第几个节点之后插入\n");
	scanf("%d", &n);
	system("cls");

	for (int i = 0; i < n-1; i++)  //将p1移动到目标节点前
	{
		p1 = p1->next;
	}
	p2 = (noteOne*)malloc(sizeof(noteOne));
	strcpy(p2->date , "+NULL");


	if (n == Total(head))		//如果p1是最后一个节点
	p2->next = NULL;			//
	else
	p2->next = p1->next;
	
	if (flag == 2)
	{
		p1->next->flont = p2;   //如果是双链表，则将目标节点的下一个节点的flont赋值p2的地址
		p2->flont = p1;			//将p2的flont赋值p1
	}
	p1->next = p2;
	
	printf("已插入\n");
}

void detele(noteOne* head, int flag)   //删除某一个节点的函数
{
	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return;
	}
	
	int n;
	noteOne* p,* p1;
	p1 = p = head;

	printf("请输入您要删除第几个节点\n");
	scanf("%d", &n);
	system("cls");

	for (int i = 1; i < n; i++)
	{
        p1 = p;
		p = p->next;
	}


	if (n == Total(head) || n==1 )		//如果要删除的指针为最后一个指针或者为第一个节点的时候
		p = NULL;

	p1->next = p->next;

		if (flag == 2)
			p->next->flont = p1;


		printf("已删除该节点\n");
}

void show(noteOne* head)
{
	if (CircleOrNot(head) == 1)
	{
		printf("请将循环链表断开\n");
		return;
	}
	int n = 1;
	noteOne* p;
	p = head;
	while (p->next != NULL)
	{
		printf("%d %s\n", n, p->date);
		p = p->next;
		n++;
	}

}
