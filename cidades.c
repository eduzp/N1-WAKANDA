//ANOTAÇÕES GERAIS:

//Usei um funcão static como auxílio para posições.
//no *getEstrada eu usei uma leitura de dos no arquivo para inicialiazação da estrutura.
//declarei os intereiros T e N, sendo o T para o Total e N para o Nº.
//Declaro uma repetição com o for para leitura e verificação.
//Uso do Double para Ordenância, definição e calculo com retorno.
//Fiz uma alocação no final para retornar o nome.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "cidades.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

int compararCidades(const void *a, const void *b) {
    Cidade *c1 = (Cidade *)a;
    Cidade *c2 = (Cidade *)b;
    return c1->Posicao - c2->Posicao;
}

Estrada *getEstrada(const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (!fp) return NULL;

    int T, N;
    if (fscanf(fp, "%d", &T) != 1 || T < 3 || T > 1000000) {
        fclose(fp);
        return NULL;
    }
    if (fscanf(fp, "%d", &N) != 1 || N < 2 || N > 10000) {
        fclose(fp);
        return NULL;
    }

    Estrada *e = malloc(sizeof(Estrada));
    if (!e) return NULL;

    e->T = T;
    e->N = N;
    e->C = malloc(sizeof(Cidade) * N);
    if (!e->C) {
        free(e);
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        if (fscanf(fp, "%d %[^\n]", &e->C[i].Posicao, e->C[i].Nome) != 2 || 
            e->C[i].Posicao <= 0 || e->C[i].Posicao >= T) {
            free(e->C);
            free(e);
            fclose(fp);
            return NULL;
        }

        // checar duplicatas
        for (int j = 0; j < i; j++) {
            if (e->C[j].Posicao == e->C[i].Posicao) {
                free(e->C);
                free(e);
                fclose(fp);
                return NULL;
            }
        }
    }

    fclose(fp);
    return e;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *e = getEstrada(nomeArquivo);
    if (!e) return -1;

    qsort(e->C, e->N, sizeof(Cidade), compararCidades);

    double menor = e->T;
    for (int i = 0; i < e->N; i++) {
        double inicio, fim;

        if (i == 0)
            inicio = 0;
        else
            inicio = (e->C[i].Posicao + e->C[i - 1].Posicao) / 2.0;

        if (i == e->N - 1)
            fim = e->T;
        else
            fim = (e->C[i].Posicao + e->C[i + 1].Posicao) / 2.0;

        double vizinhanca = fim - inicio;
        if (vizinhanca < menor)
            menor = vizinhanca;
    }

    free(e->C);
    free(e);
    return menor;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *e = getEstrada(nomeArquivo);
    if (!e) return NULL;

    qsort(e->C, e->N, sizeof(Cidade), compararCidades);

    double menor = e->T;
    int index = -1;

    for (int i = 0; i < e->N; i++) {
        double inicio, fim;

        if (i == 0)
            inicio = 0;
        else
            inicio = (e->C[i].Posicao + e->C[i - 1].Posicao) / 2.0;

        if (i == e->N - 1)
            fim = e->T;
        else
            fim = (e->C[i].Posicao + e->C[i + 1].Posicao) / 2.0;

        double vizinhanca = fim - inicio;
        if (vizinhanca < menor) {
            menor = vizinhanca;
            index = i;
        }
    }

    char *resposta = malloc(strlen(e->C[index].Nome) + 1);
    strcpy(resposta, e->C[index].Nome);

    free(e->C);
    free(e);
    return resposta;
}
