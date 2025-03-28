
//Dado o cabeçalho de uma lista vinculada individualmente, inverta a lista e retorne a lista invertida.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista vinculada
struct ListNode {
    int val;
    struct ListNode *next;
};

// Função para inverter a lista vinculada
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;   // Ponteiro para o nó anterior
    struct ListNode* current = head; // Ponteiro para o nó atual
    struct ListNode* next = NULL;   // Ponteiro para o próximo nó

    // Percorre a lista e inverte os ponteiros
    while (current != NULL) {
        next = current->next; // Salva o próximo nó
        current->next = prev; // Inverte o ponteiro do nó atual
        prev = current;       // Move o ponteiro prev para o nó atual
        current = next;       // Move o ponteiro current para o próximo nó
    }

    // No final, prev será o novo cabeçalho da lista invertida
    return prev;
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

// Função principal para testar a inversão da lista
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Lista Original: ");
    printList(head);

    struct ListNode* reversedHead = reverseList(head);

    printf("Lista Invertida: ");
    printList(reversedHead);

    return 0;
}