#include<stdio.h>
#include<stdlib.h>//sizeof 
#include<string.h>//strcmp,strcpy 
#include<windows.h>//����
#define Max 500

//ְ���Ŷ��� 
char Post[4][20]={"����","��ʦ","������","����"};
//ѧԺ��Ŷ���
char College[5][20]={"��ϢѧԺ","��ѧԺ","��ѧԺ","����ѧԺ","����ѧԺ"};

struct Teacher
 {
	char Name[20];//����
	char Id[20];//����
	char College[20];//ѧԺ 
	char Post[20];//ְ�� 1.���� 2.��ʦ 3.������ 4.���� 
	int flag;//�Ƿ�[ɾ��]�ı�־ 
}T[Max];//��ʦ�ṹ��
int T_Sum;//��ʦ����
void InT(int i);//�����ʦ��Ϣ���� 
void ShowT(int i);//��ʾ��ʦ��Ϣ���� 

struct Salary 
{
	char Id[20];//������ܶ�������ͺ����ֶ���Teacher�ṹ��һ��
	            //��������������һ���ı����������໥�����ġ�
	int Mon;
	double A,B,C,D,E;//�������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ������
	int flag;//����ͬ�� 
}S[Max];//���ʽṹ��
int S_Sum;//������Ϣ��Ŀ
void InS(int i);//���빤����Ϣ���� 
void ShowS(int i);//��ʾ������Ϣ���� 

void Welcome();//��ӭ����
void Addinfo();//¼����Ϣ
void Change();//�޸�����
void Search();//��������
void Analyze();//ͳ�Ʒ���
void Out();//�˳�
void InData();//�������� 
void ReadData();//��ȡ��������
//׷��  
void Sort();//������ 

int main()
{
	Welcome();
	return 0;
}

void InT(int i)
{
	int t;
	
	printf("����:");
	scanf("%s", T[i].Name);
	printf("����(01��ʼ):");
	scanf("%s",T[i].Id);
	
	printf("ѧԺ:(0.��ϢѧԺ 1.��ѧԺ 2.��ѧԺ 3.����ѧԺ 4.����ѧԺ)");
	scanf("%d",&t);
	while(t<0||t>4)
	{
		printf("ѧԺ��Ϣ�������������룡\n");
		scanf("%d", &t);
	}
	strcpy(T[i].College,College[t]);
	
	printf("ְ��:(0.���� 1.��ʦ 2.������ 3.����)");
	scanf("%d",&t) ;
	while(t<0||t>3)
	{
		printf("ְ����Ϣ�������������룡\n");
		scanf("%d", &t);
	}
	strcpy(T[i].Post,Post[t]);
	
	T[i].flag=1;//�ý�ʦ��Ϣ¼����� 
}

void ShowT(int i)
{	
	printf("\n����:%s\n",T[i].Id);
	printf("����:%s\n",T[i].Name);
	printf("ѧԺ:%s\n",T[i].College);
	printf("ְ��:%s\n",T[i].Post);
}//ShowT

void InS(int i)
{
	printf("����:");
	scanf("%s", S[i].Id);
	printf("�·�:(����)");
	scanf("%d", &S[i].Mon);
	while(S[i].Mon>12||S[i].Mon<1)
	{
		printf("�·���Ϣ�������������룡\n");
		i--;
		scanf("%d", &S[i].Mon);
	}
	
	printf("����¼��������ʡ�ҵ���������۳�����:\n");
	
	//2020.12.18��ŵ���ģ����������while����֤������Ϣ��Ϊ��ֵ 
	scanf("%lf", &S[i].A);
	while(S[i].A<0)
	{
		printf("����������Ϣ�������������룡\n");
		i--;
		scanf("%d", &S[i].A);
	}
	
	scanf("%lf", &S[i].B);
	while(S[i].B<0)
	{
		printf("ҵ��������Ϣ�������������룡\n");
		i--;
		scanf("%d", &S[i].B);
	}
	
	scanf("%lf", &S[i].C);
	while(S[i].C<0)
	{
		printf("�۳�������Ϣ�������������룡\n");
		i--;
		scanf("%d", &S[i].C);
	}
	
	S[i].D = S[i].A + S[i].B;
	S[i].E = S[i].D - S[i].C;
	
	S[i].flag=1;//������Ϣ�������
}

