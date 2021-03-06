#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "matriz.h"
#include "funcs.h"

void gerar_matriz(matriz *m){
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

void colocar_bombas(int l, int c, matriz *m){
    int count = 0,linha,coluna;

    while(count < 40){
        linha =  aleatorio(10);
        coluna = aleatorio(20);
        if(m->mat[linha][coluna].caractere == '*' && l != linha && c != coluna){
            count++;
            m->mat[linha][coluna].caractere = '#';
        }
    }
}

int contador_visivel(matriz m){
  int count = 0;
  for(int i = 0; i < 10;i++){
    for(int j = 0; j < 20; j++)
      count += m.mat[i][j].visibilidade;
  }
  return count;
}

int verificar_arredor(int l, int c, matriz *m){

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

void abrir_arredor(int l, int c, matriz *m){
  if(!coordenada_valida(l,c)){
    return;
  }
  else if(verificar_arredor(l,c,m) != 0){
    if(m->mat[l][c].visibilidade == 0){
      m->mat[l][c].caractere = convert_int(m->mat[l][c].bombas_perto);
      m->mat[l][c].visibilidade = 1;
    }
  }
  else{
    if(!m->mat[l][c].visibilidade){
      m->mat[l][c].caractere = ' ';
      m->mat[l][c].visibilidade = 1;
      //lados
      abrir_arredor(l,c+1,m);
      abrir_arredor(l,c-1,m);
      abrir_arredor(l+1,c,m);
      abrir_arredor(l-1,c,m);
      //diagonais
      abrir_arredor(l-1,c+1,m);
      abrir_arredor(l-1,c-1,m);
      abrir_arredor(l+1,c+1,m);
      abrir_arredor(l+1,c-1,m);
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

int jogo(matriz *m){
  time_t inicio,tempo;
  int l,c,count =0;
  char c2,escolha;

  while(count < 160){
    printf("Deseja jogar(j), ver o tempo(t) ou pedir ajuda(h)? \n");
    scanf(" %c",&escolha);
    escolha = tolower(escolha);
    if(escolha == 'j'){
      imprimir_matriz(*m);
      scanf("%d %c",&l,&c2);
      c2 = tolower(c2);
      l = l -1;
      c = convert_char(c2);
      if(count == 0){
        inicio = time(NULL);
        colocar_bombas(l,c,m);
      }
      if(m->mat[l][c].caractere == '#'){
        fim_de_jogo();
        count = 161;
      }
      else if(m->mat[l][c].visibilidade == 0){
        abrir_arredor(l,c,m);
        imprimir_matriz(*m);
        count = contador_visivel(*m);
        if(contador_visivel(*m) == 160){
          ganha_jogo();
        }
      }
    }
    else if(escolha == 't'){
      tempo = tempo_de_jogo();
      printf("Tempo em segundos: %lds\n",tempo-inicio);
    }
    else if(escolha == 'h'){
      printf("digite uma coordenada \n");
      scanf("%d %d",&l,&c);
      ajudar(l,c,*m);
    }
  }
}

void ajudar(int l, int c, matriz m){
  double x = 0;
  int quantidade_celulas = 0;
  int result;

  for(int i = l-1; i <= l+1; i++){
    for(int j = c-1; j <= c+1; j++){
      if(coordenada_valida(i,j))
        quantidade_celulas++;
    }
  }

  for(int i = l-1; i <= l+1; i++){
    for(int j = c-1; j <= c+1; j++){
      if(coordenada_valida(i,j) && m.mat[i][j].caractere == '#' && (i != l &&  j !=c))
        x++;
    }
  }
  
  result = 80/(quantidade_celulas-x);
  result = result *2;

  printf("%d %% de chance de haver uma bomba nos espa??os\n",result);
}
