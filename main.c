#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 300

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

Instrucao *initInstrucao(int lado, char conteudo, int estado, int proximoEstado) {
    Instrucao *saida;
    saida = (Instrucao *)malloc(sizeof(Instrucao) * 1);
    saida->lado = lado;
    saida->conteudo = conteudo;
    saida->estado = estado;
    saida->proximoEstado = proximoEstado;
    return saida;
}

int main() {
    int i;
    char padrao = '_';
    int posicao = (int)(TAMANHO/2);
    char* fita;
    Instrucao *a;

    a = initInstrucao(1, 'e', -1, 3);
    // a = (Instrucao *)malloc(sizeof(Instrucao) * 1);
    // a->lado = 1;
    // a->conteudo = 'e';
    // a->estado = -1;
    // a->proximoEstado = 3;
    fita = (char *) malloc(sizeof(char) * TAMANHO);

    fita = definirPeloPadrao(fita, padrao);
    mostrarInstrucao(a);
    mostrarFitaTuring(fita);
    free(fita);
    free(a);
    return 0;
}
