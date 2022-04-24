#include <stdio.h>

int ordem(int n1, int n2, int n3);

int n1, n2, n3;


int main(void) {
  printf("Digite 3 numeros inteiros\n");
  scanf("%i%i%i", &n1, &n2, &n3);



  return 0;
}

int ordem(int n1, int n2, int n3){
  int aux;
  
  if (n1 <= n2 && n2 <= n3){
    return n1, n2, n3;
  }else if (n1 <= n3 && n3 <= n2)
    aux = n2
    n3 = n2;
    aux = n3;

    return n1, n2, n3;
    aux = 0;
}else if (n2 <= n1 && n1 <= n3){
  aux = n1
  n1 = n2;
  n2 = aux;

  return n1, n2, n3;
  aux = 0;
}else if (n2 <= n3 && n3 <= n1){
  aux = n3;
  n3 = n1;
  n1 = aux;

  return n1, n2, n3;
  aux = 0;
}else if (n3 <= n1 && n1 <= n2){
  aux = n3;
  
}