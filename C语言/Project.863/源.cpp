#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
const int Max = 500;
char Post[4][20]={"����","��ʦ","������","����"};//ְ���Ŷ��� 
char College[5][20]={"��ϢѧԺ","��ѧԺ","��ѧԺ","����ѧԺ","����ѧԺ"};
struct Teacher {
	char Name[20];//����
	char Id[20];//����
	char College[20];//ѧԺ 
	char Post[20];//ְ�� 1.���� 2.��ʦ 3.������ 4.���ڣ�����ֱ���õ��ַ����飬�ɻ���������ʾ���� 
	int flag;//�Ƿ�ɾ���ı�־ 
}T[Max];//��ʦ�ṹ��
int T_Sum;//��ʦ����
void InT(int i);//�����ʦ��Ϣ���� 
void ShowT(int i);//��ʾ��ʦ��Ϣ���� 

struct Salary {
	char Id[20];
	int Mon;
	double A,B,C,D,E;//�������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ������
	int flag;//����ͬ�� 
}S[Max];//���ʽṹ��
int S_Sum;//������Ϣ��Ŀ
void InS(int i);//���빤����Ϣ���� 
void ShowS(int i);//��ʾ������Ϣ���� 

void Welcome();//��ӭ���� ԭ����
void Addinfo();//¼����Ϣ
void Change();//�޸�����
void Search();//��������
void Analyze();//ͳ�Ʒ���
void Out();//�˳� ԭ����
void InData();//�������� 
void ReadData();//��ȡ�������� 
void Sort();//������ 

