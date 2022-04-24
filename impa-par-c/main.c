#include <stdio.h>

int cont_impar(int lim_sup, int lim_inf);

int lim_sup, lim_inf, impar, par;

int main(void) {
  printf("Digite o limite inferior do intervalo");
  scanf("%i", &lim_inf);
  printf("Digite o limite superior do intervalo");
  scanf("%i", &lim_sup);

  return 0;
}

