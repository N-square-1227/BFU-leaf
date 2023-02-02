// ConsoleApplication4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;
template <typename T>
class Stack;


template <typename T>
class DataNode
{
private:
	friend class Stack<T>;
	T data;
	DataNode<T> *next;
public:
	DataNode(T d, DataNode<T> *n = NULL);
};
template <typename T>
DataNode<T>::DataNode(T d,DataNode<T> *n)
{
	data = d;
	next = n;
}

template<typename T>
class Stack
{
private:
	DataNode<T> *top;
public:
	static int count;
	Stack();
	void push(T d);
	T pop();
	~Stack();
};

template <typename T>
int Stack<T>::count = 0;

template<typename T>
Stack<T>::Stack()
{
	top = NULL;
}

template<typename T>
void Stack<T>::push(T d)
{
	top = new DataNode<T>(d, top);
	count++;
}

template<typename T>
T Stack<T>::pop()
{
	if (top == NULL)
	{
		cout << "ջ�ѿգ����ܳ�ջ";
		//return (T)"empty";
	}
	else
	{
		T temp;
		DataNode<T> *p;
		p = top;
		top = top->next;
		temp = p->data;
		delete p;
		count--;
		return temp;
	}

}
template<typename T>
Stack<T>::~Stack()
{
	DataNode<T> *p;
	while (top != NULL)
	{
		p = top;
		top = top->next;
		delete p;
	}
}


int main()
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "ջ��Ԫ�أ�"<<s.count << endl;

	cout << s.pop() << endl;
	cout << "ջ��Ԫ�أ�" << s.count << endl;

	return 0;
}

