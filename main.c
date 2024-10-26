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
void listarItens();


int main() {
 int opcao;
    do {
        printf("\n=== Menu de Estoque ===\n"); // submenu do estoque...
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // adicionarItem(); (em manuten��o..)
                break;
            case 2:
                // removerItem(); (em manuten��o..)
                break;
            case 3:
                listarItens();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}
