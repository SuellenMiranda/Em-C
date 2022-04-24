#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

//Variáveis Gerais:
const int tam = 80;
//quantidade de linhas
int i, j, qtd_lin = 10;

//Declaração e Inicialização das Varíaveis responsáveis pelos lotes de barril: 

//Informações do código e da quantidade de barris: 
int c_qtd[tam][2] = {1, 50, 3, 60, 2, 90, 4, 78, 8, 65, 5, 99, 7, 52, 6, 92, 9, 72, 10, 69}; 
//Informações do preço de compra e preço de venda: 
float pc_pv[tam][2] = {15.5, 25.5, 12.8, 24.8, 15.75, 30.75, 14.8, 60.2, 9.56, 18.90, 6.78, 19.12, 70.0, 14.15, 23.13, 56.42, 14.56, 87.0, 16.10, 59.0};
//Guarda o tipo: 
char tipo[tam][11] = {"Misto", "Naftenico", "Aromatico", "Naftenico", "Parafinico", "Aromatico", "Misto", "Misto", "Parafinico", "Naftenico"};
//Guarda o nome da plataforma: 
char plataf[tam][20] = {"PT13", "PT12", "PT90", "PT10", "PT10", "PT03", "PT12", "PT90", "PT13", "PT13"};


//Matriz de Ordenação:
int matr_ord[tam][2];

//Protótipos de Funções:

int MENU();
//Mostra o Menu e retorna a opção lida;
void imprimir_dados();
void inicializa_matr_ord();
//Função para ordenação
void ordenar();
void relatorio_lucro();
int consulta_lote(int codigo); 
void cadastrar();
void excluir();
void consultar();

//Programa Principal
int main(void) { 
  int OP;
  
  inicializa_matr_ord();


  //Menu:
   printf("\n\n======= Bem vindo a Refinaria Petrosol =======\n\n");
   printf("\n--- Funções com base no lote de barril ---\n");

   do{
       OP = MENU(); 
       switch(OP){
            case 1: cadastrar(); break;
            case 2: excluir(); break;
            case 3: break;
            case 4: consultar(); break;
            case 5: relatorio_lucro(); break;
            case 6: imprimir_dados(); break;
            case 7: printf("\n\nPrograma Finalizado"); break;
            default: printf("\nOpção Inválida"); 
         }
       }
     while(OP != 7); 
}


//Funções:

//Módulo do Menu;
int MENU(){

  int opcao;

     printf("\n1 - Cadastro");
     printf("\n2 - Exclusão");
     printf("\n3 - Atualização");
     printf("\n4 - Consulta Lote");
     printf("\n5 - Impressão do relatório de lucratividade");
     printf("\n6 - Impressão dos dados dos lotes em ordem crescente");
     printf("\n7 - Finalização do programa");

    printf("\n\nEscolha a sua opção: ");
    scanf("%i", &opcao);
  
  return opcao;
}

//Função para imprimir os dados dos lotes do estoque
void imprimir_dados(){  
  
  int lin;

    printf("\nCódigo   Tipo          Qtde   Plataforma   Vl.Compra   Vl.Venda\n");
    for(i = 0; i < qtd_lin; i++){

      lin = matr_ord[i][1]; 
   
      printf("%5i", c_qtd[lin][0]);
      printf("    ");
      printf("%-15s", tipo[lin]);
      printf("%3i", c_qtd[lin][1]);
      printf("%10s", plataf[lin]);
      printf("%13.2f", pc_pv[lin][0]);
      printf("%13.2f\n", pc_pv[lin][1]);      
    }
   printf("\n");
}


//Pegando a varíavel matr_ord, armazena o código e a linha das matrizes de dados;
void inicializa_matr_ord(){

    for(i = 0; i < qtd_lin; i++){
       
      matr_ord[i][0] = c_qtd[i][0];
      matr_ord[i][1] =  i;
    } 
    ordenar();
}

void ordenar(){
  
  int aux_matr_ord[tam][2], codigo, linha;
  const int max_cod = 999999;

  for(i = 0; i < qtd_lin; i++){
      codigo = max_cod;
      for(j = 0; j < qtd_lin; j++){
         
        if(matr_ord[j][0] < codigo && matr_ord[j][0] > 0){
           codigo = matr_ord[j][0];
           linha = j;
          }
       }
                
      if (codigo < max_cod){
          aux_matr_ord[i][0] = codigo;
          aux_matr_ord[i][1] = linha;
          matr_ord[linha][0] = 0;

        }   
   }
  
   for(i = 0; i < qtd_lin; i++){
      matr_ord[i][0] = aux_matr_ord[i][0];
      matr_ord[i][1] = aux_matr_ord[i][1];
   }    
} 


