#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>


Status initLStack(LinkStack* s)//初始化栈
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
	{
	printf("初始化失败\n");
		return ERROR;
	}

	s->top->data = '#';
	s -> count = -1;
	return SUCCESS;


}

Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->top == NULL || s->count == -1)
	{
		return SUCCESS;  //为空
	}
	return ERROR;        //不为空
}

Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p)
	{
	printf("开辟空间失败，请重试\n");
		return ERROR;
	}
	p->data = data;			//传入数据
	p->next = s->top;		//将新开辟的节点与上一个进入栈的节点相连
	s->top = p;				//重设头顶
	s -> count++;			//计数
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		return ERROR;
	}
	*data = s->top->data;		//传出数据
	p = s->top;					//将top传给p方便后续释放空间
	s->top = s->top->next;		//将指针移动到上一个栈
	free(p);
	s->count--;
	return SUCCESS;
}

Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
	if (isEmptyLStack(s))
	{
		return ERROR;
	}

	*e = s->top->data;
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	LinkStackPtr p;
	p = s->top;
	int n = 0;									//长度

	if (isEmptyLStack(s))
	{
		printf("此栈为空栈\n");
		*length = n;
		return ERROR;
	}

	while (p!= NULL)
	{
		n++;
		p = p->next;
	}

	*length = n;
	return SUCCESS;

}


Status clearLStack(LinkStack* s)//清空栈
{
	if (isEmptyLStack(s))
	{
		printf("此栈为空栈\n");
		return ERROR;
	}
	
	LinkStackPtr p = s->top;
	

	while (p!= NULL)
	{
		p->data = 0;
		p = p->next;
	}
	return SUCCESS;
	

}

Status destroyLStack(LinkStack* s)//销毁栈
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		printf("此栈为空栈\n");
		return ERROR;
	}


	while (s->top!= NULL)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;
	}


	return SUCCESS;
}
