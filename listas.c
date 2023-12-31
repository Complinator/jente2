#include "listas.h"

// Inserta el valor data al comienzo de la lista
// Retorna un puntero al primer nodo de la nueva lista
// OJO: el elemento se debe insertar al comienzo de la lista
nodo_lista *insertar_lista(nodo_lista *lista, int data){
    nodo_lista *node = (nodo_lista *)malloc(sizeof(nodo_lista));
    node->data = data;
    node->next = lista;
    return node;
}

// Busca el valor data en la lista partiendo desde el comienzo hasta el final
// Retorna un puntero al primer nodo con dato data, en caso que exista
// Si no, retorna NULL
nodo_lista *buscar_lista(nodo_lista *lista, int data){
    nodo_lista *curr = lista;
    while (curr != NULL){
        if (curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
    
    
// Imprime en pantalla la lista desde el comienzo hasta el final
void imprimir_lista(nodo_lista *lista){
    nodo_lista *curr = lista;
    while (curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}