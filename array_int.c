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
*/
struct array_int {
    int *data;
    size_t size, capacity;
};

/**
 * PT:
 * A função aloca um espaço de memória de tamanho suficiente para armazenar um tipo de estrutura
 * 'array_int' para o ponteiro de array_int '*array'. Se array for 0, quer dizer que a função de 
 * alocação 'malloc' não conseguiu alocar memória suficiente, e então a função retorna 0. Se 
 * a alocação foi bem-sucedida, os campos 'data', 'size', e 'capacity' são inicializados no tipo 
 * estrutura array_int apontado pelo ponteiro array. O campo 'data' aloca um espaço de memória de
 * tamanho do parâmetro de tipo redefinido size_t 'capacity', que será o tamanho da capacidade do
 * vetor criado. O valor inicial do campo 'size' é 0, e do campo 'capacity' é passado pelo paramêtro
 * de mesmo nome.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
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
 * A função inicializa uma variável inteira 'insertion' com -1, pois se a condição do 'if'
 * que vem depois não for aceita, o retorno será -1 (falha na inserção por índice inválido).
 * Se a condição do 'if' passar, o índice 'index' é válido, então a função verifica se o campo
 * 'size' do array é igual ao campo 'capacity', ou seja, não há espaço para inserção de um novo 
 * elemento, se sim, é alocado um novo espaço de memória com a capacidade aumentada em 'increase',
 * realiza-se a cópia do array para um novo array com a nova capacidade, e libera-se o espaço de 
 * memória do array antigo. Então a função percorre o array do índice logo após o último elemento 
 * até o índice da iteração for igual a 'index', enquanto ele percorre esse laço, em cada iteração,
 * o elemento de índice atual 'i' do campo de 'data' do array recebe o valor do elemento do índice 
 * anterior, assim deslocando todos os elementos até o índice de inserção para direita, assim livrando
 * espaço no índice 'index' para a inserção do novo elemento. A variável 'insertion' recebe 'index'
 * se a inserção for bem-sucedidada. A função retorna 'insertion', -1 se não foi realizada a inserção, e
 * 'index' se foi realizada.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é número de elementos 
 * no vetor, pois no pior caso, ela terá que percorrer os valores do vetor (adicionar um elemento
 * na primeira posição do array).
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
 * A função verifica se o 'index' é válido com um 'if', tem que ser entre 0 e size-1,
 * então ela percorre o array a partir do 'index' fornecido, e em cada iteração do laço,
 * o elemento de índice atual recebe o valor do elemento do próximo índice (parada tem que
 * ser size-1, pois o último elemento não irá ter próximo elemento para realizar essa operação),
 * essa realizando o deslocamento de todos os elementos do array a partir do 'index' pra esquerda,
 * removendo o elemento de índice 'index'. Então a função diminui o tamanho do array através do 
 * campo 'size' para sincronizar com o deslocamento que ocorreu. A função retorna o campo 'size',
 * mesmo se não ocorreu mudança (se o 'if' não passar), mas se ocorreu, o novo campo 'size' foi
 * decrementado dentro do 'if' anterior.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(n), onde 'n' é número de elementos 
 * no vetor, pois no pior caso, ela terá que percorrer os valores do vetor (remover um elemento
 * na primeira posição do array).
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
 * A função inicializa a váriavel do tipo double 'percent' com o valor 1.0, e depois
 * verifica se o campo 'size' do array, seu tamanho, é menor que o campo 'capacity', 
 * sua capacidade, se não for menor, é igual, então a condição do 'if' não será aceita
 * e o retorno será 1.0 (100% do array ocupado, pois size = capacity). Se a condição 
 * passar, é atribuído a 'percent' o resultado da divisão entre 'size' e 'capacity', 
 * com typecast para double, pois os dois são tipo 'size_t', gerando assim sua 
 * porcentagem entre 0 e 1.
 * 
 * O desempenho desta função segundo a notação big-Oh é O(1), pois é sempre o mesmo
 * número de operações, então é constante.
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
