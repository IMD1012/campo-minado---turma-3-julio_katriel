#ifndef FUNCS_H_
#define FUNCS_H_
#include <time.h>

int aleatorio(int tam);
char convert_int(int n);
void getz(int n,char st[n]);
int coordenada_valida(int l, int c);
int convert_char(char letra);
int entrada_usuario();
void como_jogar();
int tela_inicial();
void menu();
time_t tempo_de_jogo();
void ganha_jogo();
void fim_de_jogo();

#endif
