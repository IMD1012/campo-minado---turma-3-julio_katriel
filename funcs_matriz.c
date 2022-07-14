#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "funcs.h"

void gerar_Matriz(matriz *m){
    m->mat = malloc(sizeof(celula*)*10);
    for(int i = 0; i < 20; i++)
        m->mat[i] = malloc(sizeof(celula)*20);

    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 20;j++){
            m->mat[i][j].visibilidade = 0;
            m->mat[i][j].bombas = 0;
            m->mat[i][j].bomba = 0;
        }
    }
}

void colocar_bombas(matriz *m){
    int count = 0,linha,coluna;

    while(count < 40){
        linha =  aleatorio(10);
        coluna = aleatorio(20);
        if(m->mat[linha][coluna].bomba == 0){
            count++;
            m->mat[linha][coluna].bomba = 9;
        }
    }
}

int verifica_vizinho(int l, int c, matriz *m){
  int quant = 0;

  if(coordenada_valida(l-1,c-1) && m->mat[l-1][c-1].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l-1,c) && m->mat[l-1][c].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l-1,c+1) && m->mat[l-1][c+1].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l,c-1) && m->mat[l][c-1].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l,c+1) && m->mat[l][c+1].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c-1) && m->mat[l+1][c-1].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c) && m->mat[l+1][c].bomba == 9){
    quant++;
  }
  if(coordenada_valida(l+1,c+1) && m->mat[l+1][c+1].bomba == 9){
    quant++;
  }

  return quant;
}

void mostrar_tela(matriz m){
    printf("---------------------------------------------------------\n");
    printf("                      CAMPO MINADO                       \n");
    printf("---------------------------------------------------------\n");
}