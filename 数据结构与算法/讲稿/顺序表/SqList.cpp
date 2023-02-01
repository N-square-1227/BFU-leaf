/****��ģ���а������ĸ����ܣ����롢�����ͳ�Ƹ���������
     ����Input�������õ��˶��ļ������
	 ifstream inFile("book1.txt"); �������ļ����ܶ�ȡ�ļ�
	 ����Ҫ�������Ľ��Ҫд��һ�����ļ�book1_sort.txt��
	 ����Sort�������õ���д�ļ������
	 ofstream outFile("book1_sort.txt"); �������ļ��������ļ���д������
****/


/****������Ϊ�˳����������ϸ��ע��
     ϣ����Ҹ����״˳����е�ÿһ�д���
	 ��Щ������˳���Ļ�������
	 ����д�ļ����澭��Ҫ�õ��������ϻ�����Ҳ��������
	 �����׵�ͬѧ������鳤
****/

#include <iostream>
#include <fstream>
#include <iomanip>
//#include <string>
using namespace std;


#define SIZE 1000  //������ʾ��̬����Ĵ�С
int flag=0;      //Ϊʹ������н�׳�ԣ���ͼ�����������flagΪ1
char BK_head1[10],BK_head2[10],BK_head3[10]; //��������ļ���ͼ��������һ��������Ϣ


typedef struct {
    char no[15];   
    char name[50]; 
    float price;   
}Book; //ͼ����Ϣ����


typedef struct{//ͼ���ṹ��Ķ���
    Book *BK;
    int length;//ͼ����ͼ���¼����
}SqList;


void Input(SqList &L){    //���ļ�book1.txt �ж�ȡͼ�����ݣ��������һ��ʹ�����ã����������������Ĳ�������Ҫ����
	int i=0;
    L.BK=new Book[SIZE];  //��̬����һ���������Դ��ͼ�����ݣ����ɴ洢SIZE��ͼ��
	
    ifstream inFile("book1.txt");//ע�⣺����Ҫ�����ļ�book.txt��book1.txt�����һ�����ݣ�ͼ����� 105
	if(!inFile)	{   //��ȡ�ļ�ʧ�ܴ���
		cerr<<"Cannot open this file!"<<endl;
		exit(1);
	}
	
	inFile>>BK_head1>>BK_head2>>BK_head3;//��ȡ�ļ��еı��⣬����һ����Ϣ��ISBN ���� ����

	L.length=0; //ͼ�������ʼΪ0

	while(!inFile.eof()){  //�������ζ�ȡ����ͼ�����ݣ�ֱ�������ļ�β��
		inFile>>L.BK[i].no >>L.BK[i].name>>L.BK[i].price;
		i++;  //��¼ͼ�����
	}

    L.length=i; //ͼ�������ʼΪi

	inFile.close(); //����һ�����õ�ϰ�ߣ��ļ�ʹ�ú�ر�

	flag=1; //Ϊʹ������н�׳�ԣ�ͼ�����ݶ����flagΪ1����������������ʱͨ��flag�����ж��Ƿ��Ѷ�������

	cout<<"\n��ȡ book.txt ��Ϣ��ϣ�����ͨ��ѡ��(2)�鿴ͼ����Ϣ\n"<<endl;
}


void Output(SqList L){   //�����ʾͼ����Ϣ
	if(flag==0){         //����׳�Ե����֣�ͨ��flag�ж��Ƿ����ͼ����Ϣ
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	cout<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;//�������ÿ�Щ

	for(int i=1;i<=L.length;i++)
		cout<<left<<setw(15)<<L.BK[i].no <<"\t"<<left<<setw(50)<<L.BK[i].name<<"\t"<<left<<setw(5)<<L.BK[i].price<<endl;
	cout<<"\n��Ϣ��ʾ���\n"<<endl;
}


void Count(SqList L){        //ͳ��ͼ�����
	if(flag==0){               //����׳�Ե����֣�ͨ��flag�ж��Ƿ����ͼ����Ϣ
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}
	cout<<"��ǰ��ͼ������Ϊ��"<<L.length<<endl<<endl;  //L.length��ֵ��Ϊͼ�����
}


void Sort(SqList L){ //���۸�ӵ͵������������Ľ��д���ļ�book1_sort.txt
	Book b;
	if(flag==0){    //����׳�Ե����֣�ͨ��flag�ж��Ƿ����ͼ����Ϣ
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}
	cout<<"����ͼ�鰴�۸��ɵ͵�����������book_sort.txt��"<<endl;
	for(int i=0;i<L.length;i++){                  //ð������
		for(int j=0;j<L.length-i-1;j++){
			if(L.BK[j].price>L.BK[j+1].price){
				b=L.BK[j];
				L.BK[j]=L.BK[j+1];
				L.BK[j+1]=b;
			}
		}
	}
	ofstream outFile("book1_sort.txt"); //���ļ��������ļ���д������

	outFile<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;//д�����
	for(i=0;i<=L.length-1;i++) //����д��ͼ����Ϣ
		outFile<<left<<setw(15)<<L.BK[i].no<<"\t"<<left<<setw(50)<<L.BK[i].name<<"\t"<<left<<setw(5)<<L.BK[i].price<<endl;
}


void main(){
	char no;
	SqList L;

	while(1)
	{
		cout<<"**************************** ��ѧʹ��ͼ����Ϣ����ϵͳ��*************************"<<"\n";//�˵�ѡ��
		cout<<"(1)����ͼ����Ϣ"<<endl;
		cout<<"(2)�����ʾͼ����Ϣ"<<endl;
		cout<<"(3)ͳ�Ʊ���ͼ�����"<<endl;
		cout<<"(4)������ͼ�鰴�۸�����"<<endl;
		cout<<"(0)�˳�ϵͳ"<<endl;
		cout<<endl;
		cout<<"��ѡ������Ҫ�ķ���:";
		cin>>no;
		switch(no){
		case '1':
			Input(L);break;
		case '2':
			Output(L);break;
	    case '3':
			Count(L);break;
        case '4':
			Sort(L);break;
		case '0':
				cout<<"��ӭ�ٴ�ʹ��~bye bye~"<<endl;
				exit(0);
		default :
			cout<<"��ѡ����ȷ�Ĳ�������"<<endl;
			break;
		}
	}
}

