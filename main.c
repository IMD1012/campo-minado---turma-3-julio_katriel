#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "funcs.h"

int main(){
    srand(time(NULL));
    matriz m;
    gerar_Matriz(&m);
    colocar_bombas(&m);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20;j++)
            printf("%d ",m.mat[i][j].bomba);
        printf("\n");
    }

    int l,c;
    scanf("%d %d",&l,&c);
    printf("%d\n",verifica_vizinho(l,c,&m));

    return 0;
}