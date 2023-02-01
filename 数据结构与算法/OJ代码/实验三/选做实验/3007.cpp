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
vector<char> ans(100);
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
void DFSTraverse(BTree bt,int x)
{
	if (bt)
	{
		ans[x] = bt->data;//�����ǰ�ڵ���ڣ���ô�ʹ��������ߣ�������·�����ڵڼ����ߵ��������±꣩�洢��
		if (!bt->lchild && !bt->rchild)//��Ҷ�ӽڵ㣬��ô�������������Ľ����
		{
			for (int i = x; i >= 1; i--)//�����Ǵ�Ҷ�ӵ���������Ҫ���������xһ��ʼ������1�����Ե�1��ֹ
				cout << ans[i];
			cout << endl;
		}
        /*
        �ص㣺
        	 ��ʲôʱ��Ҫ�ٴε����㷨��
        	 �ش���һ�룬DFS������������ȱ������㷨�����������֪ʶ����һ�£���������ȡ���״��Ƕ��㷨��Ӧ�÷�Χ�������Ƶģ��㷨�������ǡ�������������DFS�ǡ������������㷨������ôҪ���������ڵ��ʱ��ͻ���Ȼ��Ȼ���õ�DFS�ˡ���ӳ����Ŀ����ǣ��������Ҷ�ӽڵ㣬����Ҫ��������������ʱ�򣬾ͻ��������
        	 
        	 �����㷨��ʱ��ÿ�������ĺ��嶼��ʲô������δ����㷨�еĲ���������ȷ�ģ�
        	 �ش�������Ҫ�ѡ���ͼ������ȥ�ɣ����������ԣ��ڶ���������������Ҫ��ϸ�����ġ����ȴ������Ŀ��������ͬһ��������Ҷ�ӽڵ���ans�л��������ǣ���Ϊ·������һ���������±�һ���������ڱ�����Ҷ�ӽڵ��ʱ�򣬻��Զ�������һ�δ������Ҷ�ӽڵ����Ϣ�������Զ�Ҷ�ӽڵ���˵���������ߵ���else��������������õ�DFS�����ԣ��ٿ���ͨ�ڵ㣺��������˳��ģ�ÿһ�ε��ö�˵��������һ�����������֮�䲻�����ǣ�����Ҫ��ans[x]��˳��洢����Ҫ��ÿ�ε���DFS��ʱ��֤xÿ�ζ���1���Ա����½ڵ�浽�¿ռ�����Դ𰸾͸���ˮ���ˡ����ڶ�������дx+1.
        */
		else
		{
			DFSTraverse(bt->lchild,x+1);
			DFSTraverse(bt->rchild,x+1);
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
        /////////////////////
		int x = 0;//x�ʹ����˵�ǰ�Ѿ��߹����ĸ���������Ϊx�ǵ����ģ���ÿ�ε��ö�ֻ��1�����Ծ��൱�ڱ���ļ�¼��ÿһ������˭����ȡ��
		DFSTraverse(b, x+1);//������ʵһ��ʼ�ǰ�1����ȥ��
        /////////////////////
    }
	return 0;
}
