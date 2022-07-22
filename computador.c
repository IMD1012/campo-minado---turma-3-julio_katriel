#include <stdio.h>
#include "funcs.h"
#include "matriz.h"
#include "computador.h"

void primeira_jogada(matriz *m){
    int l,c;
    l = aleatorio(10);
    c = aleatorio(20);

    colocar_bombas(l,c,m);

    abrir_arredor(l,c,m);

    imprimir_matriz(*m);
}

void computador_joga(matriz *m){
    int l,c,count = 0;

    primeira_jogada(m);

    while(count < 160){
        count = contador_visivel(*m);

        l = aleatorio(10);
        c = aleatorio(20);

        if(count < 160){
            if(m->mat[l][c].caractere == '#'){
                fim_de_jogo();
                count = 161;
            }
            else if(m->mat[l][c].visibilidade == 0){
                abrir_arredor(l,c,m);
                imprimir_matriz(*m);
                count = contador_visivel(*m);
                if(contador_visivel(*m) == 160){
                    ganha_jogo();
                }
            }
        }
        else{
            ganha_jogo();
        }
    }
}
