#ifndef MATRIZ_H_
#define MATRIZ_H_

typedef struct {
    int visibilidade;
    int bombas_perto;
    char caractere;
}celula;

typedef struct{
    celula **mat;
}matriz;

void gerar_matriz(matriz *m);
void colocar_bombas(matriz *m);
int contador_visivel(matriz m);
void como_jogar(matriz m);
void tela_inicial(matriz *m);
void imprimir_matriz(matriz m);
int verificar_arredor(int l, int c, matriz *m);
int jogo(matriz *m);
void trata_coluna(char c, matriz m);
#endif
