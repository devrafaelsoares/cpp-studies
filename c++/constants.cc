/**
 * @file constants.cc
 * @brief Boas práticas para declaração de constantes em C++ moderno.
 * 
 * Demonstra a transição de macros do estilo C para o `constexpr` do C++, 
 * provendo maior segurança de tipos e otimização na compilação.
 */

#include <iostream>
using namespace std;

// --- CONSTANTES MODERNAS VS MACROS ---
// EVITAR: #define NEWLINE '\n' (Macro legado de C, não possui verificação de tipo)
//
// PREFERIR: `constexpr` garante que o valor seja avaliado e fechado em tempo de compilação.
// Isso impõe segurança de tipagem e permite que o compilador otimize pesadamente o binário.
constexpr char NEWLINE = '\n';

// Constantes matemáticas e físicas são candidatas perfeitas para `constexpr`,
// pois seus valores são imutáveis e universais.
constexpr double PI = 3.14159;
constexpr double ELECTRON_CHARGE = 1.6e-19;
constexpr double AVOGADRO_NUMBER = 6.02e23;

int main() 
{
    // A palavra-chave `const` garante a imutabilidade durante o tempo de execução (runtime).
    // É uma excelente prática proteger as variáveis declarando-as como `const` se elas não mudarão.
    const double radius = 5.0;
    
    // Calculando a circunferência (2 * pi * r).
    // Agrupar a declaração da variável com sua inicialização é a prática recomendada.
    double circumference = 2 * PI * radius;
    
    cout << "A circunferencia de um circulo de raio " << radius << " eh: " << circumference << NEWLINE;

    return 0;
}