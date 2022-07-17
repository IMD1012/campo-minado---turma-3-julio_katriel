#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

int aleatorio(int tam){
  return (rand() % tam);
}

int coordenada_valida(int l, int c){
  return ((l >= 0 && l < 10) && (c >= 0 && c < 20));
}

int ordena_menos_um(int l1){
  int l2;
  l2 = l1 - 1;
  return l2;
}

int troca(char letra){
  if(letra < 117)
    return letra - 97;
  else
    return -1;
}

char convert_char(int n){
  switch(n){
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    default: return '\0';
  }
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
  printf("\n\n");

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
