#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct { // Estrutura heterogenea de produtos... (Vinicius)
    int id;
    int qtd;
    float precoUnidade;
    float desconto;
    float valorFinal;
    char nomeProduto[50];
} produto;


#define MAX_PRODUTOS 999
produto produtos[MAX_PRODUTOS];

int totalProdutos = 0;

void carregarProdutos();
void salvarProdutosVinculadoComEstoque();
void adicionarItemEstoque();
void removerItemEstoque();
void listarItens();



int main() {
    int opcao;
    setlocale(LC_ALL, NULL);
    printf("\n=== Menu de Estoque===\n"); // submenu do estoque...
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens\n");
    printf("0. Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
        adicionarItemEstoque();
        break;
    case 2:
        // removerItem(); (em manuten��o..)
        break;
    case 3:
        carregarProdutos();
        break;
    case 0:
        printf("Saindo do programa...\n");
        break;
    default:
        printf("Op��o inv�lida! Tente novamente.\n");
    }

    return 0;
}


/* void listarItens() { /// leitura dos produtos existentes, retornando praticamente o struct criado pelo vinicius
    FILE *arquivo;
    arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo de estoque ou arquivo n�o existe.\n"); // Progrmaa��o defensiva
        exit(0);
    }


    while(fscanf(arquivo, "%d,%99[^,],%d,%f,%f,%f", &prod.id, prod.nomeProduto, &prod.qtd, &prod.precoUnidade, &prod.desconto, &prod.valorFinal) == 6) {

        printf("ID: %d\n", prod.id);
        printf("Nome: %s\n", prod.nomeProduto);
        printf("Quantidade atual do estoque: %d\n", prod.qtd);
        printf("Pre�o Unidade: %.2f\n", prod.precoUnidade);
        printf("Desconto: %.2f\n", prod.desconto);
        printf("Valor Final: %.2f\n", prod.valorFinal);
        printf("------------------------\n");
    }
    fclose(arquivo);
}*/

void carregarProdutos() {
    totalProdutos = 0; // o total do array precisa come�a com 0
    FILE *arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "r"); // acesso o arquivo
    if (arquivo == NULL) {
        printf("Arquivo n�o existe."); // programa��o defensiva...
        exit(1);
    }
    while(fscanf(arquivo, "%d,%99[^,],%f,%f,%f", &produtos[totalProdutos].id,
                 produtos[totalProdutos].nomeProduto,
                 &produtos[totalProdutos].precoUnidade,
                 &produtos[totalProdutos].desconto,
                 &produtos[totalProdutos].valorFinal) == 5) {
        printf("ID: %s\n", produtos[totalProdutos].nomeProduto);
        produtos[totalProdutos].qtd = 0; // aqui vai come�ar com 0 pq vai ser definido dps;
        totalProdutos = totalProdutos + 1; // contador de produtos, e vai percorrer o array de produtos, assim ne precisa de for..
    }
    fclose(arquivo);
}

void salvarProdutosVinculadoComEstoque() {
    FILE *arquivo = fopen("E:\Linguagem_C\Projeto PIM 2\Projeto\bin\Debug\ProdutoEstoque.txt", "w"); // PARA ESCRITA
    if (arquivo == NULL) {
        printf("Arquivo n�o existe."); // programa��o defensiva...
        exit(1);
    }

    for (int i = 0; i <totalProdutos; i++ ) { // aqui sera um la�o for pra tipo percorrer todos os structs de produtos e assim escreve-los na nova txt
        sprintf("ID do produto: %d\n Produto: %s\n Pre�o por unidade: %.2f\n Desconto aplicado: %.2f\n Valor Final: %.2f",produtos[i].id,
                produtos[i].nomeProduto,
                produtos[i].precoUnidade,
                produtos[i].desconto,
                produtos[i].valorFinal,
                produtos[i].qtd);
    }
    fclose(arquivo);
}

void adicionarItemEstoque() {
    carregarProdutos();
    bool idExiste = false; // boolean pra controlar o la�o se o id existir no array struct.
    int id, quantidade; // declarando o id e quantidade que do produto em questao...
    printf("Insira o ID do produto: ");
    scanf("%d", &id);
    for (int i = 0; i <totalProdutos; i++) {
        if (produtos[i].id == id) {
            idExiste = true;
            printf("Produto selecionado: %s\n", produtos[i].nomeProduto);
            printf("Digite a quantidade de estoque do produto: %d", produtos[i].qtd);
            break;
        }
    }
    if (!idExiste) {
        printf("Produto com ID %d n�o encontrado.\n", id);
        }
}
