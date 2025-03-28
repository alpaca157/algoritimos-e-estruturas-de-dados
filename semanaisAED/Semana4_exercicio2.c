//Dado o cabeçalho de uma lista vinculada, determine se a lista vinculada contém um ciclo.

//Existe um ciclo em uma lista vinculada se houver algum nó na lista que possa ser alcançado novamente seguindo continuamente o próximo ponteiro. Internamente, pos é usado para denotar o índice do nó ao qual o próximo ponteiro da cauda está conectado. Observe que pos não é passado como parâmetro.

//Retorne verdadeiro se houver um ciclo na lista vinculada. Caso contrário, retorne falso.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista vinculada
struct ListNode {
    int val;
    struct ListNode *next;
};

// Função para verificar se a lista vinculada contém um ciclo
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // Inicializa os ponteiros lento (tartaruga) e rápido (lebre)
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Percorre a lista com os dois ponteiros
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Se os ponteiros se encontrarem, há um ciclo
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Função para criar um novo nó
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Função principal para testar a detecção de ciclo
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head->next; 

    if (hasCycle(head)) {
        printf("A lista contém um ciclo.\n");
    } else {
        printf("A lista não contém um ciclo.\n");
    }
    return 0;
}