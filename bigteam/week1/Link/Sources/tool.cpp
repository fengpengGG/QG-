#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<windows.system.h>
#include"tools.h"

noteOne* creat1()
{
	
	int i , n = 0;  //iΪ��Ҫ������������nΪ������

	char in[20]="NULL"; 

	printf("������Ҫ���ɵ�������:");
	scanf("%d", &i);

	noteOne* head, *p1, * p2;
	head = p2 = p1 = (noteOne*)malloc(sizeof(noteOne));

	if (i == 0)					//������ɵ��������Ƿ�Ϊ0	
	{
		head =  p2 = p1 = NULL;
	}
	else
	{
		for (; n < i; n++)		//����ÿһ���ڵ㶼ΪNULL������
		{
			strcpy(p1->date , in ); 
			p1 = (noteOne*)malloc(sizeof(noteOne));
			p2->next = p1;
			p2 = p1;
			

		}

		p2->next = NULL;
		
	}
	

	printf("��Ϊ�����ɵ�����\n");

	return head;

}

noteOne* creat2()		//����һ��˫������;
{


	int i, n = 0;  //iΪ��Ҫ������������nΪ������
	char in[20] = "NULL";
	printf("������Ҫ���ɵ�������:");
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


	printf("��Ϊ������˫������\n");

	return head;

}

void input(noteOne* head)	//�������ݵĺ���
{
	noteOne* p = head;
	int a;			//��Ҫ����д������
	int i = 1;		//������
	int sign = 0;	//��־���Ƿ�����Ҫ�޸ĵ����
	char in[40];

	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
		return;
	}


	if (head == NULL)
	{
	printf("�봴������\n");
	}
	else
	{
		printf("����������Ҫд��\\�޸����ݵĽڵ����\n");
		scanf("%d", &a);
		system("cls");
		

		


		while (p->next != NULL)
		{
			if (i == a)
			{
				sign++;
				printf("����������\n");  //��������
				scanf("%s",p->date);
				break;
			}
			i++;
			p = p->next;
			
		}
		if (sign == 0)
		printf("�޴����");
		else
		printf("�Ѵ���\n");

	}
	


}

void seek(noteOne* head)	//�������ݵ�ָ��
{	
	int flag=0;
	int seek_n;		//�����ҵ����
	int i=1;		//�ڵ�����
	noteOne* p;
	p = head;		
	char forseek[20];
	int choose;		//���ܵ�ѡ��

	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
		return;
	}

	printf("�����������ҵķ�ʽ\n");
	printf("1.������Ų���\n2.�������ݲ���\n");
	scanf("%d",&choose);
	system("cls");

	

	if (head == NULL)
		printf("���ȴ�������\n");
		
	else
	{


		switch (choose)
		{
		case 1:
			printf("������������������ݵ����\n");
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
				printf("�����ݲ�����\n");

			break;


		case 2:				//�������ݲ�������
			printf("��������������ҵ�����");
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
				printf("�����ݲ�����\n");

			break;
		default:
			printf("�������\n");
			break;

		}
		
	}


}

