#include <iostream>
using namespace std;
//n,n 
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;	
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='0')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
}
void CreateBiTree(BiTree &T,char ch)
{
	if(ch=='0')
		T=NULL;
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}
}
int Traverse(BiTree T1,BiTree T2)
{
	if(T1&&T2)//����дwhile����Ϊ���ǵݹ飬ÿ��ִ��һ�Σ����ǵ��ö�Σ����� 
	{
		if(T1->data!=T2->data)
 		{
			cout<<"NO"<<endl; 
			return -1;//������flag����Ϊ���������elde��һ������ʲô���� ���� 
		}
		else
		{
			Traverse(T1->lchild,T2->lchild);
			Traverse(T1->rchild,T2->rchild);
		}	
	}
}
int main()
{
	while(1)
	{
		char ch;
		cin>>ch;
		if(ch=='0')
			break;
		BiTree T1,T2;
		CreateBiTree(T1,ch);
		CreateBiTree(T2);
		if(Traverse(T1,T2)!=-1)
			cout<<"YES"<<endl;
	}
	return 0;
}
