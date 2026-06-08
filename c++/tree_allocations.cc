/**
 * @file tree_allocations.cc
 * @brief Demonstração das três formas principais de gerenciar memória em C++.
 * 
 * Este arquivo foi criado para comparar as diferentes estratégias de alocação 
 * de estruturas de dados (como Árvores), discutindo os Prós e Contras de cada.
 */

#include <iostream>
#include <memory> // Necessário para usar os Smart Pointers (C++ Moderno)
using namespace std;

// =====================================================================
// FORMA 1: Stack (Pilha Local)
// =====================================================================
struct NodeStack {
    NodeStack* left{nullptr};
    NodeStack* right{nullptr};
    int value;
};

void forma_stack() {
    cout << "=== FORMA 1: Stack (Memoria Local) ===" << endl;
    
    /* 
     * [ PRÓS E CONTRAS ]
     * + PRÓ: É a forma mais rápida que existe na computação (alocação instantânea).
     * + PRÓ: Limpeza 100% automática. Zero risco de memory leak.
     * - CONTRA: A memória "Stack" é muito pequena (geralmente poucos Megabytes). Se a árvore for muito funda, causa Stack Overflow (crash fatal).
     * - CONTRA: Os nós "morrem" assim que a função acaba. Você não consegue criar a árvore aqui e devolver ela para o resto do programa usar.
     */
     
    // Criando como variáveis normais diretamente na Pilha.
    NodeStack base_node;
    NodeStack left_node;
    NodeStack right_node;

    base_node.value = 10;
    left_node.value = 5;
    right_node.value = 15;

    // O operador '&' pega o endereço na memória para preencher o ponteiro.
    base_node.left = &left_node;
    base_node.right = &right_node;

    cout << "Raiz: " << base_node.value << " | Esq: " << base_node.left->value << " | Dir: " << base_node.right->value << endl;
}


// =====================================================================
// FORMA 2: Classica no Heap (C++ Raiz com new/delete)
// =====================================================================
struct NodeClassic {
    NodeClassic* left{nullptr};
    NodeClassic* right{nullptr};
    int value;
};

void forma_classica() {
    cout << "\n=== FORMA 2: Classica (Heap com new e delete) ===" << endl;
    
    /* 
     * [ PRÓS E CONTRAS ]
     * + PRÓ: Memória quase ilimitada (limitada apenas pela sua memória RAM). Ótima para árvores gigantes.
     * + PRÓ: Os nós sobrevivem após o fim da função. Você pode criar e devolver a árvore para outros lugares.
     * - CONTRA: Risco altíssimo de Memory Leak. Se um 'delete' for esquecido ou se der um erro no meio, a RAM fica ocupada pra sempre.
     * - CONTRA: Gestão manual exaustiva. Se você deletar o nó, mas outro lugar tentar acessar, o programa quebra (Dangling Pointer).
     */
     
    // Pedindo memória manualmente ao Sistema Operacional.
    NodeClassic* base_node = new NodeClassic;
    NodeClassic* left_node = new NodeClassic;
    NodeClassic* right_node = new NodeClassic;

    base_node->value = 10;
    left_node->value = 5;
    right_node->value = 15;

    base_node->left = left_node;
    base_node->right = right_node;

    cout << "Raiz: " << base_node->value << " | Esq: " << base_node->left->value << " | Dir: " << base_node->right->value << endl;

    // REGRA DE OURO: Limpeza manual obrigatória.
    delete left_node;
    delete right_node;
    delete base_node;
}


// =====================================================================
// FORMA 3: Moderna no Heap (Smart Pointers - Padrão Ouro do C++11/14)
// =====================================================================
struct NodeModern {
    // unique_ptr garante que esse ponteiro tenha UM ÚNICO dono. 
    unique_ptr<NodeModern> left{nullptr};
    unique_ptr<NodeModern> right{nullptr};
    int value;
};

void forma_moderna() {
    cout << "\n=== FORMA 3: Moderna (Smart Pointers std::unique_ptr) ===" << endl;
    
    /* 
     * [ PRÓS E CONTRAS ]
     * + PRÓ: Une o melhor dos dois mundos: Memória quase ilimitada do Heap com a limpeza 100% automática do Stack!
     * + PRÓ: Sem dores de cabeça. Fim absoluto do risco de Memory Leaks. Padrão exigido na Indústria atual.
     * - CONTRA: Sintaxe um pouco menos intuitiva para iniciantes (requer entender o std::move).
     * - CONTRA: O compilador exige que fique claro quem é o "dono" da memória, não permitindo cópias fáceis.
     */
     
    // make_unique é a forma segura e moderna de alocar memória (substitui o 'new').
    auto base_node = make_unique<NodeModern>();
    auto left_node = make_unique<NodeModern>();
    auto right_node = make_unique<NodeModern>();

    base_node->value = 10;
    left_node->value = 5;
    right_node->value = 15;

    // unique_ptr é ciumento: ele só aceita 1 dono.
    // Usamos std::move() para "transferir a posse" (Ownership) do nó filho.
    base_node->left = std::move(left_node);
    base_node->right = std::move(right_node);

    cout << "Raiz: " << base_node->value << " | Esq: " << base_node->left->value << " | Dir: " << base_node->right->value << endl;
    
    // FIM DA FUNÇÃO: O 'base_node' morre naturalmente e aciona uma destruição
    // em cadeia automática que limpa a memória de toda a árvore! Adeus, delete!
}

// =====================================================================
int main() {
    forma_stack();
    forma_classica();
    forma_moderna();
    return 0;
}
