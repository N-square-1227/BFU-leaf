#include<iostream>
using namespace std;
#define OK 1
#define ERROR -1

//��ջ�Ĵ洢�ṹ
typedef struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStack;

//��ջ�ĳ�ʼ��
int InitStack(LinkStack& S)
{//����һ����ջ��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}

int Push(LinkStack& S, char e)
{//��ջ������Ԫ��
	LinkStack p = new StackNode;//�����½��
	p->data = e;//���½ڵ�� ��������Ϊe
	p->next = S;//���½�����ջ��
	S = p;//�޸�ջ��ָ��Ϊp
	return OK;
}

char Pop(LinkStack& S, char& e)
{
	if (S == NULL)
		return ERROR;//ջ��
	e = S->data;//��ջ��Ԫ�ظ���e
	LinkStack p = S;//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next;//�޸�ջ��ָ��
	delete p;//�ͷ�ԭջ��Ԫ�صĿռ�
	return e;
}

//ȡջ��Ԫ��
char GetTop(LinkStack S)
{//��ջ���ǿ�ʱ���˲������ص�ǰջ��Ԫ�ص�ֵ��ջ��ָ��S���ֲ���
	if (S != NULL)
		return S->data;
	else
		return '?';
}


//��ջ�Ĵ洢�ṹ
typedef struct StackNoded
{
	double data;
	struct StackNoded* next;
}StackNoded, * LinkStackd;

//��ջ�ĳ�ʼ��
int InitStackd(LinkStackd& S)
{//����һ����ջ��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}

//��ջ����ջ
int Pushd(LinkStackd& S, double e)
{//��ջ������Ԫ��
	LinkStackd p = new StackNoded;//�����½��
	p->data = e;//���½ڵ�� ��������Ϊe
	p->next = S;//���½�����ջ��
	S = p;//�޸�ջ��ָ��Ϊp
	return OK;
}

//��ջ�ĳ�ջ
double Popd(LinkStackd& S, double& e)
{
	if (S == NULL)
		return -1;//ջ��
	e = S->data;//��ջ��Ԫ�ظ���e
	LinkStackd p = S;//��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next;//�޸�ջ��ָ��
	delete p;//�ͷ�ԭջ��Ԫ�صĿռ�
	return e;
}

//ȡջ��Ԫ��
double GetTopd(LinkStackd S)
{//��ջ���ǿ�ʱ���˲������ص�ǰջ��Ԫ�ص�ֵ��ջ��ָ��S���ֲ���
	if (S != NULL)  return S->data;
	else return ERROR;
}
//�ж϶�����ַ�ch�Ƿ�Ϊ�����
int In(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*'|| ch == '/' || ch == '(' || ch == ')' || ch == '=')
		return true;
	else return false;
}

//�����ȼ�
char Precede(char ch1, char ch2)
{
	switch (ch1)
	{
	case '?':
		return '<';
	case '+':
		if (ch2 == '+' || ch2 == '-' || ch2 == ')' || ch2 == '=')
			return '>';
		else
			return '<';
	case '-':
		if (ch2 == '+' || ch2 == '-' || ch2 == ')' || ch2 == '=')
			return '>';
		else
			return '<';
	case '*':
		if (ch2 == '+' || ch2 == '-' || ch2 == '*' || ch2 == '/' || ch2 == ')' || ch2 == '=')
			return '>';
		else
			return '<';
	case '/':
		if (ch2 == '+' || ch2 == '-' || ch2 == '*' || ch2 == '/' || ch2 == ')' || ch2 == '=')
			return '>';
		else
			return '<';
	case '(':
		if (ch2 == '+' || ch2 == '-' || ch2 == '*' || ch2 == '/' || ch2 == '(')
			return '<';
		else if (ch2 == '=')
			return '>';
		else
			return '=';
	case ')':
		if (ch2 == '+' || ch2 == '-' || ch2 == '*' || ch2 == '/' || ch2 == ')' || ch2 == '=')
			return '<';
		else  return ' ';
	}
}

double Operate(double a, char theta, double b)
{
	switch (theta)
	{
		case '+':return a + b;break;
		case '-':return a - b;break;
		case '*':return a * b;break;
		case '/':return a / b;break;
		default:break;
	}
}

double EvaluateExpression(char* str)
{//�������ʽ��ֵ��������ȷ�����OPND��OPTR�ֱ�Ϊ������ջ�������ջ
	char ch;//��ǰ�ַ�
	LinkStack OPTR;
	LinkStackd OPND;
	InitStackd(OPND);//��ʼ��OPNDջ
	InitStack(OPTR);//��ʼ��OPTRջ
	ch = str[0];
	int i = 0;//ɨ���ַ������±�
	//����� ������a ������b
	char theta, x;
	double a,b;
	int i1 = 0;//���ֺ�С���㹹�ɵ��ַ����±�
	char z[10] = {};//������ֵ��ַ���
	while (true)
	{
		ch = str[i];//��i���ַ�
		if (ch == '\0')
			break;
		if (In(ch))//�������
		{
			ch = str[i];
			switch (Precede(GetTop(OPTR), ch))
			{//�Ƚ�OPTR��ջ��Ԫ�غ�ch�����ȼ�
			case '<':
				Push(OPTR, ch);
				i++;
				ch = str[i];
				break;
			case '>':
				Pop(OPTR, theta);//����ջ���������
				Popd(OPND, b); 
				Popd(OPND, a);//����ջ��������������
				Pushd(OPND, Operate(a, theta, b));//��������ѹ��OPNDջ
				break;
			case '='://OPTR��ջ��Ԫ����"("��ch")"
				Pop(OPTR, x);
				i++;
				ch = str[i];
				break;
			default:break;
			}
		}
		else if (ch >= '0' && ch <= '9')//����
		{
			i1 = 0;
			do
			{
				z[i1++] = ch;
				i++;
				ch = str[i];
			} while ((ch >= '0' && ch <= '9') || ch == '.');
			z[i1] = 0;
			Pushd(OPND, atof(z));
		}
		else break;
	}
	return GetTopd(OPND);
}

int main()
{
	char str[50] = {};//������ַ����������ʽ
	char ch;
	double output;
	while (1)
	{
		cin >> str;
		ch = str[0];
		if (ch == '=')  break;

		else  printf("%.2f\n", EvaluateExpression(str));
	}
}
