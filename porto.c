#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "funcoes.h"


/* INICIO FILA ESPERA*/
void InserirFilaEspera(FILA* Fila, NAVIO reg, int navios){
    static int cont = 0; // controlador
    int tamanho;

    if(cont == 0) {

        Fila->inicio = NULL; // iniico e fim aponta pra nulo
        Fila->fim = NULL;
        cont++;
    }

    pont novoNavio = (pont) malloc(sizeof(Elemento));
    novoNavio->reg = reg; // registro passado para o usuario
    novoNavio->prox = NULL;

    if(Fila->fim == NULL){ // se inicio for nulo, insere no inicio

        Fila->inicio = novoNavio;

    }else { // senão, insere no proximo (final)

        Fila->fim->prox = novoNavio;

    }
    Fila->fim = novoNavio;

}

void RemoverFilaEspera(FILA* Fila){

    if(Fila->inicio == NULL){
        printf("Sem Fila de Espera!\n");
    }

    Elemento *apagar = Fila->inicio;
    Fila->inicio = Fila->inicio->prox;

    if (Fila->inicio == NULL){
        Fila->fim = NULL;
    }
    free(apagar); // desaloca o espaco


}

void ReiniciaFilaEspera(FILA* Fila){

    pont aux = Fila->inicio; // inicio da Porto
    while (aux != NULL){ //enquanto o auxiliar n for nulo
        pont apagar = aux; // vai apagar o auxiliar
        aux = aux->prox; // vai andar para o proximo
        free(apagar); // desaloca
    }

    Fila->inicio = NULL;
    Fila->fim = NULL;

    printf("\n\tFila de Espera Zerada\n");
}
/* FIM FILA ESPERA*/

/* ATRACAMENTOS*/
void InsereAtracamento(ATRACA1* Atraca1, ATRACA2* Atraca2, ATRACA3* Atraca3, ATRACA4* Atraca4, NAVIO reg){

    static int cont = 0; // controlador
    PILHA* Pilha;
    VEICULO* veic;

    if(cont == 0) { // inicializa os atracamnetos

        Atraca1->inicio = NULL; // inicio e fim aponta pra nulo
        Atraca1->fim = NULL;

        Atraca2->inicio = NULL; // inicio e fim aponta pra nulo
        Atraca2->fim = NULL;

        Atraca3->inicio = NULL; // inicio e fim aponta pra nulo
        Atraca3->fim = NULL;

        Atraca4->inicio = NULL; // inicio e fim aponta pra nulo
        Atraca4->fim = NULL;
        cont++;
    }

    if(Atraca1 == NULL && Atraca2 == NULL && Atraca3 == NULL && Atraca4 == NULL) {
        printf("\n\tOs Atracamentos Ja Estao Liberados");
    }

    pont novoNavio = (pont) malloc(sizeof(Elemento));
    novoNavio->reg = reg; // registro passado para o usuario
    novoNavio->prox = NULL;

    if (Atraca1->inicio == NULL){ // atraca no primeiro

        Atraca1->inicio = novoNavio;

    }else if(Atraca2->inicio == NULL){ // se não, o primeiro esta com navio, entao insere no segundo

        Atraca2->inicio = novoNavio;

    }else if(Atraca3->inicio == NULL){ // o segundo esta com navio, insere no terceiro

        Atraca3->inicio = novoNavio;

    }else if(Atraca4->inicio == NULL){ // o terceiro esta com navio, insere no quarto

        Atraca4->inicio = novoNavio;

    }

    else if (Atraca1->inicio != NULL){ // atraca depois do primeiro

        Atraca1->fim->prox = novoNavio;

    }else if(Atraca2->inicio != NULL){ // se não, o segundo/ primeiro esta com navio, entao insere atras do segundo

        Atraca2->fim->prox = novoNavio;

    }else if(Atraca3->inicio != NULL){ // o segundo /segundo esta com navio, insere atras do terceiro

        Atraca3->fim->prox = novoNavio;

    }else if(Atraca4->inicio != NULL){ // o segundo/ terceiro esta com navio, insere atras do quarto

        Atraca4->fim->prox = novoNavio;

    }else{

        Atraca1->fim->prox->prox = novoNavio; // 3 da fila

    }

    Desempilha(reg, &Pilha, &veic);

}
/* FIM ATRACAMENTO*/

