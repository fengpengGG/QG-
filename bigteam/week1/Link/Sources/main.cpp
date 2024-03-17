#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include<windows.system.h>
#include"tools.h"
#include<string>

int main()
{

	noteOne* head1 = NULL;	//链表头指针;
	int Circle = 2;		//记录是否为循环链表，0不是循环链表，1是循环链表
	int flag = 0;	//为单双向链表的标志,1为单向链表，2为双向链表
	int a=1;		//记录选项用的

	do
	{		system("pause");
			system("cls");

		win_toolchoose();//窗口
		win_ttc();
		scanf("%d", &a);
		system("cls");


		switch (a)
		{
		case 1:					//创建单向链表
			;
			head1 = creat1();
			flag = 1;
			break;
		case 2:					//创建双向链表
			head1 = creat2();
			flag = 2;
			break;

		case 3:					//查找数据
			seek(head1);
			break;
		case 4:					//统计数据个数
			printf("节点个数为%d\n",Total(head1));



			break;
		case 5:					//写入数据储存
			input(head1);
			break;	
		case 6:					//寻找中节点
			middle(head1);
			break;
		case 7:					//将当前指针的头和尾链接，构建循环指针
			head1 = LinkBE(head1,flag);
			printf("已为您链接\n");

			break;

		case 8:					//检查当前指针是否为循环指针
			Circle = CircleOrNot(head1);
			if (Circle == 0)
			{
				printf("该链表不是循环指针\n");
			
			}
			else
			{
				printf("该链表是循环指针\n");

			}
	
			break;
		case 9:					//将当前的循环指针头和尾断开
			noCircle(head1, flag);
			printf("已断开");


			break;
		case 10:				//插入一个节点
			cutin(head1,flag);
			break;
		case 11:				//删除一个节点
			detele(head1, flag);
			break;
		case 12:				//打印所有链表
			show(head1);
			break;
		}

	} while (a > 0 && a < 13);

	system("cls");
	printf("byebye\n");
	system("pause");
}
