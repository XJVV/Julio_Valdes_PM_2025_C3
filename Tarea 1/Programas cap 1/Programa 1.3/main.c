#include <stdio.h>

/* Promedio de sueldo
El programa, al recibir como datos seis sueldos de un empleado, calcula tanto el ingreso total como el promedio mensal.

CLA: variable de tipo entero.
SU1, SU2, SU3, SU4, SU5, SU6, ING PRO: variable de tipo real. */

void main (void)
{
    int CLA;
    float SU1, SU2, SU3, SU4, SU5, SU6, ING, PRO;
    printf("Ingrese la clave del empleado de los 6 sueldos: /n");
    scanf("%d %f %f %f %f %f %f", &CLA, &SU1, &SU2, &SU3, &SU4, &SU5, &SU6);
    ING = (SU1+SU2+SU3+SU4+SU5+SU6);
    PRO = ING / 6;
    printf("*/n %d %5.2f %5.2f", CLA, ING, PRO);
}
