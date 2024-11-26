#include<stdio.h>
int main()
{
	void mystrcat(char*s1,char*s2,char*new_s);
	void inv(char*x,int n);
	
	char a[]="1357911";
	char b[]="8642";
	char c[20];

	char*x,*y,*z;
	x=a,y=b,z=c;
	
	inv(b,4);
	mystrcat(x,y,z);
	printf("%s\n",c);
	return 0;
}

	void inv(char*x,int n)
{
	int i;
	int tem;
	for(i=0;i<n/2+1;i++)
	{
		tem=x[i];
		x[i]=x[n-i-1];
		x[n-i-1]=tem;
	}
}

	void mystrcat(char*s1,char*s2,char*new_s)
	{
		for(;*s2!='\0';s1++,s2++,new_s++)
		{
			*new_s=*s1;
		     new_s+=1;
			*new_s=*s2;
		}
		
		for(;*s1!='\0';s1++,new_s++)
	    {
    		*new_s=*s1;
	    }  
	}
