#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "matriz.h"


int trata_linha(char l1, matriz m){
  int l2;
  l2 = l1 - 1;
  return l2;
}

int aleatorio(int tam){
  return (rand() % tam);
}

int coordenada_valida(int l, int c){
  return ((l >= 0 && l < 10) && (c >= 0 && c < 20));
}

int troca(char letra){
  
  if(letra < 117)
    return letra - 97;
  else
    return -1;
}

char convert_char(int n){
  switch(n){
    case 0: return '0';
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

void como_jogar(matriz m){
  int escolha;
  printf("Digite um número no intervalor de 1 à 10\n");
  printf("Digite uma letra no intervalor de A a T\n");
  printf("Exemplos: a7,j9 e e13\n");
  printf("Para ver o tempo de jogo digite: t\n");
  printf("Para pedir ajudar do computador digite: h\n");
  printf("Digite 1 para jogar \n");
  scanf("%d\n",&escolha);
  if(escolha == 1){
    abre_celula(m);
  }
}

void tela_inicial(matriz m){
 int escolha;   
  printf("---------------------------------------------------------\n");
  printf("                      CAMPO MINADO                       \n");
  printf("---------------------------------------------------------\n\n\n");

  printf("1 - jogar \n");
  printf("2 - como jogar \n");
  printf("3 - modo autônomo \n");

  printf("Digite um número de 1 a 3 \n");
  scanf(" %d",&escolha);

  do{
    if(escolha == 1){
      abre_celula(m);
    }
    else if(escolha == 2){
      como_jogar(m);
    }
    else if(escolha == 3){
      printf("Função Indisponível \n");
      printf("Digite novamente \n");
      scanf(" %d",&escolha);
    }
    else{
      printf("Número inválido \n");
      printf("Digite novamente \n");
      scanf(" %d",&escolha);
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
