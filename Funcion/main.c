#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0
#define MAX_EDAD 120
#define MIN_EDAD 0

int main()
{
    //0-2 infante
    //3-10 niño
    //13-17 adolecente
    //18- 40 mayor de edad
    //41 - 65 adulto mayor
    // > envejeciente
    int edad = 0;
    printf("\nIngrese la edad: ");
    scanf("%i", &edad);

    if (edad >= MIN_EDAD && edad <= MAX_EDAD)
        {
            if (edad <=2)
            {
                printf("\nEs un infante");
            }
            if (edad >= 3 && edad <= 12)
            {
                printf("\nEs un nino");
            }
            if ( edad == 16)
            {
                printf("\nFelicidades te ganaste un apartamento");
            }
            if (edad >= 13 && edad <= 17)
            {
                printf("\nEs un adolecente");
            }
            if (edad >= 18 && edad <=40)
            {
                printf("\nEs un mayor de edad");
            }
            if (edad == 45)
            {
                printf("\nFelicidades te ganaste una CRV");
            }
            if (edad >= 41 && edad <= 65)
            {
                printf("\nEs un adulto mayor");
            }
            if (edad >= 65)
            {
                printf("\nEs un envejeciente");
            }
        }
    else {
        printf("\nEdad fuera de rango!");
        if (edad < MIN_EDAD)
            printf("\nUsted viede del pasado!");
        {
        if (edad > MAX_EDAD )
            printf("\nUsted es un bampiro!");

        }
    }

    printf("\nFin del programa");

    return 0;
}