void ShowS(int i)
{
	printf("\n����:%s\n",S[i].Id);
	printf("�·�:%d\n",S[i].Mon);
	
	printf("��������:%.2lf\n",S[i].A);
	printf("ҵ������:%.2lf\n",S[i].B);
	printf("�۳�����:%.2lf\n",S[i].C);
	printf("Ӧ������:%.2lf\n",S[i].D);
	printf("ʵ������:%.2lf\n",S[i].E);
}//ShowS

void Welcome()
{
	int i;
	printf("                                  ��֤�С���\n");
	Sleep(500);
	printf("                            ");
	for (i = 0; i < 10; i++)
	{
		printf("��");
		Sleep(50);
	}
	printf("\n");
	Sleep(1500);
	printf("                                �����֤ͨ����\n");
	Sleep(1000);
	printf("                   ����ȡ�����Ȩ�ޣ���ӭ�������������ݿ⡣\n");
	printf("    ��������������������������������������������������������������������\n");
	printf("                              �� ���� ������ǰ\n"); 
	printf("    ����������������������������������������������������������������������\n");
	printf("    ��1-¼����Ϣ����������������������������������������������������������\n");
	printf("    ��2-�޸����ݡ���������������������������������������������������������\n");
	printf("    ��3-��ѯ��Ϣ����������������������������������������������������������\n");
	printf("    ��4-ͳ�Ʒ�������������������������������������������������������������\n");
	printf("    ��5-�˳�ϵͳ����������������������������������������������������������\n");
	printf("    ��6-ʹ�ñ������ݡ�����������������������������������������������������\n");
	printf("    ����������������������������������������������������������������������\n");
	printf("                       ����ָ���������������ָʾ��\n");

	int a; 	
	scanf("%d",&a);
	
	//���ж��ǲ���Ҫ��ϵͳ
	while (a!= 5) 
	{
		switch (a)
		{
			case 1:Addinfo(); break;
			case 2:Change(); break;
			case 3:Search(); break;
			case 4:Analyze(); break;
			case 6:ReadData();break;
			default:printf("\n\n                ��Ҫ��ȡ�������漰�ܼ���������Ч��\n"); break;
		}
		
		printf("\n���������˵������ܵ�ѡ��:\n");
		printf(" 1-¼����Ϣ\n");
		printf(" 2-�޸�����\n");
		printf(" 3-��ѯ��Ϣ\n");
		printf(" 4-ͳ�Ʒ���\n");
		printf(" 5-�˳�ϵͳ\n");
		printf(" 6-ʹ�ñ�������\n");
		scanf("%d",&a);
	}
	
	InData();//�˳���ʱ�򣡣���!��!!�棡���������������ݣ��������� 
	Out();
}//Welcome


void Addinfo()
{
	printf("    ��1-¼����Ϣ����������������������������������������������������������\n");
	printf("��ʦ������");
	scanf("%d", &T_Sum);
	
	printf("��ʼ¼���ʦ��Ϣ\n");
	int i,j;
	for (i = 1; i <= T_Sum; i++)
	{
		printf("\n��%dλ��ʦ��Ϣ¼��\n",i);
		InT(i);
		T[0] = T[i];//T[0]���м����ʹ�� 
		
		//�����㷨 
		j = i - 1;
		while (strcmp(T[i].Id, T[j].Id) != 0)
		{
			j--;
		}
		
		if (j != 0)//���j�ڲ��������ʱ����˳�����
		           //˵����֮ǰ�Ѿ�������һ����ͬ�Ĺ��� 
		{
			printf("\n�����ظ���¼�����ϣ�\n");
			i--;//���¿�ʼ���ѭ��������¼����Ϣ
		}
		else
		{
			printf("¼��ɹ���\n");
		}
	}
	printf("¼���ʦ��Ϣ��ϣ�\n");
	Sort();//���̰���������
	
	//������Ϣ��¼�� 
	printf("\n������Ϣ��Ŀ��");
	scanf("%d", &S_Sum);//¼�����˵ģ���û������Ϣ���˾���0�Թ�ȥ
	while(S_Sum>T_Sum)
	{
		printf("   ������Ŀ���ܴ��ڽ�ʦ����Ŀ�����������룡\n"); 
		scanf("%d", &S_Sum);//2020.12.18�����޸� 
	}                       //֮ǰд��û�����whileѭ����ֱ�Ӷ�ȡS_Sum,û���жϴ�С��ϵ 
	
	for (i = 1; i <= S_Sum; i++)
	{
		printf("\n��%d��������Ϣ¼��\n", i);
		InS(i);
		
		//�жϹ�������Ϸ��� 
		int flag=1;//�ж�¼�빤����Ϣ��Ĺ����Ƿ���ڵı��� 
		for(j=1;j<=T_Sum;j++)//�����ָ����T_sum,����û�й��ʣ����Ǳ�������ˣ�doge�� 
		{
			if(strcmp(S[i].Id,T[j].Id)==0)//�������Ϊ��j<=i�����԰�j�������iҲ��һ������� 
			{                             //һ�����ҵ�һ����Ӧ���ţ����������ȷ�Ļ��� 
				flag=0;
				break;
			}
		}
		if(flag)
		{
			printf("\n���Ų����ڣ�����¼�룡\n\n");
			i--;
		}
		ShowS(i);
	}
	printf("¼�빤����Ϣ��ϣ�\n\n");
	printf("¼����ϣ��Զ��˳�ϵͳ\n\n");
}//Addinfo

