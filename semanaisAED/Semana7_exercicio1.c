//Implemente uma pilha LIFO (último a entrar, primeiro a sair) usando apenas duas filas.
//A pilha implementada deve suportar todas as funções de uma pilha normal (push, top, pop e empty).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

bool isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("fila cheia.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = x;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("fila vazia.\n");
        return -1;
    }
    int x = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return x;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("fila vazia.\n");
        return -1;
    }
    return q->data[q->front];
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initializeQueue(&stack->q1);
    initializeQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (!isEmpty(&obj->q1)) {
        enqueue(&obj->q1, x);
    } else {
        enqueue(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue *nonEmptyQueue, *emptyQueue;
    if (!isEmpty(&obj->q1)) {
        nonEmptyQueue = &obj->q1;
        emptyQueue = &obj->q2;
    } else {
        nonEmptyQueue = &obj->q2;
        emptyQueue = &obj->q1;
    }

    while (nonEmptyQueue->front != nonEmptyQueue->rear) {
        enqueue(emptyQueue, dequeue(nonEmptyQueue));
    }

    return dequeue(nonEmptyQueue);
}

int myStackTop(MyStack* obj) {
    Queue *nonEmptyQueue;
    if (!isEmpty(&obj->q1)) {
        nonEmptyQueue = &obj->q1;
    } else {
        nonEmptyQueue = &obj->q2;
    }

    return nonEmptyQueue->data[nonEmptyQueue->rear];
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(&obj->q1) && isEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    myStackPush(stack, 3);

    printf("Top: %d\n", myStackTop(stack)); 
    printf("Pop: %d\n", myStackPop(stack)); 
    printf("Top: %d\n", myStackTop(stack)); 

    printf("a fila esta vazia: %s\n", myStackEmpty(stack) ? "verdadeiro" : "falso"); 

    myStackFree(stack);
    return 0;
}