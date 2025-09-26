#include <stdio.h>

/*Nomina de profesores
El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.

I: variable de tipo real
SAL, NOM y PRO: variable de tipo real. */

void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;
    printf("Ingrese el salario del profesor:\t");
    scanf("%f", &SAL);

    do
    {
        NOM = NOM + SAL;
        I + I + 1;
        printf("Ingrese el salario del profesor -0 para termina- :\t");
        scanf("%f", &SAL);
    }
    while (SAL);
    PRO = NOM / I;
    printf("\nNomina: %2f \t Promedio de salario: %2f", NOM, PRO);
}
