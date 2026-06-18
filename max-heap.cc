/**
 * @file max-heap.cc
 * @brief Implementação da estrutura de dados Max-Heap com inserção em C++.
 *
 * Um Max-Heap é uma árvore binária completa onde o valor de cada nó pai
 * é sempre maior ou igual ao valor de seus filhos. Isso garante que o
 * maior elemento está sempre na raiz (posição 0 do array).
 *
 * Propriedade fundamental do Max-Heap:
 *   Para todo nó i (exceto a raiz): arr[pai(i)] >= arr[i]
 *
 * Representação como array (indexação base 0):
 *   - Pai de i:            (i - 1) / 2
 *   - Filho esquerdo de i:  2*i + 1
 *   - Filho direito de i:   2*i + 2
 *
 * Exemplo de inserção sequencial dos valores [4, 10, 3, 5]:
 *
 *   Inserir 4:     4
 *
 *   Inserir 10:    4       =>     10        (10 > 4, sobe)
 *                 /               /
 *               10               4
 *
 *   Inserir 3:   10              10
 *               /  \    =>      /  \        (3 < 10, fica)
 *              4    3          4    3
 *
 *   Inserir 5:   10              10
 *               /  \    =>      /  \        (5 > 4, sobe)
 *              4    3          5    3
 *             /               /
 *            5               4
 *
 * Complexidade da inserção:
 *   - Tempo:  O(log n) — no pior caso, o elemento sobe até a raiz
 *   - Espaço: O(1) — apenas variáveis auxiliares (sem contar o array)
 */
#include "utils.hpp"
#include <vector>
using namespace std;

/**
 * @brief Insere um novo elemento no Max-Heap mantendo a propriedade de heap.
 *
 * O processo de inserção ocorre em dois passos:
 *
 *   1. Adiciona o elemento no final do array (última posição da árvore),
 *      mantendo a propriedade de árvore binária completa.
 *
 *   2. Aplica "bubble-up" (ou "sift-up"): compara o elemento inserido com
 *      seu pai e, se for maior, troca os dois. Repete até que o elemento
 *      encontre um pai maior ou chegue à raiz.
 *
 * @param heap Referência para o array (vector) representando o Max-Heap.
 * @param number O valor a ser inserido no heap.
 *
 * Exemplo: inserir 15 no heap [10, 5, 3, 4]:
 *
 *       10                10                15
 *      /  \     =>       /  \     =>       /  \
 *     5    3           15    3           10    3
 *    / \              / \               / \
 *   4   15           4   5            4   5
 *   (adiciona)       (sobe: 15>5)     (sobe: 15>10)
 */
void insert(vector<int> &heap, int number)
{
    // Passo 1: Insere o elemento no final do array (posição de folha)
    heap.push_back(number);

    // Índice do elemento recém-inserido (última posição)
    int index = heap.size() - 1;

    // Passo 2: Bubble-up — sobe o elemento enquanto for maior que seu pai
    // Condição de parada: chegou na raiz (index == 0) ou pai é maior/igual
    // O pai de qualquer nó em index está na posição (index - 1) / 2
    while(index > 0 && heap[(index - 1) / 2] < heap[index]) {
        // Troca o elemento com seu pai
        swap(heap[index], heap[(index - 1) / 2]);

        // Atualiza o índice para a posição do pai (subindo na árvore)
        index = (index - 1) / 2;
    }
}

/**
 * @brief Função principal — demonstra a construção de um Max-Heap
 *        a partir de números aleatórios inseridos um a um.
 *
 * Gera 9 números aleatórios, exibe o vetor original e depois
 * constrói o Max-Heap inserindo cada elemento sequencialmente.
 */
int main()
{

    vector<int> arr;
    vector<int> numbers = random_numbers(9);
    int size = numbers.size();

    // Exibe o vetor original com os números aleatórios
    vector_print(numbers, "Vetor Primário");

    // Constrói o Max-Heap inserindo cada elemento um a um
    // A cada inserção, a propriedade de heap é mantida via bubble-up
    for (int i = 0; i < size; i++) 
        insert(arr, numbers[i]);

    // Exibe o resultado: o maior elemento estará na posição 0
    vector_print(arr, "Max-Heap");
    
    return 0;
}