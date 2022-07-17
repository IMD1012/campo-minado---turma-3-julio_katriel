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
            m->mat[i][j].visibilidade = 1;
            m->mat[i][j].bombas_perto = 0;
            m->mat[i][j].caractere =  '*';
        }
    }
}

void colocar_bombas(matriz *m){
    int count = 0,linha,coluna;

    while(count < 40){
        linha =  aleatorio(10);
        coluna = aleatorio(20);
        if(m->mat[linha][coluna].caractere == '*'){
            count++;
            m->mat[linha][coluna].caractere = '#';
        }
    }
}

int verifica_vizinho(int l, int c, matriz *m){

  if(coordenada_valida(l-1,c-1) && m->mat[l-1][c-1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l-1,c) && m->mat[l-1][c].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l-1,c+1) && m->mat[l-1][c+1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l,c-1) && m->mat[l][c-1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l,c+1) && m->mat[l][c+1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l+1,c-1) && m->mat[l+1][c-1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l+1,c) && m->mat[l+1][c].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }
  if(coordenada_valida(l+1,c+1) && m->mat[l+1][c+1].caractere == '#'){
    m->mat[l][c].bombas_perto++;
  }

  return m->mat[l][c].bombas_perto;
}

int verifica_aberto(int l, int c, matriz *m){
  return (coordenada_valida(l,c) && (m->mat[l][c].visibilidade == 0));
}

int abre_vizinho(int l, int c, matriz *m){
  int x;
  x = verifica_vizinho(l,c,m);
  for(int i = l-1; i < l+1; i++){
    for(int j = c-1; j < c+1; j++){
      if(coordenada_valida(i,j)){
        m->mat[i][j].caractere = convert_char(x);
        if(verifica_vizinho(i,j,m) != 0){
          return abre_vizinho(i,j,m);
        }
      }  
    }
  }
}

int abre_celula(matriz m, matriz m2){
  int count = 0;
  do{
    printf("  ------------------------------------------\n");
    printf("    a b c d e f g h i j k l m n o p q r s t");
    printf("\n");
    printf("  ------------------------------------------\n");
      for(int i = 0; i < 10; i++){
        if(i + 1 != 10){
          printf("0%d",i+1);
        }
        else{
          printf("%d",i+1);
        }
        printf("| ");
        for(int j = 0; j < 20;j++)
            printf("%c ",m2.mat[i][j].caractere);
        printf("|");
        printf("\n");
      }
    printf("  ------------------------------------------");
    printf("\n");
      int l,c;
      char c2;
      scanf("%d %c",&l,&c2);
      l = ordena_menos_um(l);
      c = troca(c2);
      if(m.mat[l][c].caractere == '#'){
        printf("Game Over");
        break;
      }
      else{
        int x;
        char y;
        x = verifica_vizinho(l,c,&m);
        y = troca_numero_caracter(x);
        m2.mat[l][c].caractere = y;
      }
      
      if(m2.mat[l][c].caractere == '0'){
        abre_vizinho(l,c,&m2);
      }
      count++;
    }while(count != 160);
}

void mostrar_tela(matriz m){
    printf("---------------------------------------------------------\n");
    printf("                      CAMPO MINADO                       \n");
    printf("---------------------------------------------------------\n");
}
