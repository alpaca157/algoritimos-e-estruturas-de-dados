
//Você recebe os cabeçalhos de duas listas vinculadas classificadas, lista1 e lista2.

//Mesclar as duas listas em uma lista classificada. A lista deve ser feita unindo os nós das duas primeiras listas.

//Retorne o cabeçalho da lista vinculada mesclada.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista vinculada
struct ListNode {
    int val;
    struct ListNode *next;
};

// Função para mesclar duas listas ordenadas
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Cria um nó fictício para facilitar a construção da lista mesclada
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // Percorre as duas listas enquanto houver elementos em ambas
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Adiciona os nós restantes de list1, se houver
    if (list1 != NULL) {
        tail->next = list1;
    }
    // Adiciona os nós restantes de list2, se houver
    if (list2 != NULL) {
        tail->next = list2;
    }

    // Retorna o cabeçalho da lista mesclada (o nó após o nó fictício)
    return dummy.next;
}

// Função para criar um novo nó
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Função para imprimir uma lista vinculada
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Função principal para testar a mesclagem de listas
int main() {

    struct ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);


    struct ListNode* mergedList = mergeTwoLists(list1, list2);


    printf("Lista Mesclada: ");
    printList(mergedList);

    return 0;
}