#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {  /// ERstrutura heterogenea que ir� representar o item do estoque.
    char nome[50];
    int quantidade;
    float preco;
} ItemEstoque;

void adicionarItem(); /// Funcoes de adiciona, remover, listar esses items mas eu vouimplementar dps.
void removerItem();
void listarItens();

int main() {
    int opcao;
    setlocale(LC_ALL, "Portuguese"); //Settando o locale para portugues brasileiro.
    printf("====MENU DO ESTOQUE======\n"); // AP�S O USU�RIO ESCOLHER O COMANDO DE ESTOQUE NO MENU PRINCIPAL, VAI CAIR NESSE SUBMENU AQUI.
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens\n");
    printf("0. Sair\n");
    printf("Escolha uma op��o: \n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
    // adicionarItem(); Adicionandc itens caso tiver uma compra por exemplo..
    break;
    case 2:
    // removerEstoque(); Removendo itens do estoque caso haja uma venda imputada ,no caso
    break;
    case 3:
    // listarItem(); Chamando a fun��o listar Items para consultar todos os items disponiveis no meu estoque
    break;
    default:
        printf("Op��o invalida... tente novamente!");
    }
    return 0;
}

void listarItens() { // CRIANDO A FUN��O LISTAR ITEM!
FILE *arquivo; // criando  um ponteiro do Tipo File.
arquivo = fopen("C:\\Users\\Familia\\\PROJETO HORTI\\PROJETO HORTIFRUTI\\PRODUTOS.txt","r"); // LENDO OS PRODUTOS CRIADOS NA ABA PRODUTOS (VINICIUS)
if (arquivo == NULL) {
        printf("N�o existe nenhum produto cadastrado no sistema, tente novamente."); // se for nulo ele nem vai prosseguir
    return;
}
}
