#pragma once
typedef struct NoteOne	//单双链表公用一个头指针
{
	struct NoteOne* flont;
	char date[40];
	struct NoteOne* next;
}noteOne;


void win_ttc();			//两个窗口函数
void win_toolchoose();	//

noteOne *creat1();	//创建单向链表的函数
noteOne *creat2();	//创建双向链表

noteOne *LinkBE(noteOne* head,int flag);	//链接头和尾的函数


void seek(noteOne* head);	//查找链表的函数
int Total(noteOne* head);	//统计节点数的函数,返回值为节点个数 
void input(noteOne* head);  //写入一个数据
void cutin(noteOne* head, int flag);  //插入一个链表
void detele(noteOne* head,int flag);	//删除一个链表
int CircleOrNot(noteOne* head);//检查是否为循环链表,返回值为0就不是循环链表，返回值是1是循环链表
void noCircle(noteOne* head,int flag);	//将循环链表的头和尾切断。
void middle(noteOne* head);		//查找中间节点
void show(noteOne* head);		//显示所有节点

 