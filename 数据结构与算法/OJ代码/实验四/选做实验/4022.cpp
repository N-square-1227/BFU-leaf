#include<bits/stdc++.h>
using namespace std;

typedef struct LNode
{
	int data;
	int mark;
	struct LNode* next;
}*linklist, LNode;
void Create(linklist &ls,int n)
{
	ls = new LNode;
	ls->next = NULL;
	linklist r = ls;
	for (int i = 0; i < n; i++)
	{
		linklist p = new LNode;
		cin >> p->data;
		p->mark = i + 1;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}
/*
  ѡ������

�ظ���Ԫ�ظ���-1����

  �ѵ�һ��û���������Ԫ������Ϊ��Сֵ

  ����ÿ��û���������Ԫ��

    ���Ԫ�� < ���ڵ���Сֵ

      ����Ԫ�����ó�Ϊ�µ���Сֵ

  ����Сֵ�͵�һ��û���������λ�ý���*/
void Sort(linklist& ls,int n)
{
	linklist p = ls->next, q = p->next;
	if (!q||!p)
		return;
	int min = p->data,cnt=0,pos=0;
	for (int i = cnt; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (q->data < min)
			{
				min = q->data;
				pos = q->mark;
			}
			q = q->next;
		}

		linklist tp = ls->next;
		for (int k = 1; k < pos; k++)
			tp = tp->next;
		if(pos!=0)
			swap(tp->data, p->data);
		cnt++;
		p = p->next;
		if (p)
		{
			q = p->next;
			min = p->data;
			pos = 0;
		}
		else break;
	}
}
void Show(linklist ls)
{
	linklist p = ls->next;
	while (p->next)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		linklist l;
		Create(l, n);
		Sort(l, n);
		Show(l);
	}
	return 0;
}
