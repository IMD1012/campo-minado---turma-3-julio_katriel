#include <stdlib.h>
#include <stdio.h>

int aleatorio(int tam){
  return (rand() % tam);
}

int coordenada_valida(int l, int c){
  return ((l >= 0 && l < 10) && (c >= 0 && c < 20));
}

void como_jogar(){
    printf("Digite uma letra no intervalor de A a J\n");
    printf("Digite um número no intervalor de 1 à 20\n");
    printf("Exemplos: a7,j9 e e13\n");
    printf("Para ver o tempo de jogo digite: t\n");
    printf("Para pedir ajudar do computador digite: h\n");
}

void fim_de_jogo(){
    printf("---------------------------------------------------------\n");
    printf("                        GAME OVER                        \n");
    printf("---------------------------------------------------------\n");
}