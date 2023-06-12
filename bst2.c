#include "bst2.h"


// Inserta el usuario data en el arbol binario de busqueda
// Retorna la nueva raiz del arbol
nodo_arbol *insertar_arbol(nodo_arbol *node, usuario data){
    if (node == NULL){
            nodo_arbol *leaf = (nodo_arbol *)malloc(sizeof(nodo_arbol));
            leaf->data = data;
            leaf->left = NULL;
            leaf->right = NULL;
            return leaf;
        }
        if (data.edad < node->data.edad){
            node->left = insertar_arbol(node->left, data);
        }
        else if (data.edad > node->data.edad){
            node->right = insertar_arbol(node->right, data);
        }
        else {
            if (strcmp(data.nombre, node->data.nombre) < 0) {
                node->left = insertar_arbol(node->left, data);
            } else {
                node->right = insertar_arbol(node->right, data);
            }
        }
        return node;
}

// Imprime en pantalla el árbol en orden inorder
void imprimir_arbol_inorder(nodo_arbol *root){
    if (root == NULL){
        return;
    }
    else{
        imprimir_arbol_inorder(root->left);
        printf("Nombre: %s, Edad: %d\n", root->data.nombre, root->data.edad);
        imprimir_arbol_inorder(root->right);
    }
}

int main(){
    nodo_arbol *root = NULL;
    FILE *fp = fopen("usuarios.txt", "r");

    char buffer[max_line];
    int count = 0;

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        usuario data;
        strcpy(data.nombre, strtok(buffer, ","));
        data.edad = atoi(strtok(NULL, ","));
        root = insertar_arbol(root, data);
        count++;
    }

    fclose(fp);
    imprimir_arbol_inorder(root);
    return 0;
}