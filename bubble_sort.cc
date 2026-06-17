/**
 * @file bubble_sort.cc
 * @brief Implementação do algoritmo de ordenação Bubble Sort em C++.
 *
 * O Bubble Sort é um algoritmo simples de ordenação que percorre
 * repetidamente a lista, compara elementos adjacentes e os troca
 * se estiverem na ordem errada. Possui complexidade O(n²).
 */
#include "utils.hpp"
#include <vector>

using namespace std;

/**
 * @brief Ordena um array utilizando o algoritmo Bubble Sort otimizado.
 *
 * Utiliza uma flag para detectar se houve trocas na iteração.
 * Caso nenhuma troca ocorra, o array já está ordenado e o algoritmo
 * encerra antecipadamente.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 */
void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  bool swapped;

  for (int i = 0; i < n - 1; i++) {
    swapped = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }
}

int main() {
  vector<int> arr = random_numbers(10);

  vector_print(arr, "\n=====> Vetor Não Ordenado <=====");

  bubbleSort(arr);

  vector_print(arr, "\n=====> Vetor Ordenado <=====");

  return 0;
}
