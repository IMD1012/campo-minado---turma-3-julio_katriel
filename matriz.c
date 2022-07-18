#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matriz.h"
#include "funcs.h"

void gerar_Matriz(matriz *m){
    m->mat = malloc(sizeof(celula*)*10);
    for(int i = 0; i < 20; i++)
        m->mat[i] = malloc(sizeof(celula)*20);

    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 20;j++){
            m->mat[i][j].visibilidade = 0;
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
  return (coordenada_valida(l,c) && (m->mat[l][c].visibilidade));
}

//Tá pronto
void abre_vizinho(int l, int c, matriz *m){
  if(!coordenada_valida(l,c) || m->mat[l][c].caractere == '#'){
    return;
  }
  else if(verifica_vizinho(l,c,m) != 0){
    m->mat[l][c].caractere = convert_char(m->mat[l][c].bombas_perto);
    m->mat[l][c].visibilidade = 1;
  }
  else{
    if(!m->mat[l][c].visibilidade){
      m->mat[l][c].caractere = ' ';
      m->mat[l][c].visibilidade = 1;
      //lados
      abre_vizinho(l,c+1,m);
      abre_vizinho(l,c-1,m);
      abre_vizinho(l+1,c,m);
      abre_vizinho(l-1,c,m);
      //diagonais
      abre_vizinho(l-1,c+1,m);
      abre_vizinho(l-1,c-1,m);
      abre_vizinho(l+1,c+1,m);
      abre_vizinho(l+1,c-1,m);
    }
  }
}

void imprimir_matriz(matriz m){
  printf("  ------------------------------------------\n");
  printf("    A B C D E F G H I J K L M N O P Q R S T\n");
  printf("  ------------------------------------------\n");
  for(int i = 0; i < 10;i++){
    printf("|");
    for(int j = 0; j < 20; j++){
      if(m.mat[i][j].caractere == '#'){
        if(j == 0)
          printf("%.2d * ",i+1);
        else
          printf("* ");
      }else{
        if(j == 0)
          printf("%.2d %c ",i+1,m.mat[i][j].caractere);
        else
          printf("%c ",m.mat[i][j].caractere);
      }
    }
    printf("|\n");
  }
  printf("  ------------------------------------------\n");
}

int abre_celula(matriz *m){
  int count = 0;
  do{
    int l,c;
    char c2;
    imprimir_matriz(*m);
    scanf("%d %c",&l,&c2);
    tolower(c2);
    c = troca(c2);
    l = trata_linha(l);
    m->mat[l][c].visibilidade = 1;
    if(m->mat[l][c].caractere == '#'){
      fim_de_jogo();
      break;
    }
    else{
      int x;
      x = verifica_vizinho(l,c,m);
      abre_vizinho(l,c,m);
      m->mat[l][c].caractere = convert_char(x);
    }
    count++;
    }while(count != 160);
}
