#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Para entender a diferenca, usamos o operador 'sizeof()', " << endl;
    cout << "que nos diz quantos bytes cada tipo ocupa na memoria do seu computador atual." << endl;
    cout << "Lembrando que 1 byte = 8 bits." << endl;
    
    cout << "\n--- Tipos de Caracteres ---" << endl;
    cout << "char: " << sizeof(char) << " byte(s)" << endl;
    cout << "char16_t: " << sizeof(char16_t) << " byte(s)" << endl;
    cout << "char32_t: " << sizeof(char32_t) << " byte(s)" << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << " byte(s)" << endl;

    cout << "\n--- Tipos Inteiros ---" << endl;
    cout << "short: " << sizeof(short) << " byte(s)" << endl;
    cout << "int: " << sizeof(int) << " byte(s)" << endl;
    cout << "long: " << sizeof(long) << " byte(s)" << endl;
    cout << "long long: " << sizeof(long long) << " byte(s)" << endl;

    cout << "\n--- Tipos de Ponto Flutuante ---" << endl;
    cout << "float: " << sizeof(float) << " byte(s)" << endl;
    cout << "double: " << sizeof(double) << " byte(s)" << endl;
    cout << "long double: " << sizeof(long double) << " byte(s)" << endl;

    cout << "\n--- Outros Tipos ---" << endl;
    cout << "bool: " << sizeof(bool) << " byte(s)" << endl;
    cout << "string: " << sizeof(string) << " byte(s)" << endl;

    return 0;
}
