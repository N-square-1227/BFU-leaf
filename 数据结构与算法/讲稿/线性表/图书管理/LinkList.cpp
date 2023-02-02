#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


typedef struct {
    char no[15];   
    char name[50]; 
    float price;   
}Book; //ͼ����Ϣ����


typedef struct LNode{
	Book   data;       //������
	struct LNode  *next;   //ָ����
}LNode,*LinkList; 

int num=0;//��¼ͼ�����
char BK_head1[10],BK_head2[10],BK_head3[10];

void Input(LinkList &L){     //��book.txt �ж�ȡ��Ϣ����巨����ͼ������
	LinkList p,r;
	
	L=new LNode;
	L->next=NULL;//��ʼ��������
	
	r=L;
	
	ifstream inFile("book.txt");
	if(!inFile){
		cerr<<"Cannot open this file!"<<endl;
		exit(1);
	}
	
	inFile>>BK_head1>>BK_head2>>BK_head3;//��ȡ�ļ��еı���
	num=0;
	while(!inFile.eof()){    //�������ζ�ȡ����ͼ������
		p=new LNode;  //�����½��
		inFile>>p->data.no>>p->data.name>>p->data.price;
		p->next=NULL;
		r->next=p;  //���뵽��β
		r=p;
		num++;   //��¼ͼ�����
	}

	inFile.close();
	cout<<"�ļ���ȡ���"<<endl;
		
    inFile.close();
	cout<<"\n��ȡ book.txt ��Ϣ��ϣ�����ͨ��ѡ��(2)�鿴ͼ������Ϣ\n"<<endl;
}

