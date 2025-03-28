//Dada uma matriz de números inteiros e um alvo inteiro, retorne os índices dos dois números de forma que eles somem ao alvo.
//Você pode assumir que cada entrada teria exatamente uma solução e não pode usar o mesmo elemento duas vezes.
//Você pode retornar a resposta em qualquer ordem.

#include <stdio.h>
#include <stdlib.h>

// Força bruta
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* indice = malloc(sizeof(int) * 2);
    if (indice == NULL) {
        printf("Sem memória suficiente, saindo...\n");
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                indice[0] = i;
                indice[1] = j;
                *returnSize = 2; // Define o tamanho do array retornado
                return indice;
            }
        }
    }
    *returnSize = 0; // Caso não tenha solução
    free(indice);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("Índices encontrados: [%d, %d]\n", result[0], result[1]);
        free(result); // Libera memória alocada
    } else {
        printf("Nenhuma solução encontrada.\n");
    }
    return 0;
}