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

int main()
{
    printf("Hello world!\n");
    return 0;
}
