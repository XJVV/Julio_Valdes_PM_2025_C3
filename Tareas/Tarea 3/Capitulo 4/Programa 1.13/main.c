#include <stdio.h>
#include <math.h>

/* Pares e impares.
el programa, al recibir como datos N numeros enteros, calcula cuantos
de ellos son pares y cuantos impares, con la ayuda de una funcion.*/

void parimp(int, int *, int *);     /*Prototipo de funcion*/

void main(void)
{
    int I, N, NUM, PAR = 0, IMP = 0;
    printf("Ingrese el numero de datos: ");
    scanf("%d", &N);
    for (I = 1; I <= N; I++)
    {
        printf("Ingrese el numero %d: ", I);
        scanf("%d", &NUM);
        parimp(NUM, &PAR, &IMP);
    /*Llamada a la funcion. Paso d parametros por valor y por
    referencia. */
    }
    printf("\nNumero de pares: %d", PAR);
    printf("\nNumero de impares: %d", IMP);
}

void parimp(int NUM, int *P, int *I)
/*La funcion incrementa el parametro *P o *I, segun sea el numero par
o impar. */
{
    int RES;
    RES = pow(-1, NUM);
    if (RES > 0)
        *I9 += 1;
}
