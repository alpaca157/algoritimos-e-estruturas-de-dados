//Você recebe um número inteiro grande representado como dígitos de uma matriz de inteiros, onde cada dígito [i] é o i-ésimo dígito do número inteiro. Os dígitos são ordenados do mais significativo para o menos significativo, da esquerda para a direita. O número inteiro grande não contém nenhum 0 à esquerda.
//Aumente o número inteiro grande em um e retorne a matriz de dígitos resultante.

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Aloca memória para o resultado com um espaço extra para o possível overflow
    int* result = (int*) malloc((digitsSize + 1) * sizeof(int));
    int carry = 1; // Começa com carry de 1

    // Loop de trás para frente
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10; // Armazena o dígito resultante
        carry = sum / 10; // Atualiza o carry
    }

    // Se ainda tiver carry, ele se torna o dígito mais significativo
    if (carry > 0) {
        result[0] = carry;
        *returnSize = digitsSize + 1;
    } else {
        // Se não tiver carry, copia o resultado e ignora o primeiro espaço
        *returnSize = digitsSize;
        result = result + 1;
    }

    return result;
}

int main() {
    int digits[] = {9, 9, 9}; // Exemplo de número
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    // Exibe o resultado
    printf("Resultado: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Libera a memória corretamente
    free(result - (returnSize > digitsSize ? 0 : 1));

    return 0;
}