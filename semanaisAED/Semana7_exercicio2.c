//Implemente uma fila FIFO (primeiro a entrar, primeiro a sair) usando apenas duas pilhas.
//A fila implementada deve suportar todas as funções de uma fila normal (push, peek, pop e vazia).


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int x = s->data[s->top];
    s->top--;
    return x;
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    initializeStack(&queue->s1);
    initializeStack(&queue->s2);
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(&obj->s2)) {
        while (!isEmpty(&obj->s1)) {
            push(&obj->s2, pop(&obj->s1));
        }
    }
    return pop(&obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(&obj->s2)) {
        while (!isEmpty(&obj->s1)) {
            push(&obj->s2, pop(&obj->s1));
        }
    }
    return peek(&obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->s1) && isEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* queue = myQueueCreate();
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);

    printf("Peek: %d\n", myQueuePeek(queue)); // Output: 1
    printf("Pop: %d\n", myQueuePop(queue));   // Output: 1
    printf("Peek: %d\n", myQueuePeek(queue)); // Output: 2

    printf("Is empty: %s\n", myQueueEmpty(queue) ? "true" : "false"); // Output: false

    myQueueFree(queue);
    return 0;
}