#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef struct BNode
{
	char data;
	struct BNode* lchild, * rchild;
}*BTree, BNode;
vector<char> path(100),ans(100);
int maxi;
void Create(BTree& bt)
{
	char c;
	cin >> c;
	if (c == '0')
		bt = NULL;
	else
	{
		bt = new BNode;
		bt->data = c;
		Create(bt->lchild);
		Create(bt->rchild);
	}
}
void Create(BTree& bt, char c)
{
	if (c == '0')
		bt = NULL;
	else
	{
		bt = new BNode;
		bt->data = c;
		Create(bt->lchild);
		Create(bt->rchild);
	}
}
void DFSTraverse(BTree bt, int x)
{
	if (bt)
	{
		path[x] = bt->data;
		if (!bt->lchild && !bt->rchild)
		{//����Ҷ�ӽڵ�
			if (x > maxi)
			{
				maxi = x;
				for (int i = 1; i <= x; i++)
					ans[i] = path[i];
			}
		}
		else
		{
			DFSTraverse(bt->lchild, x + 1);
			DFSTraverse(bt->rchild, x + 1);
		}
	}
}
int main()
{
	while (1)
	{
		char c;
		cin >> c;
		if (c == '0')
			break;
		BTree b;
		Create(b, c);
		int x = 0;
		DFSTraverse(b, x + 1);
		cout << maxi << endl;
		//������Ҫ��maxi��Ϊ����ѭ������ֵֹ�ģ���ΪDFS�У����Ĳ�����x������&x��x��ֵ����û�иı䣬��Ȼ��0��
		for (int i = 1; i <= maxi; i++)
			cout << ans[i];
		cout << endl;
		maxi = 1;
	}
	return 0;
}
