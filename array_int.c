#include <stdlib.h>
#include "array_int.h"

/**
 * PT:
 * Inicialização da estrutura 'array_int', do tipo composto de vetor dinâmico.
 * O campo 'data' é um ponteiro que aponta para o espaço de memória onde os dados
 * do vetor serão colocados. Os campos 'size' e 'capacity' representam, respectivamente,
 * o tamanho e a capacidade do vetor dinâmico.
 * EN:
 * Initialization of the structure 'array_int', from the composite type of dynamic array.
 * The 'data' field is a pointer that points to the memory space where the data of the array
 * will be placed. The fields 'size' and 'capacity represent, respectively, the size and
 * capacity of the dynamic array.
 * 
*/
struct array_int {
    int *data;
    size_t size, capacity;
};

/**
 * PT:
 * Libera o espaço de memória alocada para os dados do array, depois
 * libera o espaço de memória alocado para o próprio tipo do array.
 * EN:
 * Frees the allocated memory space for the data from the array, and then
 * frees the allocated memory space for the array type itself.
*/
void array_destroy(array_int *array) {
    free(array->data);
    free(array);
}

/**
 * PT:
 * 
 * EN:
 * 
*/
array_int* array_create(size_t capacity) {
    array_int *array = (array_int*)malloc(sizeof(array_int));
    if (!array) return 0;
    array->data = (int*)malloc(sizeof(int) * capacity);
    array->size = 0;
    array->capacity = capacity;
    return array;
}

/**
 * PT:
 * A função verifica se o paramêtro de índice 'index' está entre 0 e tamanho-1, onde 
 * tamanho é o campo 'size' do vetor, representando seu tamanho, então ela retorna o
 * elemento no índice de número 'index' nos dados do array.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
 * EN:
 * 
*/
int array_get(array_int *array, int index) {
    if (index >= 0 && index < array->size)
        return array->data[index];
}

/**
 * PT:
 * Primeiro a função verifica se o campo de tamanho do vetor dinâmico é igual 
 * ao campo de capacidade, se for, a capacidade atual não é o suficiente para inserir 
 * o inteiro 'i' no final do vetor, então o campo 'capacity' do vetor é somado ao 
 * paramêtro 'increase', depois, um ponteiro de inteiros 'copy' é declarado para apontar 
 * para um espaço de memória alocado com a nova capacidade aumentada do vetor, colocando 
 * os dados do vetor em um outro ponteiro de inteiros 'old' para guardar o estado do vetor 
 * antes do aumento, então há um processo de cópia, onde é colocado no conteúdo de cada 
 * espaço de memória apontado por 'copy', o conteúdo de cada espaço de memória apontado 
 * por 'old' (que contém os dados originais do vetor), por fim o campo 'data' do vetor é 
 * atualizado para apontar para a mesma alocação de memória que 'copy', assim atualizando 
 * a alocação deste campo, e o espaço de memória antes apontado pelo vetor anterior ao 
 * aumento da capacidade é liberado.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é o número de 
 * elementos no vetor pois no pior caso, o processo de cópia é necessário, e ela terá 
 * que percorrer todos os valores do vetor.
 * EN:
 * 
*/
size_t array_push_back(array_int *array, int i, size_t increase) {
    if (array->size == array->capacity) {
        array->capacity = array->capacity+increase;
        int *copy = (int*)malloc(sizeof(int) * (array->capacity));
        int *old = array->data;
        int index;
        for (index = 0; index < array->size; ++index)
            *(copy+index) = *(old+index);
        array->data = copy;
        free(old);
    }
    array->data[array->size++] = i;
    return array->size;
}

/**
 * PT:
 * A função verifica se o campo 'size' do vetor, seu tamanho, é maior que zero,
 * para então remover o último elemento, decrementando 1 do tamanho.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
 * EN:
 * The funcion checks if the 'size' field from the array, its size, is larger than
 * zero, to then remove the last element, decrementing 1 from the size.
 * 
 * The performance of this funcion according to big-Oh notation is O(1), because
 * it's always the same number of operations, so it's constant.
*/
size_t array_pop_back(array_int *array) {
    if (array->size > 0) array->size--;
    return array->size;
}

/**
 * PT:
 * Retorna o campo 'size' do array, que é seu tamanho.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
 * EN:
 * Returns the 'size' field from the array, which is its size.
 * 
 * The performance of this funcion according to big-Oh notation is O(1), because
 * it's always the same number of operations, so it's constant.
*/
size_t array_size(array_int *array) {
    return array->size;
}

/**
 * PT:
 * Retorna o campo 'capacity' do array, que é sua capacidade.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
 * EN:
 * Returns the 'capacity' field from the array, which is its capacity.
 * 
 * The performance of this funcion according to big-Oh notation is O(1), because
 * it's always the same number of operations, so it's constant.
*/
size_t array_capacity(array_int *array) {
    return array->capacity;
}

/**
 * PT:
 * A função percorre todo o array, utilizando um laço com o limite estabelecido 
 * pelo campo 'size' de array, se o conteúdo do índice atual do campo 'data' for 
 * igual ao parâmetro inteiro 'element', a variável de retorno index recebe o índice
 * atual do laço 'i'.
 * 
 * Depois há uma verificação pra saber se o índice 'index' está entre 0 e size-1.
 * Repare que o valor inicial de 'index' é -1 justamente para ele ser rejeitado se 
 * o 'if' dentro do laço nunca tiver sua condição aceita, ou seja, o elemento não foi
 * encontrado.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é número de elementos 
 * no vetor, pois ela terá que percorrer todos os valores do vetor.
 * EN:
 * 
*/
int array_find(array_int *array, int element) {
    int i;
    int index = -1;
    for (i = 0; i < array->size; ++i)
        if (array->data[i] == element) index = i;
    if (index >= 0 && index < array->size)
        return index;
}

/**
 * PT:
 * 
 * EN:
 * 
*/
int array_insert_at(array_int *array, int index, int value, int increase) {
    int insertion = -1;
    if (index >= 0 && index < array->size) {
        if (array->size == array->capacity) {
            array->capacity = array->capacity+increase;
            int *copy = (int*)malloc(sizeof(int) * (array->capacity));
            int *old = array->data;
            int index;
            for (index = 0; index < array->size; ++index)
                *(copy+index) = *(old+index);
            array->data = copy;
            free(old);
        }
        int i;
        array->size++;
        
        for (i = array->size; i > index; --i)
            array->data[i] = array->data[i-1];
        array->data[index] = value;
        insertion = index;
    }
    return insertion;
}

/**
 * PT:
 * 
 * EN:
 * 
*/
int array_remove_from(array_int *array, int index) {
    if (index >= 0 && index < array->size) {
        int i;
        for (i = index; i < array->size - 1; ++i)
            array->data[i] = array->data[i+1];
        array->size--;
    }
    return array->size;
}

/**
 * PT:
 * 
 * EN:
 * 
*/
double array_percent_occuped(array_int *array) {
    double percent = 1.0;
    if (array->size < array->capacity) {
        percent = ((double)array->size)/((double)array->capacity);
    }
    return percent;
}
