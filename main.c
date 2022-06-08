#include <stdio.h>
#include "coordenada.h"

int main() {
    ListaCoordenadas *lista = criarListaCoordenadas();
    // 1 -> continua adicionando | 0 -> Fechar
    int resposta = 1;

    while (resposta == 1) {
        int x, y;

        printf("Digite a coordenada x: ");
        scanf("%d", &x);

        printf("Digite a coordenada y: ");
        scanf("%d", &y);

        Coordenada *novaCoordenada = criarCoordenada(x, y);
        inserirCoordenada(lista, novaCoordenada);

        printf("Deseja adicionar mais coordenadas? (1 - Sim | 0 - Não)\n");
        scanf("%d", &resposta);
    }

    printf("Lista de coordenadas:\n");
    imprimirListaCoordenadas(lista);

    return 0;
}