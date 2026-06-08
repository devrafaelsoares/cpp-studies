/**
 * @file operators.cc
 * @brief Guia de referência prático de todos os operadores em C++.
 * 
 * Este arquivo foi construído para demonstrar o comportamento de todos
 * os grupos de operadores (atribuição, aritmética, lógicos, bitwise, etc.).
 */

#include <ios>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. ASSIGNMENT OPERATOR (=)
    // ---------------------------------------------------------
    cout << "=== 1. Atribuicao (=) ===" << endl;
    int x = 5;
    int y = x ; // 'y' copia o valor de 'x' da direita para a esquerda.

    cout << "x: " << x << ", y: " << endl;

    // ---------------------------------------------------------
    // 2. ARITHMETIC OPERATORS (+, -, *, /, %)
    // ---------------------------------------------------------
    cout << "\n=== 2. Aritmetica (+, -, *, /, %) ===" << endl;
    int a = 11, b = 3;
    cout << "Soma (11 + 3): " << (a + b) << endl;
    cout << "Modulo (11 % 3): " << (a % b) << " <- (O resto da divisao de 11 por 3)" << endl;

    // ---------------------------------------------------------
    // 3. COMPOUND ASSIGNMENT (+=, -=, *=, /=, %=)
    // ---------------------------------------------------------
    cout << "\n=== 3. Atribuicao Composta (+=) ===" << endl;
    int c = 10;
    c += 5; // Forma curta para: c = c + 5;
    cout << "Resultado de 'c += 5': " << c << endl;

    // ---------------------------------------------------------
    // 4. INCREMENT / DECREMENT (++, --)
    // ---------------------------------------------------------
    cout << "\n=== 4. Incremento (++ e --) ===" << endl;
    int d = 5;
    cout << "Original: " << d << endl;
    cout << "Prefix (++d): " << ++d << " <- (Aumenta ANTES de imprimir a linha)" << endl;
    cout << "Postfix (d++): " << d++ << " <- (Imprime ANTES de aumentar)" << endl;
    cout << "Final: " << d << " <- (Prova de que o d++ funcionou na linha anterior)" << endl;

    // ---------------------------------------------------------
    // 5. RELATIONAL OPERATORS (==, !=, >, <, >=, <=)
    // ---------------------------------------------------------
    cout << "\n=== 5. Relacionais e Comparacao ===" << endl;
    cout << boolalpha; // Força o terminal a imprimir 'true' ou 'false' ao invés de 1 e 0.
    cout << "7 == 5? " << (7 == 5) << endl;
    cout << "5 != 3? " << (5 != 3) << endl;

    // ---------------------------------------------------------
    // 6. LOGICAL OPERATORS (!, &&, ||)
    // ---------------------------------------------------------
    cout << "\n=== 6. Logicos (NOT, AND, OR) ===" << endl;
    cout << "NOT true (!true): " << (!true) << endl;
    cout << "(5==5) AND (3>6): " << ((5 == 5) && (3 > 6)) << " <- (Pois a segunda eh falsa)" << endl;
    cout << "(5==5) OR (3>6): " << ((5 == 5) || (3 > 6)) << " <- (A primeira salvou a condicao)" << endl;

    // ---------------------------------------------------------
    // 7. CONDITIONAL TERNARY OPERATOR (? :)
    // ---------------------------------------------------------
    cout << "\n=== 7. Operador Ternario (? :) ===" << endl;
    int age = 20;
    // Leia como: "Se a idade for >= 18 (?) Retorne 'Adulto' (:) Senao retorne 'Menor'"
    string status = (age >= 18) ? "Adulto" : "Menor de idade";
    cout << "Com " << age << " anos o status eh: " << status << endl;

    // ---------------------------------------------------------
    // 8. COMMA OPERATOR (,)
    // ---------------------------------------------------------
    cout << "\n=== 8. Operador de Virgula (,) ===" << endl;
    int f, g;
    f = (g = 3, g + 2); // Primeiro atribui 3 a g, depois avalia g+2 (5) e atribui apenas o 5 para f
    cout << "Apos f = (g = 3, g + 2): g=" << g << " e f=" << f << endl;

    // ---------------------------------------------------------
    // 9. BITWISE OPERATORS (&, |, ^, ~, <<, >>)
    // ---------------------------------------------------------
    cout << "\n=== 9. Bit a Bit (Bitwise) ===" << endl;
    // 5 em binário é 0101, e 3 em binário é 0011
    cout << "5 AND 3 (5 & 3): " << (5 & 3) << " <- (Apenas os bits iguais sobrevivem: 0001 = 1)" << endl;
    cout << "5 << 1: " << (5 << 1) << " <- (Desloca os bits pra esquerda, multiplicando por 2)" << endl;

    // ---------------------------------------------------------
    // 10. EXPLICIT TYPE CASTING
    // ---------------------------------------------------------
    cout << "\n=== 10. Conversao de Tipos (Type Casting) ===" << endl;
    float pi_float = 3.14159f;
    int pi_int = (int)pi_float; // C-Style (Cortou a parte decimal)
    cout << "Original Float: " << pi_float << ", Convertido para Int: " << pi_int << endl;

    // ---------------------------------------------------------
    // 11. SIZEOF
    // ---------------------------------------------------------
    cout << "\n=== 11. Operador sizeof ===" << endl;
    cout << "O tipo 'double' pesa: " << sizeof(double) << " bytes" << endl;

    return 0;
}
