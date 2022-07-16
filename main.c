#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "funcs.h"

int main(){
    srand(time(NULL));
    matriz m;
    matriz m2;
    gerar_Matriz(&m);
    gerar_Matriz(&m2);
    colocar_bombas(&m);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20;j++)
            printf("%c ",m.mat[i][j].caractere);
        printf("\n");
    }
    tela_inicial(m,m2);

    return 0;
}
