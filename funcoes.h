#ifndef TRABALHO_EDI_FUNCOES_H
#define TRABALHO_EDI_FUNCOES_H

#endif //TRABALHO_EDI_FUNCOES_H

typedef struct { // struct navio

    int ID;
    int pilhaNavio1;
    int pilhaNavio2;
    int pilhaNavio3;
    int pilhaNavio4;
    int tempo;

}NAVIO;

typedef struct{

    NAVIO Pilha1[5];
    int qtd1;
    NAVIO Pilha2[5];
    int qtd2;
    NAVIO Pilha3[5];
    int qtd3;
    NAVIO Pilha4[5];
    int qtd4;
    NAVIO Pilha5[5];
    int qtd5;

}PILHA;

typedef struct aux{

    NAVIO reg;
    struct aux* prox;

}Elemento, *pont;

typedef struct{

    pont inicio;
    pont fim;

}PORTO;

typedef struct{

    pont inicio;
    pont fim;

}ATRACA1;

typedef struct{

    pont inicio;
    pont fim;

}ATRACA2;

typedef struct{

    pont inicio;
    pont fim;

}ATRACA3;

typedef struct{

    pont inicio;
    pont fim;

}ATRACA4;

typedef struct{

    pont inicio;
    pont fim;

}FILA;

typedef struct{ // controle veiculo

    int quantidadeMovimento;

}VEICULO;

void Inicio(FILA* Fila, NAVIO* Navio);

// Fila de Espera //
void InserirFilaEspera(FILA* Fila, NAVIO reg, int navios);
void RemoverFilaEspera(FILA* Fila);
void ReiniciaFilaEspera(FILA* Fila);

// Fila do Porto//
void InsereAtracamento(ATRACA1* Atraca1, ATRACA2* Atraca2, ATRACA3* Atraca3, ATRACA4* Atraca4, NAVIO reg);

// Navio //
void CriaNavio(NAVIO* Navio, int navios);

// Pilha //
void Desempilha(NAVIO reg, PILHA* Pilha, VEICULO* veic);
