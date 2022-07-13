#include <stdio.h>
#include "matriz.h"

int aleatorio(){
  srand(time(NULL));

  int posi[40], posi2[40];
  
  for(int i = 0; i < 40; i++){
    posi[i] = (rand() % 10) + 1;
    posi2[i] = (rand() % 20) + 1;
    
    printf("[%d][%d] \n",posi[i],posi2[i]);
  }
}

int main(){
    matriz m;
    m.mat[0][0] = 1;
    printf("%d\n",m.mat[0][0]);

    return 0;
}
