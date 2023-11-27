#include <stdio.h>

int main()
{
    int a, b, vmin, vmax;
    printf("Input a: ");
    scanf("%d", &a);

    printf("Input b: ");
    scanf("%d", &b);

    if (a > b)
    {
        vmin = b;
        vmax = a;
    }
    else
    {
        vmin = a;
        vmax = b;
    }
    printf("Min: %d\nMax: %d\n", vmin, vmax);
    return 0;
}