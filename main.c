#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int main() {
    int Soma = 0;
    int NumTeste = 0;

    FILE *Resposta = fopen("Resultado.txt", "w");
    if (!Resposta) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    Estrada *T1 = getEstrada("Teste01.txt");
    if (T1 == NULL) {
        fprintf(Resposta, "Erro ao ler os dados.\n");
        fclose(Resposta);
        return 1;
    }

    double D1 = calcularMenorVizinhanca("Teste01.txt");
    char *C1 = cidadeMenorVizinhanca("Teste01.txt");

    if (T1->T == 10) Soma++;
    NumTeste++;

    if (T1->N == 2) Soma++;
    NumTeste++;

    if (D1 == 3.5) Soma++;
    NumTeste++;

    if (C1 && strcmp(C1, "Birnin Zana") == 0) Soma++;
    NumTeste++;

    fprintf(Resposta,
        "\n\nForam acertados %d de %d itens. Sua nota foi %.2f.\n",
        Soma, NumTeste, 2.0f * Soma / NumTeste);

    printf("Teste finalizado! Verique o Resultado.txt.\n");

    free(C1);
    free(T1->C);
    free(T1);
    fclose(Resposta);
    return 0;
}
