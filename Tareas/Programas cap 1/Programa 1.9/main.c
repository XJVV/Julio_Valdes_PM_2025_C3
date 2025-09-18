#include <stdio.h>

/* Estancia
El programa, al recibir como valor dato la superficie de una estancia expresada
en acres, la convierte a hectareas.

ECA: variable de tipo real. */

void main(void)
{
    float ECA;
    printf("\nIngrese la extension de la estancia: ");
    scanf("%f", &ECA);
    ECA = ECA * 4047 / 10000;
    printf("\nExtension de la estancia en hectarias: %5.2f", ECA);
}
