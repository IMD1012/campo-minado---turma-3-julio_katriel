#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "matriz.h"
#include "funcs.h"

time_t tempo_de_jogo();

int main(){
    time_t inicio;
    inicio = time(NULL);
    srand(time(NULL));
    matriz m;
    gerar_matriz(&m);
    colocar_bombas(&m);
    tela_inicial(&m);

    return 0;
}
time_t tempo_de_jogo(){
    return time(NULL);
}