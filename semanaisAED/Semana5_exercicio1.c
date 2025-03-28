//Dado o topo de uma lista vinculada classificada, exclua todas as duplicatas
//de forma que cada elemento apareça apenas uma vez. Retorne a lista vinculada classificada também.

#include <stdio.h>
#include <stdlib.h>

//Estritura para um nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para remover todas as duplicatas da lista vinculada
struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);  // Remove o nó duplicado
        } else {
            current = current->next; // Move para o próximo nó
        }
    }

    return head;
}

//função para imprimir a lista vinculada
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//função para liberar memória da lista
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


//função principal para testar a remoção de duplicatas
int main() {
    //lista vinculada classificada com duplicatas
    struct Node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Lista original:\n");
    printList(head);

    // Removendo duplicatas
    head = removeDuplicates(head);

    printf("Lista após remover duplicatas:\n");
    printList(head);

    // Liberando memória alocada
    freeList(head);

    return 0;
}