#include "bst.h"

// Inserta el valor data en el arbol binario de busqueda
// Retorna la nueva raiz del arbol
nodo_arbol *insertar_arbol(nodo_arbol *node, int data){
    if (node == NULL){
        nodo_arbol *leaf = (nodo_arbol *)malloc(sizeof(nodo_arbol));
        leaf->data = data;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }
    if (data < node->data){
        node->left = insertar_arbol(node->left, data);
    }
    else{
        node->right = insertar_arbol(node->right, data);
    }
    return node;
}

// Busca el valor data en el arbol binario de busqueda
// Retorna el primer nodo que se encuentra con valor data, si existe, 
// o NULL en caso contrario
nodo_arbol *buscar_arbol(nodo_arbol *root, int data){
    if (root == NULL || root->data == data){
        return root;
    }
    if (data < root->data){
        return buscar_arbol(root->left, data);
    }
    return buscar_arbol(root->right, data);
}

// Retorna la altura del arbol
int altura_arbol(nodo_arbol *root){
    if (root == NULL){
        return 0;
    }
    else{
        int left = altura_arbol(root->left);
        int right = altura_arbol(root->right);
        if (left > right){
            return left + 1;
        }
        return right + 1;
    }
}

// Imprime en pantalla el árbol en orden inorder
void imprimir_arbol_inorder(nodo_arbol *root){
    if (root == NULL){
        return;
    }
    else{
        imprimir_arbol_inorder(root->left);
        printf("%d ", root->data);
        imprimir_arbol_inorder(root->right);
    }
}