void Change()
{	
	int t;
	printf("    ��2-�޸����ݡ���������������������������������������������������������\n");
	printf("1.���ݹ����޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
	printf("2.���������޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
	printf("3.ɾ��ĳһ���ŵĽ�ʦ��������Ϣ\n");
	printf("4.�˳��޸�ϵͳ\n");
	scanf("%d",&t);
	printf("���롶�޸�ϵͳ�����ܵ�ѡ��:");
	
	int i;//i��֮�������Ҫ����ġ�
	
	while(t!=4)
	{
		switch(t)
		{
			case 1:
			{
				char Id[20];
				printf("�����޸Ĺ���:");
				scanf("%s",Id);
				printf("�޸Ļ�����Ϣ\n");
				
				int flag=1;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						flag=0;//�ҵ��˹���Ϊ���Ľ�ʦ 

						//�û��Ѻ���
						printf("ԭ��Ϣ:\n");
						ShowT(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int t;
						scanf("%d",&t);
						
						if(t==2)
						{
							break;//��ʦ�ǰ����Ų��ң�Ψһ��ֻҪ�ҵ�,�Ͳ��������ˣ�ֱ��break 
							      //��ʦ�͹���֮����һһ��Ӧ�Ĺ�ϵ 
						}
						printf("�޸���Ϣ:\n");
						InT(i);//�޸ľ����������벢����
							  //ͬһ������������������Ϣ�����Զ�������һ��
					}
				}
				if(flag==1)
				{
					printf("��ѯʧ�ܣ�\n");
					break;//��ѯʧ�ܣ�case���ֱ���˳� 
				}
				
				//�޸Ĺ�����Ϣ 
				printf("�޸Ĺ�����Ϣ\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0)
					{
						printf("ԭ��Ϣ:\n");
						ShowS(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int t;
						scanf("%d",&t);
						
						if(t==2)
						{
							continue;//��������Ϣ��һ�� ���� ���Զ�Ӧ�ܶ���Ϣ
							//�ͽ�ʦ�빤��֮���һһ��Ӧ�Ĺ�ϵ��ͬ 
							//��һ���ҵ�֮���޷�ȷ�����滹��û��������ŵĹ�����Ϣ���ͼ���
							//���Բ���break 
						}
						printf("�޸���Ϣ:\n");
						InS(i);
					}
				}
				
				Sort(); //���򣡣� 
				break; 
			}
			
			case 2:
			{
				char Name[20];
				printf("������޸�������:");
				scanf("%s",Name);
				printf("�޸Ļ�����Ϣ\n");
				int t;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Name,T[i].Name)==0)
					{
						t=i;//��ʱ��������
						 
						printf("ԭ��Ϣ:\n");
						ShowT(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int tem;
						scanf("%d",&tem);
						if(tem==2) break;
						printf("�޸���Ϣ:\n");
						InT(i);
					}
				}
				
				printf("�޸Ĺ�����Ϣ\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(T[t].Id,S[i].Id)==0)
					{
						printf("ԭ��Ϣ:\n");
						ShowS(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int tem;
						scanf("%d",&tem);
						if(tem==2) continue;//������Ϣ�����кܶ� 
						printf("�޸���Ϣ:\n");
						InS(i);
					}
				}
				
				Sort();
				break;
			}
			
			case 3:
			{
				printf("���ٴ�ȷ���Ƿ�ִ��ɾ����������������1����  2������\n");
				int m;
				scanf("%d",&m);
				if(m==1)
				{ 
					char Id[20];
					printf("���빤��:");
					scanf("%s",Id);
					for(i=1;i<=T_Sum;i++)
					{
						if(strcmp(Id,T[i].Id)==0)
						{
							T[i].flag=0;//��ɾ����flag��־�������Ǵ����ڿռ���
							            // ���Ǽ�װɾ���������û�����������ɾ���ˣ��㹻 
							break;
						}
					}
					for(i=1;i<=S_Sum;i++)
					{
						if(strcmp(Id,S[i].Id)==0)
						{
							S[i].flag=0;
						}
					}
					printf("ɾ���ɹ���\n");
				}
				printf("    δִ��ɾ��������\n");
				 
				Sort();
				break;
			}
			
			default:printf("\n\n                ��Ҫ��ȡ�������漰�ܼ���������Ч��\n"); break;
		}
		printf("�������롶�޸�ϵͳ�����ܵ�ѡ��:\n");
		printf("1.���ݹ����޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
		printf("2.���������޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
		printf("3.ɾ��ĳһ���ŵĽ�ʦ��������Ϣ\n");
		printf("4.�˳��޸�ϵͳ\n");
		printf("���롶�޸�ϵͳ�����ܵ�ѡ��:");
		
		scanf("%d",&t); 
	}
	 printf("\n�˳��޸�\n\n"); 
}//Change

void Search()
{	
	printf("    ��3-��ѯ��Ϣ����������������������������������������������������������\n");
	printf("1.��ʾ���н�ʦ�Ļ�����Ϣ\n");
	printf("2.�����·���ʾ���н�ʦ���¹�����Ϣ\n");
	printf("3.���ݹ��Ų�ѯĳλ��ʦĳһ�·ݵĻ�����Ϣ�͹�����Ϣ\n"); 
	printf("4.����������ѯĳλ��ʦĳһ�·ݵĻ�����Ϣ�͹�����Ϣ\n");
	printf("5.�˳���ѯϵͳ\n");
	
	int tem;
	int i,j;
	printf("���롶��ѯϵͳ�����ܵ�ѡ��:");
	scanf("%d",&tem);
	while(tem!=5)
	{
		switch(tem)
		{
			case 1:
			{
				for(i=1;i<=T_Sum;i++)
				{
					//���ж��Ƿ�ɾ��
					if(T[i].flag) ShowT(i);					
				}
				break;
			}
			
			case 2:
			{
				printf("\n�����ѯ�·�:");
				int M;
				scanf("%d",&M);
				printf("\nΪ���ҵ�������Ϣ:\n");
				 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M&&S[i].flag)//�ж��Ƿ�ɾ��,��ͬ			
					{
						ShowS(i);
					}
				}
				printf("��ϣ�\n");
				break; 
			}
			
			case 3:
			{
				printf("\n�����ѯ����:");
				char Id[20];
				scanf("%s",Id);
				printf("\n�����ѯ�·�:");
				int M;
				scanf("%d",&M);
				 
				printf("\nΪ���ҵ�������Ϣ:\n");
				int flag=1;
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0&&S[i].Mon==M&&S[i].flag)
					{
						flag=0;
						ShowS(i);
					}
				}
				if(flag)
				{
					printf("\n�޲�ѯ��Ϣ��\n\n");
				} 
				printf("��ϣ�\n");
				break;
			}
			case 4:
			{
				printf("\n�����ѯ����:");
				char Name[20];
				scanf("%s",Name);
				printf("\n�����ѯ�·�:");
				int M;
				scanf("%d",&M); 
				
				printf("\nΪ���ҵ�������Ϣ:\n");
				int flag=1;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Name,T[i].Name)==0&&T[i].flag)
					{
						for(j=1;j<=S_Sum;j++)
						{
							if(strcmp(T[i].Id,S[j].Id)==0&&S[j].Mon==M&&S[j].flag)
							{
								ShowS(j);
							}
						}
						flag=0;	
					}
					if(flag==0) break;//˵����γɹ��ˣ���ǰ����ѭ��
				}
				if(flag)
				{
					printf("\n�޲�ѯ��Ϣ��\n\n");	
				}
				printf("��ϣ�\n");
				break;
			}
			default: printf("\n\n                ��Ҫ��ȡ�������漰�ܼ���������Ч��\n"); break;
		}
		printf("�������롶��ѯϵͳ�����ܵ�ѡ��:\n");
		printf("1.��ʾ���н�ʦ�Ļ�����Ϣ\n");
		printf("2.�����·���ʾ���н�ʦ���¹�����Ϣ\n");
		printf("3.���ݹ��Ų�ѯĳλ��ʦĳһ�·ݵĻ�����Ϣ�͹�����Ϣ\n"); 
		printf("4.����������ѯĳλ��ʦĳһ�·ݵĻ�����Ϣ�͹�����Ϣ\n");
		printf("5.�˳���ѯϵͳ\n");
		scanf("%d",&tem);
	}
	 printf("\n�˳���ѯ\n\n"); 
}//Search

