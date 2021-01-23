#include <stdio.h>
#include <stdlib.h>


struct tipo_estoque{
    int codigo;
    char descricao[300];
    int quantidade;
    char tipoEmbalagem[50];
    float valorCompra;
    float valorVenda;
    char dtvalidade[50];
};
typedef struct tipo_estoque elemento;
const elemento VL_NULO = {0, NULL, 0, NULL, 0, 0, NULL};

#include "tad_fila.c"
#include "tad_pilha.c"


int main(){

    tipo_pilha pilha;
    tipo_fila fila;

    inicializa_lista_pilha(&pilha);
    inicializa_lista_fila(&fila);

    int menu = 0;

    while(menu != 4){
        printf("Bem vindo!\n1 - Cadastrar elemento\n2 - Listar\n4 - Sair\nEscolha: ");
        scanf("%d",&menu);
        if(menu == 1){
            elemento e;
            printf("Digite o codigo do produto: ");
            scanf("%d", &e.codigo);
            printf("Digite a descricao do produto: ");
            fflush(stdin);
            gets(e.descricao);
            fflush(stdin);
            printf("Digite a quantidade do produto: ");
            scanf("%d", &e.quantidade);
            printf("Digite o tipo de embalagem do produto: ");
            fflush(stdin);
            gets(e.tipoEmbalagem);
            fflush(stdin);
            printf("Digite o valor de compra do produto: ");
            scanf("%f", &e.valorCompra);
            printf("Digite o valor de venda do produto: ");
            scanf("%f", &e.valorVenda);
            printf("Digite a data de validade do produto: ");
            fflush(stdin);
            gets(e.dtvalidade);
            fflush(stdin);

            incluir_elemento_fila(&fila, e);
            incluir_elemento_pilha(&pilha,e);
        }else if(menu == 2){
            if(tamanho_quantidade_nodos_fila(fila)){
                printf("Fila: \n");
                tipo_fila aux = fila;
                int i,j;
                elemento e;
                for(i = 0, j = tamanho_quantidade_nodos_fila(aux); i < j; i++){
                    obter_elemento_fila(aux, &e);
                    printf("Elemento: %s; Valor venda: %f; Valor compra: %f;\n", e.descricao, e.valorVenda, e.valorCompra);
                    excluir_elemento_fila(&aux);
                }
            }
            
            if(tamanho_quantidade_nodos_pilha(pilha)){
                printf("Pilha: \n");
                tipo_pilha aux = pilha;
                int i,j;
                elemento e;
                for(i = 0, j = tamanho_quantidade_nodos_pilha(aux); i < j; i++){
                    obter_elemento_pilha(aux, &e);
                    printf("Elemento: %s; Valor venda: %f; Valor compra: %f;\n", e.descricao, e.valorVenda, e.valorCompra);
                    excluir_elemento_pilha(&aux);
                }
            }
            
        }
    }
    return 0;
}