#include<stdio.h>

#define TAMANHO 100

void mostrarMaquinaTuring() {
    return;
}

int main() {
    int i;
    int maquina[TAMANHO] = {0};


    printf("Maquina de Turing\n");

    for(i = 0; i < TAMANHO; i++) {
        printf("maquina[%i] = %i\n", i, maquina[i]);
    }

    return 0;
}
