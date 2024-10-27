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
    carregarProdutos();
    do {
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
            listarItens();
            break;
        case 0:
            printf("Saindo do programa...\n");
            salvarProdutosVinculadoComEstoque();
            break;
        default:
            printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}


void listarItens() {
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nomeProduto);
        printf("Pre�o Unidade: %.2f\n", produtos[i].precoUnidade);
        printf("Desconto: %.2f\n", produtos[i].desconto);
        printf("Valor Final: %.2f\n", produtos[i].valorFinal);
        printf("Estoque: %d unidades\n", produtos[i].qtd);
        printf("------------------------\n");
    }
}

void carregarProdutos() {
    totalProdutos = 0; // o total do array precisa come�a com 0
    FILE *arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\Produtos.txt", "r"); // acesso o arquivo do vinicius
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
    /// Teste com arquivo-estoque que eu criei....
    int idEstoque, idQtd;
    FILE *arquivoEstoque = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\ProdutoEstoque.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo n�o existe."); // programa��o defensiva!
        exit(1);
    }
    while(fscanf(arquivoEstoque, "ID do produto: %d%*[^\n]\n%*[^\n]\n%*[^\n]\n%*[^\n]\nEstoque: %d\n", &idEstoque, &idQtd) == 2) { // aqui vai ler o id (primeira linha), vai pular 4 linhas e depois ler o estoque...
        for(int i = 0; i < totalProdutos; i++ ) { // percorrendo o struct global de produtos...
            if (idEstoque == produtos[i].id) {
                produtos[i].qtd = idQtd; /// se o id for correspondente ao produto ele vai atualizar o estoque dele j� declarado da outra fun��o
                break;
            }
        }
    }

    void salvarProdutosVinculadoComEstoque() {
        FILE *arquivo = fopen("E:\\Linguagem_C\\Projeto PIM 2\\Projeto\\bin\\Debug\\ProdutoEstoque.txt", "w"); // PASTA TXT NOVA QUE VOU ESCREVER OS PRODUTOS COM ESTOQUE
        if (arquivo == NULL) {
            printf("Arquivo n�o existe."); // programa��o defensiva...
            exit(1);
        }

        for (int i = 0; i <totalProdutos; i++ ) { // aqui sera um la�o for pra tipo percorrer todos os structs de produtos e assim escreve-los na nova txt
            fprintf(arquivo, "ID do produto: %d\n Produto: %s\n Pre�o por unidade: %.2f\n Desconto aplicado: %.2f\n Valor Final: %.2f\n Estoque: %d\n------------------------\n",produtos[i].id,
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
                printf("Digite a quantidade de estoque do produto: " );
                scanf("%d", &quantidade);
                produtos[i].qtd += quantidade;
                printf("Estoque atualizado com sucesso!\n Estoque atual do produto: %d", produtos[i].qtd);
                break;
            }
        }
        if (!idExiste) {
            printf("Produto com ID %d n�o encontrado.\n", id);
        }
    }
