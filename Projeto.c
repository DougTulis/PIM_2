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

    printf("====MENU DO ESTOQUE======"); // APÓS O USUÁRIO ESCOLHER O COMANDO DE ESTOQUE NO MENU PRINCIPAL, VAI CAIR NESSE SUBMENU AQUI.
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Itens\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

return 0;
}
