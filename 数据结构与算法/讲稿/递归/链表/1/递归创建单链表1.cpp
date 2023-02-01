#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;


void CreatList(LinkList &L,int n)
{
	LinkList p;
	if(n==0)
		return ;
	else
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		L->next=p;
		CreatList(p,n-1);
	}
}
/*
void Output(LinkList L)
{
	LinkList p=L;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}

}
*/


void Output(LinkList L)
{
	if(L)
	{
		cout<<L->data<<endl;
		Output(L->next);
	}

}

LinkList reverse(LinkList p)
{
	LinkList q,h;
	if(p->next == NULL) return p; // ������ֻ��һ����㣬��ת���ͷָ�벻��
	else
	{
		q = p->next; // qΪ����(a2,an)��ͷָ��
		h = reverse(q); // ��ת����(a2,an)����������ת���ͷָ��
		q->next = p; // ��a1������a2֮��
		p->next = NULL;
		return h; // (a2,,an)��ת���ͷָ�뼴Ϊ(a1,a2,,an)
	}
}

int main()
{
	LinkList L;
	L=new LNode;
	L->next=NULL;
	cout<<"����5����:\n";
	CreatList(L,5);
	Output(L->next);
	return 0;
}