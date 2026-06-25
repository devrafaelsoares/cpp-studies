/**
 * @file insertion_sort.cc
 * @brief Implementação do algoritmo de ordenação Insertion Sort em C++.
 *
 * O Insertion Sort é um algoritmo de ordenação simples e intuitivo.
 * Funciona de maneira semelhante à ordenação de cartas de baralho com as mãos.
 * Possui complexidade de tempo de pior caso O(n²) e melhor caso O(n).
 */
#include "utils.hpp"
#include <vector>

using namespace std;

/**
 * @brief Ordena um array utilizando o algoritmo Insertion Sort.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 */
void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    // Move os elementos de arr[0..i-1] que são maiores que key
    // para uma posição à frente de sua posição atual
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  vector<int> arr = random_numbers(10);

  vector_print(arr, "\n=====> Vetor Não Ordenado <=====");

  insertionSort(arr);

  vector_print(arr, "\n=====> Vetor Ordenado <=====");

  return 0;
}
