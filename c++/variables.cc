/**
 * @file variables.cc
 * @brief Demonstração dos tipos fundamentais e dedução de tipos em C++.
 * 
 * Explora os tipos básicos fornecidos pela linguagem, sua inicialização,
 * e a funcionalidade moderna `decltype` para dedução de tipos em tempo de compilação.
 */

#include <iostream>
using namespace std;

int main()
{
    // --- TIPOS INTEIROS ---
    // 'int' é o tipo padrão para matemática com números inteiros (geralmente 4 bytes).
    int number_1 = 10;
    int number_2 = 20;

    // --- TIPO BOOLEANO ---
    // Representa valores lógicos de verdade: true (1) ou false (0).
    bool is_2026 = true;

    // --- TIPO CARACTERE ---
    // Representa um único caractere. É armazenado internamente como um número inteiro (Código ASCII).
    // Obrigatório o uso de aspas simples ('').
    char letter_r = 'R';

    // --- TIPOS DE PONTO FLUTUANTE (Decimais) ---
    // 'float' fornece precisão simples (4 bytes). O sufixo 'f' previne
    // uma conversão implícita e desnecessária a partir do tipo 'double'.
    float value = 2.5f;
    
    // 'double' fornece dupla-precisão (8 bytes). É o padrão 
    // adotado pelo C++ para a imensa maioria dos cálculos decimais.
    double price = 500.000;
    
    // --- DECLTYPE (DEDUÇÃO DE TIPO) ---
    // 'decltype' (declare type) inspeciona o tipo de uma entidade na compilação.
    // Aqui, a variável 'bar' irá deduzir e assumir o tipo exato de 'number_1' (que é 'int').
    // Extremamente útil em programação genérica (Templates) onde os tipos podem variar.
    decltype(number_1) bar = 30;
    
    // --- EXIBINDO OS RESULTADOS ---
    cout << "--- Aritmetica Basica ---" << endl;
    cout << number_1 << " + " << number_2 << " = " << number_1 + number_2 << endl;

    cout << "\n--- Testando decltype ---" << endl;
    cout << "A variavel 'bar' deduziu o tipo 'int' e armazenou o valor: " << bar << endl;

    return 0;
}