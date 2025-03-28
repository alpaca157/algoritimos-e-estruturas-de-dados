//Você está registrando o placar de um jogo de beisebol com regras estranhas. No início do jogo, você começa com um registro vazio.

//Você recebe uma lista de operações de strings, onde operações[i] é a i-ésima operação que você deve aplicar ao registro e é uma das seguintes:

//Um inteiro x.
//Registre uma nova pontuação de x.
//'+'.
//Registre uma nova pontuação que seja a soma das duas pontuações anteriores.
//'D'.
//Registre uma nova pontuação que seja o dobro da pontuação anterior.
//'C'.
//Invalidar a pontuação anterior, retirando-a do registro.
//Retorne a soma de todas as pontuações do registro após aplicar todas as operações.

//Os casos de teste são gerados de forma que a resposta e todos os cálculos intermediários caibam em um número inteiro de 32 bits e que todas as operações sejam válidas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura da pilha
typedef struct {
    int* data; // Array para armazenar os elementos da pilha
    int top;   // Índice do topo da pilha
    int capacity; // Capacidade máxima da pilha
} Stack;

// Função para inicializar a pilha
void initStack(Stack* stack, int capacity) {
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

// Função para empilhar um elemento
void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++(stack->top)] = value;
    }
}

// Função para desempilhar um elemento
int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return -1; // Retorna -1 se a pilha estiver vazia
}

// Função para obter o elemento no topo da pilha
int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1; // Retorna -1 se a pilha estiver vazia
}

// Função para processar as operações e retornar a soma das pontuações
int calPoints(char** operations, int operationsSize) {
    Stack stack;
    initStack(&stack, operationsSize); // Inicializa a pilha

    for (int i = 0; i < operationsSize; i++) {
        if (isdigit(operations[i][0]) || operations[i][0] == '-') {
            // Se for um número, empilha o valor
            push(&stack, atoi(operations[i]));
        } else if (operations[i][0] == '+') {
            // Soma os dois últimos valores e empilha o resultado
            int last = pop(&stack);
            int secondLast = peek(&stack);
            push(&stack, last);
            push(&stack, last + secondLast);
        } else if (operations[i][0] == 'D') {
            // Dobra o último valor e empilha o resultado
            int last = peek(&stack);
            push(&stack, 2 * last);
        } else if (operations[i][0] == 'C') {
            // Remove o último valor
            pop(&stack);
        }
    }

    // Soma todos os valores na pilha
    int sum = 0;
    while (stack.top >= 0) {
        sum += pop(&stack);
    }

    // Libera a memória alocada para a pilha
    free(stack.data);

    return sum;
}

// Função principal para testar o código
int main() {
    char* operations[] = {"5", "2", "C", "D", "+"};
    int operationsSize = sizeof(operations) / sizeof(operations[0]);

    int result = calPoints(operations, operationsSize);

    printf("Soma das pontuações: %d\n", result);

    return 0;
}