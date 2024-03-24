#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>


Status initLStack(LinkStack* s)//��ʼ��ջ
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
	{
	printf("��ʼ��ʧ��\n");
		return ERROR;
	}

	s->top->data = '#';
	s -> count = -1;
	return SUCCESS;


}

Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == NULL || s->count == -1)
	{
		return SUCCESS;  //Ϊ��
	}
	return ERROR;        //��Ϊ��
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!p)
	{
	printf("���ٿռ�ʧ�ܣ�������\n");
		return ERROR;
	}
	p->data = data;			//��������
	p->next = s->top;		//���¿��ٵĽڵ�����һ������ջ�Ľڵ�����
	s->top = p;				//����ͷ��
	s -> count++;			//����
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		return ERROR;
	}
	*data = s->top->data;		//��������
	p = s->top;					//��top����p��������ͷſռ�
	s->top = s->top->next;		//��ָ���ƶ�����һ��ջ
	free(p);
	s->count--;
	return SUCCESS;
}

Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	if (isEmptyLStack(s))
	{
		return ERROR;
	}

	*e = s->top->data;
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	LinkStackPtr p;
	p = s->top;
	int n = 0;									//����

	if (isEmptyLStack(s))
	{
		printf("��ջΪ��ջ\n");
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


Status clearLStack(LinkStack* s)//���ջ
{
	if (isEmptyLStack(s))
	{
		printf("��ջΪ��ջ\n");
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

Status destroyLStack(LinkStack* s)//����ջ
{
	LinkStackPtr p;
	if (isEmptyLStack(s))
	{
		printf("��ջΪ��ջ\n");
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
