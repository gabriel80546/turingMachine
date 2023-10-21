#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 300
#define QTS_INSTRUCOES 6

typedef struct Instrucao {
    int estado;
    int lado; // 0 esquerda, 1 direita
    char leia;
    char escreva;
    int proximoEstado;
} Instrucao;

struct Programa {
   Instrucao inst;
   struct Programa *proximaInstrucao;
};

struct Programa *inicio = NULL;
struct Programa *atualInst = NULL;

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


//insertion at the beginning
void insertatbegin(Instrucao inst){

   //create a link
   struct Programa *lk = (struct Programa*) malloc(sizeof(struct Programa));
   lk->inst = inst;

   // point it to old first node
   lk->proximaInstrucao = atualInst;

   //point first to new first node
   atualInst = lk;
}

// typedef struct Instrucao {
//     int estado;
//     int lado; // 0 esquerda, 1 direita
//     char leia;
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
    Instrucao *a0;
    Instrucao *a1;
    Instrucao *b0;
    Instrucao *b1;
    Instrucao *c0;
    Instrucao *c1;

    // Instrucao *atual;

    a0 = initInstrucao(1, '0', '1', 1, 2);
    a1 = initInstrucao(1, '1', '1', 1, 0);
    b0 = initInstrucao(1, '0', '0', 2, 3);
    b1 = initInstrucao(1, '1', '1', 2, 2);
    c0 = initInstrucao(0, '0', '1', 3, 3);
    c1 = initInstrucao(0, '1', '1', 3, 1);
    fita = initFita(TAMANHO, padrao);

    // mostrarInstrucao(a0);
    mostrarFitaTuring(fita);

    // for(i = 0; i < QTS_INSTRUCOES; i++) {
    //     if (a0->estado == 1)
    // }

    while(1) {
        break;
    }

    free(fita);
    free(a0);
    free(a1);
    free(b0);
    free(b1);
    free(c0);
    free(c1);
    return 0;
}
