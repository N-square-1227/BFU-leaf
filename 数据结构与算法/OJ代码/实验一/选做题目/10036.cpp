//#include<string>
//#include<iostream>
//#include<map>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//int cnt[100];
//int main()
//{
//	//��ν��Ԫ�ؾ�����һ�������е�ĳһ��Ԫ�������ֵĵĴ���>=���鳤�ȵ�1/2
//	int n;
//	cin >> n;
//	while (n != 0)
//	{
//		vector<int> v(n);
//		int main = -1, len = n, max = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			cnt[v[i]]++;
//			max = cnt[v[i]] > max ? cnt[v[i]] : max;
//		}
//		if (max * 2 < len)
//			cout << -1 << endl;
//		else
//		{
//			for (int i = 0; i < 100; i++)
//			{
//				if (cnt[i] == max)
//				{
//					cout << i <<endl;
//					break;
//				}
//			}
//		}
//		cin >> n;
//		for (int i = 0; i < 100; i++)
//			cnt[i] = 0;
//	}
//	return 0;
//}

//������㷨�������Ҳ�����ˣ���������Ϊû������ 
#include <iostream>
using namespace std;
 
void MainElem(int a[],int n)
{
	int i;int flag[100];
	
	for(i=0;i<100;i++)
		flag[i]=0;
	
	for(i=0;i<n;i++)
		flag[a[i]]++;
	
	int max=flag[a[0]];
	for(i=0;i<n;i++)//���ܳ��������С 
		if(max<flag[a[i]])
			max=flag[a[i]];
	for(i=0;i<n;i++)
		if(flag[a[i]]==max && flag[a[i]]>n/2)
		{
			cout<<a[i]<<endl;
			break;
		}
		else if(flag[a[i]]==max && flag[a[i]]<=n/2)
		{
			cout<<-1<<endl;
			break;
		}
	return;
}
int main()
{
	int n; 
	while(1)
	{
		cin>>n;
		if(n==0) break;
		int a[n];
		int i;
		for(i=0;i<n;i++)
			cin>>a[i]; 
		MainElem(a,n);
	 } 
 }
