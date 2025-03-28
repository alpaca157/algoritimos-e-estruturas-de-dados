#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove nós do início da lista que possuem o valor `val`
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    // Percorre o restante da lista
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            // Remove o nó com o valor `val`
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            // Avança para o próximo nó
            current = current->next;
        }
    }

    return head;
}

void append(struct ListNode** head, int val) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Cria uma lista encadeada de exemplo: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 6);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Lista original:\n");
    printList(head);

    // Remove todos os nós com valor 6
    int val = 6;
    head = removeElements(head, val);

    printf("Lista após remover %d:\n", val);
    printList(head);

    // Libera a memória alocada para a lista
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}