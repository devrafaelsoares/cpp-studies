/**
 * @file merge_sort.cc
 * @brief Implementação do algoritmo de ordenação Merge Sort em C++.
 * 
 * O Merge Sort é um algoritmo eficiente de ordenação baseado na estratégia
 * de "divisão e conquista" (divide and conquer), possuindo complexidade de 
 * tempo garantida de O(n log n) em todos os cenários (pior, médio e melhor caso).
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Mescla dois sub-arrays ordenados em um único array ordenado.
 * 
 * Esta função é o núcleo do algoritmo Merge Sort. Ela recebe um array e os índices
 * que delimitam dois sub-arrays adjacentes (que já devem estar ordenados). A função 
 * então os copia para arrays temporários e os mescla de volta no array original 
 * mantendo a ordenação.
 *
 * @param arr Referência para o array (vector) que contém os elementos.
 * @param left Índice inicial do primeiro sub-array.
 * @param mid Índice final do primeiro sub-array (limite entre as duas metades).
 * @param right Índice final do segundo sub-array.
 */
void merge(vector<int> &arr, int left, int mid, int right) {

  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];

  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/**
 * @brief Ordena um array utilizando o algoritmo recursivo Merge Sort.
 * 
 * A função divide o array recursivamente pela metade até que cada sub-array contenha 
 * no máximo um elemento. Em seguida, as metades são recombinadas e ordenadas usando 
 * a função auxiliar 'merge'.
 *
 * @param arr Referência para o array (vector) a ser ordenado.
 * @param left Índice inicial da porção do array a ser processada.
 * @param right Índice final da porção do array a ser processada.
 */
void mergeSort(vector<int> &arr, int left, int right) {

  if (left >= right)
    return;

  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main() {

  vector<int> arr = {25, 84, 10, 62, 5, 88, 10};
  int arr_size = arr.size();
  int left = 0;
  int right = arr_size - 1;

  mergeSort(arr, left, right);

  for (int i = 0; i < arr_size; i++) {
    if (i == 0)
      cout << "| ";
    cout << arr[i] << " | ";
  }
  cout << endl;

  return 0;
}