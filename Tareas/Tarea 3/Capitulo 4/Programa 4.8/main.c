#include <stdio.h>

/*Combinacion de variables globales y locales, y parametros por valor
y referencia. */

int a, b, c, d;     /*Variable globales*/

void funcion1(int *, int *);
/*Prototipo de funcion. Observa que los dos parametros son por
referencia*/

int funcion2(int, int *);
/*En este prototipo el primer parametro es por valor y el segundo por
referencia. */

void main(void)
{
    int a;
    a = 1;  /* Nota que a es una variable local. */
    b = 2;  /* Se asigna un valor a la variable local a. */
    c = 3;  /* Se asignan valores a las variables gloabales b, c y d*/
    d = 4;
    printf("\n%d %d %d %d", a, b, c, d);
    funcion1(&b, &c);
    printf("\n%d %d %d %d", a, b, c, d);
    a = funcion2(c, &d);
    printf("\n%d %d %d %d %d", a, b, c, d);
}

void funcion1(int *b, int *c)
{
    int d;
    a = 5;
    d = 3;
    (*b)++;
    (*c) += 2;
    printf("\n%d %d %d %d", a, *b, *c, d);
}

int funcion2(int c, int *d)
{
    int b;
    a++;
    b = 7;
    c += 3;
    (*d) += 2;
    printf("\n%d %d %d %d", a, b, c, *d);
    return (c);
}
