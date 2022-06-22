#include <stdio.h>
#include <math.h>

/*
    * Programa que recebe 3 coordenadas e calcula a area usando a formula de heron
*/

#define QTD_COORDENADAS 3

int main() {
    float area, coordenadas[2][QTD_COORDENADAS];

    for (int i = 0; i < QTD_COORDENADAS; i++) {
        printf("COORDENADA %d\n", i + 1);
        printf("X: ");
        scanf("%f", &coordenadas[0][i]);
        printf("Y: ");
        scanf("%f", &coordenadas[1][i]);
    }

    // imprimir todas as coordenadas

    for (int i = 0; i < QTD_COORDENADAS; i++) {
        printf("COORD %d: %.2f %.2f\n", i + 1, coordenadas[0][i], coordenadas[1][i]);
    }

    float distancias[QTD_COORDENADAS], perimetro = 0;

    for (int i = 0; i < QTD_COORDENADAS; i++) {
        int proxI = (i + 1) % QTD_COORDENADAS;
        printf("ind %d prox %d\n", i, proxI);
        distancias[i] = distancia(coordenadas[0][i], coordenadas[1][i], coordenadas[0][proxI], coordenadas[1][proxI]);
        printf("dist %d: %f\n", i + 1, distancias[i]);
        perimetro += distancias[i];
    }

    printf("Perimetro: %.2f\n", perimetro);

    float S = perimetro / 2;

    area = sqrt(S * (S - distancias[0]) * (S - distancias[1]) * (S - distancias[2]));

    printf("Area: %.2f\n", area);

    return 0;
}