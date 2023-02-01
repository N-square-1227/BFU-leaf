#include <iostream>
#include<iomanip>
using namespace std;
#define MAXSIZE 10000
 
typedef struct 
{
	string no;
	string name;
	double price;
}Book;
 
typedef struct LNode
{
	Book data;
	struct LNode *next;
}LNode,*LinkList;
 
void CreateList_R(LinkList &L)
{
	//βָ��rear 
	LinkList r; 
	//�½ڵ�ָ��p 
	LinkList p;
	
	//����ͷ�ڵ㲢��ʼ����ָ����Ϊ�� 
	L=new LNode;
	L->next=NULL;
	
	//��ʼ��βָ��ָ��ͷ�ڵ� 
	r=L;
	
	int n;
	cin>>n;
	
	int i=0;
	while(1) 
	{
		//�½ڵ�ָ�븺�𴴽��½ڵ� 
		p=new LNode;
		//�½ڵ㣨p����ʼ�� ��ָ��� 
		p->next=NULL;
		
		
		string a,b;
		double c;
		cin>>a>>b>>c;
		p->data.no=a;
		p->data.name=b;
		p->data.price=c; 
		
		//βָ��ָ��Ľڵ㣨r->next��ָ���½ڵ㣨p�� 
		r->next=p;
		//βָ�루r��ָ���½ڵ� ��p�� 
		r=p;
		
		i++;
		if(i==n) break;
	}
	return;
}
 
void FindMostExpensiveBooks(LinkList &L)
{
	LinkList p;
	//Խ��ͷ�ڵ㣬�ӵ�һ���ڵ㿪ʼ 
	p=L->next;
	//һ�����ڵ� 
	LinkList max=p;
	//�����ֵͬ�����ڵ� 
	LinkList maxs[3];//ʹ��û�г�ʼ����ָ�뽫�����޷�Ԥ�ϵĽ��
	
	//�������� 
	while(p)
	{
		//���������нڵ����������ڵ����̨ 
		if(p->data.price > max->data.price)
		{
			//�����ڵ�ָ�뱣��һ�����ڵ�ĵ�ַ 
			max=p;
		}
		//������һ���ڵ� 
		p=p->next;
	}
	
	//Խ��ͷ�ڵ㣬�ӵ�һ���ڵ㿪ʼ 
	p=L->next;
	//���ڵ���ͳ�� 
	int k=0;
	//��������	
	while(p)	
	{
		//����������е������ڵ�������ڵ� 
		if(p->data.price==max->data.price)
		{
			//�������ڵ����� 
			maxs[k]=p;
			k++;
		}
		//������һ���ڵ� 
		p=p->next;
	}
	
	cout<<k<<endl;
	int i=0;
	while(maxs[i]&&i<k)
	{
		cout<<maxs[i]->data.no<<" "<<maxs[i]->data.name<<" ";
		cout<<fixed<<setprecision(2)<<maxs[i]->data.price<<endl;
		i++;
	}
 
}
 
int main()
{
	LinkList L;
	CreateList_R(L);
	FindMostExpensiveBooks(L);
	return 0;
}

