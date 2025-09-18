#include <stdio.h>
#include <math.h>

/* Area del triangulo
El programa, al recibir los tres lados de un triangulo, calcula su area.

LA1, LA2, LA3, AUX y ARE: varibles de tipo real. */

void main (void)
{
    float LA1, LA2, LA3, AUX, ARE;
    printf("Ingrese los lados del triangulo: ");
    scanf("%f %f %f", &LA1, &LA2, &LA3);
    AUX = (LA1 + LA2 + LA3) / 2;
    ARE = sqrt (AUX * (AUX-LA1) * (AUX-LA2) * (AUX-LA3));
    /* sqrt es una funcion de math.h que calcula la raiz cuadrade de un numero */
    printf("\nEl area del triangulo es: %6.2f", ARE);
}
