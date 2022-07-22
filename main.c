#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "matriz.h"
#include "funcs.h"
#include "computador.h"

time_t tempo_de_jogo();

int main(){
    time_t inicio;
    srand(time(NULL));
    matriz m;
    gerar_matriz(&m);
    if(tela_inicial() == 1)
        jogo(&m);
    else
        computador_joga(&m);

    return 0;
}