void relatorio_lucro(){
    
  char plataforma[20];
  int lin;

  printf("\nInforme a Plataforma: ");
  scanf(" %s", plataforma);

  printf("\n\nRelatório de Lucratividade da Plataforma: %s\n", plataforma);
  printf("\nCódigo     Vl.Compra      Vl.Venda       Lucro\n");
  for(i = 0; i < qtd_lin; i++){

      lin = matr_ord[i][1];       
      if(strcmp(plataforma, plataf[lin]) == 0){
          printf("%5i", c_qtd[lin][0]);
          printf("%14.2f", pc_pv[lin][0]);
          printf("%14.2f", pc_pv[lin][1]);
          printf("%13.2f\n", pc_pv[lin][1] - pc_pv[lin][0]);
       } ;     
   }
   printf("\n");
}

//Exclusão tentar fazer 
void excluir(){
  int exclui, codigo, lin_excl, lin_atual;

  

   printf("\nPara voltar ao menu principal digite 0 no código");
   do{ 
      
      printf("\n\nDigite o código: ");
      scanf("%i", &codigo);
 
      if(codigo > 0){
          lin_excl = consulta_lote(codigo);
          if(lin_excl >= 0){
            printf("\nPara confirmar a exclusão, digite 1 caso contrário digite 2: ");
            scanf("%i", &exclui);
              if(exclui == 1){
                for(i = lin_excl; i < qtd_lin; i++){
                   lin_atual = i+1;
                   c_qtd[i][0] = c_qtd[lin_atual][0];
                   c_qtd[i][1] = c_qtd[lin_atual][1];
                   pc_pv[i][0] = pc_pv[lin_atual][0];
                   pc_pv[i][1] = pc_pv[lin_atual][1];
                   //tipo[i][0] = tipo[lin_atual][0];
                   //plataf[i][0] = plataf[lin_atual][0];
                  }
                

                qtd_lin = qtd_lin - 1;
                printf("\nExclusão realizada com sucesso\n");
               }
           }
       }
     }
   while(codigo > 0);
   ordenar();
}

int consulta_lote(int codigo){  
  
  int lin = -1;
  
  for(i = 0; i < qtd_lin; i++){
    if(matr_ord[i][0] == codigo){
      lin = matr_ord[i][1]; 
      
      printf("\nCódigo do lote: %i\n", c_qtd[lin][0]); 
      printf("Tipo: %s\n", tipo[lin]);
      printf("Quantidade de Barris: %i\n", c_qtd[lin][1]);
      printf("Plataforma: %s\n", plataf[lin]);
      printf("Valor de Compra: %.2f\n", pc_pv[lin][0]);
      printf("Valor de Venda: %.2f\n\n", pc_pv[lin][1]);   
      
     } 
       
    }
  if(lin < 0){
    printf("Código inexistente\n");
  }

  return lin;
}

void cadastrar(){
   
   int codigo;
   bool cadastrou = false;
   
   printf("\nPara voltar ao menu principal digite 0 no código");
   do{ 
      
     printf("\n\nDigite o código: ");
     scanf("%i", &codigo);
 
    if(codigo > 0){
     
        printf("\nTipo: ");
        scanf(" %s", tipo[qtd_lin]);

        printf("\nQtde de Barris: ");
        scanf("%i", &c_qtd[qtd_lin][1]);

        printf("\nPlataforma: ");
        scanf(" %s", plataf[qtd_lin]);

        printf("\nValor de Compra: ");
        scanf("%f", &pc_pv[qtd_lin][0]);

        printf("\nValor de Venda: "); 
        scanf("%f", &pc_pv[qtd_lin][1]);

        c_qtd[qtd_lin][0] = codigo;
        matr_ord[qtd_lin][0] = c_qtd[qtd_lin][0];
        matr_ord[qtd_lin][1] =  qtd_lin;
        qtd_lin++;
        cadastrou = true;
      }
   }
   while(codigo > 0);
   if(cadastrou == true){
      ordenar();
   } 
}


void consultar(){
  
  int codigo;

   printf("\nPara voltar ao menu principal digite 0 no código");
   do{ 
      
      printf("\n\nDigite o código: ");
      scanf("%i", &codigo);
 
      if(codigo > 0){
         consulta_lote(codigo);
       }
     }
   while(codigo > 0);
}