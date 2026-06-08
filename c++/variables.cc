#include <iostream>
using namespace std;

int main()
{
    // --- TIPOS INTEIROS ---
    int number_1 = 10;
    int number_2 = 20;

    // --- TIPO BOOLEANO ---
    // Guarda apenas verdadeiro (true/1) ou falso (false/0).
    bool is_2026 = true;

    // --- TIPO CARACTERE ---
    // Guarda apenas uma letra ou simbolo (sempre entre aspas simples).
    char letter_r = 'R';

    // --- TIPOS DE PONTO FLUTUANTE (Decimais) ---
    // O sufixo 'f' garante que o compilador trate o numero como float (4 bytes).
    float value = 2.5f;
    // O double eh o padrao para decimais em C++ e possui o dobro de precisao (8 bytes).
    double price = 500.000;
    
    // --- A PALAVRA-CHAVE: DECLTYPE ---
    // 'decltype' (declare type) inspeciona o tipo de uma variavel ja existente.
    // Como 'number_1' eh um int, o C++ automaticamente cria 'bar' como um int.
    // Isso eh super util em programacao avancada (templates) onde o tipo pode variar.
    decltype(number_1) bar = 30; // Eh a mesma coisa que digitar: int bar = 30;

    
    // --- EXIBINDO OS RESULTADOS ---
    cout << "--- Calculo Basico ---" << endl;
    cout << number_1 << " + " << number_2 << " = " << number_1 + number_2 << endl;

    cout << "\n--- Testando decltype ---" << endl;
    cout << "A variavel 'bar' copiou o tipo 'int' e guardou o valor: " << bar << endl;

    return 0;
}