void Analyze()
{	
	int i,j,k;
	int t;
	printf("    ��4-ͳ�Ʒ�������������������������������������������������������������\n");
	printf("1.�����·ݣ�ͳ�Ʋ�ͬѧԺ��ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������\n");
	printf("2.�����·ݣ�ͳ�Ʋ�ְͬ�ƽ�ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������\n");
	printf("3.�˳�ͳ�Ʒ���ϵͳ\n"); 
	scanf("%d",&t);
	printf("���롶ͳ��ϵͳ�����ܵ�ѡ��:");
	
	while(t!=3)
	{
		int M;
		printf("\n�����·�:");
		scanf("%d",&M);
		
		switch(t)
		{
			case 1:
			{
				double Da[5]={0};////Ӧ������ //5��ѧԺ��ͬ�������ݵĴ洢����������� 
				double Ea[5]={0};//ʵ������ //ͬ�� 
				int Sum[5]={0};//����£����ѧԺ��¼���˼���������Ϣ
				//����˵Sum[0]����ʾ�ڵ�M�£���ϢѧԺ�м���������Ϣ 
				//�������ѧԺ�����ó���Ϊ�������洢������ְ��ͬ��
				 
				//������Ϣƥ�䣬������������ʦ�������·� 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M)//�·�������ȷ
					{
						for(j=1;j<=T_Sum;j++)
						{
							if(strcmp(T[j].Id,S[i].Id)==0)//�˵Ĺ��ź͹��ʵĹ�����Ϣƥ�� 
							{
								for(k=0;k<5;k++)//һ��5��ѧԺ������k=5
								//���ö�Ӧһ��ʼ�����ѧԺ��ţ�0��1��2��3��4 ��
								{
									if(strcmp(T[j].College,College[k])==0)//��ʦ����ѧԺ�ı�źͷ�Ժͳ�������еı����ƥ��
									{
										Da[k]+=S[i].D;
										Ea[k]+=S[i].E;
										Sum[k]++;//���Ϊk�����ѧԺ�������Ŀ���У�һ����ʦ�ģ�����
										         //���൱��һ���ӷ�������
										break;//�ҵ�ѧԺֱ���˳�ѧԺ��for k����ѭ��������ѭ������
									}
								}
							}
							break;//��ʦ�Ĺ���Ψһ��ֻҪ�ҵ��Ͳ���ʣ�µĽ�ʦ��
						} 
					}
				}
				
				for(i=0;i<5;i++)
				{
					if(Sum[i]!=0)//һ��ʼ�벻������������sum[i]����ĸ��Ӧ��������Ҫ������������� 
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum[i];
						printf("��%d��%sƽ��Ӧ������:%.2f\n��%d��ƽ��ʵ������:%.2f\n\n",M,College[i],Da[i],M,Ea[i]);
					}
					printf("��Ǹ��%s������Ϣ\n\n",College[i]);
				}
				break;
			}
			
			case 2:
			{
				double Da[4]={0};//4��ְ��Ӧ������
				double Ea[4]={0};//ʵ������ 
				int Sum[4]={0};//���¹�����Ϣ�� 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M)
					{
						for(j=1;j<=T_Sum;j++)
						{
							if(strcmp(T[j].Id,S[i].Id)==0)
							{
								for(k=0;k<4;k++)
								{
									if(strcmp(T[j].Post,Post[k])==0)
									{
										Da[k]+=S[i].D;
										Ea[k]+=S[i].E;
										Sum[k]++;
										break;
									}
								}
							}
							break;
						} 
					}
				}
				
				for(i=3;i>=0;i--)//ְ�ƽ���
				{
					if(Sum[i]!=0)
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum
						[i];
						printf("��%d��%sƽ��Ӧ������:%.2f\n��%d��ƽ��ʵ������:%.2f\n\n",M,Post[i],Da[i],M,Ea[i]);
					}
					else
					printf("��Ǹ��%s������Ϣ\n\n",Post[i]);
				}
				printf("\n��ϣ�\n");
				break;
			}
			
			default:printf("\n\n                ��Ҫ��ȡ�������漰�ܼ���������Ч��\n"); break;
		}
		
		printf("\n������ͳ��ϵͳ�����ܵ�ѡ��:\n");
		printf("1.�����·ݣ�ͳ�Ʋ�ͬѧԺ��ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������:\n");
		printf("2.����ְ�ƣ�ͳ�Ʋ�ͬѧԺ��ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������:\n");
		printf("3.�˳�ͳ�Ʒ���ϵͳ\n");  		 
		
		scanf("%d",&t);
	}
	
	printf("\n��ϣ�\n");
	printf("�˳�ͳ�Ʒ���\n");
}//Analyze

