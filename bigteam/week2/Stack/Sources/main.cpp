#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>
#include<windows.system.h>
#include<string.h>
#include<ctype.h>

//m是中缀字符串
//b是后缀字符串
void turn(char *m, int *b)		//将中缀转化为后缀
{
	int e;

	LinkStack Lk;
	LinkStack* s = &Lk;
	initLStack(s);		//初始化
	int j = 0;
	int i;
	for (i = 0; i < strlen(m); i++)
	{

		if (m[i] <= '9' && m[i] >= '0')				//将char转化为int
		{
			e = m[i] - 48;
			i++;
			while (m[i] <= '9' && m[i] >= '0')
			{
				e = e * 10 + (m[i] - 48);
				i++;
			}
			b[j] = e;
			j++;									//后移
		}

		//如果是(直接进栈
		if (m[i] == '(')
		{
			pushLStack(s, m[i]);
		}

		//如果是)栈内的直接全部出栈
		if (m[i] == ')')
		{
			while (s->top->data != '(')
			{
				popLStack(s, &e);
				b[j] = e;
				j++;			
			}
			popLStack(s,&e);		//释放(
		}


		//遇到了+ -
		//如果是空栈或者是(左括号，直接进栈)
		//出栈
		if (m[i] == '+' || m[i] == '-')
		{
			while (!isEmptyLStack(s) && s->top->data != '(')
			{
				popLStack(s, &e);
				b[j] = e;
				j++;
			}
			pushLStack(s, m[i]);		//进栈
			
		}
		//如果遇到了* / 
		//如果是空栈，左括号，栈顶是+-，直接进栈，否则一直出栈

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
	while (!isEmptyLStack(s))		//把剩余的全部输出
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
	initLStack(s);		//初始化
	int top1,top2;		//栈顶元素
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

	char m[1000] = { 1 };		//中缀表达式
	int b[1000];		//后缀表达式
	int choose = 1;

	while (choose == 1)
	{
		choose = 0;
		printf("请输入正确的表达式(输入一个0退出程序)\n会自动跳过英文如：1jdf+dsa1结结果是2\n");
		scanf("%s", m);
		turn(m, b);
		//	for(int i = 0;b[i]!='\0'; i++)
		//	printf("%d\n", b[i]);
		printf("%d\n", cal(b));

		system("pause");
		system("cls");
		printf("是否还使用该程序\n是的话请扣1加回车,退出请随便扣个数\n");
		scanf("%d",&choose);
		system("cls");
	}

return 0;
}



