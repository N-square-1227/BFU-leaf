#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
const int Max = 500;
char Post[4][20]={"助教","讲师","副教授","教授"};//职务编号对照 
char College[5][20]={"信息学院","工学院","理学院","人文学院","生物学院"};
struct Teacher {
	char Name[20];//姓名
	char Id[20];//工号
	char College[20];//学院 
	char Post[20];//职务 1.助教 2.讲师 3.副教授 4.教授，这里直接用的字符数组，可换成其他表示类型 
	int flag;//是否被删除的标志 
}T[Max];//教师结构体
int T_Sum;//教师人数
void InT(int i);//输入教师信息函数 
void ShowT(int i);//显示教师信息函数 

struct Salary {
	char Id[20];
	int Mon;
	double A,B,C,D,E;//基本工资、业绩津贴、扣除费用、应发工资、实发工资
	int flag;//作用同上 
}S[Max];//工资结构体
int S_Sum;//工资信息数目
void InS(int i);//输入工资信息函数 
void ShowS(int i);//显示工资信息函数 

void Welcome();//欢迎界面 原代码
void Addinfo();//录入信息
void Change();//修改数据
void Search();//查找数据
void Analyze();//统计分析
void Out();//退出 原代码
void InData();//储存内容 
void ReadData();//读取储存内容 
void Sort();//排序函数 

