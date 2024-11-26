#include<stdio.h>
#include<stdlib.h>//sizeof 
#include<string.h>//strcmp,strcpy 
#include<windows.h>//清屏
#define Max 500

//职务编号对照 
char Post[4][20]={"助教","讲师","副教授","教授"};
//学院编号对照
char College[5][20]={"信息学院","工学院","理学院","人文学院","生物学院"};

struct Teacher
 {
	char Name[20];//姓名
	char Id[20];//工号
	char College[20];//学院 
	char Post[20];//职务 1.助教 2.讲师 3.副教授 4.教授 
	int flag;//是否被[删除]的标志 
}T[Max];//教师结构体
int T_Sum;//教师人数
void InT(int i);//输入教师信息函数 
void ShowT(int i);//显示教师信息函数 

struct Salary 
{
	char Id[20];//这里，尽管定义的类型和名字都和Teacher结构体一样
	            //但是这是两个不一样的变量，不会相互混淆的。
	int Mon;
	double A,B,C,D,E;//基本工资、业绩津贴、扣除费用、应发工资、实发工资
	int flag;//作用同上 
}S[Max];//工资结构体
int S_Sum;//工资信息数目
void InS(int i);//输入工资信息函数 
void ShowS(int i);//显示工资信息函数 

void Welcome();//欢迎界面
void Addinfo();//录入信息
void Change();//修改数据
void Search();//查找数据
void Analyze();//统计分析
void Out();//退出
void InData();//储存内容 
void ReadData();//读取储存内容
//追加  
void Sort();//排序函数 

int main()
{
	Welcome();
	return 0;
}

void InT(int i)
{
	int t;
	
	printf("姓名:");
	scanf("%s", T[i].Name);
	printf("工号(01开始):");
	scanf("%s",T[i].Id);
	
	printf("学院:(0.信息学院 1.工学院 2.理学院 3.人文学院 4.生物学院)");
	scanf("%d",&t);
	while(t<0||t>4)
	{
		printf("学院信息错误！请重新输入！\n");
		scanf("%d", &t);
	}
	strcpy(T[i].College,College[t]);
	
	printf("职务:(0.助教 1.讲师 2.副教授 3.教授)");
	scanf("%d",&t) ;
	while(t<0||t>3)
	{
		printf("职务信息错误！请重新输入！\n");
		scanf("%d", &t);
	}
	strcpy(T[i].Post,Post[t]);
	
	T[i].flag=1;//该教师信息录入完毕 
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
	printf("工号:");
	scanf("%s", S[i].Id);
	printf("月份:(数字)");
	scanf("%d", &S[i].Mon);
	while(S[i].Mon>12||S[i].Mon<1)
	{
		printf("月份信息错误！请重新输入！\n");
		i--;
		scanf("%d", &S[i].Mon);
	}
	
	printf("依次录入基本工资、业绩津贴、扣除费用:\n");
	
	//2020.12.18早九点更改，添加了三个while，保证工资信息不为负值 
	scanf("%lf", &S[i].A);
	while(S[i].A<0)
	{
		printf("基本工资信息错误！请重新输入！\n");
		i--;
		scanf("%d", &S[i].A);
	}
	
	scanf("%lf", &S[i].B);
	while(S[i].B<0)
	{
		printf("业绩津贴信息错误！请重新输入！\n");
		i--;
		scanf("%d", &S[i].B);
	}
	
	scanf("%lf", &S[i].C);
	while(S[i].C<0)
	{
		printf("扣除费用信息错误！请重新输入！\n");
		i--;
		scanf("%d", &S[i].C);
	}
	
	S[i].D = S[i].A + S[i].B;
	S[i].E = S[i].D - S[i].C;
	
	S[i].flag=1;//工资信息输入完成
}

