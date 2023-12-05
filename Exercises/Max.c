#include <stdio.h>
void main(){
    bool bVal;
    float x =. 6.7F, y = 93F, z;
    bVal = (x==y);
    printf("%d\n", bVal);
    bVal = (x<y);
    printf("%d\n", bVal);
    z = (x>y)*x + (x<=y)*y;
    printf("Max of x and y is: %d\n", z);
}