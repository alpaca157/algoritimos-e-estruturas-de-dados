//Dado um array inteiro nums classificado em ordem não decrescente, remova as duplicatas no local de forma que cada elemento exclusivo apareça apenas uma vez. A ordem relativa dos elementos deve ser mantida a mesma. Em seguida, retorne o número de elementos únicos em nums. 
//Considere o número de elementos únicos de nums como k. Para ser aceito, você precisa fazer o seguinte:
//Altere a matriz nums de modo que os primeiros k elementos de nums contenham os elementos únicos na ordem em que estavam presentes inicialmente em nums. Os elementos restantes de nums não são importantes, assim como o tamanho de nums.
//Retorno k.

#include <stdio.h>
#include <stdlib.h>

int removeduplicados(int* nums, int numsSize){
  if(numsSize == 0) return 0;

  int k = 1; //ponteiro para a posição do próximo elemento único
  for(int i = 1; i < numsSize; i++){
    if(nums[i] != nums[k - 1]){ //comparar com o último elemento único
        nums[k] =  nums[i];
        k++;
    }
  }
  return k;
}

int main(){
    int nums[] = {1, 1, 2, 3, 3, 4, 5, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeduplicados(nums, numsSize);

    printf("Numeros unicos: %d\n", k);
    printf("Array modificado: ");
    for(int i = 0; i < k; i++){

        printf("%d", nums[i]);
    }
    return 0;
}