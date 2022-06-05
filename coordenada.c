#include <stdio.h>
#include <stdlib.h>
#include "coordenada.h"

typedef struct coordernada {
    float x;
    float y;
    struct coordernada *prox;
} Coordenada;

typedef struct listaCoordendas {
    Coordenada *inicio;
    Coordenada *fim;
} ListaCoordenadas;

Coordenada *criarCoordenada(float x, float y) {
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
        printf("(%f, %f)\n", aux->x, aux->y);
        aux = aux->prox;
    }
}