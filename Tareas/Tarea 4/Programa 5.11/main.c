#include <stdio.h>

/* B�squeda binaria. */

const int MAX=100;
void Lectura(int*, int); /* Prototipos de funciones. */
int Binaria(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1); /* Se verifica que el tama�o del arreglo sea corrcto. */

    Lectura(VEC, TAM);
    printf("\Ingrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Binaria(VEC, TAM, ELE); /* Se llama a la funci�n que busca en el arreglo. */

    if (RES)
    /* Si RES tiene un valor verdadero �diferente de 0�, se escribe la
    posicion en la que se encontro el elemento. */
        printf("\nEl elemento se encuentra en la posicion: %d", RES);
}

void Lectura(int A[], int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de T
elemtos de tipo entero. */

{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento: %d", I+1);
    }
}

int Binaria(int A[], int T, int E)
/* Esta funci�n se utiliza para realizar una b�squeda binaria del
elemento E en el arreglo unidimensional A de T elementos. Si se
encuentra el elemento, la funci�n regresa la posici�n correspondiente.
En caso contrario, regresa 0. */

{
    int ELE, IZQ = 0, CEN, DER = T-1, BAN = 0;
    while ((IZQ <= DER) && (!BAN))
    {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            BAN = CEN;
        else
            if (E > A[CEN])
                IZQ = CEN + 1;
            else
                DER = CEN - 1;
    }
    return (BAN);
}
