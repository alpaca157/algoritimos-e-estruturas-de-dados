
//Dada a raiz de uma árvore binária
//retorne a travessia de pré-ordem dos valores de seus nós.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore binária
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Função auxiliar para realizar a travessia de pré-ordem e armazenar os valores no array
void preorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    // Visita o nó raiz
    result[(*index)++] = root->val;
    // Percorre a subárvore esquerda
    preorderHelper(root->left, result, index);
    // Percorre a subárvore direita
    preorderHelper(root->right, result, index);
}

// Função principal para retornar a travessia de pré-ordem
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Verifica se a árvore está vazia
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Array para armazenar os valores dos nós
    int* result = (int*)malloc(1000 * sizeof(int)); // Tamanho inicial arbitrário
    int index = 0;

    // Realiza a travessia de pré-ordem
    preorderHelper(root, result, &index);

    // Define o tamanho do array de retorno
    *returnSize = index;

    return result;
}

// Função para criar um novo nó da árvore
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função principal para testar a travessia de pré-ordem
int main() {
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    int returnSize;
    int* result = preorderTraversal(root, &returnSize);

    // Imprime o resultado da travessia de pré-ordem
    printf("Travessia de Pré-Ordem: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(result);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}