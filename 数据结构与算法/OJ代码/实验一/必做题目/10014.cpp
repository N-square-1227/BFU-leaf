#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Book
{
public:
	string id, name;
	float price;
};
typedef struct LNode
{
	Book data;
	LNode* next;
}*linklist, LNode;
void Init(linklist &l)
{
	l = new LNode;
	l->next = NULL;
}
void Change(linklist& l, float avg)
{
	linklist p = l->next;
	while (p)
	{
		if (p->data.price < avg)
			p->data.price *= 1.2;
		else
			p->data.price *= 1.1;
		p = p->next;
	}
}
float Insert(linklist &l)
{
	string id,name;
	float price,avg=0;
	int cnt = 0;
	linklist p = l;
	while (cin >> id >> name >> price)
	{
		if (id == "0" && name == "0" && price == 0.0)
			break;
		else
		{
			cnt++;
 
			linklist q = new LNode; //����һ����ָ��q
 
			q->data.id = id;       //���   
			q->data.name = name;   //����
			q->data.price = price; //�۸�
			avg += price;
			q->next = NULL;         //βָ��Ϊ0
 
			p->next = q;            //��q����p�ĺ���
			p = q;    //����p��pָ��q
			
		}
	}
	avg /= cnt;
	return cnt;
}
void HeadInsert(linklist& l,int n)
{
	l = new LNode;
	l->next = NULL;
	for (int i = 0; i < n; i++)
	{
		linklist q = new LNode; 
		cin >> q->data.id >> q->data.name >> q->data.price;
		q->next = l->next;         //βָ��Ϊ0
		l->next = q;            //��q����p�ĺ���
	}
}
void Show(linklist l)
{
	linklist p = l->next;
	while (p)
	{
		printf("%s %s %.2f\n", p->data.id.c_str(), p->data.name.c_str(), p->data.price);
		p = p->next;
	}
}
void Sort(linklist& l,int n)
{
	linklist p = l;
	for (int i = 0; i < n ; i++)
	{
		p = l->next;
		int j = 0;
		while (p && j < n - 1 - i)
		{
			if (p->data.price < p->next->data.price)
			{
				Book t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
			p = p->next;
			j++;
		}
	}
}
int main()
{
	linklist l;
	Init(l);
	int cnt;
	cin >> cnt;
	HeadInsert(l,cnt);
	Show(l);
}

