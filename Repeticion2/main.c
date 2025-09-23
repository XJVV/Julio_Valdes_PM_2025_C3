#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSE 0

int main()
{
    int num = 0;

    for(num = -10; num <=10; num++)
    {
        if ((num == -5) || (num ==5))
        {
        printf("\nValor num:%i", num*10);
        }
    }
    printf("\nFIN!");
    return 0;
}
