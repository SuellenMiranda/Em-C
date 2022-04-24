#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 80

//Criação da Struct Lote
typedef struct lote {
    int codigo, qntd;
    char tipo[11];
    float precoUnidade, precoVenda;
    char fornecedor[100];
}LOTE;

//Declaração dos Módulos/Funcoes
void carregarStruct(LOTE lotes[MAX]);
int menu();
void cadastrarLote(LOTE lotes[MAX], int qntd);
void excluirLote(LOTE lotes[MAX], int codigo);
void atualizarLote(LOTE lotes[MAX], int codigo);
void consultarLote(LOTE lotes[MAX], int codigo);
void relatorioDeLote(LOTE lotes[MAX], char fornecedor[100]);
void exibirLotes(LOTE lotes[MAX]);
void ordernarLotes(LOTE lotes[MAX]);
int verificarNumeroDeLotes(LOTE lotes[MAX]);

int main() {
    setlocale(LC_ALL, "English");

    LOTE lotes[MAX];
    int opcao, auxiliar;
    char auxiliarChar[100];

    carregarStruct(lotes);
// MENU de funcionalidades.
    do {
        printf("------------------------------------\n");

        opcao = menu();

        if(opcao == 1) {
            system("cls");

            printf("Informe Quantos Lotes Deseja Cadastrar: ");
            scanf("%i", &auxiliar);

            system("cls");

            if(auxiliar > 0 && auxiliar <= 80) {
                cadastrarLote(lotes, auxiliar);
            } else {
                printf("\nNumero Invalido\n");
            }

        } else if(opcao == 2) {
            system("cls");

            printf("Informe O Codigo Do Lote: ");
            scanf("%i", &auxiliar);

            system("cls");

            excluirLote(lotes, auxiliar);
        } else if(opcao == 3) {
            system("cls");

            printf("Informe O Codigo Do Lote: ");
            scanf("%i", &auxiliar);

            system("cls");

            atualizarLote(lotes, auxiliar);
        } else if(opcao == 4) {
            system("cls");

            printf("Informe O Codigo Do Lote: ");
            scanf("%i", &auxiliar);

            system("cls");

            consultarLote(lotes, auxiliar);
        } else if(opcao == 5) {
            system("cls");

            printf("Informe O Fornecedor: ");
            scanf("\n%[^\n]", auxiliarChar);

            system("cls");

            relatorioDeLote(lotes, auxiliarChar);
        } else if(opcao == 6) {
            system("cls");

            exibirLotes(lotes);
        } else if(opcao == 0) {
            printf("Programa Finalizado Com Sucesso!");
        } else {
            printf("\nOpcao Nao Existe!\n");
        }
    }while(opcao != 0);

    return 0;
}

// Criação dos 10 primeiros Lotes obrigatórios.
void carregarStruct(LOTE lotes[MAX]) {
    int i;

    for(i = 0; i < MAX; i++) {
        if(i < 10) {
            lotes[i].codigo = rand() % (100 - 1) + 1;
            lotes[i].qntd = rand() % (100 - 50) + 50;
            lotes[i].precoUnidade = rand() % (152 - 43) + 43;
            lotes[i].precoVenda = lotes[i].precoUnidade + lotes[i].precoUnidade * 0.3;
            if(i <= 6) {
                strcpy(lotes[i].fornecedor, "Murphy Exploration & Production Company");
            } else {
                strcpy(lotes[i].fornecedor, "Petrobras");
            }

            if(i < 4) {
                strcpy(lotes[i].tipo, "Parafinicos");
            } else if(i > 3 && i <= 5) {
                strcpy(lotes[i].tipo, "Naftenicos");
            } else if(i > 5 && i <= 9) {
                strcpy(lotes[i].tipo, "Mistos");
            } else {
                strcpy(lotes[i].tipo, "Aromaticos");
            }
        } else {
            lotes[i].codigo = -1;
            lotes[i].tipo[0] = '-';
            lotes[i].qntd = 0;
            lotes[i].precoUnidade = 0;
            lotes[i].precoVenda = 0;
            lotes[i].fornecedor[0] = '-';
        }
    }
}

// Menu que aloca valor digitado em op e retorna em opção.
int menu() {
    int op;

    printf("1 - Cadastrar Novo Lote.\n");
    printf("2 - Excluir Lote.\n");
    printf("3 - Atualizar Lote.\n");
    printf("4 - Consultar Lote.\n");
    printf("5 - Relatorio.\n");
    printf("6 - Exibir Todos os Lotes.\n");
    printf("0 - Encerrar Programa.\n\n");
    printf("DIGITE SUA OPCAO: ");
    scanf("%i", &op);

    return op;
}

