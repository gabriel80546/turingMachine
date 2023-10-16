#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 100

void mostrarFitaTuring(char *fita) {
    int i;

    printf("Fita:\n\"");
    for(i = 0; i < TAMANHO; i++) {
        printf("%c", fita[i]);
    }
    printf("\"\n");
    return;
}

char *definirPeloPadrao(char *entrada, char padr) {
    int i;
    char *saida;

    saida = (char *) malloc(sizeof(char) * TAMANHO);
    if(entrada == NULL) {
        printf("Erro variavel com erro, provavelmente NULL\n");
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
    char padrao = 'R';
    char* fita;
    
    fita = (char *) malloc(sizeof(char) * TAMANHO);
    fita = definirPeloPadrao(fita, padrao);
    mostrarFitaTuring(fita);
    free(fita);
    return 0;
}