void Out()
{
	printf("    ���ٴ�ȷ���Ƿ�Ҫ�˳�,���¡�y����ʾȷ�ϣ���n����ʾȡ����\n");
	char a=getchar();
	a=getchar();
	if (a == 'y')
	{
		printf("  ���ĵ�¼��Ϣ�ѱ�����������������ķ���ִ�����ϸ�ı����ƶȡ�\n\n");
		printf("                     3s���Զ��˳�"); 
		Sleep(3000);
	}
	if (a == 'n')
	{
		printf("\n  ��������ִ�е�½���򡭡�\n");
		Welcome();
	}
	Sleep(1000);
	system("cls");
}//Out

void InData()
{
	FILE *fp;
	int i;
	fp=fopen("Tdata.txt","wb"); 
	if(fp==NULL)
	{
		printf("   ���ļ�ʧ�ܣ������Ƿ��Ѹ����ļ������ļ�λ��\n");
		exit(0); 
	}
	
	for(i=1;i<=T_Sum;i++)
	{
		if(T[i].flag)
		{
			fwrite(&T[i],sizeof(struct Teacher),1,fp);//��flag��������Ǹ��ṹ��ֱ�����ڻ�����ʱ����ִ��
		}
	}
	fclose(fp);
	fp==NULL;
	
	
	fp=fopen("Sdata.txt","wb");
	if(fp==NULL)
	{
		printf("   ���ļ�ʧ�ܣ������Ƿ��Ѹ����ļ������ļ�λ��\n");
		exit(0); 
	}
	
	for(i=1;i<=S_Sum;i++)
	{
		if(T[i].flag) fwrite(&S[i],sizeof(struct Salary),1,fp);
	}
	fclose(fp);
	fp==NULL;
	
	printf("\n�洢�ɹ���\n");
}//InData

