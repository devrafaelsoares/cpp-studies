#include <iostream>
#include <random>
#include <vector>
using namespace std;

template <typename T> inline void vector_print(vector<T> &arr, string text) {

  cout << text << endl;

  cout << "[";

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
};

inline vector<int> random_numbers(int size = 1, int max = 100) {

  vector<int> numbers;
  numbers.reserve(max);

  random_device random;
  mt19937 gen(random());

  uniform_real_distribution<> distrib(0, max - 1);

  for (int i = 0; i < size; i++)
    numbers.push_back(distrib(gen));

  return numbers;
}
