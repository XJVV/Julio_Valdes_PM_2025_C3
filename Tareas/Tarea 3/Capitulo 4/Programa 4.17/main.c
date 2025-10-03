#include <stdio.h>

/*Lluvias
el programa permite calcular el promedio mensual de las lluvias caidas en
tres regiones importantes del pais. Determina tambien cual es la region
con mayor promedio de lluvia anual. */

void Mayor (float, float, float);        /*Prototipo de funcion*/

void main(void)
{
    int I;
    float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
    for (I = 1; I <= 12; I++)
    {
        printf("\n\nIngresa las lluvias del mes %d: ", I);
        printf("\nRegiones Golfo, Pacifico y Caribe: ");
        scanf("%f %f %f", &GOL, &PAC, &CAR);
        AGOL += GOL;
        APAC += PAC;
        ACAR += CAR;
    }
    printf("\n\nPromedio de lluvia Region Golfo: %6.2", (AGOL / 12));
    printf("\n\nPromedio de lluvia Region Pacifica: %6.2", (APAC / 12));
    printf("\n\nPromedio de lluvia Region Caribe: % 6.2", (ACAR / 12));
    Mayor(AGOL, APAC, ACAR);
    /*Se llama a la funcion Mayor. Paso e parametros por valor*/
}

void Mayor(float R1, float R2, float R3)
/*Esta funcion obtiene la region con mayor promedio de lluvia anual. */
{
    if (R1 > R2)
        if (R1 > R3)
            printf("\nRegion con mayor promedio: Region Golfo. Promedio: %6.2", (R1 / 12));
        else
            printf("\nRegion con mayor promedio: Region Caribe. Promedio: %6.2", (R3 / 12));
    else
        if (R2 > R3)
            printf("\nRegion con mayor promedio: Region Pacifica. Promedio: %6.2", (R2 / 12));
        else
            printf("\nRegion con mayor promedio: Region Caribe. Promedio: %6.2", (R3 / 12));
}
