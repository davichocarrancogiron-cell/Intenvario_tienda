
#include <stdio.h>
#include <string.h>

#define MAX 10

// Declaracion de funciones
void ingresarDatos(char nombres[MAX][50], float precios[MAX], int cantidad);
float calcularTotal(float precios[MAX], int cantidad);
float calcularPromedio(float precios[MAX], int cantidad);
int buscarMayor(float precios[MAX], int cantidad);
int buscarMenor(float precios[MAX], int cantidad);
void buscarProducto(char nombres[MAX][50], float precios[MAX], int cantidad);

int main() {
    char nombres[MAX][50];
    float precios[MAX];
    int cantidad;
    int mayor, menor;

    printf("====================================\n");
    printf("    SISTEMA DE INVENTARIO\n");
    printf("====================================\n");

    // Ingreso de la cantidad de productos
    do {
        printf("Ingrese la cantidad de productos (1-10): ");
        scanf("%d", &cantidad);

        if (cantidad < 1 || cantidad > MAX) {
            printf("Error: ingrese una cantidad entre 1 y 10.\n");
        }

    } while (cantidad < 1 || cantidad > MAX);

    // Ingreso de los datos
    ingresarDatos(nombres, precios, cantidad);

    // Mostrar el inventario
    printf("\n====================================\n");
    printf("       INVENTARIO REGISTRADO\n");
    printf("====================================\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%s - Precio: $%.2f\n", nombres[i], precios[i]);
    }

    // Calcular el total y el promedio
    printf("\nPrecio total del inventario: $%.2f\n",
           calcularTotal(precios, cantidad));

    printf("Precio promedio: $%.2f\n",
           calcularPromedio(precios, cantidad));

    // Encontrar el producto mas caro y el mas barato
    mayor = buscarMayor(precios, cantidad);
    menor = buscarMenor(precios, cantidad);

    printf("\nProducto mas caro: %s - $%.2f\n",
           nombres[mayor], precios[mayor]);

    printf("Producto mas barato: %s - $%.2f\n",
           nombres[menor], precios[menor]);

    // Buscar un producto por su nombre
    buscarProducto(nombres, precios, cantidad);

    printf("\n====================================\n");
    printf("       FIN DEL PROGRAMA\n");
    printf("====================================\n");

    return 0;
}

// Funcion para ingresar nombres y precios
void ingresarDatos(char nombres[MAX][50], float precios[MAX], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);

        printf("Ingrese el nombre del producto: ");
        scanf(" %49[^\n]", nombres[i]);

        do {
            printf("Ingrese el precio del producto: $");
            scanf("%f", &precios[i]);

            if (precios[i] < 0) {
                printf("Error: el precio no puede ser negativo.\n");
            }

        } while (precios[i] < 0);
    }
}

// Funcion para calcular el precio total
float calcularTotal(float precios[MAX], int cantidad) {
    float total = 0;

    for (int i = 0; i < cantidad; i++) {
        total = total + precios[i];
    }

    return total;
}

// Funcion para calcular el precio promedio
float calcularPromedio(float precios[MAX], int cantidad) {
    float total = calcularTotal(precios, cantidad);

    return total / cantidad;
}

// Funcion para encontrar el producto mas caro
int buscarMayor(float precios[MAX], int cantidad) {
    int mayor = 0;

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[mayor]) {
            mayor = i;
        }
    }

    return mayor;
}

// Funcion para encontrar el producto mas barato
int buscarMenor(float precios[MAX], int cantidad) {
    int menor = 0;

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[menor]) {
            menor = i;
        }
    }

    return menor;
}

// Funcion para buscar un producto por su nombre
void buscarProducto(char nombres[MAX][50], float precios[MAX], int cantidad) {
    char nombreBuscado[50];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto que desea buscar: ");
    scanf(" %49[^\n]", nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado: %s\n", nombres[i]);
            printf("Precio: $%.2f\n", precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("El producto no se encuentra en el inventario.\n");
    }
}
