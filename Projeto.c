#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {  /// ERstrutura homogenea que irá representar o item do estoque.
    char nome[50];
    int quantidade;
    float preco;
} ItemEstoque;

void adicionarItem(); /// Funcoes de adiciona, remover, listar esses items mas eu vouimplementar dps.
void removerItem();
void listarItens();

int main() {
    int opcao;

    printf("====MENU DO ESTOQUE======\n"); // APÓS O USUÁRIO ESCOLHER O COMANDO DE ESTOQUE NO MENU PRINCIPAL, VAI CAIR NESSE SUBMENU AQUI.
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1:
    // adicionarItem(); Adicionandc itens caso tiver uma compra por exemplo..
    break;
    case 2:
    // removerEstoque(); Removendo itens do estoque caso haja uma venda imputada ,no caso
    break;
    case 3:
    // listarItem(); Chamando a função listar Items para consultar todos os items disponiveis no meu estoque
    break;
    default:
        printf("Opção invalida... tente novamente!");
    }
    return 0;
}
