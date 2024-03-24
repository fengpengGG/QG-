#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)



#include<stdio.h>
#include"Queue.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char type = '?';
char datatype[30];

void InitLQueue(LQueue* Q)		//初始化链队
{
    Node * p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return;
	Q->front = Q->rear = p;
	Q->length = 0;
	Q->rear->next = NULL;
}


Status IsEmptyLQueue(const LQueue* Q)		//判判断是否为空
{
	if (Q->front == Q->rear == NULL)
	{
		return TRUE;
	}
	return FALSE;
}


Status EnLQueue(LQueue* Q, void* data)		//入队
{
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	if (!p)
	{
		return FALSE;
	}
	p->data = data;
	p->next = NULL;
	Q->rear->next = p;	//指针前后连接
	Q->rear = p;		//将未指针后移
	Q->length++;

	return TRUE;
}

void DestoryLQueue(LQueue* Q)				//销毁对列
{
	 Node *p = Q->front;
	for (;p;p = Q->front)						//一个一个节点free
	{
		Q->front = Q->front->next;
		free(p);
	}
}

int LengthLQueue(LQueue* Q)						//确定长度
{
	int L = 0;
	Node* p = Q->front->next;
	while (p != Q->rear)
	{
		p = p->next;
		L++;
	}
	return L;
	
}

void ClearLQueue(LQueue* Q)		//清空对列
{
	Node* p;
	for (p = Q->front->next;p;p = p->next)			//保留头的节点
	{
		free(p);
		Q->length--;
	}
	Q->rear = Q->front;

}

Status DeLQueue(LQueue* Q)							//出队
{

	if(IsEmptyLQueue(Q))			//判断空否
	{
		return FALSE;
	}
		
	Node* p;
	p = Q->front->next;				//中间节点		Q->front Q->front->next/p p->next
	Q->front->next = p->next;		//跳过中间节点		Q->front     (p)     p->next			
	if (Q->front->next == NULL)		//如果头的下一个是NULL的，就空了,或者p == Q -> rear时
	{
		Q->rear = Q->front;
	}
	free(p);
	Q->length--;
	return TRUE;
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	//复制内存
	e = Q->front->next->data;

	return TRUE;

}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))		//遍历节点
{
	if (IsEmptyLQueue(Q))
		return FALSE;

	Node* p = Q->front->next;
	for (p; p; p = p->next)
	{
		foo(p->data);
	}
	printf("\n");
	return TRUE;
}

void LPrint(void* q)
{

	if (type == 'i')
		printf("%d", *(int*)q);
	else if (type == 'f')
		printf("%.2f", *(float*)q);
	else if (type == 's')
		printf("%s", (char*)q);
}


int main()
{
	LQueue Q;
	InitLQueue(&Q);		//初始化
	char f[] = "float", s[]="string";
	while (type == '?')
	{
		printf("请输入您所要输入的数据类型\n输入string,float\n");		//选择要输入的数据类型
		scanf("%s", datatype, 30);
		 if (strcmp(f, datatype) == 0)
		{
			type = 'f';
		}
		else if (strcmp(s, datatype) == 0)
		{
			type = 's';
		}
		else
		{
			 printf("无此类型,请重新输入\n");
			 system("pause");
			 system("cls");

		}
	}

	system("cls");

	int choose;
	do
	{
		void* data;
		printf("请输入你所选择的功能当前的数据类型为（%s）\n",datatype);
		printf("1.进队  2.出队  3.清空队  4.销毁队  5.求队的长度  6.得到队顶数据  7.退出\n");
		
		scanf("%d", &choose);
		while ((getchar()) != '\n');

		system("cls");
		switch (choose)
		{
		case 1:
			printf("请输入数据\n");
			if (type == 'f')
			{
				data = (float*)malloc(sizeof(float));
				scanf("%f", (float*)data);
			}
			else
			{
				data = (char*)malloc(30 * sizeof(char));
				scanf("%s", (char*)data, 30);
			}

			EnLQueue(&Q, data);
			printf("入队成功\n");
			system("pause");
			system("cls"); break;
		case 2:
			DeLQueue(&Q);
			printf("出队成功\n");
			system("pause");
			system("cls");
			break;
		case 3:
			ClearLQueue(&Q);
			printf("清空成功\n");
			system("pause");
			system("cls");
			break;
		case 4:
			DestoryLQueue(&Q);
			printf("销毁成功\n");
			system("pause");
			system("cls");
			break;
		case 5:
			printf("长度为%d\n", LengthLQueue(&Q));
			system("pause");
			system("cls");
			break;
		case 6:
			GetHeadLQueue(&Q, &data);
			LPrint(data);
			system("pause");
			system("cls");
			break;

		default:
			if(choose !=7)
			{ 
				printf("请重新输入\n");
				system("pause");
				system("cls");
			}
			break;
		}
		if (choose == 7)
			break;
	} while (1);




	system("pause");
	return 0;


}