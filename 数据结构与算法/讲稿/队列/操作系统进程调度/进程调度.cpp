#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include"linkqueue.h"
//****************����������к͵ȴ������еĽ���****************
void Print(LinkQueue &wait,LinkQueue &ok){
	QueuePtr p;

	if(QueueEmpty(ok)){		//���������в�Ϊ�գ��������������
		p=ok.front->next;	//��pָ��ok��Ԫ��
		cout<<"��������Ϊ��";
		while(p!=NULL){
			cout<<p->data.name<<"   ";
			p=p->next;
		}
	}
	else
		cout<<endl<<"�޽����ھ�������";

	if(QueueEmpty(wait)){	//���ȴ����в�Ϊ�գ��������������
		p=wait.front->next;//��pָ��wait��Ԫ��
		cout<<endl<<"�ȴ�����Ϊ��";
		while(p!=NULL){
			cout<<p->data.name<<"   ";
			p=p->next;
		}
	}
	else 
		cout<<endl<<"�޽����ڵȴ�����";
}
//*********************�Ƚ��ȳ������㷨*********************
void FCFS(LinkQueue &wait,LinkQueue &ok){//waitΪ�ȴ����У�okΪ��������
	int i=1;
	PCB e,f;

	Print(wait,ok);

	while(QueueEmpty(wait)&&QueueEmpty(ok)){		
		cout<<endl<<"��"<<i<<"��------";
		int j=rand()%3;//���������0��1��2		
		if(j==0){
			DeQueue (ok,e);//�Ӿ��������г���
			cout<<"����"<<e.name<<"ִ�����,���������0,����ִ��"<<endl;
		}
		else if(j==1){
			DeQueue (ok,e);//�Ӿ��������г���
			EnQueue (ok,e);//����������еĶ�β
			cout<<"����"<<e.name<<"ִ�����,���������1,����������еĶ�β"<<endl;
		}
		else if(j==2){
			DeQueue (ok,e);//�Ӿ��������г���
			EnQueue (wait,e);//����ȴ�����
			DeQueue(wait,f);//�ӵȴ������г���
			EnQueue(ok,f);//�����������
			cout<<"����"<<e.name<<"ִ�����,���������2,����ȴ����еĶ�β��ͬʱ���ȴ������еĵ�һ�����̲���������еĶ�β"<<endl;
		}

		Print(wait,ok);

		i++;
	}
}
//********************�����ȼ��ɴ�С�Զ�������********************
void Findprior(LinkQueue &Q){
	PCB temp;		//�м����
	QueuePtr p,q,large;
	p=new QNode;
	q=new QNode;
	large=new QNode;
	p=Q.front->next;
	for(p;p->next!=NULL;p=p->next){
		large=p; 
		for(q=p->next;q;q=q->next) 
			if(q->data.prior>large->data.prior) 
				large=q; 
		if(large!=p){
			temp=p->data; 
			p->data=large->data; 
			large->data=temp;
		} 
	}
}
//********************�������ȼ��ĵ����㷨********************
void Prior(LinkQueue &wait,LinkQueue &ok){
	int i=1;
	PCB e,f;
	
	Print(wait,ok);

	while(QueueEmpty(wait)&&QueueEmpty(ok)){		
		cout<<endl<<"��"<<i<<"��------";
		Findprior(ok);
		int j=rand()%3;//���������0��1��2		
		if(j==0){
			DeQueue (ok,e);
			cout<<"����"<<e.name<<"���ȼ����Ϊ"<<e.prior<<"����ִ��,ִ�����,���������0,����ִ��"<<endl;
		}
		else if(j==1){
			DeQueue (ok,e);
			EnQueue (ok,e);
			cout<<"����"<<e.name<<"���ȼ����Ϊ"<<e.prior<<"����ִ��,ִ����ϣ����������1,����������еĶ�β"<<endl;
		}
		else if(j==2){
			DeQueue (ok,e);
			EnQueue (wait,e);
			DeQueue(wait,f);
			EnQueue(ok,f);		
			cout<<"����"<<e.name<<"���ȼ����Ϊ"<<e.prior<<"����ִ��,ִ�����,���������2,����ȴ����еĶ�β��ͬʱ���ȴ������еĵ�һ�����̲���������еĶ�β"<<endl;
		}
		
		Print(wait,ok);

		i++;
	}
}
//********************��ִ��ʱ����С����Զ�������********************
void Findsjf(LinkQueue &Q){
	PCB temp;
	QueuePtr p,q,small;
	p=new QNode;
	q=new QNode;
	small=new QNode;
	p=Q.front->next;
	for(p;p->next!=NULL;p=p->next){
		small=p; 
		for(q=p->next;q;q=q->next) 
			if(q->data.time<small->data.time) 
				small=q; 
		if(small!=p){
			temp=p->data; 
			p->data=small->data; 
			small->data=temp;
		} 
	}
}
//***************���ִ��ʱ������㷨***************
void SJF(LinkQueue &wait,LinkQueue &ok){
	int i=1;
	PCB e,f;

	Print(wait,ok);

	while(QueueEmpty(wait)&&QueueEmpty(ok)){		
		cout<<endl<<"��"<<i<<"��------";
		Findsjf(ok);
		int j=rand()%3;//���������0��1��2		
		if(j==0){
			DeQueue (ok,e);
			cout<<"����"<<e.name<<"ִ��ʱ�����Ϊ"<<e.time<<"����ִ��,ִ�����,���������0,����ִ��"<<endl;
		}
		else if(j==1){
			DeQueue (ok,e);
			EnQueue (ok,e);
			cout<<"����"<<e.name<<"ִ��ʱ�����Ϊ"<<e.time<<"����ִ��,ִ����ϣ����������1,����������еĶ�β"<<endl;
		}
		else if(j==2){
			DeQueue (ok,e);
			EnQueue (wait,e);
			DeQueue(wait,f);
			EnQueue(ok,f);		
			cout<<"����"<<e.name<<"ִ��ʱ�����Ϊ"<<e.time<<"����ִ��,ִ�����,���������2,����ȴ����еĶ�β��ͬʱ���ȴ������еĵ�һ�����̲���������еĶ�β"<<endl;
		}

		Print(wait,ok);

		i++;
	}
}
void main(){
	int i;
	char c,b;
	LinkQueue wait,ok;	//����ȴ����к;�������
	do{
		system("cls");	//����
		cout<<"****************��ӭʹ�ý��̵���ϵͳ****************"<<endl;
		InitQueue(ok);	//��ʼ���ȴ����к;�������
		InitQueue(wait);
		for(i=0;i<10;i++){
			PCB p;
			p.name=i+1;
			p.prior=rand()%10;	//���������0-9,��Ϊ���ȼ�
			p.state=rand()%2;	//���������0��1,��Ϊ1�����,��Ϊ0��ȴ�
			p.time=rand()%100;
			if(p.state) 
				EnQueue(ok,p);	//1�Ļ������������
			else 
				EnQueue(wait,p);//0�Ļ�����ȴ�����
			
			cout<<"������"<<"\t"<<p.name<<"\t";	
			cout<<"���ȼ�:"<<p.prior<<"\t";
			if(p.state)	
				cout<<"����"<<"  "<<"\t";
			else 
				cout<<"�ȴ�"<<"  "<<"\t";
			cout<<"ִ��ʱ��"<<p.time<<"ms"<<endl;
		}
		cout<<endl<<endl;
		cout<<"****************************************************"<<endl;
		cout<<"* �����͵ȴ������Ѿ�����,��ѡ����ϣ���ĵ����㷨: ***"<<endl;
		cout<<"* 1.�Ƚ��ȳ������㷨********************************"<<endl;
		cout<<"* 2.�������ȼ��ĵ����㷨****************************"<<endl;
		cout<<"* 3.���ִ��ʱ������㷨****************************"<<endl;
		cout<<"* 0.�˳�********************************************"<<endl;
		cout<<"****************************************************"<<endl;
		cout<<"���������֣�0-3��:";
		cin>>b;
		switch(b){
			case '1':
				FCFS(wait,ok);
				break;
			case '2':
				Prior(wait,ok);
				break;
			case '3':
				SJF(wait,ok);
				break;
			case '0':
				cout<<"��л����ʹ��!"<<endl;
				exit(0);
			default:
				cout<<"������Ĵ�������,����������";
		}
		cout<<endl<<endl<<"��Ҫ����ô����Y/N��"<<endl;
		cin>>c;
	}while(c=='Y'||c=='y');
	cout<<"��л����ʹ��!"<<endl;
	exit(0);
}
