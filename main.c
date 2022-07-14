#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int aleatorio(int tam);
void gerarMatriz(matriz *m);
int coordenada_valida(int l, int c);
int verifica_vizinho(int l, int c, matriz m);

int main(){
    srand(time(NULL));
    matriz m;
    gerarMatriz(&m);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20;j++)
            printf("%d ",m.mat[i][j]);
        printf("\n");
    }

    int l,c;
    scanf("%d %d",&l,&c);
    printf("%d",verifica_vizinho(l,c,m));

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

int coordenada_valida(int l, int c){
  if((l >= 0 && l < 10) && (c >= 0 && c < 20)){
    return 1;
  }
  else{
    return 0;
  }
}

int verifica_vizinho(int l, int c, matriz m){
  int quant = 0;

  if(coordenada_valida(l-1,c-1) && m.mat[l-1][c-1] == 9){
    quant++;
  }
  if(coordenada_valida(l-1,c) && m.mat[l-1][c] == 9){
    quant++;
  }
  if(coordenada_valida(l-1,c+1) && m.mat[l-1][c+1] == 9){
    quant++;
  }
  if(coordenada_valida(l,c-1) && m.mat[l][c-1] == 9){
    quant++;
  }
  if(coordenada_valida(l,c+1) && m.mat[l][c+1] == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c-1) && m.mat[l+1][c-1] == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c) && m.mat[l+1][c] == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c+1) && m.mat[l+1][c+1] == 9){
    quant++;
  }

  return quant;
}
