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

void mostrarInstrucao(Instrucao *inst) {

    printf("inst = %p\n", inst);
    
    // Instrucao *initInstrucao(int lado, char conteudo, int estado, int proximoEstado) {
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

char *initFita(int tamanho, char padrao) {
    int i;
    char *saida;

    saida = (char *)malloc(sizeof(char) * tamanho);
    for(i = 0; i < tamanho; i++) {
        saida[i] = padrao;
    }
    return saida;
}

int main() {
    int i;
    char padrao = '0';
    int posicao = (int)(TAMANHO/2);
    char* fita;
    Instrucao *a;

    a = initInstrucao(1, 'a', -1, 3);
    fita = initFita(TAMANHO, padrao);

    mostrarInstrucao(a);
    // mostrarFitaTuring(fita);

    free(fita);
    free(a);
    return 0;
}
