#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 100

void mostrarMaquinaTuring() {
    return;
}


char *definirPeloPadrao(char *entrada, char padr) {
    int i;
    char *saida;

    saida = (char *) malloc(sizeof(char) * TAMANHO);
    if(entrada == NULL) {
        printf("Erro variavel com erro, provavelmente NULL");
        exit(1);
    }
    free(entrada);
    for(i = 0; i < TAMANHO; i++) {
        saida[i] = padr;
    }
    return saida;
}

int main() {
    int i;
    char padrao = 'L';
    char* maquina;
    
    maquina = (char *) malloc(sizeof(char) * TAMANHO);

    maquina = definirPeloPadrao(maquina, padrao);
    // for(i = 0; i < TAMANHO; i++){
    //     maquina[i] = padrao;
    // }

    printf("Maquina de Turing\n");

    for(i = 0; i < TAMANHO; i++) {
        printf("maquina[%i] = '%c'\n", i, maquina[i]);
    }

    free(maquina);
    return 0;
}
