#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matriz.h"
#include "funcs.h"

int main(){
    srand(time(NULL));
    matriz m;
    gerar_matriz(&m);
    colocar_bombas(&m);
    tela_inicial(&m);
    return 0;
}
