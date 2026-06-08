/**
 * @file hello_word.cc
 * @brief Introdução a Entrada/Saída padrão no C++.
 * 
 * Este é classicamente o primeiro programa escrito em C++. Ele demonstra 
 * a estrutura básica de uma aplicação e como exibir textos no console.
 */

#include <iostream>

using namespace std;

int main()
{
    // std::cout representa o dispositivo padrão de saída (normalmente o terminal).
    // O operador de inserção (<<) direciona a string "Hello World!" para o fluxo de saída.
    cout << "Hello World!";
    
    // Retornar 0 indica ao Sistema Operacional que o programa terminou com sucesso.
    return 0;
}