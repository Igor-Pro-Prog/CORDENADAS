#include <stdio.h>
#include <stdlib.h>
#include "coordenada.h" // adicona a biblioteca de funções do cordenada.h

typedef struct coordernada { // criação da estrutura cordenadas
    int x; // adicionando variavel inteira
    int y; // adicionando variavel inteira
    struct coordernada *prox; // estrutura cordenada apontando para o próximo
} Coordenada;

typedef struct listaCoordendas { // criação da estrutura lista de cordenadas
    Coordenada *inicio; // ponteiro apontando para o inicio
    Coordenada *fim; // ponteiro apontando para o fim
} ListaCoordenadas;

Coordenada *criarCoordenada(int x, int y) { 
    Coordenada *novaCoordenada = (Coordenada *) malloc(sizeof(Coordenada));
    novaCoordenada->x = x;
    novaCoordenada->y = y;
    novaCoordenada->prox = NULL;
    return novaCoordenada;
}

void destruirCoordenada(Coordenada *coordenada) {
    free(coordenada);
}

ListaCoordenadas *criarListaCoordenadas() {
    ListaCoordenadas *novaLista = (ListaCoordenadas *) malloc(sizeof(ListaCoordenadas));
    novaLista->inicio = NULL;
    novaLista->fim = NULL;
    return novaLista;
}

void destruirListaCoordenadas(ListaCoordenadas *lista) {
    Coordenada *aux = lista->inicio;

    while (aux != NULL) {
        lista->inicio = aux->prox; // Atualiza o inicio da lista    
        destruirCoordenada(aux);    
        aux = lista->inicio;
    }

    free(lista);
}

void inserirCoordenada(ListaCoordenadas *lista, Coordenada *coordernada) {
    if (lista->inicio == NULL) {
        lista->inicio = coordernada;
        lista->fim = coordernada;
    } else {
        lista->fim->prox = coordernada; 
        lista->fim = coordernada;
    }
}

void imprimirListaCoordenadas(ListaCoordenadas *lista) {
    Coordenada *aux = lista->inicio;

    while (aux != NULL) {
        printf("(%d, %d)\n", aux->x, aux->y);
        aux = aux->prox;
    }
}