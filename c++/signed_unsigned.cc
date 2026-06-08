#include <iostream>
using namespace std;

int main() {
    cout << "--- 1. A Vantagem do Unsigned (Sem Sinal) ---" << endl;
    
    // Um 'short' normal (signed short) gasta 1 bit para guardar o sinal (+ ou -).
    // O seu limite maximo positivo e 32.767
    short signed_short = 32767;
    
    // O 'unsigned short' recusa numeros negativos. Em troca, ele usa esse bit extra 
    // para dobrar o limite positivo, indo ate 65.535!
    unsigned short unsigned_short_maior = 60000; 

    cout << "Limite do Short normal (com sinal): " << signed_short << endl;
    cout << "Short Unsigned consegue passar disso: " << unsigned_short_maior << endl;


    cout << "\n--- 2. O Perigo de Usar Unsigned do Jeito Errado ---" << endl;
    
    // O que acontece se voce tentar guardar uma divida ou temperatura negativa 
    // em uma variavel que NAO aceita sinais negativos?
    int divida_com_sinal = -50; // Funciona perfeitamente
    unsigned int divida_sem_sinal = -50; // Cuidado!

    cout << "Divida em variavel normal (int)  : " << divida_com_sinal << endl;
    cout << "Divida em variavel unsigned int  : " << divida_sem_sinal << " <- (Deu a volta para o MAIOR numero possivel!)" << endl;

    return 0;
}
