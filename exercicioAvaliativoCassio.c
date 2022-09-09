/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.


Exercício Avaliativo
Aluna: Suellen Miranda Amorim
Professor: Cássio Capucho

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct ExercicioAvaliativoNo{
    int valor;
    struct ExercicioAvaliativoNo *proximo;
}ExercicioAvaliativoNo;

// procedimento para inserir no início
void inserir_no_inicio(ExercicioAvaliativoNo **lista, int num){
    ExercicioAvaliativoNo *novo = malloc(sizeof(ExercicioAvaliativoNo));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(ExercicioAvaliativoNo **lista, int num){
    ExercicioAvaliativoNo *aux, *novo = malloc(sizeof(ExercicioAvaliativoNo));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(ExercicioAvaliativoNo **lista, int num, int ant){
    ExercicioAvaliativoNo *aux, *novo = malloc(sizeof(ExercicioAvaliativoNo));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(ExercicioAvaliativoNo **lista, int num){
    ExercicioAvaliativoNo *aux, *novo = malloc(sizeof(ExercicioAvaliativoNo));

    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

ExercicioAvaliativoNo* remover(ExercicioAvaliativoNo **lista, int num){
    ExercicioAvaliativoNo *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

ExercicioAvaliativoNo* buscar(ExercicioAvaliativoNo **lista, int num){
    ExercicioAvaliativoNo *aux, *ea_no = NULL;

    aux = *lista;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        ea_no = aux;
    return ea_no;
}

void imprimir(ExercicioAvaliativoNo *ea_no){
    printf("\n\tLista: ");
    while(ea_no){
        printf("%d ", ea_no->valor);
        ea_no = ea_no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    ExercicioAvaliativoNo *removido, *lista = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:
            imprimir(lista);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
