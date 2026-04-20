#include<stdio.h>
#include<math.h>
	int main()
{
	double principal;
	double rate;
	double time;

	printf("Enter the principal amount :");
	scanf("%le",&principal);

	printf("Enter the intrest rate :");
	scanf("%le",&rate);

	printf("Enter the time for which the amount is lend or borrowed :");
	scanf("%le",&time);

	double amount=principal*((pow((1+rate/100),time)));

	double cl=amount-principal;

	printf("The compund intrest is %f",cl);

	return 0;
}
