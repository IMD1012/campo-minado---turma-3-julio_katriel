#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "funcs.h"

int aleatorio(int tam){
  return (rand() % tam);
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