// Funcao para Cadastro de Lotes
void cadastrarLote(LOTE lotes[MAX], int qntd) {
    int i, j, aux, codigo, quantidade, jaExiste;
    char tipo[11];

    aux = verificarNumeroDeLotes(lotes); //Conta quantos lotes cadastrados existem

    for(i = aux; i < MAX; i++) {
        jaExiste = 0;

        if(qntd > 0) {
            printf("\tPreencha os Dados do Lote\n\n");
            printf("Codigo do Lote: ");
            scanf("%i", &codigo);

            for(j = 0; j < MAX; j++) {
                if(lotes[j].codigo == codigo) {
                    jaExiste = 1;
                }
            }

            if(!jaExiste) {
                printf("Tipo: ");
                scanf("\n%[^\n]", tipo);
                printf("Quantidade de Barris: ");
                scanf("%i", &quantidade);
                if(quantidade < 50 || quantidade > 100) {
                    printf("***Apenas Permitido O Cadastro de 50 a 100 Barris Por Lote!***\n\n");
                } else {
                    lotes[i].codigo = codigo;
                    strcpy(lotes[i].tipo, tipo);
                    lotes[i].qntd = quantidade;
                    printf("Preco Unidade: ");
                    scanf("%f", &lotes[i].precoUnidade);
                    lotes[i].precoVenda = lotes[i].precoUnidade + lotes[i].precoUnidade * 0.3;
                    printf("Fornecedor: ");
                    scanf("\n%[^\n]", lotes[i].fornecedor);
                    printf("\n");
                    qntd--;
                }
            } else {
                system("cls");
                printf("Esse Codigo Ja Existe!\n\n");
            }
        } else
            break;
    }
}

// Funcao para excluir determinado Lote.
void excluirLote(LOTE lotes[MAX], int codigo) {
    int i, tam, aux = 0;

    tam = verificarNumeroDeLotes(lotes);

    for(i = 0; i < tam; i++) {
        if(lotes[i].codigo == codigo) {
            lotes[i].codigo = lotes[i + 1].codigo;
            strcpy(lotes[i].tipo, lotes[i+1].tipo);
            lotes[i].qntd = lotes[i + 1].qntd;
            lotes[i].precoUnidade = lotes[i + 1].precoUnidade;
            strcpy(lotes[i].fornecedor, lotes[i+1].fornecedor);
            aux = 1;
        }
    }

    if(aux == 1) {
        printf("Lote Excluido Com Sucesso!\n\n");
    } else {
        printf("Esse Lote Nao Foi Encontrado!\n\n");
    }
}
// Modulo para atualizar informacoes de um Lote especifico.
void atualizarLote(LOTE lotes[MAX], int codigo) {
    int i, tam, aux = 0, quantidade;
    char tipo[11];

    tam = verificarNumeroDeLotes(lotes);

    for(i = 0; i < tam; i++) {
        if(lotes[i].codigo == codigo) {
            printf("\tPreencha os Dados do Lote\n\n");
            printf("Codigo do Lote: %i\n", lotes[i].codigo);
            printf("Tipo: ");
            scanf("\n%[^\n]", tipo);
            printf("Quantidade de Barris: ");
            scanf("%i", &quantidade);
            if(quantidade < 50 || quantidade > 100) {
                printf("***Apenas Permitido O Cadastro de 50 a 100 Barris Por Lote!***\n\n");
                i--;
            } else {
                strcpy(lotes[i].tipo, tipo);
                lotes[i].qntd = quantidade;
                printf("Preco Unidade: ");
                scanf("%f", &lotes[i].precoUnidade);
                lotes[i].precoVenda = lotes[i].precoUnidade + lotes[i].precoUnidade * 0.3;
                printf("Fornecedor: ");
                scanf("\n%[^\n]", lotes[i].fornecedor);
                printf("\n");
                aux = 1;
            }
        }
    }

    if(aux == 1) {
        printf("Lote Atualizado Com Sucesso!\n\n");
    } else {
        printf("Esse Lote Nao Foi Encontrado!\n\n");
    }
}
// Modulo para consultar informacoes de determinado Lote
void consultarLote(LOTE lotes[MAX], int codigo) {
   int i, aux = 0, tam;
   float precoTotalCompra, precoTotalVenda;

   tam = verificarNumeroDeLotes(lotes);

    for(i = 0; i < tam; i++) {
        if(lotes[i].codigo == codigo) {
            printf("Codigo do Lote: %i\n", lotes[i].codigo);
            printf("Tipo do Lote: %s\n", lotes[i].tipo);
            printf("Quantidade de Barris: %i\n", lotes[i].qntd);
            printf("Preco dos Barris (UNIDADE): %.2f\n", lotes[i].precoUnidade);
            printf("Fornecedor: %s\n", lotes[i].fornecedor);

            precoTotalCompra = lotes[i].precoUnidade * lotes[i].qntd;
            precoTotalVenda = lotes[i].precoVenda * lotes[i].qntd;

            printf("\tPreco Total De Compra: %.2f\n", precoTotalCompra);
            printf("\tPreco Total De Venda: %.2f\n", precoTotalVenda);
            printf("------------------------------------\n");
            aux = 1;
        }
    }

    if(aux == 0) {
        printf("Nenhum Lote Encontrado Com Esse Codigo\n\n");
    }
}

