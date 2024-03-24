#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>
#include<windows.system.h>
#include<string.h>
#include<ctype.h>

//m����׺�ַ���
//b�Ǻ�׺�ַ���
void turn(char *m, int *b)		//����׺ת��Ϊ��׺
{
	int e;

	LinkStack Lk;
	LinkStack* s = &Lk;
	initLStack(s);		//��ʼ��
	int j = 0;
	int i;
	for (i = 0; i < strlen(m); i++)
	{

		if (m[i] <= '9' && m[i] >= '0')				//��charת��Ϊint
		{
			e = m[i] - 48;
			i++;
			while (m[i] <= '9' && m[i] >= '0')
			{
				e = e * 10 + (m[i] - 48);
				i++;
			}
			b[j] = e;
			j++;									//����
		}

		//�����(ֱ�ӽ�ջ
		if (m[i] == '(')
		{
			pushLStack(s, m[i]);
		}

		//�����)ջ�ڵ�ֱ��ȫ����ջ
		if (m[i] == ')')
		{
			while (s->top->data != '(')
			{
				popLStack(s, &e);
				b[j] = e;
				j++;			
			}
			popLStack(s,&e);		//�ͷ�(
		}


		//������+ -
		//����ǿ�ջ������(�����ţ�ֱ�ӽ�ջ)
		//��ջ
		if (m[i] == '+' || m[i] == '-')
		{
			while (!isEmptyLStack(s) && s->top->data != '(')
			{
				popLStack(s, &e);
				b[j] = e;
				j++;
			}
			pushLStack(s, m[i]);		//��ջ
			
		}
		//���������* / 
		//����ǿ�ջ�������ţ�ջ����+-��ֱ�ӽ�ջ������һֱ��ջ

		if (m[i] == '*' || m[i] == '/')
		{
			while (!isEmptyLStack(s) && s->top->data != '(' && s->top->data != '+' && s->top->data != '-')
			{
				popLStack(s, &e);
				b[j] = e;
				j++;
			}
			pushLStack(s, m[i]);
		}



	}
	while (!isEmptyLStack(s))		//��ʣ���ȫ�����
	{

		popLStack(s, &e);
		if (e != '(')
		{
			b[j] = e;
			j++;
		}

	}

	b[j--] = '\0';
}

int cal(int* b)
{

	LinkStack Lk;
	LinkStack* s = &Lk;
	initLStack(s);		//��ʼ��
	int top1,top2;		//ջ��Ԫ��
	int result = 0;

	int i = 0;
	for (i = 0; b[i] != '\0'; i++)
	{
		switch (b[i])
		{
		case '+':	
			popLStack(s, &top1);
			popLStack(s, &top2);
			result = top2 + top1;
			pushLStack(s, result);
			break;
		case '-':
			popLStack(s, &top1);
			popLStack(s, &top2);
			result = top2 - top1;
			pushLStack(s, result);
			break;
		case '*':
			popLStack(s, &top1);
			popLStack(s, &top2);
			result = top2 * top1;
			pushLStack(s, result);
			break;
		case '/':
			popLStack(s, &top1);
			popLStack(s, &top2);
			result = top2 / top1;
			pushLStack(s, result);
			break;
		default:
			pushLStack(s, b[i]);
			
			break;
		}

	}
	
	return result;
}

int main()
{

	char m[1000] = { 1 };		//��׺���ʽ
	int b[1000];		//��׺���ʽ
	int choose = 1;

	while (choose == 1)
	{
		choose = 0;
		printf("��������ȷ�ı��ʽ(����һ��0�˳�����)\n���Զ�����Ӣ���磺1jdf+dsa1������2\n");
		scanf("%s", m);
		turn(m, b);
		//	for(int i = 0;b[i]!='\0'; i++)
		//	printf("%d\n", b[i]);
		printf("%d\n", cal(b));

		system("pause");
		system("cls");
		printf("�Ƿ�ʹ�øó���\n�ǵĻ����1�ӻس�,�˳������۸���\n");
		scanf("%d",&choose);
		system("cls");
	}

return 0;
}



