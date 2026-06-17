/**
 * @file quick_sort.cc
 * @brief Implementação do algoritmo de ordenação Quick Sort em C++.
 *
 * O Quick Sort é um algoritmo eficiente de ordenação baseado na estratégia
 * de "divisão e conquista" (divide and conquer). Possui complexidade média
 * de O(n log n) e pior caso O(n²), mas na prática é um dos algoritmos
 * mais rápidos devido ao seu bom uso de cache.
 */
#include "utils.hpp"
#include <vector>

using namespace std;

/**
 * @brief Particiona o array em torno de um pivô.
 *
 * Escolhe o último elemento como pivô e reorganiza o array de forma que
 * todos os elementos menores que o pivô fiquem à esquerda e os maiores
 * à direita.
 *
 * @param arr Referência para o array (vector) que contém os elementos.
 * @param low Índice inicial da partição.
 * @param high Índice final da partição (elemento pivô).
 * @return Índice final do pivô após a partição.
 */
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

/**
 * @brief Ordena um array utilizando o algoritmo recursivo Quick Sort.
 *
 * A função seleciona um pivô, particiona o array e ordena recursivamente
 * as duas metades resultantes.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 * @param low Índice inicial da porção do array a ser processada.
 * @param high Índice final da porção do array a ser processada.
 */
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  vector<int> arr = random_numbers(12);
  int arr_size = arr.size();

  vector_print(arr, "\n=====> Vetor Não Ordenado <=====");

  quickSort(arr, 0, arr_size - 1);

  vector_print(arr, "\n=====> Vetor Ordenado <=====");

  return 0;
}
