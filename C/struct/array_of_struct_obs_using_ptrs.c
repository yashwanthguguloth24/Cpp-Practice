#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int Re;
    int Im;
}C;



int main()
{
    int x[] = {1,2,3};
    //struct C X[3];
    //C X[3];
    C *X = (C *) malloc(3*sizeof(C));
    for(int i = 0;i<=2;i++)
    {
        X[i].Re = x[i];
        X[i].Im = x[i];
        printf("Re and Im are %d , %d \n",X[i].Re,X[i].Im);
        printf("%d\n",x[i]);
    }
}
