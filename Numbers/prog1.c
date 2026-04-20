#include <stdio.h>
#include <conio.h>

int main() {
    int a, b;
    char op;
    clrscr();
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter operator (+, -, etc.): ");
    scanf(" %c", &op);  // Space before %c skips newline
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            if (b != 0) printf("%d / %d = %d\n", a, b, a / b);
            else printf("Division by zero!\n");
            break;
        default:
            printf("Invalid operator!\n");
    }
    getch();
    return 0;
}
