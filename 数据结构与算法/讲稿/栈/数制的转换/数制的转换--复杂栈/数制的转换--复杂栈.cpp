 #include<iostream.h>
 #include<stdio.h> 
 #include<stdlib.h> 
 #include<math.h> 

 typedef int SElemType; 

 #include"stack.h" 

void conversion ( ) {
  //�������������һ���Ǹ�ʮ����������ӡ��������ֵ�Ķ�������
  SqStack S;
  int N,e;
  InitStack(S);      //�����ջ
  cin>>N;
  while(N) {
    Push(S,N%2);
    N=N/2;
  }
  while (!StackEmpty(S)){
    Pop(S,e);
    cout<<e;
  }
}// conversion

 void main() 
 {
   cout<<"������һ��ʮ��������"<<endl;
   conversion ( ) ;
   cout<<endl;
 }

