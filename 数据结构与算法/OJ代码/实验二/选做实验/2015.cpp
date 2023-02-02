#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct LSode
{
	char data;
	struct LSode* next;
}*LinkStack, Lsode;
void Init(LinkStack& ls)
{
	ls = NULL;
}
void Insert(LinkStack& ls, char c)
{
	LinkStack t = new LSode;
	t->data = c;
	t->next = ls;
	ls = t;
}
void PopNoPrint(LinkStack& ls)
{
	if (!ls) 
		exit(1);
	LinkStack t = ls;
	ls = ls->next;
	delete t;
}
void PopAndPrint(LinkStack& ls)
{
	if (!ls)  exit(1);
	LinkStack t = ls;
	ls = ls->next;
	if(t->data!='('&&t->data!=')')
		cout << t->data;
	delete t;
}
char GetTop(LinkStack ls)
{
	return ls->data;
}
char Compare(char a,char b)
{//a��ջ����ģ�b��������
	//>��ջ��<����������a�ȵȻ�Ҫ��ջ
	if (b == '+' || b == '-')
	{
		if (a == '(')
			return '>';
		else return '<';
	}
	else if (b == '*' || b == '/')
	{
		if (a == '+' || a == '-'||a=='(')
			return '>';
		else return '<';
	}
}
void OutLoop(LinkStack& ls)
{
	if (ls != NULL)
	{
		while (ls->data != '(')
		{
			PopAndPrint(ls);
			if (ls == NULL) break;
		}
		if (ls != NULL)
			PopNoPrint(ls);//����'(',���ǲ���ӡ
		else return;
	}
	else return;
}
void Ans(string s,LinkStack &l)
{
	for (int i = 0; i < s.length()-1; i++)
	{
		if (isdigit(s[i]))
			cout << s[i];
		else if (s[i] == '(')//���ɷ�˵�ؽ�ջ
			Insert(l,s[i]);
		else if (s[i] == ')')//��ջ�ɣ�(��ʱ����δ��ջ
			OutLoop(l);
		else //�Ȳ�������Ҳ������������
		{//ֻ���ǼӼ��˳�֮һ��
			if (l == NULL)
				Insert(l, s[i]);
			else if (Compare(GetTop(l), s[i]) == '>')//��ջ
				Insert(l, s[i]);
			else//һֱ��ջ
			{
				OutLoop(l);
				Insert(l,s[i]);
			}
		}
	}
	OutLoop(l);
	cout << endl;
}
int main()
{
	string s;
	while (cin >> s && s != "=")
	{
		LinkStack l;
		Init(l);
		Ans(s,l);
	}
	return 0;
}

