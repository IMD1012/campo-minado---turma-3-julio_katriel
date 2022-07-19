#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
//Tá pronto
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

void como_jogar(matriz m){
  int escolha;
  printf("Digite um número no intervalor de 1 à 10\n");
  printf("Digite uma letra no intervalor de A a T\n");
  printf("Exemplos: a7, j9 e e13\n");
  printf("Para ver o tempo de jogo digite: t\n");
  printf("Para pedir ajudar do computador digite: h\n");
  printf("Digite 1 para jogar \n");
  scanf("%d\n",&escolha);
  if(escolha == 1){
    jogo(&m);
  }
}

void tela_inicial(matriz *m){
  int escolha;   
  printf("---------------------------------------------------------\n");
  printf("                      CAMPO MINADO                       \n");
  printf("---------------------------------------------------------\n\n\n");
  printf("1 - jogar \n");
  printf("2 - como jogar \n");
  printf("3 - modo autônomo \n");
  printf("Digite um número de 1 a 3 \n");
  scanf(" %d",&escolha);

  do{
    if(escolha == 1){
      jogo(m);
    }
    else if(escolha == 2){
      como_jogar(*m);
    }
    else if(escolha == 3){
      printf("Função Indisponível \n");
      printf("Digite novamente \n");
      scanf(" %d",&escolha);
    }
    else{
      printf("Número inválido \n");
      printf("Digite novamente \n");
      scanf(" %d",&escolha);
    }
  }while(escolha > 2);
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
  int l,c;
  char c2;
  imprimir_matriz(*m);
  do{
    scanf("%d %c",&l,&c2);
    c2 = tolower(c2);
    l = l -1;
    c = convert_char(c2);
    if(m->mat[l][c].visibilidade == 0){
      if(m->mat[l][c].caractere == '#'){
        fim_de_jogo();
        break;
      }
      else{
        abrir_arredor(l,c,m);
        imprimir_matriz(*m);
      }
    }
  }while(contador_visivel(*m) < 160);
}
