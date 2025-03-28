
//Dado o cabeçalho de uma lista vinculada individualmente
//retorne verdadeiro se for um palíndromo ou falso caso contrário.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista vinculada
struct ListNode {
    int val;
    struct ListNode *next;
};

// Função para inverter uma lista vinculada
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next; // Salva o próximo nó
        current->next = prev; // Inverte o ponteiro do nó atual
        prev = current;       // Move o ponteiro prev para o nó atual
        current = next;       // Move o ponteiro current para o próximo nó
    }

    return prev; // Retorna o novo cabeçalho da lista invertida
}

// Função para verificar se a lista vinculada é um palíndromo
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; // Lista vazia ou com apenas um nó é um palíndromo
    }

    // Encontra o meio da lista usando o algoritmo do "Tortoise and Hare"
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Ponteiro lento avança 1 passo
        fast = fast->next->next;    // Ponteiro rápido avança 2 passos
    }

    // Inverte a segunda metade da lista
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    // Compara a primeira metade com a segunda metade invertida
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false; // Se os valores não corresponderem, não é um palíndromo
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // Se todos os valores corresponderem, é um palíndromo
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

// Função principal para testar a verificação de palíndromo
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Lista: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("A lista é um palíndromo.\n");
    } else {
        printf("A lista não é um palíndromo.\n");
    }

    return 0;
}