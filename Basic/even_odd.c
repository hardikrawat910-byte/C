#include <stdio.h>

int main() {
	 clrscr();
    int n;
    printf("Enter a value: "); // Ensure the prompt is printed before input
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("Given value %d is even\n", n);
    else
        printf("Given value %d is odd\n", n);

    if (n > 0)
        printf("Given value %d is positive\n", n);
    else if (n < 0)
        printf("Given value %d is negative\n", n);
    else
        printf("Given value is zero\n");

    return 0;
	}