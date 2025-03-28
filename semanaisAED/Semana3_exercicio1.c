//Dada uma matriz ordenada de inteiros distintos e um valor alvo, retorne o índice se o alvo for encontrado. Caso contrário, retorne o índice onde estaria se fosse inserido na ordem.
//Você deve escrever um algoritmo com complexidade de tempo de execução O(log n).

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
    int esquerda = 0;
    int direita = numsSize - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (nums[meio] == target) {
            return meio;
        } else if (nums[meio]< target) {
            esquerda = meio + 1;
        }else {
            direita = meio - 1; 
        }
    }
    //retorna o indice onde deve ser inserido se não for encontrado
    return esquerda;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target;

    printf("digite o valor do alvo: ");
    scanf("5d", &target);

    int indice = searchInsert(nums, numsSize, target);
    printf("O indice é: %d\n", indice);

    return 0;
}