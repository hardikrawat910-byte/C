#include<stdio.h>
int main()
{
	int x,y;
	printf("Enter the two value for swapping the number without using the third variable :");
	scanf("%d %d",&x,&y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("The value for first digit after swapping is %d \n",x);
	printf("The value for second digit after swapping is %d",y);
	return 0;
}
