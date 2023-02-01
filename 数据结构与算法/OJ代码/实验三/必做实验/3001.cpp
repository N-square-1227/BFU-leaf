#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
/*BGM�� ��û�й�������û�����й���
		������ɽС����
		�����ˮ�˴��ˡ�
		���θ�«�񻨡�
		���ͷ�æ�� 
*/
typedef struct HNode
{
	char data;//���� 
	int parent, weight, lchild, rchild;//˫�ף�Ȩֵ�����Һ��� 
	string code;//ÿ���ڵ��Լ��Ĺ��������� 
}*HTree, HNode;
void DeCode(HTree ht, string s, int m)//���� 
{
	int i = m, j = 0;
	while (s[j])
	{
		if (s[j] == '0')
			i = ht[i].lchild;
		else
			i = ht[i].rchild;
		if (ht[i].lchild == 0 && ht[i].rchild == 0)//��Ҷ�ӽڵ�
		{
			cout << ht[i].data;
			i = m;//�ص����ڵ�
		}
		j++;
	}
}
void Cout(map<char, int> m, int size, HTree ht, string s)
{
	//��ӡ�ַ���Ƶ��
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it != m.begin())
			cout << " ";
		printf("%c:%d", it->first, it->second);
	}
	cout << endl;
	//��ӡ���
	for (int i = 1; i <= size * 2 - 1; i++)
		printf("%d %d %d %d %d\n", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	//��ӡ�ַ������Ӧ��Huffman Code
	for (int i = 1; i <= size; i++)
	{
		if (i != 1)
			cout << " ";
		printf("%c:%s", ht[i].data, ht[i].code.c_str());
	}
	cout << endl;

	map<char, int>::iterator it = m.begin();
	string decode;
	for (int i = 0; i < s.length(); i++)//i�����������
	{
		for (int k = 1; k <= size; k++, it++)//ƥ��ht���data�͵�ǰ�ַ�
		{
			if (ht[k].data == s[i])//�ҵ���
			{
				cout << ht[k].code;
				decode += ht[k].code;
				break;
			}
		}
		it = m.begin();
	}
	cout << endl;
	DeCode(ht, decode, size * 2 - 1);//����
	cout << endl;
}
pair<pair<int, int>, pair<int, int>> FindParent(map<int, int>& ass, HTree ht, int size,int nowsize)//С���������(����
{
	int min1 = 30000, min2 = 30000;//��¼��ǰ��������СȨֵ 
	int p1 = 0, p2 = 0;
	int i = 0, j = 0;//��¼��ǰ�ڵ���������� 
	for (map<int, int>::iterator it = ass.begin(); it != ass.end(); it++)
	{
		if (it->first < min1 && it->second == 1)
		{
			min1 = it->first;
			it->second = 0;
		}
	}
	for (map<int, int>::iterator it = ass.begin(); it != ass.end(); it++)
	{
		if (it->first < min2 && it->first != min1 && it->second == 1)
		{
			min2 = it->first;
			it->second = 0;
		}
	}
	if (min2 == 30000)//��������2
		min2 = min1;
	for (int k = 1; k < size; k++)
	{
		if (ht[k].weight == min1)
			i = k;
		if (ht[k].weight == min2)
			j = k;
		if (i != 0 && j != 0)
			break;
	}
	if (min1 == min2)//��������2
	{
		int flag = 0;
		for (int k = 1; k <= nowsize; k++)
		{
			if (min1 == ht[k].weight)
				flag++;
			if (flag == 2)
			{
				j = k; 
				break;
			}
		}
 	}
	pair<int, int > weight = make_pair(min1, min2);
	pair<int, int > parent = make_pair(i, j);
	pair< pair<int, int>, pair<int, int>>ans = make_pair(weight, parent);
	return ans;
}
void Create(HTree& ht, int size, map<char, int> mp, map<int, int>ass)//�����������
{
	if (size <= 1)
		return;
	else
	{
		int m = size * 2 - 1;//�������ô����ڵ�
		int patch = m + 1;//�������ôд���������[]��дm+1�Ļ���oj�ᱨ��compile error 
		ht = new HNode[patch];//0���±겻�ã�HT[m]��ʾ�����
		map<char, int>::iterator it = mp.begin();
		for (int i = 1; i <= size; i++, it++)//��ʼ��ǰ�漸������ֵ����֪�ڵ�
		{
			ht[i].lchild = 0;
			ht[i].rchild = 0;
			ht[i].parent = 0;
			ht[i].data = it->first;
			ht[i].weight = it->second;
			ass[it->second] = 1;
		}
		//������漸���ڵ��weight,lch,rch
		for (int i = size + 1; i <= m; i++)
		{
			pair<pair<int, int>, pair<int, int>>ans = FindParent(ass, ht, m,i);
			ht[i].weight = ans.first.first + ans.first.second;
			ht[i].lchild = ans.second.first;
			ht[i].rchild = ans.second.second;
			ht[ans.second.first].parent = i;
			ht[ans.second.second].parent = i;
			ass[ht[i].weight] = 1;
		}
		ht[m].parent = 0;
	}
}
void SetCode(HTree ht, int size)
{
	for (int i = 1; i <= size; i++)
	{
		int fammem = ht[i].parent;
		while (fammem != 0)
		{
			if (ht[fammem].lchild == i)
				ht[i].code = '0' + ht[i].code;
			else
				ht[i].code = '1' + ht[i].code;
			fammem = ht[fammem].parent;
		}
	}
}
int cmp(char a, char b)
{return a < b;}
void SetMap(map<char, int>& m, string s)
{
	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;
}
int main()
{
	char temp[100];
	while (cin >> temp && temp[0] != '0')
	{
		HTree ans;//ʤ��������
		string s = temp;//Ϊ�˻�ȡ����
		string cd = temp;//Ϊ�˼�¼��ԭʽ�ַ���
		sort(temp, temp + s.length(), cmp);//ASCII����
		s = temp;//�����ٴθ�ֵ�����ź������
		map<char, int>m;//��¼��ĸ�����Լ����ִ���
		map<int, int>ass;//������Ϊ����min2��min1��һ��
		SetMap(m, s);	//��ÿ���ַ��Լ����ǵ�Ƶ�ʵ�map�У��ǵò���д���ã�����
		Create(ans, m.size(), m, ass);//����������
		SetCode(ans, m.size());//Ϊÿ���ڵ㴴��Huffman Code
		Cout(m, m.size(), ans, cd);//�������
	}
	return 0;
}
