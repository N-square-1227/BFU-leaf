//��ά���鶯̬����
#include <iostream>
#include <iomanip>
using namespace std; 

int main()
{
 int num1,//����
     num2;//���� 

 cout<<"��ֱ���������������: "<<endl;
 cin >> num1 >> num2; 

 //Ϊ��ά���鿪�ٿռ�
 int **p = new int*[num1];
 for(int i=0; i<num1; ++i)
  p[i] = new int[num2]; 

for(int j=0;j<num1;j++)
 {
  for(int k=0;k<num2;k++)
  {
   p[j][k]=(j+1)*(k+1);
   cout<<setw(6)<<p[j][k]<<':'<<setw(8)<<&p[j][k];
  }
  cout<<endl;
 } 

 //�ͷŶ�ά����ռ�õĿռ�
 for(int m=0;m<num1;m++)
  delete[] p[m];
 delete[] p; 

 return 0;
} 