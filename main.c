#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 100

typedef struct Instrucao {
    int lado;
    char conteudo;
    int estado;
    int proximoEstado;
} Instrucao;

void mostrarFitaTuring(char *fita) {
    int i;

    printf("Fita:\n\"");
    for(i = 0; i < (TAMANHO - 1); i++) {
        printf("%c ", fita[i]);
    }
    printf("%c\"\n", fita[i]);
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

void mostrarInstrucao(Instrucao *inst) {

    printf("inst = %p\n", inst);
    printf("inst->conteudo = \'%c\' \n", inst->conteudo);
    return;
}

int main() {
    int i;
    char padrao = '0';
    int posicao = (int)(TAMANHO/2);
    char* fita;
    Instrucao *a;

    a = (Instrucao *)malloc(sizeof(Instrucao) * 1);
    a->lado = 1;
    a->conteudo = 'a';
    a->estado = -1;
    a->proximoEstado = 3;
    mostrarInstrucao(a);
    fita = (char *) malloc(sizeof(char) * TAMANHO);
    fita = definirPeloPadrao(fita, padrao);
    mostrarFitaTuring(fita);
    free(fita);
    free(a);
    return 0;
}
