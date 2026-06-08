/**
 * @file signed_unsigned.cc
 * @brief Compreendendo a diferença entre inteiros 'signed' e 'unsigned'.
 * 
 * Explica como sacrificar a habilidade de representar números negativos 
 * dobra o limite máximo positivo de um dado, e os riscos envolvidos nisso.
 */

#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. A VANTAGEM DO UNSIGNED
    // ---------------------------------------------------------
    // Um 'short' padrão (signed por definição) dedica 1 bit ao sinal (+/-).
    // Seu limite máximo positivo cai pela metade (geralmente 32.767).
    short signed_limit = 32767;
    
    // Um 'unsigned short' reaproveita esse bit de sinal, dobrando efetivamente
    // a sua capacidade máxima para 65.535.
    unsigned short unsigned_capacity = 60000; 

    cout << "--- 1. A Vantagem do Unsigned ---" << endl;
    cout << "Limite do Signed Short:   " << signed_limit << endl;
    cout << "Unsigned Short suporta: " << unsigned_capacity << endl;

    // ---------------------------------------------------------
    // 2. O PERIGO DO UNSIGNED
    // ---------------------------------------------------------
    // Atribuir um número negativo a uma variável unsigned força um "underflow" binário, 
    // fazendo o valor girar e assumir o maior número positivo possível daquele tipo.
    cout << "\n--- 2. O Perigo do Unsigned ---" << endl;
    
    int valid_debt = -50; 
    unsigned int invalid_debt = -50; // Erro crítico preste a acontecer

    cout << "Divida em um 'int' comum   : " << valid_debt << endl;
    cout << "Divida em um 'unsigned int': " << invalid_debt << " <- (Girou para o maior limite possivel!)" << endl;

    return 0;
}
