#pragma once
typedef struct NoteOne	//��˫������һ��ͷָ��
{
	struct NoteOne* flont;
	char date[40];
	struct NoteOne* next;
}noteOne;


void win_ttc();			//�������ں���
void win_toolchoose();	//

noteOne *creat1();	//������������ĺ���
noteOne *creat2();	//����˫������

noteOne *LinkBE(noteOne* head,int flag);	//����ͷ��β�ĺ���


void seek(noteOne* head);	//��������ĺ���
int Total(noteOne* head);	//ͳ�ƽڵ����ĺ���,����ֵΪ�ڵ���� 
void input(noteOne* head);  //д��һ������
void cutin(noteOne* head, int flag);  //����һ������
void detele(noteOne* head,int flag);	//ɾ��һ������
int CircleOrNot(noteOne* head);//����Ƿ�Ϊѭ������,����ֵΪ0�Ͳ���ѭ����������ֵ��1��ѭ������
void noCircle(noteOne* head,int flag);	//��ѭ�������ͷ��β�жϡ�
void middle(noteOne* head);		//�����м�ڵ�
void show(noteOne* head);		//��ʾ���нڵ�

 