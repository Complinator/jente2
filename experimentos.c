#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listas.h"
#include "bst.h"

void generateArr(int arr[], int size){
    time_t t;
    srand((unsigned) time (&t));
    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }
}

int main(int argc, char *argv[]){	
    nodo_lista *lista;
    nodo_arbol *root;
    int lenghts[] = {100, 1000, 10000, 100000, 200000, 500000};
    int n = sizeof(lenghts) / sizeof(lenghts[0]);

    for(int i = 0; i < n; i++){
        lista = NULL;
        root = NULL;
        int arr[lenghts[i]];

        generateArr(arr, lenghts[i]);
        printf("Usando %d datos:\n", lenghts[i]);
        printf("- Insercion:\n");

        for(int j = 0; j < 2; j++){
            clock_t start_t, end_t;
            double total_t;
            start_t = clock();

            switch (j){
                case 0:
                    for(int k = 0; k < lenghts[i]; k++){
                        lista = insertar_lista(lista, arr[k]);
                    }
                    printf("  - En Listas, demora un total de ");
                    break;

                case 1:
                    for(int k = 0; k < lenghts[i]; k++){
                        root = insertar_arbol(root, arr[k]);
                    }
                    printf("  - En Arboles, demora un total de ");
                    break;

                default:
                    break;
            }
            end_t = clock();
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("%lf s\n", total_t);
        }
        printf("- Busqueda:\n");

        for(int j = 0; j < 2; j++){
            clock_t start_t, end_t;
            double total_t;
            start_t = clock();

            switch (j){
                case 0:
                    for(int k = 0; k < lenghts[i]; k++){
                        buscar_lista(lista, arr[k]);
                    }
                    printf("  - En Listas, demora un total de ");
                    break;

                case 1:
                    for(int k = 0; k < lenghts[i]; k++){
                        buscar_arbol(root, arr[k]);
                    }
                    printf("  - En Arboles, demora un total de ");
                    break;

                default:
                    break;
            }
            end_t = clock();
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("%lf s\n", total_t);
        }
        printf("Altura del arbol generado: %d\n", altura_arbol(root));
    }

    return 0;
}