// Funcao para mostrar todos lotes de determinado fornecedor e o calcular o Lucro de todos lotes.
void relatorioDeLote(LOTE lotes[MAX], char fornecedor[100]) {
    int i, aux = 0;
    float precoCompra, precoVenda, precoTotalCompra = 0, precoTotalVenda = 0, lucro;

    for(i = 0; i < MAX; i++) {
        if(strcasecmp(lotes[i].fornecedor, fornecedor) == 0) {
            printf("Codigo do Lote: %i\n", lotes[i].codigo);
            printf("Tipo do Lote: %s\n", lotes[i].tipo);
            printf("Quantidade de Barris: %i\n", lotes[i].qntd);
            printf("Preco De Compra (UNIDADE): $%.2f\n", lotes[i].precoUnidade);
            printf("Preco De Venda (UNIDADE): $%.2f\n", lotes[i].precoVenda);

            precoCompra = lotes[i].precoUnidade * lotes[i].qntd;
            precoVenda = lotes[i].precoVenda * lotes[i].qntd;

            printf("\tPreco Total De Compra Desse Lote: $%.2f\n", precoCompra);
            printf("\tPreco Total De Venda Desse Lote: $%.2f\n", precoVenda);
            printf("------------------------------------\n");

            precoTotalCompra += precoCompra;
            precoTotalVenda += precoVenda;
            lucro = precoTotalVenda - precoTotalCompra;
            aux = 1;
        }
    }

    if(aux == 0) {
        printf("Nenhum Lote Encontrado Com Esse Fornecedor\n\n");
    } else {
        printf("Preco Total De Compra De Todos Os Lotes: $%.2f\n", precoTotalCompra);
        printf("Preco Total De Venda De Todos Os Lotes: $%.2f\n", precoTotalVenda);
        printf("Lucro Total: $%.2f\n\n", lucro);
    }
}
// Funcao para exibir todos os lotes disponiveis.
void exibirLotes(LOTE lotes[MAX]) {
    ordernarLotes(lotes);

    int i, aux = 0, tam;

    tam = verificarNumeroDeLotes(lotes);

    for(i = 0; i < tam; i++) {
        if(lotes[i].codigo > 0) {
            printf("Codigo do Lote: %i\n", lotes[i].codigo);
            printf("Tipo do Lote: %s\n", lotes[i].tipo);
            printf("Quantidade de Barris: %i\n", lotes[i].qntd);
            printf("Preco De Compra (UNIDADE): $%.2f\n", lotes[i].precoUnidade);
            printf("Preco De Venda (UNIDADE): $%.2f\n", lotes[i].precoVenda);
            printf("Fornecedor: %s\n", lotes[i].fornecedor);
            printf("------------------------------------\n");
            aux++;
        }
    }

    if(aux > 0) {
        printf("Quantidade De Lotes Cadastrados: %i\n\n", aux);
    } else {
        printf("Nao Existe Nenhum Lote Cadastrado\n\n");
    }
}
//Funcao para fazer ordenacao dos lotes
void ordernarLotes(LOTE lotes[MAX]) {
    int i, j, aux = 0;
    LOTE auxiliar;

    aux = verificarNumeroDeLotes(lotes);

    for(i = 0; i < aux; i++) {
        for(j = i + 1; j < aux; j++) {
            if(lotes[i].codigo > lotes[j].codigo) {
                auxiliar = lotes[i];
                lotes[i] = lotes[j];
                lotes[j] = auxiliar;
            }
        }
    }
}

int verificarNumeroDeLotes(LOTE lotes[MAX]) {
    int i, aux = 0;

    for(i = 0; i < MAX; i++) {
        if(lotes[i].codigo != -1) {
            aux++;
        }
    }

    return aux;
}
