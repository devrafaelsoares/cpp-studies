#include <iostream>
using namespace std;

int main()
{
    string name;

    cout << "Informe o seu nome: ";

    getline(cin, name);

    cout << "Olá " << name << ", tudo bem?" << endl;

    return 0;
}