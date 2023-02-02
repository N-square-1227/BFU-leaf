#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//n��1 
typedef struct LSode
{
	double data;
	struct LSode* next;
}*LinkStack, LSode;
void Init(LinkStack& ls)
{
	ls = NULL;
}
void In(LinkStack& ls, double x)
{
	LinkStack temp = new LSode;
	temp->data = x;
	temp->next = ls;
	ls = temp;
}
double Pop(LinkStack& ls)
{
	LinkStack temp = ls;
	ls = ls->next == NULL ? NULL : ls->next;
	return temp->data;
}
int main()
{
	string s;
	while (getline(cin, s) && s != "=")
	{
		LinkStack ls;
		Init(ls);
		for (int i = 0; i < s.length() - 1; i++)//-1��Ϊ�˲����ȥ����Ǹ��Ⱥţ��ȽϷ���
		{
			string num;
			while (isdigit(s[i]) || s[i] == '.')//С������λ����
			{
				num += s[i];
				i++;
			}
			if (num.length() > 1 || isdigit(num[0]))//num������˶�����In����ջ��
				In(ls, stof(num));
			if (s[i] != ' ')//�������
			{
				switch (s[i])
				{
				case'+':In(ls, Pop(ls) + Pop(ls)); break;
				case'-':In(ls, -Pop(ls) + Pop(ls)); break;
				case'*':In(ls, Pop(ls) * Pop(ls)); break;
				case'/':
				{
					double x = Pop(ls), y = Pop(ls);
					In(ls, (double)y / x);
					break;
				}
				default:break;
				}
			}
		}
		printf("%.2f\n", Pop(ls));
	}
	return 0;
}
