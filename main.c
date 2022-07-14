#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int aleatorio(int tam);
void gerarMatriz(matriz *m);

int main(){
    srand(time(NULL));
    matriz m;
    gerarMatriz(&m);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20;j++)
            printf("%d ",m.mat[i][j]);
        printf("\n");
    }

    return 0;
}

int aleatorio(int tam){
  return (rand() % tam);
}

void gerarMatriz(matriz *m){
    int count = 0,linha,coluna;
    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 20;j++)
            m->mat[i][j] = 0;
    }
    while(count < 40){
        linha =  aleatorio(10);
        coluna = aleatorio(20);
        if(m->mat[linha][coluna] == 0){
            count++;
            m->mat[linha][coluna] = 9;
        }
    }
}