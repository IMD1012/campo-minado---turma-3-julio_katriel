#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int aleatorio(int tam){
  srand(time(NULL));
  return (rand() % tam) + 1;
}

void gerarMatriz(matriz m){
    int count = 0,linha,coluna;
    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 20;j++)
        m.mat[i][j] = 0;
    }
    while(count < 40){
        linha =  aleatorio(10);
        coluna = aleatorio(20);
        if(m.mat[linha][coluna] == 0){
            count++;
            m.mat[linha][coluna] = 9;
        }
    }
}

int main(){
    matriz m;
    gerarMatriz(m);
    printf("%d\n",m.mat[0][0]);

    return 0;
}
