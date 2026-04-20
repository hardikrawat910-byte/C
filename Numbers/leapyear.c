#include<stdio.h>
	void leapyear(int year)
{ 	 if ((year%400==0)||(year%4==0 && year%100!=0))
{
	printf("This number is leap year");
}
	else
{
	printf("This number is not a leap year");
}
}
	int main()
{	int year;
	printf("Enter a year of your choice to identify leap year:");
	scanf("%d", &year);
	leapyear(year);
	return 0;
}
