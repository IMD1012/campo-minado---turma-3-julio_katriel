#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matriz.h"
#include "funcs.h"

int main(){
    srand(time(NULL));
    matriz m;
    gerar_Matriz(&m);
    colocar_bombas(&m);
    for(int i = 0; i < 10;i++){
        for(int j = 0; j < 20;j++)
            printf("%c ",m.mat[i][j].caractere);
        printf("\n");
    }
    tela_inicial(&m);
    return 0;
}