void ShowS(int i)
{
	printf("\n工号:%s\n",S[i].Id);
	printf("月份:%d\n",S[i].Mon);
	
	printf("基本工资:%.2lf\n",S[i].A);
	printf("业绩津贴:%.2lf\n",S[i].B);
	printf("扣除费用:%.2lf\n",S[i].C);
	printf("应发工资:%.2lf\n",S[i].D);
	printf("实发工资:%.2lf\n",S[i].E);
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
		Sleep(50);
	}
	printf("\n");
	Sleep(1500);
	printf("                                身份验证通过。\n");
	Sleep(1000);
	printf("                   您已取得最高权限，欢迎您访问天命数据库。\n");
	printf("    ——————————————————————————————————\n");
	printf("                              ★ 绝密 ★启用前\n"); 
	printf("    ———————————————————————————————————\n");
	printf("    —1-录入信息—————————————————————————————\n");
	printf("    —2-修改数据—————————————————————————————\n");
	printf("    —3-查询信息—————————————————————————————\n");
	printf("    —4-统计分析—————————————————————————————\n");
	printf("    —5-退出系统—————————————————————————————\n");
	printf("    —6-使用保存数据———————————————————————————\n");
	printf("    ———————————————————————————————————\n");
	printf("                       按下指定数字来做出你的指示。\n");

	int a; 	
	scanf("%d",&a);
	
	//先判断是不是要用系统
	while (a!= 5) 
	{
		switch (a)
		{
			case 1:Addinfo(); break;
			case 2:Change(); break;
			case 3:Search(); break;
			case 4:Analyze(); break;
			case 6:ReadData();break;
			default:printf("\n\n                您要获取的资料涉及密级。申请无效。\n"); break;
		}
		
		printf("\n继续《主菜单》功能的选择:\n");
		printf(" 1-录入信息\n");
		printf(" 2-修改数据\n");
		printf(" 3-查询信息\n");
		printf(" 4-统计分析\n");
		printf(" 5-退出系统\n");
		printf(" 6-使用保存数据\n");
		scanf("%d",&a);
	}
	
	InData();//退出的时候！！先!保!!存！！！数！！！！据！！！！！ 
	Out();
}//Welcome


