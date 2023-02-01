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
		
		//��ֵ 
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
 
void FindFavouriteBooks(LinkList &L)
{
	//������洢����������
	string bookname[10];
	//�ҵ����飬����fav������
	LinkList favouritebooks[5]; 
	
	//����n��Ŀ�� 
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>bookname[i];
	}
	
	//����ָ�� 
	LinkList p;
	//������k:��¼�ҵ��������Ŀ
	int k=0;
	for(int j=0;j<n;j++)
	{ 
		//��ʼ�����ҵ��������Ŀ 
		k=0;
		//����ͷ�ڵ㿪ʼ���� 
		p=L->next;
		while(p)
		{
			if(p->data.name==bookname[j])
			{
				favouritebooks[k]=p;//�ɹ��ȶԣ����ҵ���Ŀ��Ԫ�صĵ�ַ����favouritebooks������ 
				k++;
			}			
			p=p->next;
		}
		if(k==0)
			cout<<"Sorry��there is no your favourite!"<<endl;
		else
		{
			cout<<k<<endl;
			for(int i=0;i<k;i++)
				cout<<favouritebooks[i]->data.no<<" "<<favouritebooks[i]->data.name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<favouritebooks[i]->data.price<<endl;
		}
	}
	
}
 
int main()
{
	LinkList L;
	CreateList_R(L);
	FindFavouriteBooks(L); 
	return 0;
}

