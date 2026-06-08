/**
 * @file constexpr_vs_const.cc
 * @brief Distinguindo constantes de runtime (`const`) de constantes de compilação (`constexpr`).
 * 
 * Ilustra as diferenças fundamentais de "como" e "quando" o C++ avalia as constantes.
 */

#include <iostream>
using namespace std;

/**
 * @brief Simula o recebimento de dados em runtime (ex: via teclado ou sensor).
 * O valor de retorno não pode ser inferido até o programa estar efetivamente rodando.
 */
int fetch_runtime_data() {
    return 42; 
}

int main() {
    // ---------------------------------------------------------
    // 1. 'const' (Imutabilidade em Tempo de Execução)
    // ---------------------------------------------------------
    // Promete que a variável não sofrerá mutações após ser inicializada.
    // Aceita perfeitamente valores que só são determinados durante a execução do programa.
    const int runtime_locked_value = fetch_runtime_data(); 
    
    // Descomentar a linha abaixo gera um erro de compilação:
    // runtime_locked_value = 100; // ERRO: Atribuição em variável read-only


    // ---------------------------------------------------------
    // 2. 'constexpr' (Avaliação em Tempo de Compilação)
    // ---------------------------------------------------------
    // Um contrato mais estrito: O valor exato DEVE ser conhecido durante a compilação.
    // O compilador pré-computa este valor e o embute diretamente no binário do executável.
    constexpr int earth_gravity = 10;
    constexpr int speed_of_light = 299792458;

    // Descomentar a linha abaixo impede o programa de compilar:
    // constexpr int impossible_data = fetch_runtime_data(); 
    // ERRO: fetch_runtime_data() não é processado até o runtime, quebrando a regra do constexpr.

    cout << "Const (Runtime): " << runtime_locked_value << endl;
    cout << "Constexpr (Compile-Time): " << earth_gravity << endl;

    return 0;
}
