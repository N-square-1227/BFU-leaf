 /* stack.h ջ��˳��洢��ʾ */
 
 #define OK 1
 #define ERROR 0
 typedef int Status; 
 #define  SIZE 50 /* �洢�ռ��ʼ������ */
 typedef struct SqStack
 {
   SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   SElemType *top; /* ջ��ָ�� */
   int stacksize;
 }SqStack; /* ˳��ջ */

 Status InitStack(SqStack &S)
 { /* ����һ����ջS */
   S.base=new SElemType[SIZE];
   if(!S.base)
     exit(OVERFLOW); /* �洢����ʧ�� */
   S.top=S.base;
   S.stacksize=SIZE;
   return OK;
 }


 bool StackEmpty(SqStack S)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if(S.top==S.base)
     return true;
   else
     return false;
 }

void Push(SqStack &S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if(S.top-S.base==S.stacksize) /* ջ�� */
	   cout<<"ջ�����޷�ѹջ!"<<endl;
   *S.top++=e;
 }
int Pop(SqStack &S,int &e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if(S.top==S.base)
     return ERROR;
   e=*--S.top;
   return e;
 }

