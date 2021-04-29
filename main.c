#include <stdio.h>
#include <time.h>
#include "array_int.h"

/**
 * PT:
 * Função para printar o array, recebe o ponteiro que aponta para a área de memória onde está
 * a estrutura 'array_int', acessa o tamanho e a capacidade através das funções de retorno
 * 'array_size' e 'array_capacity' para imprimi-las, e roda o array inteiro utilizando a
 * função 'array_get' para acessar os índices do vetor.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é o tamanho do vetor,
 * pois ela terá que percorrer todos os valores do vetor.
 * EN:
 * Function to print the array, it receives the pointer that points to the memory area where
 * the structure 'array_int' is, it also gets the size and capacity through the return functions
 * 'array_size' and 'array_capacity'
 * 
*/
void print_array(array_int *array) {
    int i;
    printf(" (Size: %u, Capacity: %u) { ", array_size(array), array_capacity(array));
    for (i = 0; i < array_size(array); ++i)
        printf("%d ", array_get(array, i));
    printf("}\n");
}

int main() {
    clock_t inicio, fim;
    array_int *array = array_create(10000);
    if (!array) {
        return 0;
    }
    int i;
    inicio = clock();
    for (i = 0; i < 20000000; ++i) 
        array_push_back(array, i*2, 10000);
    fim = clock();
    array_destroy(array);
    double elapsedTime = (fim-inicio)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo decorrido: %lfms\n", elapsedTime);
    return 0;
}