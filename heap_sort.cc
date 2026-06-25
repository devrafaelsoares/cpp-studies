/**
 * @file heap_sort.cc
 * @brief Implementação do algoritmo de ordenação Heap Sort em C++.
 *
 * O Heap Sort é um algoritmo de ordenação baseado em uma estrutura de dados
 * chamada Binary Heap (heap binário). Ele funciona em duas fases:
 *
 *   1. Construção do Max-Heap: reorganiza o array para que o maior elemento
 *      fique na raiz (posição 0), respeitando a propriedade de heap máximo
 *      onde cada nó pai é maior ou igual aos seus filhos.
 *
 *   2. Extração ordenada: remove repetidamente o maior elemento (raiz),
 *      coloca-o na posição final correta do array e restaura a propriedade
 *      de heap na sub-árvore restante.
 *
 * Complexidade:
 *   - Tempo:  O(n log n) em todos os casos (melhor, médio e pior)
 *   - Espaço: O(1) — ordenação in-place, sem memória auxiliar
 *
 * Representação do heap como array (indexação base 0):
 *   - Filho esquerdo de i:  2*i + 1
 *   - Filho direito de i:   2*i + 2
 *   - Pai de i:             (i - 1) / 2
 *
 * Exemplo visual para o array [4, 10, 3, 5, 1]:
 *
 *       4              10              10
 *      / \     =>     /  \     =>     /  \      (Max-Heap construído)
 *    10    3        5     3         5     3
 *   / \            / \             / \
 *  5   1          4   1           4   1
 */
#include "utils.hpp"
#include <vector>

/**
 * @brief Mantém a propriedade de Max-Heap em uma sub-árvore.
 *
 * Dado um nó na posição `i`, verifica se ele é maior que seus filhos
 * esquerdo e direito. Caso não seja, realiza a troca com o maior filho
 * e aplica heapify recursivamente na sub-árvore afetada, garantindo que
 * a propriedade de heap máximo seja restaurada em cascata.
 *
 * @param arr Referência para o array (vector) representando o heap.
 * @param n   Tamanho efetivo do heap (pode ser menor que arr.size()
 *            durante a fase de extração).
 * @param i   Índice do nó raiz da sub-árvore a ser verificada.
 *
 * Exemplo: heapify em i=0 com arr = [4, 10, 3]
 *
 *       4                10
 *      / \     =>       /  \
 *    10    3           4    3
 */
void heapify(vector<int> &arr, int n, int i) {
  // Assume que o nó atual (i) é o maior
  int largest = i;

  // Calcula os índices dos filhos na representação de array
  int left = 2 * i + 1;  // Filho esquerdo
  int right = 2 * i + 2; // Filho direito

  // Se o filho esquerdo existe e é maior que o nó atual, atualiza o maior
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  // Se o filho direito existe e é maior que o atual maior, atualiza
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // Se o maior não é o nó atual, troca e aplica heapify recursivamente
  // na sub-árvore afetada para manter a propriedade de heap
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // Chamada recursiva: o elemento trocado pode violar o heap
    // na sub-árvore do filho, então corrige em cascata
    heapify(arr, n, largest);
  }
}

/**
 * @brief Ordena um array utilizando o algoritmo Heap Sort.
 *
 * O processo ocorre em duas etapas:
 *
 *   Fase 1 — Build Max-Heap:
 *     Percorre os nós internos (de n/2-1 até 0) aplicando heapify
 *     em cada um. Começa pelo último nó pai porque as folhas (n/2 em
 *     diante) já são heaps válidos trivialmente. Após esta fase, o
 *     maior elemento estará na posição 0 (raiz).
 *
 *   Fase 2 — Extração e Ordenação:
 *     Move o maior elemento (raiz) para o final do array, reduz o
 *     tamanho lógico do heap e restaura a propriedade com heapify.
 *     Repete até que reste apenas um elemento.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 *
 * Passo a passo com [4, 10, 3, 5, 1]:
 *   Build:    [4,10,3,5,1] -> [10,5,3,4,1]  (Max-Heap)
 *   Extract:  [10,5,3,4,1] -> swap(10,1) -> [1,5,3,4,|10] -> heapify ->
 * [5,4,3,1,|10] [5,4,3,1]    -> swap(5,1)  -> [1,4,3,|5,10]  -> heapify ->
 * [4,1,3,|5,10]
 *             ...continua até estar totalmente ordenado: [1,3,4,5,10]
 */
void heap_sort(vector<int> &arr) {
  int n = arr.size();

  // ──────────────────────────────────────────────────────
  // Fase 1: Construção do Max-Heap (bottom-up)
  // Começa no último nó que possui filhos (n/2 - 1)
  // e sobe até a raiz, garantindo a propriedade de heap
  // ──────────────────────────────────────────────────────
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // ──────────────────────────────────────────────────────
  // Fase 2: Extração ordenada
  // A cada iteração:
  //   1. Troca a raiz (maior) com o último elemento do heap
  //   2. Reduz o tamanho lógico do heap (i--)
  //   3. Restaura o Max-Heap na raiz com heapify
  // ──────────────────────────────────────────────────────
  for (int i = n - 1; i > 0; i--) {
    // Move o maior elemento (raiz) para a posição final correta
    swap(arr[0], arr[i]);

    // Restaura a propriedade de heap no sub-array reduzido [0..i-1]
    heapify(arr, i, 0);
  }
};

int main() {
  vector<int> arr = random_numbers(10);

  vector_print(arr, "\n=====> Vetor Não Ordenado <=====");

  heap_sort(arr);

  vector_print(arr, "\n=====> Vetor Ordenado <=====");

  return 0;
};