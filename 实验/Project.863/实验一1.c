#include<stdio.h>
int main()
{
	int i;
	int ge,shi,bai;
	for(i=200;i<=300;i++)
	{
		bai=i/100;
		shi=i/10%10;
		ge=i%10%10;
		if(bai*shi*ge==42&&bai+shi+ge==12)
		{
			printf("%d\n",i);
		}
	 }
	 return 0; 
}
