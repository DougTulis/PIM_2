#include <stdio.h>
#include <stdlib.h>

typedef struct { // Estrutura heterogenea de produtos... (Vinicius)
    int id;
    int qtd;
    float precoUnidade;
    float desconto;
    float valorFinal;
    char nomeProduto[100];
} produto;


void adicionarItem();
void removerItem();
/// void listarItens();


int main() {
    int opcao;
    do {
        printf("\n=== Menu de Estoque ===\n"); // submenu do estoque...
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            // adicionarItem(); (em manutenção..)
            break;
        case 2:
            // removerItem(); (em manutenção..)
            break;
        case 3:
            listarItens();
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}


void listarItens() { /// leitura dos produtos existentes, retornando praticamente o struct criado pelo vinicius...
    FILE *arquivo;
    arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo de estoque ou arquivo não existe.\n"); // Progrmaação defensiva
        exit(0);
    }
}
