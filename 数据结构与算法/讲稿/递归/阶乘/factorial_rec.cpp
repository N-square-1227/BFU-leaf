
//�򿪹��̣����β����˵����£�Project->Setting->Link����Category ��ѡ��Output��Ȼ����Reserve���趨��ջ�����ֵ��commit�� 

//ע�⣺reserve��СֵΪ4Byte��commit�Ǳ����������ڴ��ҳ�ļ� 



#include<iostream.h>
int x=0;
double factorial(int n)
{
	if(n==1)
		return 1;
	else
	{
		cout<<++x<<endl;
		return n*factorial(n-1);}
}

int main(int argc, char* argv[])
{
	int n;
	cin>>n;
	cout<<factorial(n)<<endl;
	return 0;
}

