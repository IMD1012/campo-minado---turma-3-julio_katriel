#ifndef MATRIZ_H_
#define MATRIZ_H_

typedef struct {
    int visibilidade;
    char bomba;
    int bombas;
}celula;

typedef struct{
    celula **mat;
}matriz;

void gerar_Matriz(matriz *m);
void colocar_bombas(matriz *m);
int verifica_vizinho(int l, int c, matriz *m);
void mostrar_tela(matriz m);
int aleatorio(int tam);
#endif
