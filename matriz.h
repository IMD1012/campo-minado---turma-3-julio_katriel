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

void gerar_Matriz(matriz *m);
void colocar_bombas(matriz *m);
int verifica_vizinho(int l, int c, matriz *m);
int abre_celula(matriz m);
int aleatorio(int tam);
#endif
