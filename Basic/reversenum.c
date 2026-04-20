#include<stdio.h>
	int main()
{
	int num,remainder,reversed=0;

	printf("Enter a number you have to reverse :");
	scanf("%d",&num);

	while(num!=0)
    {
	remainder=num%10;
	reversed=reversed*10+remainder;
	num/=10;
    }
	printf("Your reversed number is %d",reversed);
	return 0;
}
