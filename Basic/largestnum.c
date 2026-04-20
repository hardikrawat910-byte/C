#include<stdio.h>
	int main()
{	int a,b,c;
	printf("Enter any three numbers of yours choice to find largest number:");
	scanf("%d %d %d",&a,&b,&c);
	if (a>b && a>c)
{
	printf("The value is %d is largest",a);
}
	else if(b>a && b>c)
{
	printf("The value is %d is largest",b);
}
	else 
{
	printf("The value is %d is largest",c);
}
	return 0;
}
