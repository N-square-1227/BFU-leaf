#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int cmp(char a, char b)
{	//�ַ�����˳����ASCII���С�����˳��
	return a < b;
}
void Show(string s)
{
	int cnt = 1;
	char c;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{//��ǰ�ַ�Ϊ��д��ĸ������
		if (isalnum(s[i]) && s[i] < 97)
			temp = temp + s[i];
	}
	c = temp[0];
	if (c == '\0')
	{
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i < temp.length(); i++)
	{
		if (temp[i] == c)
			cnt++;
		else
		{
			printf("%c:%d\n", c, cnt);
			c = temp[i];
			cnt = 1;
		}
	}
	printf("%c:%d\n", c, cnt);//���һ���ַ��ǲ������ıȽϵģ��ǵõ��������
}
int main()
{
	string s;
	while (getline(cin,s)&&s!="0")//getline������Դ��ո���������Ǵ��ո��ַ���������ͻ�WA
	{
		char c[1000];
		s.copy(c, s.length(), 0);//����s.length()�����Ƽ����ַ���0�����Ƶ�λ�ã�
		*(c + s.length()) = '\0';//ע���ֶ��ӽ�����������
		sort(c, c + s.length(), cmp);
		s = c;
		Show(s);
		strcpy(c, "");//vs 2019Ҫд��strcpy_s������oj�ϼǵð�_sȥ��
	}
	return 0;
}
