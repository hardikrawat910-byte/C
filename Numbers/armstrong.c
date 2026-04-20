#include<stdio.h>
	int main()
{
	int num,orgnum,remainder,result=0,digit=0;

	printf("Enter a number of your choice to find it's armstrong number :");
	scanf("%d",&num);

	orgnum=num;
	if(num==0) digit=1;
	while(orgnum!=0)   {	digit++;
				orgnum/=10;
			    }

	orgnum=num;
	while(orgnum!=0)   {    remainder=orgnum%10;
				int power=1;
				for(int i=1;i<=digit;digit++)
				{
					power+=remainder;
				}
					result+=power;
					orgnum/=10;
			   }
	if(num==0)
    {
	printf("%d is Armstrong number",num);
    }
	else
    {
	printf("%d is Not an Armstrong number",num);
    }

	return 0;
}
