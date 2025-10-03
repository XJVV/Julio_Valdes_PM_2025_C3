#include <stdio.h>

/*Productoria.
El programa calcula la productoria de los N primeros numeros naturales. */

int Productoria(int);   /*Prototipo de funcion. */

void main(void)
{
    int NUM;
    /*se escribe commo do-while para verificar que el numero del cual quie se
    quiere colcular la protectoria sea correcto. */

    do
    {
        printf("Ingresa el numero del cual quieres calcular la productora: ");
        scanf("%d", &NUM);
    }

    while (NUM > 100 || NUM < 1);
    printf("\n La productoria de %d es: %d", NUM, Productoria(NUM));
}

int Productoria(int N)
/*La funcion calcula la productoria de N. */
{
    int I, PRO = 1;
    for (I = 1; I <= N; I++)
        PRO *= I;
    return (PRO);
}

