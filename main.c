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
    colocar_bombas(&m);
    gerar_Matriz(&m2);
    
    //tela_inicial(m,m2);

    return 0;
}
