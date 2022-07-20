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
void colocar_bombas(int l, int c, matriz *m);
int contador_visivel(matriz m);
int verificar_arredor(int l, int c, matriz *m);
int jogo(matriz *m);
#endif