int main()
{
	Welcome();
	return 0;
}
void InT(int i)
{
	int t;
	printf("����:"); scanf("%s", T[i].Name);
	printf("����:"); scanf("%s",T[i].Id);
	
	printf("ѧԺ:(0.��ϢѧԺ 1.��ѧԺ 2.��ѧԺ 3.����ѧԺ 4.����ѧԺ)");
	scanf("%d",&t);
	strcpy(T[i].College,College[t]);
	
	printf("ְ��:(0.���� 1.��ʦ 2.������ 3.����)");
	scanf("%d",&t) ;
	strcpy(T[i].Post,Post[t]);
	
	T[i].flag=1;
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
	printf("����:"); scanf("%s", S[i].Id);
	printf("�·�:(����)"); scanf("%d", &S[i].Mon);
	printf("����¼��������ʡ�ҵ���������۳�����:\n");
	scanf("%lf%lf%lf", &S[i].A, &S[i].B, &S[i].C);
	S[i].D = S[i].A + S[i].B;
	S[i].E = S[i].D - S[i].C;
	S[i].flag=1;
}
void ShowS(int i)
{
	printf("\n����:%s\n�·�:%d\n��������:%.2lf\nҵ������:%.2lf\n�۳�����:%.2lf\nӦ������:%.2lf\nʵ������:%.2lf\n",S[i].Id,S[i].Mon,S[i].A,S[i].B,S[i].C,S[i].D,S[i].E);
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
		Sleep(100);
	}
	printf("\n");
	Sleep(1500);
	printf("                                �����֤ͨ����\n");
	Sleep(1000);
	printf("                   ����ȡ�����Ȩ�ޣ���ӭ�������������ݿ⡣\n");
	printf("    ��������������������������������������������������������������������\n");
	printf("                                 �� ���� ������ǰ\n"); //�����м� 
	printf("    ����������������������������������������������������������������������\n");
	printf("    ��1-¼����Ϣ����������������������������������������������������������\n");
	printf("    ��2-�޸����ݡ���������������������������������������������������������\n");
	printf("    ��3-��ѯ��Ϣ����������������������������������������������������������\n");
	printf("    ��4-ͳ�Ʒ�������������������������������������������������������������\n");
	printf("    ��5-�˳�ϵͳ����������������������������������������������������������\n");
	printf("    ��6-ʹ�ñ������ݡ�����������������������������������������������������\n");
	printf("    ����������������������������������������������������������������������\n");
	printf("          ����ָ�����ֵİ�ť���������֪����һ�С�\n");
	int a;//switch��価����int�� 
	scanf("%d",&a);//���õ������Ļس�������ɵ�Ӱ�� 
	while (a != 5)
	{
		switch (a)
		{
			case 1:Addinfo(); break;
			case 2:Change(); break;
			case 3:Search(); break;
			case 4:Analyze(); break;
			case 6:ReadData();break;
			default:printf("\n\n                ����Ӧ�����쳬�����������֪ʶ��\n"); break;
		}

		printf("\n���������˵������ܵ�ѡ��:");
		scanf("%d",&a);
	}
	InData();
	Out();
}//Welcome
void Addinfo()
{
	printf("    ��1-¼����Ϣ����������������������������������������������������������\n");
	printf("��ʦ������");//��������������и���
	scanf("%d", &T_Sum);
	printf("��ʼ¼���ʦ��Ϣ\n");
	int i,j;
	for (i = 1; i <= T_Sum; i++)
	{
		printf("\n��%dλ��ʦ��Ϣ¼��\n",i);
		InT(i);
		T[0] = T[i];//T[0]��¼��������Ϣ�����ظ����м����ʹ�� ,��ʵ�� 
		j = i - 1;//������һЩС�㷨����ʵ�� 
		while (strcmp(T[i].Id, T[j].Id) != 0)
		{
			j--;
		}
		if (j != 0)
		{
			printf("\n�����ظ���¼�����ϣ�\n");
			i--;
		}
		else
		{
			printf("¼��ɹ���\n");
		}
	}
	printf("¼���ʦ��Ϣ��ϣ�\n");
	Sort();//���������� 
	printf("\n������Ϣ��Ŀ��");
	scanf("%d", &S_Sum);
	for (i = 1; i <= S_Sum; i++)
	{
		printf("\n��%d��������Ϣ¼��\n", i);
		InS(i);
		int flag=1;//�ж�¼�빤����Ϣ��Ĺ����Ƿ���� 
		for(j=1;j<=T_Sum;j++)
		{
			if(strcmp(S[i].Id,T[j].Id)==0)
			{
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
	printf("    ��2-�޸����ݡ���������������������������������������������������������\n");
	printf("1.���ݹ����޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
	printf("2.���������޸�ĳλ��ʦ�Ļ�����Ϣ�͹�����Ϣ\n");
	printf("3.ɾ��ĳһ���ŵĽ�ʦ��������Ϣ\n");
	printf("4.�˳��޸�ϵͳ\n");
	int select,i,j;
	printf("���롶�޸�ϵͳ�����ܵ�ѡ��:");
	scanf("%d",&select);
	while(select!=4)
	{
		switch(select)
		{
			case 1:{
				char Id[20];
				printf("�����޸Ĺ���:");
				scanf("%s",Id);
				printf("�޸Ļ�����Ϣ\n");
				int flag=1;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						flag=0;
						printf("ԭ��Ϣ:\n");
						ShowT(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int t;
						scanf("%d",&t);
						if(t==2) break;//������Ϣֻ��һ�Σ�ֱ��break 
						printf("�޸���Ϣ:\n");
						InT(i);//�޸ľ����������벢���� 
					}
				}
				if(flag)
				{
					printf("��ѯʧ�ܣ�\n");
					break;//��ѯʧ�ܣ�case���ֱ���˳� 
				}
				printf("�޸Ĺ�����Ϣ��Ϣ\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0)
					{
						printf("ԭ��Ϣ:\n");
						ShowS(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int t;
						scanf("%d",&t);
						if(t==2) continue;//������Ϣ�����кܶ� 
						printf("�޸���Ϣ:\n");
						InS(i);
					}
				}
				Sort(); 
				break;
			}
			case 2:{
				char Name[20];
				printf("�����޸�����:");
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
						int t;
						scanf("%d",&t);
						if(t==2) break;
						printf("�޸���Ϣ:\n");
						InT(i);
					}
				}
				printf("�޸Ĺ�����Ϣ��Ϣ\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(T[t].Id,S[i].Id)==0)
					{
						printf("ԭ��Ϣ:\n");
						ShowS(i);
						printf("�Ƿ��޸ģ�1.��, 2.��");
						int t;
						scanf("%d",&t);
						if(t==2) continue;//������Ϣ�����кܶ� 
						printf("�޸���Ϣ:\n");
						InS(i);
					}
				}
				Sort();
				break;
			}
			case 3:{
				char Id[20];
				printf("���빤��:");
				scanf("%s",Id);
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						T[i].flag=0;//ɾ����־�������Ǵ����ڿռ��� 
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
				Sort();
				break;
			}
			default:printf("\n\n                ����Ӧ�����쳬�����������֪ʶ��\n"); break;
		}
		printf("�������롶�޸�ϵͳ�����ܵ�ѡ��:");
		scanf("%d",&select);
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
	int select,i,j;
	printf("���롶��ѯϵͳ�����ܵ�ѡ��:");
	scanf("%d",&select);
	while(select!=5)
	{
		switch(select)
		{
			case 1:{
				for(i=1;i<=T_Sum;i++)
				{
					if(T[i].flag) ShowT(i);//���ж��Ƿ�ɾ��					
				}
				break;
			}
			case 2:{
				printf("\n�����ѯ�·�:");
				int M;
				scanf("%d",&M);
				printf("\nΪ���ҵ�������Ϣ:\n");
				for(int i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M&&S[i].flag)//�ж��Ƿ�ɾ��,��ͬ			
					{
						ShowS(i);
					}
				}
				printf("��ϣ�\n");
				break; 
			}
			case 3:{
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
				if(flag) printf("\n�޲�ѯ��Ϣ��\n\n");
				printf("��ϣ�\n");
				break;
			}
			case 4:{
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
					if(flag==0) break;
				}
				if(flag) printf("\n�޲�ѯ��Ϣ��\n\n");
				
				printf("��ϣ�\n");
				break;
			}
			default: printf("\n\n                ����Ӧ�����쳬�����������֪ʶ��\n"); break;
		}
		printf("�������롶��ѯϵͳ�����ܵ�ѡ��:");
		scanf("%d",&select);
	}
	 printf("\n�˳���ѯ\n\n"); 
}//Search
void Analyze()
{
	printf("    ��4-ͳ�Ʒ�������������������������������������������������������������\n");
	printf("1.�����·ݣ�ͳ�Ʋ�ͬѧԺ��ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������\n");
	printf("2.�����·ݣ�ͳ�Ʋ�ְͬ�ƽ�ʦ��ƽ��Ӧ�����ʺ�ƽ��ʵ������\n");
	printf("3.�˳�ͳ�Ʒ���ϵͳ\n"); 
	int select,i,j,k;
	printf("���롶ͳ��ϵͳ�����ܵ�ѡ��:");
	scanf("%d",&select);
	while(select!=3)
	{
		int M;
		double Da[5]={0};//4��ְ��Ӧ������
		double Ea[5]={0};//ʵ������ 
		int Sum[5]={0};//���¹�����Ϣ�� 
		printf("\n�����·�:");
		scanf("%d",&M);
		switch(select)
		{
			case 1:{
				double Da[5]={0};//5��ѧԺӦ������ 
				double Ea[5]={0};//ʵ������ 
				int Sum[5]={0};//���¹�����Ϣ�� 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M)
					{
						for(j=1;j<=T_Sum;j++)
						{
							if(strcmp(T[j].Id,S[i].Id)==0)
							{
								for(k=0;k<5;k++)
								{
									if(strcmp(T[j].College,College[k])==0)
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
				for(i=0;i<5;i++)
				{
					if(Sum[i]!=0)
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum[i];
						printf("��%d��%sƽ��Ӧ������:%.2f\n��%d��ƽ��ʵ������:%.2f\n\n",M,College[i],Da[i],M,Ea[i]);
					}
					else
					{
						printf("��Ǹ��%s������Ϣ\n\n",College[i]);
					}
				}
				break;
			}
			case 2:{
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
				for(i=3;i>=0;i--)
				{
					if(Sum[i]!=0)
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum[i];
						printf("��%d��%sƽ��Ӧ������:%.2f\n��%d��ƽ��ʵ������:%.2f\n\n",M,Post[i],Da[i],M,Ea[i]);
					}
					else
					{
						printf("��Ǹ��%s������Ϣ\n\n",Post[i]);
					}
				}
				printf("\n��ϣ�\n");
				break;
			}
			default:printf("\n\n                ����Ӧ�����쳬�����������֪ʶ��\n"); break;
		}
		printf("\n������ͳ��ϵͳ�����ܵ�ѡ��:");
		scanf("%d",&select);
	}
	
	printf("\n��ϣ�\n");
	printf("�˳�ͳ�Ʒ���\n");
}//Analyze
void Out()
{
	printf("    ���ٴ�ȷ���Ƿ�Ҫ�˳�,���¡�y����ʾȷ�ϣ���n����ʾȡ����\n");
	char a;
	getchar();
	a = getchar();//�����ñ�ģ���Ȼ�س���Ҳ�ᱻ��ȡ��getche������һ���ַ�������̱���ȡ�� 
	if (a == 'y')
	{
		//printf("  ���������������֪��������¼��������档\n\n") ; 
		printf("  ����Otto��Apocalypse���ҵ���ʿ�����ǻ��ټ��ġ���ô��ף����ˡ�\n");
		Sleep(3000);
		exit(1);
	}
	if (a == 'n')
	{
		printf("\n  �����㻹���ٶ�����һ�᣿��ɡ�\n");
		Welcome();
	}
	Sleep(3000);
	system("cls");
}//Out
void InData()
{
	FILE *fp;
	int i;
	fp=fopen("D:\\Tdata.txt","wb");//�Զ���·�� 
	for(i=1;i<=T_Sum;i++)
	{
		if(T[i].flag) fwrite(&T[i],sizeof(Teacher),1,fp);
	}
	fclose(fp);
	fp=fopen("D:\\Sdata.txt","wb");
	for(i=1;i<=S_Sum;i++)
	{
		if(T[i].flag) fwrite(&S[i],sizeof(Salary),1,fp);
	}
	fclose(fp);
	printf("\n�洢�ɹ���\n");
}//InData
void ReadData()
{
	FILE *fp;
	fp=fopen("D:\\Tdata.txt","rb");
	int i=1;
	while(fread(&T[i],sizeof(Teacher),1,fp)==1)
    {
        i++;
    }
    T_Sum=i-1;
	fclose(fp);
	
	i=1;
	fp=fopen("D:\\Sdata.txt","rb");
	while(fread(&S[i],sizeof(Salary),1,fp)==1)
    {
        i++;
    }
    S_Sum=i-1;
	fclose(fp);
	printf("\n��ȡ�ɹ���\n");
}
void Sort()
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
	}//ð���㷨������������ 
}//Sort 
