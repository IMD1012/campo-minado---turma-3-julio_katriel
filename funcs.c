#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

int aleatorio(int tam){
  return (rand() % tam);
}

int coordenada_valida(int l, int c){
  return ((l >= 0 && l < 10) && (c >= 0 && c < 20));
}

void como_jogar(matriz m, matriz m2){
  int escolha;
  printf("Digite uma letra no intervalor de A a J\n");
  printf("Digite um número no intervalor de 1 à 20\n");
  printf("Exemplos: a7,j9 e e13\n");
  printf("Para ver o tempo de jogo digite: t\n");
  printf("Para pedir ajudar do computador digite: h\n");
  printf("Digite 1 para jogar \n");
  scanf("%d",&escolha);
  printf("\n");
  if(escolha == 1){
    abre_celula(m,m2);
  }
}

void tela_inicial(matriz m, matriz m2){
 int escolha;   
  printf("---------------------------------------------------------\n");
    printf("                      CAMPO MINADO                       \n");
    printf("---------------------------------------------------------\n");
  printf("\n \n");

  printf("1 - jogar \n");
  printf("2 - como jogar \n");
  printf("3 - modo autônomo \n");

  printf("Digite um número de 1 a 3 \n");
  scanf("%d",&escolha);

  do{
    if(escolha == 1){
      abre_celula(m,m2);
    }
    else if(escolha == 2){
      como_jogar(m,m2);
    }
    else if(escolha == 3){
      printf("Função Indisponível \n");
      printf("Digite novamente \n");
      scanf("%d",&escolha);
    }
    else{
      printf("Número inválido \n");
      printf("Digite novamente \n");
      scanf("%d",&escolha);
    }
  }while(escolha > 2);
}

void Time(){
  
}

void help(){
  
}

void fim_de_jogo(){
    printf("---------------------------------------------------------\n");
    printf("                        GAME OVER                        \n");
    printf("---------------------------------------------------------\n");
}
