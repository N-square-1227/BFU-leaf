#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int flag, out;
int map[100][3],mark[100];
//map��ʾ���ǵ�ͼ��mark��ǵ�ǰλ���ǲ����߹���
void DFS(int n)//n�����ڵ�����
{
	if (n == out)
	{
		flag = 1;//�ҵ����ڣ������˳��ˣ���Ϊ����⿼�Ĳ������·�������ܲ����߳�ȥ
		return;
	}
	//else����û�ҵ�����orû�г���
	for (int i = 0; i < 3; i++)//��ÿһ�е�������ֵ������DFS
	{
		//map��ǰ��·�ڲ���0���������λ�û�û�б�mark
		if ( map[n][i]  && mark[map[n][i]]==0)
		{
			mark[map[n][i]] = 1;//�ȱ���߹���
			DFS(map[n][i]);//�ӵ�ǰλ�ü�����
			mark[map[n][i]] = 0;
		}
	}
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		flag = 0;
		//n��·���Ǵ�1��ʼ��ŵġ�������������0��ʼ�����ͻ�WA����
		for (int i = 1; i <= n; i++)
			mark[i] = 0;
		//�������������Ϊ��ÿ�γ�ʼ������һ��ȷʵ����
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> map[i][j];
		cin >> out;
		mark[1] = 1;//���ȳ�ʼλ�ÿ϶��ǡ��߹��ġ�
		DFS(1);
		if (flag == 1)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
