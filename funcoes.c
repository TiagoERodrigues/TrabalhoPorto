#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "funcoes.h"

// DANDO ERRO NO TAMANHO, DANDO ERRO AO ADICIONAR NOVAMENTE (ADICIONAR NO FINAL DA FILA)
// REMOVER FILA E ADICIONAR NO PORTO
// DESEMPILHAR DO NAVIO
// CONFERIR TAMANHO DA PILHA PARA PODER REMOVER
// CONFERIR SE ESTA CRIANDO 5 PILHAS


/* INICIO FILA ESPERA*/
void InserirFilaEspera(FILA* Fila, NAVIO reg){
    static int cont = 0; // controlador

    PORTO* Porto;

    int tamanho = 0;

    if(cont == 0) {

        Fila->inicio = NULL; // iniico e fim aponta pra nulo
        Fila->fim = NULL;
        cont++;
    }

    pont novoNavio = (pont) malloc(sizeof(Elemento));
    novoNavio->reg = reg; // registro passado para o usuario
    novoNavio->prox = NULL;

    if(Fila->inicio == NULL){ // se inicio for nulo, insere no inicio

        Fila->inicio = novoNavio;

    }else { // senão, insere no proximo (final)

        Fila->fim->prox = novoNavio;

    }

    pont aux = Fila->inicio; // auxiliar recebe o primeiro elemento

    while(aux != NULL){ // enquanto o auxiliar for diferente de nulo

        tamanho++; // tamanho ira aumentar

        aux = aux->prox; // auxiliar vai para o proximo
    }

    printf("\n\tA Fila de Espera Esta com %d Navio(s)\n", tamanho);

    reg.tempo++; // tempo no porto

}

