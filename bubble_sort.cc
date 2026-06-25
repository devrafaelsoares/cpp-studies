/**
 * @file bubble_sort.cc
 * @brief Implementação do algoritmo de ordenação Bubble Sort em C++.
 *
 * O Bubble Sort é um algoritmo simples de ordenação que percorre
 * repetidamente a lista, compara elementos adjacentes e os troca
 * se estiverem na ordem errada. Possui complexidade O(n²).
 */
#include "utils.hpp"
#include <utility>
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

/**
 * Versão otimizada. Nessa versão utilizando uma variável de controle 'swapped'
 * Ela verifica se houver alguma trocar na última iteração.
 */
void bubbleSortOtimized(vector<int> &arr) {
  int n = arr.size();
  bool swapped;
  int temp;

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

/**
 * @brief Ordena um array utilizando o algoritmo Bubble Sort tradicional.
 *
 * Percorre o array repetidamente, comparando pares adjacentes e
 * trocando-os se estiverem fora de ordem. Continua até que nenhuma
 * troca seja necessária em uma passagem completa.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 */
void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  int temp;

  for (int i = 0; i < n - 1; i++) {

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

int main() {
  vector<int> arr = random_numbers(3);

  vector_print(arr, "\n=====> Vetor Não Ordenado <=====");

  bubbleSortOtimized(arr);

  vector_print(arr, "\n=====> Vetor Ordenado <=====");

  return 0;
}
