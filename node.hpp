#include <iostream>
using namespace std;

template <typename T>

struct Node
{
    Node* left{nullptr};
    Node* right{nullptr};
    T value;

    Node(T v): value(v) {}
    void print() { cout << value << endl; }
};
