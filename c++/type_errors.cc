#include <iostream>
using namespace std;

int main() {
    cout << "--- 1. O Problema do Tamanho (Overflow) ---" << endl;
    
    // O tipo 'short' (2 bytes) tem um limite maximo de 32767
    short numero_certo = 32000;
    short numero_errado = 32768; // Passou 1 do limite!
    
    cout << "Valor esperado (32000): " << numero_certo << endl;
    cout << "Valor estourado (32768): " << numero_errado << " <- (Deu a volta e virou negativo!)" << endl;


    cout << "\n--- 2. O Problema da Precisao (Ponto Flutuante) ---" << endl;
    
    // Queremos salvar o numero exato 123456789.12345
    float float_errado = 123456789.12345f; // float tem 4 bytes
    double double_certo = 123456789.12345; // double tem 8 bytes
    
    // Configura o 'cout' para mostrar mais casas decimais e nao usar notacao cientifica
    cout.precision(14);
    cout << fixed;      
    
    cout << "Salvando em um Float : " << float_errado << " <- (Perdeu precisao!)" << endl;
    cout << "Salvando em um Double: " << double_certo << " <- (Manteve os dados exatos)" << endl;


    cout << "\n--- 3. Erro Silencioso de Tipos ---" << endl;
    
    // O que acontece se colocar um numero quebrado dentro de uma variavel que so aceita inteiros?
    int inteiro_certo = 10;
    int inteiro_errado = 10.99; // C++ permite, mas "corta" os decimais!
    
    cout << "Int certo (10)    : " << inteiro_certo << endl;
    cout << "Int errado (10.99): " << inteiro_errado << " <- (A parte decimal inteira foi ignorada!)" << endl;

    return 0;
}
