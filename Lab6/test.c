#include <stdio.h>
void byValue(int x)
{
    x = x + 1;

    printf("during byValue %d\n", x);
}

void byReference(int *y)
{
    *y += 3;
    printf("during byRef %d\n", *y);
        printf("y ref = %p\n",&y);

}

void swapByRef(int *x, int *y)

{
    printf("x ref = %p, y ref = %p\n", x,y);
    int tmp = *x;
    *x = *y;
    *y = tmp;
    
}

void arrayIsRefByDefault(int d[])
{
    d[0] = 7;
}

int main()
{
    int a = 2;
    printf("before byValue %d\n", a);
    byValue(a);
    printf("after byValue %d\n", a);
    printf("***************\n");
    printf("a ref = %p\n",&a);
    printf("before byRef %d\n", a);
    byReference(&a);
    printf("after byRef %d\n", a);
    int b = 9;
    printf("a ref = %p, b ref = %p\n", &a,&b);
    swapByRef(&a, &b);
    printf("swap succeeds with by ref: %d %d\n", a, b);
     printf("a ref = %p, b ref = %p\n", &a,&b);

    printf("* ********\n");
    int c[] = {1, 1};
    arrayIsRefByDefault(c);
    printf("after c is passed %d %d\n", c[0], c[1]);
}