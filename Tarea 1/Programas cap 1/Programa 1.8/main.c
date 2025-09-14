#include <stdio.h>
#include <math.h>

/* Volumen y area del cilindo
El programa, al recibir com datos el radio y la altura de un cilindo,
calcula su area y su volumen.

RAD, ALT, VOL y ARE: varibles de tipo real. */

void main (void)
{
    float RAD, ALT, VOL, ARE;
    printf("Ingrese el radio y la altura del cilindo: ");
    scanf("%f %f", &RAD, &ALT);
    /* M_PI es una constante definida en mat.h que contiene el valor de PI */
    VOL = M_PI * pow (RAD, 2) * ALT;
    ARE = 2 * M_PI * RAD * ALT;
    printf("\nEl volumen es: %6.2f \t El area es: %6.2f", VOL, ARE);
}
