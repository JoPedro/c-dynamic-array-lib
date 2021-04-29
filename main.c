#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array_int.h"

/**
 * PT:
 * Função para printar o array, recebe o ponteiro que aponta para a área de memória onde está
 * a estrutura 'array_int', acessa o tamanho e a capacidade através das funções de retorno
 * 'array_size' e 'array_capacity' para imprimi-las, e roda o array inteiro utilizando a
 * função 'array_get' para acessar os índices do vetor.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é número de elementos 
 * no vetor, pois ela terá que percorrer todos os valores do vetor.
 * EN:
 * Function to print the array, it receives the pointer that points to the memory area where
 * the structure 'array_int' is, it also gets the size and capacity through the return functions
 * 'array_size' and 'array_capacity' to print them, and also goes through the entire array
 * utilizing the function 'array_get' to access the indexes of the array.
 * 
 * The performance of this funcion according to big-Oh notation is O(n), where 'n' is the 
 * number of elements in the array, because it will run through all the values in the array.
*/
void print_array(array_int *array) {
    int i;
    printf(" (Size: %u, Capacity: %u) { ", array_size(array), array_capacity(array));
    for (i = 0; i < array_size(array); ++i)
        printf("%d ", array_get(array, i));
    printf("}\n");
}

int main() {
    /* Utilizando o tipo 'clock_t' para realizar testes de tempo */
    clock_t inicio, fim;
                                    /* Os testes foram realizados com estes valores iniciais 
                                     * da capacidade: 10, 10000 e 2, no argumento da função.*/
    array_int *array = array_create(2);
    if (!array) {
        return 0;
    }
    int i;

    /* =-----------------------------------------------------------= */
    /* TESTES DE INSERÇÕES CONSECUTIVAS UTILIZANDO array_push_back() */
    /* Variável recebe o número de clocks antes da função */
    inicio = clock();
    for (i = 0; i < 250000; ++i) 
                                    /* Os testes foram realizados com estes valores de 'increase' 
                                     * da capacidade: 10, 10000 e array_capacity(array), no argumento 
                                     * 'increase' da função. 
                                     * OBS.: array_capacity(array) no argumento 'increase' faz com
                                     * que o valor duplique cada vez que a capacidade precise aumentar.*/    
        array_push_back(array, i*2, array_capacity(array));
    /* Variável recebe o número de clocks depois da função */
    fim = clock();
    /* Cálculo da diferença de tempo para a realização de testes */ 
    double elapsedTime = (fim-inicio)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo decorrido: %lfms\n", elapsedTime);

    /* =--------------------------------------------------------------= */
    /* TESTES DE BUSCAS DE ELEMENTOS ALEATÓRIOS UTILIZANDO array_find() */
    srand(time(NULL));
    inicio = clock();
    for (i = 0; i < 20000; ++i)
        array_find(array, rand());
    fim = clock();
    elapsedTime = (fim-inicio)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo decorrido: %lfms\n", elapsedTime);

    

    array_destroy(array);
    return 0;
}