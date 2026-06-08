/**
 * @file type_errors.cc
 * @brief Armadilhas comuns ao trabalhar com tipos de dados em C++.
 * 
 * Demonstra conceitos de 'Overflow' de memória, perda de precisão, 
 * e truncamento implícito de valores.
 */

#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. DATA OVERFLOW (Estouro de Limite)
    // ---------------------------------------------------------
    // Quando um valor ultrapassa o limite máximo do seu tipo de dado, 
    // ele "dá a volta" devido a forma como os limites binários operam.
    cout << "--- 1. Limites de Tamanho (Overflow) ---" << endl;
    short valid_short = 32000;
    short overflowed_short = 32768; // Ultrapassa o limite padrão de 32.767
    
    cout << "Valor esperado (32000): " << valid_short << endl;
    cout << "Valor estourado (32768): " << overflowed_short << " <- (Deu a volta para o negativo)" << endl;

    // ---------------------------------------------------------
    // 2. PERDA DE PRECISÃO
    // ---------------------------------------------------------
    // O tipo 'float' sacrifica a precisão matemática em favor da eficiência 
    // de memória quando comparado ao 'double'.
    cout << "\n--- 2. Precisao Decimal (Ponto Flutuante) ---" << endl;
    float low_precision_float = 123456789.12345f; // 4 bytes
    double high_precision_double = 123456789.12345; // 8 bytes
    
    // Formatando a saída do terminal para fins de demonstração
    cout.precision(14);
    cout << fixed;      
    
    cout << "Salvo em Float : " << low_precision_float << " <- (Precisao foi perdida!)" << endl;
    cout << "Salvo em Double: " << high_precision_double << " <- (Mantem os dados exatos)" << endl;

    // ---------------------------------------------------------
    // 3. TRUNCAMENTO SILENCIOSO
    // ---------------------------------------------------------
    // Atribuir um valor de ponto flutuante (decimal) para uma variável inteira 
    // resulta no descarte total e silencioso da parte fracionária.
    cout << "\n--- 3. Truncamento de Tipos ---" << endl;
    int valid_integer = 10;
    int truncated_integer = 10.99; // Compila perfeitamente, mas a fração some
    
    cout << "Int valido (10)   : " << valid_integer << endl;
    cout << "Truncado (10.99)  : " << truncated_integer << " <- (Decimais foram completamente ignorados!)" << endl;

    return 0;
}
