#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"

int aleatorio(int tam){
  return (rand() % tam);
}

void getz(int n,char st[n]){
  fgets(st,n,stdin);
  while(st[0] == '\n')
    fgets(st,n,stdin);
  if(st[strlen(st)-1] == '\n')
    st[strlen(st)-1] = '\0';
}

int coordenada_valida(int l, int c){
  return ((l >= 0 && l < 10) && (c >= 0 && c < 20));
}

int convert_char(char letra){
  
  if(letra < 117)
    return letra - 97;
  else
    return -1;
}

char convert_int(int n){
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

int entrada_usuario(){//modificado 2
  char str[10];
  getz(10,str);
  int num;
  if(strlen(str) == 1 && isalpha(str[0])){
    str[0] = tolower(str[0]);
    switch(str[0]){
      case 'v': return 4;
      case 't': return 5;
      case 'h': return 6;
      default: return -1;
    }
  }else if(strlen(str) == 1 && isalnum(str[0])){
    sscanf(str,"%d",&num);
    return num;
  }else
    return -1;
}

void como_jogar(){// modificado 2
  printf("Digite um número de 1 à 10 e uma letra de A à T\n");
  printf("Exemplos: 7b, 9j e 10t\n\n");
  printf("Para ver o tempo de jogo digite: T\n");
  printf("Para pedir ajudar do computador digite: H\n\n");
  printf("Digite V para voltar\n");
}

void menu(){//criado 1
  printf("---------------------------------------------------------\n");
  printf("                      CAMPO MINADO                       \n");
  printf("---------------------------------------------------------\n\n\n");
  printf("1 - jogar \n");
  printf("2 - como jogar \n");
  printf("3 - modo autônomo \n");
  printf("Digite um número de 1 a 3 \n");
}

int tela_inicial(){// modificado 2
  int escolha;
  menu();
  escolha = entrada_usuario();

  while(escolha != 1){
    if(escolha == 2){
      como_jogar();
      escolha = entrada_usuario();
    }
    else if(escolha == 3){
      printf("Função Indisponível \n");
      printf("Digite novamente \n");
      escolha = entrada_usuario();
    }
    else{
      printf("Entrada ínvalida\n");
      printf("Digite novamente \n");
      escolha = entrada_usuario();
    }
  }

  return 1;
}

void ganha_jogo(){
    printf("---------------------------------------------------------\n");
    printf("                         YOU WIN                         \n");
    printf("---------------------------------------------------------\n");
}

void fim_de_jogo(){
    printf("---------------------------------------------------------\n");
    printf("                        GAME OVER                        \n");
    printf("---------------------------------------------------------\n");
}
