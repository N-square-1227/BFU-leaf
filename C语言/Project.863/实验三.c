#include<stdio.h>
int main()
	{	
		while(1)
		{
		    char a=getchar();
		    getchar();
			if(a<=64||a>=91&&a<=96||a>=123&&a<=127)
			{
				printf("不是字母\n"); 
		 	} 
		 	else if(a>=65&&a<=90)
		 	{
		 		printf("是字母，在%d位\n",a-64);
		 	}
		 	else if(a>=97&&a<=122)
		 	{
		 		printf("是字母，在%d位\n",a-96);
		 	}
		 }
			return 0;
	}
