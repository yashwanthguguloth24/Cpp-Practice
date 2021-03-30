#include <stdio.h>

int main()
{
    // swapping using pointers
    int x = 5;
    int y = 10;
    printf("Before swapping x = %d and y = %d\n",x,y);
    int *p;
    int *k;
    int t;
    k = &y;
    p = &x;
    t = *p;
    *p = *k;
    *k = t;
    printf("After swapping x = %d and y = %d\n",x,y);
    return 0;
}
