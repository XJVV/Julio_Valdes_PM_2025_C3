#include <stdio.h>
/* Cuenta-numeros.
El programa, al recibir como datos un arreglo unidimensional de tipo
entero y un numero entero, determina cuantas veces se encuentra el
numero en el arreglo. */

void main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[100];  /*Declaracion del arreglo*/
    for (I = 0; I < 100; I++)
    {
        printf("Ingrese el numero %d del arreglo: ", I + 1);
        scanf("%d", &ARRE[I]); /*:ectura -asignacion- del arreglo*/
    }
    printf("\nIngrese el numero que se va a buscar en el arreglo: ");
    scanf("%d", &NUM);
    for (I = 0; I < 100; I++)
        if (ARRE[I] == NUM) /*Comparacion del numero con los elemetos del
                            arreglo*/
            CUE++;
    printf("\nEl %d encuentra %d veces en el arreglo", NUM, CUE);
}

