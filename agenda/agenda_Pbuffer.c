#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPessoa(void **pBuffer);
void removerPessoa(void **pBuffer);
void buscarPessoa(void *pBuffer);
void listarTodos(void *pBuffer);

int main() {
    void *pBuffer = malloc(sizeof(int)); // Espaço para o contador de pessoas
    if (!pBuffer) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }
    *(int *)pBuffer = 0; // Inicializa o contador de pessoas

    int opcao;
    do {
        printf("\nMenu:\n1- Adicionar Pessoa\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar Todos\n5- Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarPessoa(&pBuffer); break;
            case 2: removerPessoa(&pBuffer); break;
            case 3: buscarPessoa(pBuffer); break;
            case 4: listarTodos(pBuffer); break;
            case 5: break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    free(pBuffer);
    return 0;
}

void adicionarPessoa(void **pBuffer) {
    int *contador = (int *)(*pBuffer);
    *pBuffer = realloc(*pBuffer, sizeof(int) + ((*contador + 1) * (50 + sizeof(int) + 50)));
    if (!*pBuffer) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    void *pAtual = (char *)(*pBuffer) + sizeof(int) + (*contador * (50 + sizeof(int) + 50));
    printf("Nome: ");
    scanf("%s", (char *)pAtual);
    pAtual = (char *)pAtual + 50;
    printf("Idade: ");
    scanf("%d", (int *)pAtual);
    pAtual = (char *)pAtual + sizeof(int);
    printf("Email: ");
    scanf("%s", (char *)pAtual);

    (*contador)++;
}

void removerPessoa(void **pBuffer) {
    int *contador = (int *)(*pBuffer);
    if (*contador == 0) {
        printf("Agenda vazia!\n");
        return;
    }

    char nome[50];
    printf("Digite o nome para remover: ");
    scanf("%s", nome);

    void *pAtual = (char *)(*pBuffer) + sizeof(int);
    for (int i = 0; i < *contador; i++) {
        if (strcmp((char *)pAtual, nome) == 0) {
            void *pProx = (char *)pAtual + 50 + sizeof(int) + 50;
            memmove(pAtual, pProx, ((*contador - i - 1) * (50 + sizeof(int) + 50)));
            (*contador)--;
            *pBuffer = realloc(*pBuffer, sizeof(int) + (*contador * (50 + sizeof(int) + 50)));
            printf("Pessoa removida!\n");
            return;
        }
        pAtual = (char *)pAtual + 50 + sizeof(int) + 50;
    }
    printf("Pessoa não encontrada!\n");
}

void buscarPessoa(void *pBuffer) {
    int *contador = (int *)pBuffer;
    char nome[50];
    printf("Digite o nome para buscar: ");
    scanf("%s", nome);

    void *pAtual = (char *)pBuffer + sizeof(int);
    for (int i = 0; i < *contador; i++) {
        if (strcmp((char *)pAtual, nome) == 0) {
            printf("Nome: %s\n", (char *)pAtual);
            pAtual = (char *)pAtual + 50;
            printf("Idade: %d\n", *(int *)pAtual);
            pAtual = (char *)pAtual + sizeof(int);
            printf("Email: %s\n", (char *)pAtual);
            return;
        }
        pAtual = (char *)pAtual + 50 + sizeof(int) + 50;
    }
    printf("Pessoa não encontrada!\n");
}

void listarTodos(void *pBuffer) {
    int *contador = (int *)pBuffer;
    if (*contador == 0) {
        printf("Agenda vazia!\n");
        return;
    }

    void *pAtual = (char *)pBuffer + sizeof(int);
    for (int i = 0; i < *contador; i++) {
        printf("Nome: %s\n", (char *)pAtual);
        pAtual = (char *)pAtual + 50;
        printf("Idade: %d\n", *(int *)pAtual);
        pAtual = (char *)pAtual + sizeof(int);
        printf("Email: %s\n", (char *)pAtual);
        pAtual = (char *)pAtual + 50;
        printf("------------------------\n");
    }
}