void RemoverFilaEspera(PORTO* Porto, FILA* Fila, NAVIO reg){

    if(Fila->inicio == NULL){
        printf("Sem Fila de Espera!\n");
    }
    NAVIO* Navio;
    reg = Fila->inicio->reg; // copia o registro para a memoria
    InserirFilaPorto(&Porto, reg); // envia o navio para o porto
    pont apagar = Fila->inicio; // apagar o primeito elemento
    Fila->inicio = Fila->inicio->prox; // Porto aponta para o proximo

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

/* INICIO PORTO*/

void ExibirFilaPorto(PORTO* Porto){ // exibir a lista de espera

    pont aux = Porto->inicio; // aulixiar é o inicio

    printf("Porto de Espera: \n");

    while (aux != NULL){ // enquanto auxiliar não for nulo

        aux = aux->prox; // aponta para o proximo
    }
    printf("\n");

}

void InserirFilaPorto(PORTO* Porto, NAVIO reg){

    static int cont = 0; // controlador

    int tamanho = 0;

    if(cont == 0) {

        Porto->inicio = NULL; // iniico e fim aponta pra nulo
        Porto->fim = NULL;
        cont++;
    }

    pont novoNavio = (pont) malloc(sizeof(Elemento));
    novoNavio->reg = reg; // registro passado para o usuario
    novoNavio->prox = NULL;

    if(Porto->inicio == NULL){ // se inicio estiver vazio, insere

        Porto->inicio = novoNavio;

    }else { // se não, insere no proximo

        Porto->fim->prox = novoNavio;

    }

    pont aux = Porto->inicio; // auxiliar recebe o primeiro elemento

    while(aux != NULL){ // enquanto o auxiliar for diferente de nulo

        tamanho++; // tamanho ira aumentar

        aux = aux->prox; // auxiliar vai para o proximo
    }

    if(tamanho == 4){ // porto em formato circular

        return InserirFilaPorto(&Porto, reg);

    }
    reg.tempo++; // tempo no porto

}

void RemoverFilaPorto(PORTO* Porto, NAVIO reg){

    if(Porto->inicio == NULL){
        printf("Sem Porto!\n");
    }
    NAVIO* Navio;
    reg = Porto->inicio->reg; // copia o registro para a memoria
    pont apagar = Porto->inicio; // apagar o primeito elemento
    Porto->inicio = Porto->inicio->prox; // Porto aponta para o proximo

    if (Porto->inicio == NULL){
        Porto->fim = NULL;
    }
    free(apagar); // desaloca o espaco

}

void Desempilha(PORTO *Porto, NAVIO reg, PILHA* Pilha) {

    printf("\n\tO Navio Comecara a Desempilhar\n");

    Pilha = (pont)malloc(sizeof(Elemento)); // alocando o topo

    pont pilha = (pont)malloc(sizeof(Elemento));

    pilha->reg = reg; // copia para o no
    pilha->prox = Pilha; // topo da pilha
    Pilha = pilha; // topo recebe valor

    ReiniciaFilaPorto(&Porto);

}

void Removepilha(PILHA* Pilha){

    pont pilha = Pilha;
    Pilha = pilha->prox;
    free(pilha);
}

void ReiniciaFilaPorto(PORTO* Porto){

    pont aux = Porto->inicio; // inicio da Porto
    while (aux != NULL){ //enquanto o auxiliar n for nulo
        pont apagar = aux; // vai apagar o auxiliar
        aux = aux->prox; // vai andar para o proximo
        free(apagar); // desaloca
    }

    Porto->inicio = NULL;
    Porto->fim = NULL;

    printf("\n\tPorto Zerado\n");
}
/*FIM PORTO */

/* INICIO NAVIO*/
void CriaNavio(NAVIO* Navio){

    FILA* Fila;
    NAVIO reg;

    srand(time(NULL));

    int id = 0;
    int navios = rand() % 4; // gera navios aleatorios de 0 a 3 (0-1-2-3)

    int i;

    if(navios == 0){
        return CriaNavio(Navio);
    }

    printf("Esta Chegando %d Navio(s)\n\n", navios);

    for(i = 0; i < navios; i++) {

        Navio->ID = id + 1; // A cada criação de navio, o id vai ser um valor

        Navio->pilhaNavio1 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio2 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio3 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha
        Navio->pilhaNavio4 = rand() % 4+1; // gera uma valor de 0 a 4 (0-1-2-3-4) para a pilha

        Navio->tempo = 0;

        printf("\n\nNavio Com Registro %d Chegou ao Porto\n", Navio->ID);
        printf("Com %d de Conteiners na Primeira Pilha\n", Navio->pilhaNavio1);
        printf("Com %d de Conteiners na Segunda Pilha\n", Navio->pilhaNavio2);
        printf("Com %d de Conteiners na Terceira Pilha\n", Navio->pilhaNavio3);
        printf("Com %d de Conteiners na Quarta Pilha\n", Navio->pilhaNavio4);

        id++; // apos criar o id "1", proximo navio a ser criado ira ser o "2"

        InserirFilaEspera(&Fila, reg);
    }
}
/* FIM NAVIO*/

void Inicio(FILA* Fila, NAVIO* Navio){

    int permissao;
    PORTO* Porto;
    NAVIO reg;

    do{

        printf("\n\n\tPorto Aberto:\n");
        printf("1- Abrir Fila de Espera\n");
        printf("2- Negar Entrada Fila de Espera\n");
        printf("3- Fechar Fila de Espera\n");
        printf("4- Fechar Porto\n");
        scanf("%d", &permissao);

        if(permissao == 1){

            int porto;

            CriaNavio(&Navio);
            printf("\tDeseja Mover o Navio da Fila de Espera\n"
                   "\tPara o Porto? (1-sim) (2-nao)\n");
            scanf("%d", &porto);

            if(porto == 1){

                RemoverFilaEspera(&Porto, &Fila, reg);

            }
            if(porto == 2){
                CriaNavio(&Navio);
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

    printf("Porto Esta Fechado!\n");
    printf("Aguarde o Fechamento das Cancelas\n");

    return;
}
