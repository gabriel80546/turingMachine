#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 100

void mostrarMaquinaTuring() {
    return;
}

int main() {
    int i;
    char padrao = 'L';
    char* maquina;
    
    maquina = (char *) malloc(sizeof(char) * TAMANHO);

    for(i = 0; i < TAMANHO; i++){
        maquina[i] = padrao;
    }

    printf("Maquina de Turing\n");

    for(i = 0; i < TAMANHO; i++) {
        printf("maquina[%i] = '%c'\n", i, maquina[i]);
    }

    return 0;
}
