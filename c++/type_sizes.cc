/**
 * @file type_sizes.cc
 * @brief Analisando o consumo de memória dos tipos fundamentais do C++.
 * 
 * Demonstra o uso do operador `sizeof()`, que avalia o tamanho 
 * (em bytes) de um tipo de dado na arquitetura atual da máquina.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Tamanhos de memoria dependem do hardware e do compilador." << endl;
    cout << "O operador sizeof() revela quantos bytes cada tipo consome." << endl;
    cout << "Lembrete: 1 byte = 8 bits.\n" << endl;
    
    // --- TIPOS DE CARACTERES ---
    // Usados para representar textos e símbolos através de diferentes codificações.
    cout << "--- Tipos de Caracteres ---" << endl;
    cout << "char (Padrao ASCII): " << sizeof(char) << " byte(s)" << endl;
    cout << "char16_t (UTF-16):   " << sizeof(char16_t) << " byte(s)" << endl;
    cout << "char32_t (UTF-32):   " << sizeof(char32_t) << " byte(s)" << endl;
    cout << "wchar_t (Wide char): " << sizeof(wchar_t) << " byte(s)" << endl;

    // --- TIPOS INTEIROS ---
    // Diferem primariamente em seus limites máximos e mínimos de representação.
    cout << "\n--- Tipos Inteiros ---" << endl;
    cout << "short:     " << sizeof(short) << " byte(s)" << endl;
    cout << "int:       " << sizeof(int) << " byte(s)" << endl;
    cout << "long:      " << sizeof(long) << " byte(s)" << endl;
    cout << "long long: " << sizeof(long long) << " byte(s)" << endl;

    // --- TIPOS DE PONTO FLUTUANTE ---
    // Diferem em sua precisão matemática (número de casas decimais confiáveis).
    cout << "\n--- Tipos de Ponto Flutuante ---" << endl;
    cout << "float:       " << sizeof(float) << " byte(s)" << endl;
    cout << "double:      " << sizeof(double) << " byte(s)" << endl;
    cout << "long double: " << sizeof(long double) << " byte(s)" << endl;

    // --- OUTROS TIPOS ---
    cout << "\n--- Outros Tipos ---" << endl;
    cout << "bool:   " << sizeof(bool) << " byte(s)" << endl;
    
    // std::string é uma classe complexa, então seu tamanho representa sua estrutura
    // de controle interno (ponteiros, capacidade alocada), e não o tamanho do texto.
    cout << "string: " << sizeof(string) << " byte(s)" << endl;

    return 0;
}