void Addinfo()
{
	printf("    —1-录入信息—————————————————————————————\n");
	printf("教师人数：");
	scanf("%d", &T_Sum);
	
	printf("开始录入教师信息\n");
	int i,j;
	for (i = 1; i <= T_Sum; i++)
	{
		printf("\n第%d位教师信息录入\n",i);
		InT(i);
		T[0] = T[i];//T[0]当中间变量使用 
		
		//查重算法 
		j = i - 1;
		while (strcmp(T[i].Id, T[j].Id) != 0)
		{
			j--;
		}
		
		if (j != 0)//如果j在不等于零的时候就退出来了
		           //说明在之前已经出现了一个相同的工号 
		{
			printf("\n工号重复！录入作废！\n");
			i--;//重新开始这次循环并重新录入信息
		}
		else
		{
			printf("录入成功！\n");
		}
	}
	printf("录入教师信息完毕！\n");
	Sort();//立刻按工号排序
	
	//工资信息的录入 
	printf("\n工资信息数目：");
	scanf("%d", &S_Sum);//录几个人的，有没工资信息的人就输0略过去
	while(S_Sum>T_Sum)
	{
		printf("   工资数目不能大于教师的数目！请重新输入！\n"); 
		scanf("%d", &S_Sum);//2020.12.18早上修改 
	}                       //之前写的没有这个while循环，直接读取S_Sum,没有判断大小关系 
	
	for (i = 1; i <= S_Sum; i++)
	{
		printf("\n第%d条工资信息录入\n", i);
		InS(i);
		
		//判断工号输入合法性 
		int flag=1;//判断录入工资信息里的工号是否存在的变量 
		for(j=1;j<=T_Sum;j++)//这里的指标是T_sum,可以没有工资，但是必须得有人（doge） 
		{
			if(strcmp(S[i].Id,T[j].Id)==0)//可以理解为：j<=i，所以把j穷举完了i也不一定穷举完 
			{                             //一定能找到一个对应工号（如果输入正确的话） 
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
	int t;
	printf("    —2-修改数据—————————————————————————————\n");
	printf("1.根据工号修改某位教师的基本信息和工资信息\n");
	printf("2.根据姓名修改某位教师的基本信息和工资信息\n");
	printf("3.删除某一工号的教师的所有信息\n");
	printf("4.退出修改系统\n");
	scanf("%d",&t);
	printf("输入《修改系统》功能的选择:");
	
	int i;//i是之后根据需要补充的。
	
	while(t!=4)
	{
		switch(t)
		{
			case 1:
			{
				char Id[20];
				printf("输入修改工号:");
				scanf("%s",Id);
				printf("修改基本信息\n");
				
				int flag=1;
				for(i=1;i<=T_Sum;i++)
				{
					if(strcmp(Id,T[i].Id)==0)
					{
						flag=0;//找到了工号为…的教师 

						//用户友好性
						printf("原信息:\n");
						ShowT(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						
						if(t==2)
						{
							break;//教师是按工号查找，唯一，只要找到,就不用再找了，直接break 
							      //教师和工号之间是一一对应的关系 
						}
						printf("修改信息:\n");
						InT(i);//修改就是重新输入并覆盖
							  //同一工号连续输入两次信息，会自动覆盖上一次
					}
				}
				if(flag==1)
				{
					printf("查询失败！\n");
					break;//查询失败，case语句直接退出 
				}
				
				//修改工资信息 
				printf("修改工资信息\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(Id,S[i].Id)==0)
					{
						printf("原信息:\n");
						ShowS(i);
						printf("是否修改？1.是, 2.否");
						int t;
						scanf("%d",&t);
						
						if(t==2)
						{
							continue;//而工资信息，一个 工号 可以对应很多信息
							//和教师与工号之间的一一对应的关系不同 
							//第一条找到之后，无法确定下面还有没有这个工号的工资信息，就继续
							//所以不能break 
						}
						printf("修改信息:\n");
						InS(i);
					}
				}
				
				Sort(); //排序！！ 
				break; 
			}
			
			case 2:
			{
				char Name[20];
				printf("输入待修改者姓名:");
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
						int tem;
						scanf("%d",&tem);
						if(tem==2) break;
						printf("修改信息:\n");
						InT(i);
					}
				}
				
				printf("修改工资信息\n");
				for(i=1;i<=S_Sum;i++)
				{
					if(strcmp(T[t].Id,S[i].Id)==0)
					{
						printf("原信息:\n");
						ShowS(i);
						printf("是否修改？1.是, 2.否");
						int tem;
						scanf("%d",&tem);
						if(tem==2) continue;//工资信息可能有很多 
						printf("修改信息:\n");
						InS(i);
					}
				}
				
				Sort();
				break;
			}
			
			case 3:
			{
				printf("请再次确认是否执行删除操作！！按数字1：是  2：不是\n");
				int m;
				scanf("%d",&m);
				if(m==1)
				{ 
					char Id[20];
					printf("输入工号:");
					scanf("%s",Id);
					for(i=1;i<=T_Sum;i++)
					{
						if(strcmp(Id,T[i].Id)==0)
						{
							T[i].flag=0;//【删除】flag标志，但还是储存在空间里
							            // 就是假装删除…反正用户看不到就是删除了（你够 
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
				}
				printf("    未执行删除操作！\n");
				 
				Sort();
				break;
			}
			
			default:printf("\n\n                您要获取的资料涉及密级。申请无效。\n"); break;
		}
		printf("继续输入《修改系统》功能的选择:\n");
		printf("1.根据工号修改某位教师的基本信息和工资信息\n");
		printf("2.根据姓名修改某位教师的基本信息和工资信息\n");
		printf("3.删除某一工号的教师的所有信息\n");
		printf("4.退出修改系统\n");
		printf("输入《修改系统》功能的选择:");
		
		scanf("%d",&t); 
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
	
	int tem;
	int i,j;
	printf("输入《查询系统》功能的选择:");
	scanf("%d",&tem);
	while(tem!=5)
	{
		switch(tem)
		{
			case 1:
			{
				for(i=1;i<=T_Sum;i++)
				{
					//先判断是否被删除
					if(T[i].flag) ShowT(i);					
				}
				break;
			}
			
			case 2:
			{
				printf("\n输入查询月份:");
				int M;
				scanf("%d",&M);
				printf("\n为您找到以下信息:\n");
				 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M&&S[i].flag)//判断是否被删除,下同			
					{
						ShowS(i);
					}
				}
				printf("完毕！\n");
				break; 
			}
			
			case 3:
			{
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
				if(flag)
				{
					printf("\n无查询信息！\n\n");
				} 
				printf("完毕！\n");
				break;
			}
			case 4:
			{
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
					if(flag==0) break;//说明这次成功了，提前结束循环
				}
				if(flag)
				{
					printf("\n无查询信息！\n\n");	
				}
				printf("完毕！\n");
				break;
			}
			default: printf("\n\n                您要获取的资料涉及密级。申请无效。\n"); break;
		}
		printf("继续输入《查询系统》功能的选择:\n");
		printf("1.显示所有教师的基本信息\n");
		printf("2.根据月份显示所有教师当月工资信息\n");
		printf("3.根据工号查询某位教师某一月份的基本信息和工资信息\n"); 
		printf("4.根据姓名查询某位教师某一月份的基本信息和工资信息\n");
		printf("5.退出查询系统\n");
		scanf("%d",&tem);
	}
	 printf("\n退出查询\n\n"); 
}//Search

void Analyze()
{	
	int i,j,k;
	int t;
	printf("    —4-统计分析—————————————————————————————\n");
	printf("1.根据月份，统计不同学院教师的平均应发工资和平均实发工资\n");
	printf("2.根据月份，统计不同职称教师的平均应发工资和平均实发工资\n");
	printf("3.退出统计分析系统\n"); 
	scanf("%d",&t);
	printf("输入《统计系统》功能的选择:");
	
	while(t!=3)
	{
		int M;
		printf("\n输入月份:");
		scanf("%d",&M);
		
		switch(t)
		{
			case 1:
			{
				double Da[5]={0};////应发工资 //5个学院的同类型数据的存储，得用数组吧 
				double Ea[5]={0};//实发工资 //同上 
				int Sum[5]={0};//这个月（这个学院）录入了几条工资信息
				//比如说Sum[0]，表示在第M月，信息学院有几条工资信息 
				//给出五个学院，就用长度为五的数组存储，下面职称同理
				 
				//工号信息匹配，工资人数，教师人数，月份 
				for(i=1;i<=S_Sum;i++)
				{
					if(S[i].Mon==M)//月份输入正确
					{
						for(j=1;j<=T_Sum;j++)
						{
							if(strcmp(T[j].Id,S[i].Id)==0)//人的工号和工资的工号信息匹配 
							{
								for(k=0;k<5;k++)//一共5个学院，所以k=5
								//正好对应一开始输入的学院编号（0，1，2，3，4 ）
								{
									if(strcmp(T[j].College,College[k])==0)//教师所在学院的编号和分院统计数组中的编号能匹配
									{
										Da[k]+=S[i].D;
										Ea[k]+=S[i].E;
										Sum[k]++;//编号为k的这个学院这项工资条目里有（一个老师的）数据
										         //这相当于一个加法计数器
										break;//找到学院直接退出学院（for k）的循环，减少循环次数
									}
								}
							}
							break;//教师的工号唯一，只要找到就不看剩下的教师了
						} 
					}
				}
				
				for(i=0;i<5;i++)
				{
					if(Sum[i]!=0)//一开始想不到，但从下面sum[i]当分母反应过来这里要补充这个条件的 
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum[i];
						printf("第%d月%s平均应发工资:%.2f\n第%d月平均实发工资:%.2f\n\n",M,College[i],Da[i],M,Ea[i]);
					}
					printf("抱歉，%s暂无信息\n\n",College[i]);
				}
				break;
			}
			
			case 2:
			{
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
				
				for(i=3;i>=0;i--)//职称降序
				{
					if(Sum[i]!=0)
					{
						Da[i]/=Sum[i];
						Ea[i]/=Sum
						[i];
						printf("第%d月%s平均应发工资:%.2f\n第%d月平均实发工资:%.2f\n\n",M,Post[i],Da[i],M,Ea[i]);
					}
					else
					printf("抱歉，%s暂无信息\n\n",Post[i]);
				}
				printf("\n完毕！\n");
				break;
			}
			
			default:printf("\n\n                您要获取的资料涉及密级。申请无效。\n"); break;
		}
		
		printf("\n继续《统计系统》功能的选择:\n");
		printf("1.根据月份，统计不同学院教师的平均应发工资和平均实发工资:\n");
		printf("2.根据职称，统计不同学院教师的平均应发工资和平均实发工资:\n");
		printf("3.退出统计分析系统\n");  		 
		
		scanf("%d",&t);
	}
	
	printf("\n完毕！\n");
	printf("退出统计分析\n");
}//Analyze

void Out()
{
	printf("    请再次确认是否要退出,按下“y”表示确认；“n”表示取消。\n");
	char a=getchar();
	a=getchar();
	if (a == 'y')
	{
		printf("  您的登录信息已被清除，天命将对您的访问执行最严格的保密制度。\n\n");
		printf("                     3s后自动退出"); 
		Sleep(3000);
	}
	if (a == 'n')
	{
		printf("\n  正在重新执行登陆程序……\n");
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
		printf("   打开文件失败！请检查是否已更改文件名或文件位置\n");
		exit(0); 
	}
	
	for(i=1;i<=T_Sum;i++)
	{
		if(T[i].flag)
		{
			fwrite(&T[i],sizeof(struct Teacher),1,fp);//当flag所代表的那个结构体直到现在还存在时，才执行
		}
	}
	fclose(fp);
	fp==NULL;
	
	
	fp=fopen("Sdata.txt","wb");
	if(fp==NULL)
	{
		printf("   打开文件失败！请检查是否已更改文件名或文件位置\n");
		exit(0); 
	}
	
	for(i=1;i<=S_Sum;i++)
	{
		if(T[i].flag) fwrite(&S[i],sizeof(struct Salary),1,fp);
	}
	fclose(fp);
	fp==NULL;
	
	printf("\n存储成功！\n");
}//InData

void ReadData()
{
	FILE *fp;
	fp=fopen("Tdata.txt","rb");
	if(fp==NULL)
	{
		printf("   打开文件失败！请检查是否已更改文件名或文件位置\n");
		exit(0); 
	}
	
	int i=1;
	while(fread(&T[i],sizeof(struct Teacher),1,fp)==1)//当fread返回值是1时，读数成功 
    {
        i++;//教师的人数加一 
    }
    T_Sum=i-1;//读取文件，当fread返回值是1时读取成功，教师的人数加一，但由于一开始i是从1开始算的，所以最后的人数还得减去1
	fclose(fp);
	
	i=1;
	fp=fopen("Sdata.txt","rb");
	if(fp==NULL)
	{
		printf("   打开文件失败！请检查是否已更改文件名或文件位置\n");
		exit(0); 
	}
	while(fread(&S[i],sizeof(struct Salary),1,fp)==1)
    {
        i++;
    }
    S_Sum=i-1;
	fclose(fp);
	
	printf("\n读取成功！\n");
}

void Sort()//冒泡算法，按工号排序
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
	} 
}//Sort 
