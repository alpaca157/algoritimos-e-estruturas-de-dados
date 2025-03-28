//Dada uma string s contendo apenas os caracteres '(', ')', '{', '}', '[' e ']', determine se a string de entrada é válida. 

//Uma string de entrada é válida se:

//Os colchetes abertos devem ser fechados pelo mesmo tipo de colchetes.
//Os colchetes abertos devem ser fechados na ordem correta.
//Cada colchete fechado possui um colchete aberto correspondente do mesmo tipo.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10000

// Estrutura da pilha
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Inicializa a pilha
void initStack(Stack *s) {
    s->top = -1;
}

// Verifica se a pilha está vazia
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Empilha um caractere
void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = c;
    }
}

// Desempilha um caractere
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0'; // Retorna caractere nulo se a pilha estiver vazia
}

// Verifica se a string de colchetes é válida
bool isValid(char *s) {
    Stack stack;
    initStack(&stack);

    // Percorre cada caractere da string
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            // Se for um caractere de abertura, empilha
            push(&stack, c);
        } else {
            // Se for um caractere de fechamento, verifica o topo da pilha
            if (isEmpty(&stack)) {
                return false; // Não há correspondência
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Não corresponde
            }
        }
    }

    // Se a pilha estiver vazia, todos os colchetes foram fechados corretamente
    return isEmpty(&stack);
}


// Função principal para testar o código
int main() {
    char s1[] = "()";
    char s2[] = "()[]{}";
    char s3[] = "(]";
    char s4[] = "([)]";
    char s5[] = "{[]}";

    printf("Teste 1: %s -> %s\n", s1, isValid(s1) ? "Válido" : "Inválido");
    printf("Teste 2: %s -> %s\n", s2, isValid(s2) ? "Válido" : "Inválido");
    printf("Teste 3: %s -> %s\n", s3, isValid(s3) ? "Válido" : "Inválido");
    printf("Teste 4: %s -> %s\n", s4, isValid(s4) ? "Válido" : "Inválido");
    printf("Teste 5: %s -> %s\n", s5, isValid(s5) ? "Válido" : "Inválido");

    return 0;
}