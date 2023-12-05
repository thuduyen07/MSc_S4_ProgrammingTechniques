#include <stdio.h>
int main()
{
    int sum = 0, x;
    do
    {
        printf("Input x: ");
        scanf("%d", &x);
        if (x % 2 == 0)
            continue;
        if (x <= 0)
            break;
        sum += x;
    } while (1);
    printf("Sum: %d\n", sum);
    printf("%d", sum);
    return 0;
}