int main()
{
	Welcome();
	return 0;
}
void InT(int i)
{
	int t;
	printf("姓名:"); scanf("%s", T[i].Name);
	printf("工号:"); scanf("%s",T[i].Id);
	
	printf("学院:(0.信息学院 1.工学院 2.理学院 3.人文学院 4.生物学院)");
	scanf("%d",&t);
	strcpy(T[i].College,College[t]);
	
	printf("职务:(0.助教 1.讲师 2.副教授 3.教授)");
	scanf("%d",&t) ;
	strcpy(T[i].Post,Post[t]);
	
	T[i].flag=1;
}
void ShowT(int i)
{
	printf("\n工号:%s\n",T[i].Id);
	printf("姓名:%s\n",T[i].Name);
	printf("学院:%s\n",T[i].College);
	printf("职务:%s\n",T[i].Post);
}//ShowT
void InS(int i)
{
	printf("工号:"); scanf("%s", S[i].Id);
	printf("月份:(数字)"); scanf("%d", &S[i].Mon);
	printf("依次录入基本工资、业绩津贴、扣除费用:\n");
	scanf("%lf%lf%lf", &S[i].A, &S[i].B, &S[i].C);
	S[i].D = S[i].A + S[i].B;
	S[i].E = S[i].D - S[i].C;
	S[i].flag=1;
}
void ShowS(int i)
{
	printf("\n工号:%s\n月份:%d\n基本工资:%.2lf\n业绩津贴:%.2lf\n扣除费用:%.2lf\n应发工资:%.2lf\n实发工资:%.2lf\n",S[i].Id,S[i].Mon,S[i].A,S[i].B,S[i].C,S[i].D,S[i].E);
}//ShowS
void Welcome()
{
	int i;
	printf("                                  验证中……\n");
	Sleep(500);
	printf("                            ");
	for (i = 0; i < 10; i++)
	{
		printf("■");
		Sleep(100);
	}
	printf("\n");
	Sleep(1500);
	printf("                                身份验证通过。\n");
	Sleep(1000);
	printf("                   您已取得最高权限，欢迎您访问天命数据库。\n");
	printf("    ——————————————————————————————————\n");
	printf("                                 ★ 绝密 ★启用前\n"); //这是中间 
	printf("    ———————————————————————————————————\n");
	printf("    —1-录入信息—————————————————————————————\n");
	printf("    —2-修改数据—————————————————————————————\n");
	printf("    —3-查询信息—————————————————————————————\n");
	printf("    —4-统计分析—————————————————————————————\n");
	printf("    —5-退出系统—————————————————————————————\n");
	printf("    —6-使用保存数据———————————————————————————\n");
	printf("    ———————————————————————————————————\n");
	printf("          按下指定数字的按钮来获得你想知道的一切。\n");
	int a;//switch语句尽量用int型 
	scanf("%d",&a);//不用担心最后的回车符所造成的影响 
	while (a != 5)
	{
		switch (a)
		{
			case 1:Addinfo(); break;
			case 2:Change(); break;
			case 3:Search(); break;
			case 4:Analyze(); break;
			case 6:ReadData();break;
			default:printf("\n\n                您不应当觊觎超出这个世代的知识。\n"); break;
		}

		printf("\n继续《主菜单》功能的选择:");
		scanf("%d",&a);
	}
	InData();
	Out();
}//Welcome
void Addinfo()
{
	printf("    —1-录入信息—————————————————————————————\n");
	printf("教师人数：");//输入输出均可自行更改
	scanf("%d", &T_Sum);
	printf("开始录入教师信息\n");
	int i,j;
	for (i = 1; i <= T_Sum; i++)
	{
		printf("\n第%d位教师信息录入\n",i);
		InT(i);
		T[0] = T[i];//T[0]不录入有用信息，可重复当中间变量使用 ,很实用 
		j = i - 1;//下面是一些小算法，简单实用 
		while (strcmp(T[i].Id, T[j].Id) != 0)
		{
			j--;
		}
		if (j != 0)
		{
			printf("\n工号重复！录入作废！\n");
			i--;
		}
		else
		{
			printf("录入成功！\n");
		}
	}
	printf("录入教师信息完毕！\n");
	Sort();//按工号排序 
	printf("\n工资信息数目：");
	scanf("%d", &S_Sum);
	for (i = 1; i <= S_Sum; i++)
	{
		printf("\n第%d条工资信息录入\n", i);
		InS(i);
		int flag=1;//判断录入工资信息里的工号是否存在 
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
			printf("\n工号不存在！重新录入！\n\n");
			i--;
		}
		ShowS(i);
	}
	printf("录入工资信息完毕！\n\n");
	printf("录入完毕！自动退出系统\n\n");
}//Addinfo
void Change()
{
	printf("    —2-修改数据—————————————————————————————\n");
	printf("1.根据工号修改某位教师的基本信息和工资信息\n");
	printf("2.根据姓名修改某位教师的基本信息和工资信息\n");
	printf("3.删除某一工号的教师的所有信息\n");
	printf("4.退出修改系统\n");
	int select,i,j;
	printf("输入《修改系统》功能的选择:");
	scanf("%d",&select);
	while(select!=4)
	{
		switch(select)
		{
			case 1:{
				char Id[20];
				printf("输入修改工号:");
				scanf("%s",Id);
				printf("修改基本信息\n");
				int flag=1;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						flag=0;
						printf("原信息:\n");
						ShowT(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						if(t==2) break;//基本信息只有一次，直接break 
						printf("修改信息:\n");
						InT(i);//修改就是重新输入并覆盖 
					}
				}
				if(flag)
				{
					printf("查询失败！\n");
					break;//查询失败，case语句直接退出 
				}
				printf("修改工资信息信息\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0)
					{
						printf("原信息:\n");
						ShowS(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						if(t==2) continue;//工资信息可能有很多 
						printf("修改信息:\n");
						InS(i);
					}
				}
				Sort(); 
				break;
			}
			case 2:{
				char Name[20];
				printf("输入修改姓名:");
				scanf("%s",Name);
				printf("修改基本信息\n");
				int t;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Name,T[i].Name)==0)
					{
						t=i;//临时变量储存 
						printf("原信息:\n");
						ShowT(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						if(t==2) break;
						printf("修改信息:\n");
						InT(i);
					}
				}
				printf("修改工资信息信息\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(T[t].Id,S[i].Id)==0)
					{
						printf("原信息:\n");
						ShowS(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						if(t==2) continue;//工资信息可能有很多 
						printf("修改信息:\n");
						InS(i);
					}
				}
				Sort();
				break;
			}
			case 3:{
				char Id[20];
				printf("输入工号:");
				scanf("%s",Id);
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						T[i].flag=0;//删除标志，但还是储存在空间里 
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
				printf("删除成功！\n");
				Sort();
				break;
			}
			default:printf("\n\n                您不应当觊觎超出这个世代的知识。\n"); break;
		}
		printf("继续输入《修改系统》功能的选择:");
		scanf("%d",&select);
	}
	 printf("\n退出修改\n\n"); 
}//Change
void Search()
{
	printf("    —3-查询信息—————————————————————————————\n");
	printf("1.显示所有教师的基本信息\n");
	printf("2.根据月份显示所有教师当月工资信息\n");
	printf("3.根据工号查询某位教师某一月份的基本信息和工资信息\n"); 
	printf("4.根据姓名查询某位教师某一月份的基本信息和工资信息\n");
	printf("5.退出查询系统\n");
	int select,i,j;
	printf("输入《查询系统》功能的选择:");
	scanf("%d",&select);
	while(select!=5)
	{
		switch(select)
		{
			case 1:{
				for(i=1;i<=T_Sum;i++)
				{
					if(T[i].flag) ShowT(i);//先判断是否被删除					
				}
				break;
			}
			case 2:{
				printf("\n输入查询月份:");
				int M;
				scanf("%d",&M);
				printf("\n为您找到以下信息:\n");
				for(int i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M&&S[i].flag)//判断是否被删除,下同			
					{
						ShowS(i);
					}
				}
				printf("完毕！\n");
				break; 
			}
			case 3:{
				printf("\n输入查询工号:");
				char Id[20];
				scanf("%s",Id);
				printf("\n输入查询月份:");
				int M;
				scanf("%d",&M); 
				printf("\n为您找到以下信息:\n");
				int flag=1;
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0&&S[i].Mon==M&&S[i].flag)
					{
						flag=0;
						ShowS(i);
					}
				}
				if(flag) printf("\n无查询信息！\n\n");
				printf("完毕！\n");
				break;
			}
			case 4:{
				printf("\n输入查询姓名:");
				char Name[20];
				scanf("%s",Name);
				printf("\n输入查询月份:");
				int M;
				scanf("%d",&M); 
				printf("\n为您找到以下信息:\n");
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
				if(flag) printf("\n无查询信息！\n\n");
				
				printf("完毕！\n");
				break;
			}
			default: printf("\n\n                您不应当觊觎超出这个世代的知识。\n"); break;
		}
		printf("继续输入《查询系统》功能的选择:");
		scanf("%d",&select);
	}
	 printf("\n退出查询\n\n"); 
}//Search
void Analyze()
{
	printf("    —4-统计分析—————————————————————————————\n");
	printf("1.根据月份，统计不同学院教师的平均应发工资和平均实发工资\n");
	printf("2.根据月份，统计不同职称教师的平均应发工资和平均实发工资\n");
	printf("3.退出统计分析系统\n"); 
	int select,i,j,k;
	printf("输入《统计系统》功能的选择:");
	scanf("%d",&select);
	while(select!=3)
	{
		int M;
		double Da[5]={0};//4种职务应发工资
		double Ea[5]={0};//实发工资 
		int Sum[5]={0};//该月工资信息数 
		printf("\n输入月份:");
		scanf("%d",&M);
		switch(select)
		{
			case 1:{
				double Da[5]={0};//5个学院应发工资 
				double Ea[5]={0};//实发工资 
				int Sum[5]={0};//该月工资信息数 
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
						printf("第%d月%s平均应发工资:%.2f\n第%d月平均实发工资:%.2f\n\n",M,College[i],Da[i],M,Ea[i]);
					}
					else
					{
						printf("抱歉，%s暂无信息\n\n",College[i]);
					}
				}
				break;
			}
			case 2:{
				double Da[4]={0};//4种职务应发工资
				double Ea[4]={0};//实发工资 
				int Sum[4]={0};//该月工资信息数 
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
						printf("第%d月%s平均应发工资:%.2f\n第%d月平均实发工资:%.2f\n\n",M,Post[i],Da[i],M,Ea[i]);
					}
					else
					{
						printf("抱歉，%s暂无信息\n\n",Post[i]);
					}
				}
				printf("\n完毕！\n");
				break;
			}
			default:printf("\n\n                您不应当觊觎超出这个世代的知识。\n"); break;
		}
		printf("\n继续《统计系统》功能的选择:");
		scanf("%d",&select);
	}
	
	printf("\n完毕！\n");
	printf("退出统计分析\n");
}//Analyze
void Out()
{
	printf("    请再次确认是否要退出,按下“y”表示确认；“n”表示取消。\n");
	char a;
	getchar();
	a = getchar();//不能用别的，不然回车键也会被读取。getche：输入一个字符后会立刻被读取。 
	if (a == 'y')
	{
		//printf("  ……你的名字无人知晓，你的事迹与世长存。\n\n") ; 
		printf("  我是Otto·Apocalypse，我的勇士，我们会再见的。那么，祝你好运。\n");
		Sleep(3000);
		exit(1);
	}
	if (a == 'n')
	{
		printf("\n  看来你还想再多流连一会？请吧。\n");
		Welcome();
	}
	Sleep(3000);
	system("cls");
}//Out
void InData()
{
	FILE *fp;
	int i;
	fp=fopen("D:\\Tdata.txt","wb");//自定义路径 
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
	printf("\n存储成功！\n");
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
	printf("\n读取成功！\n");
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
				T[j]=T[0];//T[0]作用第二次 
			}
		}
	}//冒泡算法，按工号排序 
}//Sort 