void ReadData()
{
	FILE *fp;
	fp=fopen("Tdata.txt","rb");
	if(fp==NULL)
	{
		printf("   ���ļ�ʧ�ܣ������Ƿ��Ѹ����ļ������ļ�λ��\n");
		exit(0); 
	}
	
	int i=1;
	while(fread(&T[i],sizeof(struct Teacher),1,fp)==1)//��fread����ֵ��1ʱ�������ɹ� 
    {
        i++;//��ʦ��������һ 
    }
    T_Sum=i-1;//��ȡ�ļ�����fread����ֵ��1ʱ��ȡ�ɹ�����ʦ��������һ��������һ��ʼi�Ǵ�1��ʼ��ģ����������������ü�ȥ1
	fclose(fp);
	
	i=1;
	fp=fopen("Sdata.txt","rb");
	if(fp==NULL)
	{
		printf("   ���ļ�ʧ�ܣ������Ƿ��Ѹ����ļ������ļ�λ��\n");
		exit(0); 
	}
	while(fread(&S[i],sizeof(struct Salary),1,fp)==1)
    {
        i++;
    }
    S_Sum=i-1;
	fclose(fp);
	
	printf("\n��ȡ�ɹ���\n");
}

void Sort()//ð���㷨������������
{
	int i,j;
	for(i=1;i<T_Sum;i++)
	{
		for(j=1;j<T_Sum-i+1;j++)
		{
			if(strcmp(T[j].Id,T[j+1].Id)>0)
			{
				T[0]=T[j];
				T[j]=T[j+1];
				T[j]=T[0];//T[0]���õڶ��� 
			}
		}
	} 
}//Sort 
