#include<iostream.h>

typedef struct LNode{
		 int data;
 struct LNode *next;}LNode,*LinkList;
/*void CreatList(LinkList &L){
	int i,n;LinkList p;
	L=new LNode;
	L->next=NULL;
	cin>>n; //�������������Ԫ�صĸ���	
	for(i=0;i<n;i++){
		p= new LNode;
		cin>>p->data.name>>p->data.price;      //�������ͼ����Ϣ
		p->next=L->next; L->next=p;       }    //���뵽��ͷ	
}*/

void CreatList(LinkList &p){
	int n;
	cin>>n; //��������ֵ������0���˳�
	if (n==0)  p=NULL;
    else{
		p=new LNode;
		p->data=n;
		CreatList(p->next);
	}
}

void Output(LinkList &p){
	if (p==NULL) return;
    else{
		cout<<p->data<<' ';
		Output(p->next);
	}
}

/*
 LNode* node = (LNode *) malloc (sizeof(LNode));//�����½ڵ�
 L.next = node;    //ָ������
 node ->data = n;   //������װ
 node ->next = NULL;   //β�ڵ㸳��

 create(L, n);    //�����ݹ�
}
*/
void Min (LinkList L ){
	LinkList pmin,p;
	if(L->next==NULL) return ;
	pmin=L->next; 	p=L->next->next;
	while(p != NULL ){
		if(p->data<pmin->data) pmin=p;
		p=p->next;	}
   cout<<"����˵�ͼ����:"<<pmin->data<<endl; 	
}
void main( ){	  
	  LinkList  L;
	  L=new LNode;
	  L->next=NULL;
	  CreatList(L->next);//����������	  
	  Output(L->next);
	  Min(L);   //�������˵�ͼ��
 }