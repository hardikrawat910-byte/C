#include<stdio.h>
	int main()
{
	int n ;
	printf("Enter the size of array :");
	scanf("%d",&n);

	int arr[100];
	printf("Enter %d elements of your choice ",n);

	for(int i=0;i<=n;i++)
    {
	    scanf("%d",&arr[i]);    }

	int largest=arr[0];
	int second=arr[1];

	for(int i=0;i<=n;i++)
    {
	if(arr[i]>largest)
      {
	second=largest;
	largest=arr[i];
      }
	else if(arr[i]>second && arr[i]!=largest)
      {
	second=arr[i];
      }
   }
	printf("The second largest number is %d",second);
	return 0;
}
