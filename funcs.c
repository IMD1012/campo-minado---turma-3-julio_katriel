#include <stdio.h>
#include <string.h>
#include "matriz.h"

void mostrar_tela(matriz m){
    printf("---------------------------------------------------------\n");
    printf("                      CAMPO MINADO                       \n");
    printf("---------------------------------------------------------\n");
}

void como_jogar(){
    printf("Digite uma letra no intervalor de A a J\n");
    printf("Digite um número no intervalor de 1 à 20\n");
    printf("Exemplos: a7,j9 e e13\n");
    printf("Para ver o tempo de jogo digite: t\n");
    printf("Para pedir ajudar do computador digite: h\n");
}