#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 300

typedef struct Instrucao {
    int estado;
    int lado; // 0 esquerda, 1 direita
    char leia;
    char escreva;
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
    if(inst == NULL) {
        printf("ponteiro inst, na funcao mostrarInstrucao esta NULL\n");
        exit(1);
    }
    printf("inst = %p\n", inst);
    printf("inst->lado = %i\n", inst->lado);
    printf("inst->leia = \'%c\'\n", inst->leia);
    printf("inst->escreva = \'%c\'\n", inst->escreva);
    printf("inst->estado = %i\n", inst->estado);
    printf("inst->proximoEstado = %i\n", inst->proximoEstado);
    return;
}

Instrucao *initInstrucao(int lado, char leia, char escreva, int estado, int proximoEstado) {
    Instrucao *saida;

    saida = (Instrucao *)malloc(sizeof(Instrucao) * 1);
    saida->lado = lado;
    saida->leia = leia;
    saida->escreva = escreva;
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

// typedef struct Instrucao {
//     int estado;
//     int lado; // 0 esquerda, 1 direita
//     char escreva;
//     int proximoEstado;
// } Instrucao;
// Instrucao *initInstrucao(int lado, char escreva, int estado, int proximoEstado) {

//      A       B       C
// 0    1R B    0R C    1L C
// 1	1R H_   1R B    1L A
int main() {
    int i;
    char padrao = '0';
    int posicao = (int)(TAMANHO/2);
    char* fita;
    Instrucao *a;
    Instrucao *b;
    Instrucao *c;

    a = initInstrucao(1, '0', '1', -1, 3);
    b = initInstrucao(1, '0', '1', -1, 3);
    c = initInstrucao(1, '0', '1', -1, 3);
    fita = initFita(TAMANHO, padrao);

    mostrarInstrucao(a);
    mostrarFitaTuring(fita);

    while(1) {
        break;
    }

    free(fita);
    free(a);
    free(b);
    free(c);
    return 0;
}