/* PILHA */
void Desempilha(NAVIO reg, PILHA* Pilha, VEICULO* veic){

    static cont = 0; // controlador
    veic->quantidadeMovimento = 0;

    if(cont == 0) { // inicia as 5 pilhas
        Pilha->qtd1 = -1;
        Pilha->qtd2 = -1;
        Pilha->qtd3 = -1;
        Pilha->qtd4 = -1;
        Pilha->qtd5 = -1;

    }

    if(Pilha->qtd1 == -1){

        Pilha->qtd1 = Pilha->qtd1 + 1;
        Pilha->Pilha1[Pilha->qtd1] = reg;

        reg.tempo--;

    } else if(Pilha->qtd2 == -1){

        Pilha->qtd2 = Pilha->qtd2 + 1;
        Pilha->Pilha2[Pilha->qtd2] = reg;
        reg.tempo--;

    } else if(Pilha->qtd3 == -1){

        Pilha->qtd3 = Pilha->qtd3 + 1;
        Pilha->Pilha3[Pilha->qtd3] = reg;
        reg.tempo--;

    } else if(Pilha->qtd4 == -1){

        Pilha->qtd4 = Pilha->qtd4 + 1;
        Pilha->Pilha4[Pilha->qtd4] = reg;
        reg.tempo--;

    } else if(Pilha->qtd5 == -1){

        Pilha->qtd5 = Pilha->qtd5 + 1;
        Pilha->Pilha5[Pilha->qtd5] = reg;
        reg.tempo--;
    }

    if (Pilha->qtd1 + 1 == 5){ // reinicia a pilha 1

        Pilha->qtd1 = -1;
        veic->quantidadeMovimento++;
        reg.tempo--;

    }
    if (Pilha->qtd2 + 1 == 5){ // reinicia a pilha 2

        Pilha->qtd2 = -1;
        veic->quantidadeMovimento++;
        reg.tempo--;

    }
    if (Pilha->qtd3 + 1 == 5){ // reinicia a pilha 3

        Pilha->qtd3 = -1;
        veic->quantidadeMovimento++;
        reg.tempo--;

    }
    if (Pilha->qtd4 + 1 == 5){ // reinicia a pilha 4

        Pilha->qtd4 = -1;
        veic->quantidadeMovimento++;
        reg.tempo--;

    }
    if (Pilha->qtd5 + 1 == 5){ // reinicia a pilha 5

        Pilha->qtd5 = -1;
        veic->quantidadeMovimento++;
        reg.tempo--;

    }

}

/* FIM PILHA */

/* INICIO NAVIO*/
void CriaNavio(NAVIO* Navio, int navios){

    FILA* Fila;
    NAVIO reg;

    int id = 0;
    int i = 0;

    printf("Esta Chegando %d Navio(s)\n\n", navios);

    for(i = 0; i < navios; i++) {

        Navio->ID = id + 1; // A cada criação de navio, o id vai ser um valor

        Navio->pilhaNavio1 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio2 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio3 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio4 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha

        Navio->tempo = 16;

        printf("\n\nNavio Com Registro %d Chegou ao Porto\n", Navio->ID);
        printf("Com %d Conteiners na Primeira Pilha\n", Navio->pilhaNavio1);
        printf("Com %d Conteiners na Segunda Pilha\n", Navio->pilhaNavio2);
        printf("Com %d Conteiners na Terceira Pilha\n", Navio->pilhaNavio3);
        printf("Com %d Conteiners na Quarta Pilha\n", Navio->pilhaNavio4);

        id++; // apos criar o id "1", proximo navio a ser criado ira ser o "2"

        InserirFilaEspera(&Fila, reg, navios);
    }
}
/* FIM NAVIO*/

void Inicio(FILA* Fila, NAVIO* Navio){

    int permissao;
    NAVIO reg;
    ATRACA1* Atraca1;
    ATRACA2* Atraca2;
    ATRACA3* Atraca3;
    ATRACA4* Atraca4;
    VEICULO* veic;


    srand(time(NULL));
    int navios = rand() % 4; // gera navios aleatorios de 0 a 3 (0-1-2-3)

    if(navios == 0){
        return Inicio(&Fila, &Navio);
    }


    do{

        printf("\n\n\tPorto Aberto:\n");
        printf("1- Abrir Fila de Espera\n");
        printf("2- Negar Entrada Fila de Espera\n");
        printf("3- Fechar Fila de Espera\n");
        printf("4- Fechar Porto\n");
        scanf("%d", &permissao);

        if(permissao == 1){

            int porto;

            CriaNavio(&Navio, navios);
            printf("\n\tDeseja Mover o Navio Para o Porto? (1-sim) (2-nao)\n");
            scanf("%d", &porto);

            if(porto == 1){

                InsereAtracamento(&Atraca1, &Atraca2, &Atraca3, &Atraca4, reg);
                RemoverFilaEspera(&Fila);

            }
            if(porto == 2){
                CriaNavio(&Navio, navios);
            }

        }

        if(permissao == 2){

            printf("\n\tEntrada Negada, De a Volta e Tente Mais Tarde\n");
            Inicio(&Fila, &Navio);
        }

        if(permissao == 3){

            ReiniciaFilaEspera(&Fila);

        }

    }while (permissao != 4);

    printf("\n\t Hoje Desempilhamos %d Containers\n", veic->quantidadeMovimento);
    printf("Porto Esta Fechado!\n");
    printf("Aguarde o Fechamento das Cancelas\n");

    return;
}