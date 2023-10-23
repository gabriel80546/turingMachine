#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAMANHO 30
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
    int atualEstado = 0;
    char atualLeitura = '\0';
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
    // mostrarFitaTuring(fita);

    // for(i = 0; i < QTS_INSTRUCOES; i++) {
    //     if (a0->estado == 1)
    // }

    Instrucao *atual;

    atual = a0;
    atualEstado = a0->estado;
    i = 0;
    mostrarFitaTuring(fita);
    while(atualEstado != 0) {

        // atualEstado = atual->estado;
        atualLeitura = fita[posicao];

        printf("posicao = %i\n", posicao);
        printf("atualLeitura = \'%c\'\n", atualLeitura);
        printf("atualEstado = %i\n", atualEstado);


        if(atualLeitura == a0->leia && atualEstado == a0->estado) {
            printf("atualLeitura == a0->leia && atualEstado == a0->estado\n");
            fita[posicao] = a0->escreva;
            if(a0->lado == 1) {
                posicao++;
            } else if (a0->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", a0, a0, a0->lado);
                exit(1);
            }
            printf("atualEstado = %i; a0->proximoEstado = %i\n", atualEstado, a0->proximoEstado);
            atualEstado = a0->proximoEstado;
            printf("atualEstado = %i; a0->proximoEstado = %i\n", atualEstado, a0->proximoEstado);
            // atualLeitura = fita[posicao];
        } else if(atualLeitura == a1->leia && atualEstado == a1->estado) {
            printf("atualLeitura == a1->leia && atualEstado == a1->estado\n");
            fita[posicao] = a1->escreva;
            if(a1->lado == 1) {
                posicao++;
            } else if (a1->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", a1, a1, a1->lado);
                exit(1);
            }
            atualEstado = a1->proximoEstado;
            // atualLeitura = fita[posicao];
        } else if(atualLeitura == b0->leia && atualEstado == b0->estado) {
            printf("atualLeitura == b0->leia && atualEstado == b0->estado\n");
            fita[posicao] = b0->escreva;
            if(b0->lado == 1) {
                posicao++;
            } else if (b0->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", b0, b0, b0->lado);
                exit(1);
            }
            atualEstado = b0->proximoEstado;
            // atualLeitura = fita[posicao];
        } else if(atualLeitura == b1->leia && atualEstado == b1->estado) {
            printf("atualLeitura == b1->leia && atualEstado == b1->estado\n");
            fita[posicao] = b1->escreva;
            if(b1->lado == 1) {
                posicao++;
            } else if (b1->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", b1, b1, b1->lado);
                exit(1);
            }
            atualEstado = b1->proximoEstado;
            // atualLeitura = fita[posicao];
        } else if(atualLeitura == c0->leia && atualEstado == c0->estado) {
            printf("atualLeitura == c0->leia && atualEstado == c0->estado\n");
            fita[posicao] = c0->escreva;
            if(c0->lado == 1) {
                posicao++;
            } else if (c0->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", c0, c0, c0->lado);
                exit(1);
            }
            atualEstado = c0->proximoEstado;
            // atualLeitura = fita[posicao];
        } else if(atualLeitura == c1->leia && atualEstado == c1->estado) {
            printf("atualLeitura == c1->leia && atualEstado == c1->estado\n");
            fita[posicao] = c1->escreva;
            if(c1->lado == 1) {
                posicao++;
            } else if (c1->lado == 0) {
                posicao--;
            } else {
                printf("Erro: Instrucao %p->lado nao eh nem 1 nem 0; %p->lado = %i\n", c1, c1, c1->lado);
                exit(1);
            }
            atualEstado = c1->proximoEstado;
            // atualLeitura = fita[posicao];
        } else {
            printf("Erro, atualEstado = %i, atualLeitura = \'%c\', tipo não encontrado ou leitura não encontrada\n", atualEstado, atualLeitura);
            free(fita);
            free(a0);
            free(a1);
            free(b0);
            free(b1);
            free(c0);
            free(c1);
            exit(2);
        }
        mostrarFitaTuring(fita);
        if (i > 3) {
            break;
        }
        i++;
    }
    if(atual->estado == 0) {
        printf("Maquina de Turing finalizada com sucesso\n");
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
