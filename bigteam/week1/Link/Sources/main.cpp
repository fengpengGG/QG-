#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include<windows.system.h>
#include"tools.h"
#include<string>

int main()
{

	noteOne* head1 = NULL;	//����ͷָ��;
	int Circle = 2;		//��¼�Ƿ�Ϊѭ������0����ѭ������1��ѭ������
	int flag = 0;	//Ϊ��˫������ı�־,1Ϊ��������2Ϊ˫������
	int a=1;		//��¼ѡ���õ�

	do
	{		system("pause");
			system("cls");

		win_toolchoose();//����
		win_ttc();
		scanf("%d", &a);
		system("cls");


		switch (a)
		{
		case 1:					//������������
			;
			head1 = creat1();
			flag = 1;
			break;
		case 2:					//����˫������
			head1 = creat2();
			flag = 2;
			break;

		case 3:					//��������
			seek(head1);
			break;
		case 4:					//ͳ�����ݸ���
			printf("�ڵ����Ϊ%d\n",Total(head1));



			break;
		case 5:					//д�����ݴ���
			input(head1);
			break;	
		case 6:					//Ѱ���нڵ�
			middle(head1);
			break;
		case 7:					//����ǰָ���ͷ��β���ӣ�����ѭ��ָ��
			head1 = LinkBE(head1,flag);
			printf("��Ϊ������\n");

			break;

		case 8:					//��鵱ǰָ���Ƿ�Ϊѭ��ָ��
			Circle = CircleOrNot(head1);
			if (Circle == 0)
			{
				printf("��������ѭ��ָ��\n");
			
			}
			else
			{
				printf("��������ѭ��ָ��\n");

			}
	
			break;
		case 9:					//����ǰ��ѭ��ָ��ͷ��β�Ͽ�
			noCircle(head1, flag);
			printf("�ѶϿ�");


			break;
		case 10:				//����һ���ڵ�
			cutin(head1,flag);
			break;
		case 11:				//ɾ��һ���ڵ�
			detele(head1, flag);
			break;
		case 12:				//��ӡ��������
			show(head1);
			break;
		}

	} while (a > 0 && a < 13);

	system("cls");
	printf("byebye\n");
	system("pause");
}
