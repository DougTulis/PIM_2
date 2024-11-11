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
void salvarProdutos();
void adicionarItemEstoque();
void removerItemEstoque();
void listarItens();



int main() {
    int opcao;

    carregarProdutos();
    do {
        printf("\n=== Menu de Estoque===\n"); // submenu do estoque...
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
            adicionarItemEstoque();
            break;
        case 2:
            removerItemEstoque();
            break;
        case 3:
            listarItens();
            break;
        case 0:
            printf("Saindo do programa...\n");
            salvarProdutos();
            exit(1);
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}


void listarItens() {
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nomeProduto);
        printf("Preço Unidade: %.2f\n", produtos[i].precoUnidade);
        printf("Desconto: %.2f\n", produtos[i].desconto);
        printf("Valor Final: %.2f\n", produtos[i].valorFinal);
        printf("Estoque: %d unidades\n", produtos[i].qtd);
        printf("------------------------\n");
    }
}

void carregarProdutos() {
    totalProdutos = 0; // o total do array precisa começa com 0
    FILE *arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "r"); // acesso o arquivo do vinicius
    if (arquivo == NULL) {
        printf("Arquivo não existe!!!!"); // programação defensiva...
        exit(1);
    }
    while(fscanf(arquivo, "%d,%99[^,],%d,%f,%f,%f", &produtos[totalProdutos].id,
                 produtos[totalProdutos].nomeProduto,
                 &produtos[totalProdutos].qtd,
                 &produtos[totalProdutos].precoUnidade,
                &produtos[totalProdutos].desconto,
                 &produtos[totalProdutos].valorFinal) == 6) {
        totalProdutos = totalProdutos + 1; // contador de produtos, e vai percorrer o array de produtos, assim ne precisa de for..
    }
    fclose(arquivo);
}

void adicionarItemEstoque() {
    bool idExiste = false; // boolean pra controlar o laço se o id existir no array struct.
    int id, quantidade; // declarando o id e quantidade que do produto em questao...
    printf("Insira o ID do produto: ");
    scanf("%d", &id);
    for (int i = 0; i <totalProdutos; i++) {
        if (produtos[i].id == id) {
            idExiste = true;
            printf("Produto selecionado: %s\n", produtos[i].nomeProduto);
            printf("Digite a quantidade de estoque do produto: " );
            scanf("%d", &quantidade);
            produtos[i].qtd += quantidade;
            printf("Estoque atualizado com sucesso!\nEstoque atual do produto: %d", produtos[i].qtd);
            salvarProdutos();
            break;
        }
    }
    if (!idExiste) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

void removerItemEstoque() {
    int idEstoque, qtdRemover;
    bool idExiste = false;

    printf("Escreva o ID do item que você deseja remover do estoque: ");
    scanf("%d", &idEstoque);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == idEstoque) {
            idExiste = true;
            printf("Produto selecionado: %s\n", produtos[i].nomeProduto);
            printf("Selecione a quantidade de itens que você deseja remover: ");
            scanf("%d", &qtdRemover);

            if (produtos[i].qtd >= qtdRemover) {
                produtos[i].qtd -= qtdRemover;
                printf("Estoque atualizado com sucesso!\nEstoque atual do produto: %d\n", produtos[i].qtd);
            } else {
                printf("Erro: Quantidade insuficiente em estoque.\n");
            }

            salvarProdutos();
            break;
        }
    }

    if (!idExiste) {
        printf("Produto com ID %d não encontrado.\n", idEstoque);
    }
}


void salvarProdutos() {
    FILE *arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de produtos para salvar.\n");
        exit(1);
    }
    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%d,%s,%d,%.2f,%.2f,%.2f\n",
                produtos[i].id,
                produtos[i].nomeProduto,
                produtos[i].qtd, // salvando direto do arquivo vinicius
                produtos[i].precoUnidade,
                produtos[i].desconto,
                produtos[i].valorFinal);
    }
    fclose(arquivo);
}

