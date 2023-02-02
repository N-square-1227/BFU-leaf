#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
//********************PCB����********************
typedef struct PCB{
	int name;		//�����ֶ����ݿ���
	int state;		//��״̬Ϊ0��1
	int prior;		//���ȼ�
	int time;		//��Ҫ�ڴ������ִ�е�ʱ��
}PCB;
//*******************���еĶ���*******************
typedef struct QNode{
	PCB   data;
    struct QNode  *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr  front;            //��ͷָ��   
    QueuePtr  rear;             //��βָ��
}LinkQueue;  
//********************��ʼ������********************
int InitQueue(LinkQueue &Q){
    Q.front=Q.rear=new QNode; 
    if(!Q.front) 
		exit(0);
	Q.front->next=NULL;
    return 1;
}
//********************���********************
int EnQueue(LinkQueue &Q,PCB e){
	QueuePtr p;
    p=new QNode;
    if(!p) 
		exit(0);
    p->data=e; 
	p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return 1;
}
//********************����********************
int DeQueue(LinkQueue &Q,PCB &e){
	QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(Q.front==Q.rear) 
		return 0;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p) 
		Q.rear=Q.front;
    free(p);
    return 1;
}
//********************�ж϶����Ƿ�Ϊ��********************
int QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
		return 0;    
	else
		return 1;
}
