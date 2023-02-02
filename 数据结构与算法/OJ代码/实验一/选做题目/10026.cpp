#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int num[100];
class Book
{
public:
	string id, name;
	float price;
};
typedef struct LNode
{
	int data;
	LNode* next;
}*linklist, LNode;
void Init(linklist &l)
{
	l = new LNode;
	l->next = NULL;
}
void Insert(linklist &l,int n)
{
	l = new LNode;
	l->next = NULL;
	linklist rear = l;
	int max;
	for (int i = 0; i < n; i++)
	{
		linklist p = new LNode;
		cin >> p->data;
		max=((i==0)?p->data:(max>p->data?max:p->data));
		p->next = NULL;
		rear->next = p;
        rear = p;
	}
	cout<<max;
}
void HeadInsert(linklist& l,int n)//�ǵ��򣡣�
{
	l = new LNode;
	l->next = NULL;
}
void Show(linklist l)
{
	linklist p = l;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
linklist Merge(linklist p1, linklist p2)
{
	if (!p1)
		return p2;
	else if (!p2)
		return p1;
	if (p1->data < p2->data)
	{
		p1->next=Merge(p1->next, p2);
		return p1;
	}
	else// if (p1->data > p2->data)
	{
		p2->next=Merge(p1, p2->next);
		return p2;
	}

}
linklist Reverse(linklist l)
{
	linklist p = l->next, l1;
	l1 = new LNode;
	l1->data = l->data;
	l1->next = NULL;
	while (p)
	{
		linklist q;
		q = new LNode;
		q->data = p->data;
		q->next = l1->next;
		l1->next = q;
		p = p->next;
	}
	return l1;
}
void And(linklist l)
{
	for (int i = 0; i < 100; i++)
	{
		if (num[i] == 2)
			cout << i << " ";
	}
	for (int i = 0; i < 100; i++)
		num[i] = 0;
}
int main()
{
	linklist l1,l2;
	Init(l1);
	Init(l2);
	int n1, n2;
	while(cin >> n1 &&n1!=0)
	{
		Insert(l1, n1);
		cout << endl;
	}
 
	return 0;
}