int Total(noteOne* head)
{
	int count = 0;		//���ݵĸ���
	noteOne* p=head;

	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
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

void middle(noteOne* head) //���������е�ĺ���
{
	int n = 1;		//��¼�е�����
	int count = 0;  //��¼�ڵ����

	noteOne *p1, *p2, *p3;   //p3�ǽڵ����ǵ�����Ҫ�õĽڵ�
	 p3 = p1 = p2 = head ;

	if (CircleOrNot(head) == 1)
	 {
		 printf("�뽫ѭ������Ͽ�\n");
		 return;
	 }


	 count = Total(head);

	 
	
	if (head == NULL || count == 0 )
	{
		printf("�봴������\n");
	}
	else
	{
		if (count % 2 != 0)			//�жϽڵ������˫�����ǵ�����
		{
			while (p2->next!= NULL)
			{
				p2 = p2->next;
				if (p2->next == NULL)		//�������һ�����������ָ�����һ������NULL�����
				break;

				p2 = p2->next;
				
				p1 = p1->next;
				n++;

			}
			printf("��������м�ڵ�Ϊ���%d\n", n);
			printf("����Ϊ%s\n", p1->date);

		}
		else if(count != 0 )						//Ϊ˫����ʱ��
		{
			
			while (p2->next != NULL)
			{

				p2 = p2->next;
				p2 = p2->next;

				p1 = p1->next;
				if(n!=1)			//p3һ��ָ��� p1��һ��
				p3 = p3->next;
				n++;

			}
			printf("��������м�ڵ�ֱ�Ϊ���%d��%d\n",n-1,n);
			printf("���ݷֱ�Ϊ%s,%s\n",p3->date,p1->date);



		}
		
	
	
	}


}

noteOne* LinkBE(noteOne* head,int flag)
{
	noteOne * p;
	 p = head;
	 if (CircleOrNot(head) == 1)
		 printf("����������ѭ������\n");
	 else
	 {
		 while (p->next != NULL)		//p�ƶ���ָ��ĩβ
			 p = p->next;

		 p->next = head;

		 if (flag == 2)  //��������ӵ�����Ϊ˫������
			 head->flont = p;	//��ĩβ�ĵ�ַ��ֵ��head->flont
	 }
	return head;
}


int CircleOrNot(noteOne* head)	//�ж�һ�������Ƿ�Ϊѭ������ĺ���,����ֵΪ0�Ͳ���ѭ����������ֵ��1��ѭ������
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

void noCircle(noteOne* head,int flag)  ////����ǰ��ѭ��ָ��ͷ��β�Ͽ�
{
	if (CircleOrNot(head) == 0)
		printf("��������ѭ������\n");

	else
	{
		noteOne* p;
		p = head;
		while (p->next != head)
			p = p->next;

		p->next = NULL;

		if (flag == 2)				//���Ϊ˫��������һ������
			head->flont = NULL;
	}
}

void cutin(noteOne* head, int flag)			//����һ���ӽڵ�
{


	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
		return;
	}

	noteOne* p1, * p2;
	p1 = p2 = head;
	int n;

	printf("�������ڵڼ����ڵ�֮�����\n");
	scanf("%d", &n);
	system("cls");

	for (int i = 0; i < n-1; i++)  //��p1�ƶ���Ŀ��ڵ�ǰ
	{
		p1 = p1->next;
	}
	p2 = (noteOne*)malloc(sizeof(noteOne));
	strcpy(p2->date , "+NULL");


	if (n == Total(head))		//���p1�����һ���ڵ�
	p2->next = NULL;			//
	else
	p2->next = p1->next;
	
	if (flag == 2)
	{
		p1->next->flont = p2;   //�����˫������Ŀ��ڵ����һ���ڵ��flont��ֵp2�ĵ�ַ
		p2->flont = p1;			//��p2��flont��ֵp1
	}
	p1->next = p2;
	
	printf("�Ѳ���\n");
}

void detele(noteOne* head, int flag)   //ɾ��ĳһ���ڵ�ĺ���
{
	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
		return;
	}
	
	int n;
	noteOne* p,* p1;
	p1 = p = head;

	printf("��������Ҫɾ���ڼ����ڵ�\n");
	scanf("%d", &n);
	system("cls");

	for (int i = 1; i < n; i++)
	{
        p1 = p;
		p = p->next;
	}


	if (n == Total(head) || n==1 )		//���Ҫɾ����ָ��Ϊ���һ��ָ�����Ϊ��һ���ڵ��ʱ��
		p = NULL;

	p1->next = p->next;

		if (flag == 2)
			p->next->flont = p1;


		printf("��ɾ���ýڵ�\n");
}

void show(noteOne* head)
{
	if (CircleOrNot(head) == 1)
	{
		printf("�뽫ѭ������Ͽ�\n");
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