void Output(LinkList L){  //�����ʾ���е���Ϣ
	if(num==0) {      //�ж��Ƿ����ͼ����Ϣ
	    cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	LinkList p;
	p=L->next;
	/*for(int i=0;i<num;i++){
		cout<<p->data.no<<"\t"<<p->data.name<<"\t"<<p->data.score<<endl;
		p=p->next;
	}*/
	
	cout<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<setw(5)<<BK_head1<<endl;
	while(p){     //ѭ�����ͼ����Ϣ
		cout<<left<<setw(15)<<p->data.no<<"\t"<<left<<setw(50)<<p->data.name<<"\t"<<left<<setw(5)<<p->data.price<<endl;
		p=p->next;
	}	
	cout<<"\n��Ϣ��ʾ���\n"<<endl;
}

void Count_Len(LinkList L){
	if(num==0){    //�ж��Ƿ����ͼ����Ϣ     
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	cout<<"��ǰ��ͼ������Ϊ��"<<num<<endl<<endl;
}


void NameSearch(LinkList L){          //����������ͼ����Ϣ  
	if(num==0){      //�ж��Ƿ����ͼ����Ϣ                                
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	char n[30];
	cout<<"��������Ҫ���ҵ�������";
	cin>>n;                 //����Ҫ���ҵ��������
	int a=0;
	LinkList p;
	p=L->next;
	while(p){      
		if(strcmp(n,p->data.name)==0){      //��strcmp()�����ж��Ƿ���Ҫ���ҵ���  
			if(a==0){
				cout<<"�ҵ����飬�������Ϣ���£�"<<endl;
				cout<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;
			}
			cout<<left<<setw(15)<<p->data.no<<"\t"<<left<<setw(50)<<p->data.name<<"\t"<<left<<setw(5)<<p->data.price<<endl;  //����ҵ������Ϣ
			a++;
		}
		p=p->next;
	}
	if(a==0)
		cout<<"�Բ���û����Ҫ���ҵ���!"<<endl;
}

   
void LocationSearch(LinkList L){    //��λ�ò���ͼ����Ϣ
	if(num==0){      //�ж��Ƿ����ͼ����Ϣ	                                    
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	int i;     //i���ڼ�¼Ҫ����ͼ���λ��
	cout<<"��������Ҫ���ҵ�ͼ���λ�ã�";
	cin>>i;
	LinkList p;
	int j;
	p=L->next;
	j=1;
	while(p&&j<i){    //ѭ���ҵ�ͼ���λ��
		p=p->next;
		++j;
	}
	if(!p||j>i){
		cout<<"��Ҫ���ҵ�Ԫ�ز�����"<<endl;
		return;
	}
	cout<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;
	cout<<left<<setw(15)<<p->data.no<<"\t"<<left<<setw(50)<<p->data.name<<"\t"<<left<<setw(5)<<p->data.price<<endl;
}


void Insert(LinkList L){
	if(num==0){       //�ж��Ƿ����ͼ����Ϣ	                                   
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	int i;    //i���ڼ�¼Ҫ����ͼ���λ��
	cout<<"��������Ҫ����ͼ���λ�ã�";
	cin>>i;
	LinkList p,l;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1){       //ѭ���ҵ�Ҫ����ͼ���λ��
		p=p->next;
		++j;
	}
	if(!p||j>i-1){
		cout<<"��Ҫ����ͼ���λ�ò���ȷ"<<endl;
		return;
	}
	LinkList s=new LNode;
	cout<<"��������Ҫ����ͼ�����Ϣ(������š������Ͷ���)��";
	cin>>s->data.no>>s->data.name>>s->data.price;     //�������ͼ�����Ϣ
	s->next=p->next;
	p->next=s;
	++num;

	l=L->next;
	int k;
	ofstream outFile("book.txt");       //����ͼ�����whileѭ����д��"book.txt"
	outFile<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;
	for(k=1;k<num;k++){	
		outFile<<left<<setw(15)<<l->data.no<<"\t"<<left<<setw(50)<<l->data.name<<"\t"<<left<<setw(5)<<l->data.price<<endl;
		l=l->next;
	}
	outFile<<left<<setw(15)<<l->data.no<<"\t"<<left<<setw(50)<<l->data.name<<"\t"<<left<<setw(5)<<l->data.price;   //���һ�����벻����
	cout<<"����ͼ�����д�롰book.txt����"<<endl;
}


void Delete(LinkList L){
	if(num==0){       //�ж��Ƿ����ͼ����Ϣ	                                   
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}

	int i;    //i���ڼ�¼Ҫɾ��ͼ���λ��
	cout<<"��������Ҫɾ��ͼ���λ�ã�";
	cin>>i;
	LinkList p,q,l;
	int j;
	p=L;
	j=0;
	while(p->next&&j<i-1){       //ѭ���ҵ�Ҫɾ��ͼ���λ��
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		cout<<"��Ҫɾ��ͼ���λ�ò���ȷ"<<endl;
		return;
	}
	q=p->next;
	p->next=q->next;
	delete q;
	--num;

	l=L->next;
	int k;
	ofstream outFile("book.txt");       //ɾ��ͼ�����whileѭ����д��"book.txt"
	outFile<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;
	for(k=1;k<num;k++){
		outFile<<left<<setw(15)<<l->data.no<<"\t"<<left<<setw(50)<<l->data.name<<"\t"<<left<<setw(5)<<l->data.price<<endl;
		l=l->next;
	}
	outFile<<left<<setw(15)<<l->data.no<<"\t"<<left<<setw(50)<<l->data.name<<"\t"<<left<<setw(5)<<l->data.price;    //���һ�����벻����
	cout<<"ɾ��ͼ�����д�롰book.txt����"<<endl;
}


void Sort(LinkList L){     //���۸�ӵ͵�������                       
	if(num==0){      //�ж��Ƿ����ͼ����Ϣ	              
		cout<<"��û�д�book.txt�ж�ȡͼ����Ϣ����ѡ��(1)����ͼ����Ϣ\n"<<endl;
		return;
	}
	

	LinkList p,pnext,q,l;
    int i,j;
	for(i=0;i<num-1;i++){          //ð������
        q=L;
        p=L->next;
        pnext=p->next;
        for(j=0;j<num-i-1;j++){
            if(p->data.price>pnext->data.price){
                p->next=pnext->next;
                q->next=pnext;
                q=pnext;
                q->next=p;
            }
            else{           
                q=q->next;
                p=p->next;
            }
            pnext=p->next;
        }
    }

	l=L->next;
	ofstream outFile("book_sort.txt");       //��������ͼ����Ϣ��whileѭ��д����Ϊ"book_sort.txt"���ļ���
	outFile<<left<<setw(15)<<BK_head1<<"\t"<<left<<setw(50)<<BK_head2<<"\t"<<left<<setw(5)<<BK_head3<<endl;
	while(l){
		outFile<<left<<setw(15)<<l->data.no<<"\t"<<left<<setw(50)<<l->data.name<<"\t"<<left<<setw(5)<<l->data.price<<endl;
		l=l->next;
	}
	cout<<"�����鰴�۸��ɵ͵����������ڡ�book_sort���С�"<<endl;
}


int main(){
	char no;
	LinkList L;

	while(1){
		cout<<"**************************** ��ѧʹ��ͼ����Ϣ����ϵͳ��*************************"<<"\n";//�˵�ѡ��
		cout<<"(1)����ͼ����Ϣ"<<"\n";
		cout<<"(2)�����ʾͼ����Ϣ"<<"\n";
		cout<<"(3)ͳ�Ʊ���ͼ�����"<<"\n";
		cout<<"(4)�����������в���"<<"\n";
		cout<<"(5)����ָ��λ�ý��в���"<<"\n";
		cout<<"(6)����ͼ����Ϣ��ָ��λ��"<<"\n";
		cout<<"(7)ɾ��ָ��λ�õ�ͼ���¼""\n";
		cout<<"(8)������ͼ�鰴�۸�����""\n";
		cout<<"(0)�˳�ϵͳ"<<"\n";
		cout<<"\n";
		cout<<"��ѡ������Ҫ�ķ���:";
		cin>>no;
		switch(no){
		case '1':
			Input(L);break;
		case '2':
			Output(L);break;
        case '3':
			Count_Len(L);break;
		case '4':
			NameSearch(L);break;
		case '5':
			LocationSearch(L);break;
        case '6':
			Insert(L);break;
		case '7':
			Delete(L);break;
		case '8':
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
