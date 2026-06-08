#include <iostream>
#include "node.hpp"

using namespace std;


int main()
{
    Node<int> left(5);
    Node<int> node(10);
    Node<int> right(15);

    node.right = &right;
    node.left  = &left;

    cout << node.left->value << endl;
    cout << node.right->value << endl;
    cout << node.value << endl;

    return 0;
}