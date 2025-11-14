#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define ARCHI "inventario.txt"

// Estructura para representar un producto
typedef struct {
    int codigo;
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

/* Prototipos de funciones*/
int contarProductos();
Producto* cargarInventario(int *numProductos);
void mostrarInventario(Producto *inventario, int numProductos);
void agregarProducto();
void liberarMemoria(Producto *inventario);
void limpiarBuffer();
int obtenerOpcion(const char *pregunta);

int main() {
    Producto *inventario = NULL;
    int numProductos = 0;
    int opcion;

    printf("Cargando inventario desde archivo...\n"); /* Buscando inventario si ahi */
    inventario = cargarInventario(&numProductos);

    if (inventario != NULL) {
        printf("Inventario cargado exitosamente: %d productos\n\n", numProductos);
    } else {
        printf("No se encontro inventario previo. Se iniciara uno nuevo.\n\n");
        numProductos = 0;
    }

    /* Agregar algo*/
    opcion = obtenerOpcion("Desea agregar un nuevo producto al inventario? (1=Si, 0=No): ");

    if (opcion == 1) {
        agregarProducto();

        /* Liberar espacio de almacenamiento para actualizar */
        liberarMemoria(inventario);
        inventario = cargarInventario(&numProductos);
        printf("\nProducto agregado exitosamente!\n\n");
    }

    /* Ver inventario */
    opcion = obtenerOpcion("Desea ver el inventario completo? (1=Si, 0=No): ");

    if (opcion == 1 && inventario != NULL) {
        mostrarInventario(inventario, numProductos);
    } else if (opcion == 1 && inventario == NULL) {
        printf("\nNo hay productos en el inventario.\n");
    }

    /*Liberando memoria*/
    liberarMemoria(inventario);

    printf("\nGracias por usar el sistema de inventario!\n");

    return 0;
}

/*Funcion de ver cuando hay en el inventario*/
int contarProductos() {
    FILE *archivo = fopen(ARCHI, "r");
    int count = 0;
    char linea[200];

    if (archivo == NULL) {
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        count++;
    }

    fclose(archivo);
    return count;
}

/* Función para cargar el inventario desde archivo usando memoria dinámica */
Producto* cargarInventario(int *numProductos) {
    FILE *archivo = fopen(ARCHI, "r");
    Producto *inventario = NULL;
    int count = 0;

    if (archivo == NULL) {
        *numProductos = 0;
        return NULL;
    }

    /* Contar productos */
    count = contarProductos();

    if (count == 0) {
        fclose(archivo);
        *numProductos = 0;
        return NULL;
    }

    /* Asignar memoria dinámica */
    inventario = (Producto*)malloc(count * sizeof(Producto));

    if (inventario == NULL) {
        printf("Error: No se pudo asignar memoria o no hay espacio.\n"); /*Tengo un solo sueño*/
        fclose(archivo);
        *numProductos = 0;
        return NULL;
    }

    /* volver abrir archivo para leer desde el inicio */
    fclose(archivo);
    archivo = fopen(ARCHI, "r");

    /* Leer productos */
    int i = 0;
    while (i < count && fscanf(archivo, "%d,%49[^,],%d,%f\n",
                                &inventario[i].codigo,
                                inventario[i].nombre,
                                &inventario[i].cantidad,
                                &inventario[i].precio) == 4) {
        i++;
    }

    fclose(archivo);
    *numProductos = i;

    return inventario;
}

/* Función para mostrar el inventario completo */
void mostrarInventario(Producto *inventario, int numProductos) {
    printf("\nINVENTARIO ACTUAL\n");
    printf("%-8s %-25s %-12s %-10s\n", "Codigo", "Nombre", "Cantidad", "Precio");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numProductos; i++) {
        printf("%-8d %-25s %-12d $%-9.2f\n",
               inventario[i].codigo,
               inventario[i].nombre,
               inventario[i].cantidad,
               inventario[i].precio);
    }

    printf("-------------------------------------------------\n");
    printf("Total de productos: %d\n", numProductos);
}

/* Función para agregar un nuevo producto al archivo */
void agregarProducto() {
    FILE *archivo = fopen(ARCHI, "a");
    Producto nuevo;

    if (archivo == NULL) {
        /* Si el archivo no existe, crearlo atento a mi*/
        archivo = fopen(ARCHI, "w");
        if (archivo == NULL) {
            printf("Error: No se pudo abrir el archivo.\n");
            return;
        }
    }

    printf("\n--- AGREGAR NUEVO PRODUCTO ---\n");

    printf("Codigo del producto: ");
    scanf("%d", &nuevo.codigo);
    limpiarBuffer();

    printf("Nombre del producto: ");
    fgets(nuevo.nombre, MAX_NOMBRE, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; // Eliminar salto de línea

    printf("Cantidad: ");
    scanf("%d", &nuevo.cantidad);

    printf("Precio: ");
    scanf("%f", &nuevo.precio);
    limpiarBuffer();

    /* Escribir en el archivo */
    fprintf(archivo, "%d,%s,%d,%.2f\n",
            nuevo.codigo,
            nuevo.nombre,
            nuevo.cantidad,
            nuevo.precio);

    fclose(archivo);
}

/* Función para liberar la memoria dinamica */
void liberarMemoria(Producto *inventario) {
    if (inventario != NULL) {
        free(inventario);
    }
}

/* Función para limpiar el buffer de entrada */
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*Función para obtener una opción del usuario */
int obtenerOpcion(const char *pregunta) {
    int opcion;
    printf("%s", pregunta);
    scanf("%d", &opcion);
    limpiarBuffer();
    return opcion;
}

/* Esto fue un trabajo en equipo yo pense que iba a ser facil y no lo fue. Yo hice la logica y entre casi 3/4 del codigo, gemini lo puso bonito
y le arreglo par de errores*/
