# Readme

Este projeto implementa, em linguagem C, um sistema para cálculo de vizinhança de cidades ao longo de uma estrada linear, como proposto na atividade avaliativa de Estruturas de Dados da Universidade Católica de Brasília (UCB).

## Formato do Arquivo de Entrada

T         <- Comprimento total da estrada (int)

N         <- Número de cidades (int)

Xi Nome   <- Distância da cidade i da fronteira oeste (int) e nome da cidade (string)

## Funcionalidades

O projeto implementa três funções principais, definidas em cidades.h:

Estrada *getEstrada(const char *nomeArquivo);               // Inicializa os dados da estrada

double calcularMenorVizinhanca(const char *nomeArquivo);    // Retorna a menor vizinhança

char *cidadeMenorVizinhanca(const char *nomeArquivo);       // Retorna o nome da cidade com menor vizinhança

## Compilação

gcc main.c cidades.c -o cidades.exe

✅ Compatível com GCC padrão, DevC++, Code::Blocks e VSCode com extensão C/C++.

## Estrutura do Projeto

├── cidades.h         # Arquivo de cabeçalho com os protótipos

├── cidades.c         # Implementação das funções

├── main.c            # Arquivo base fornecido pelo Professor.

├── Teste01.txt       # Arquivo de Teste N°1

├── Teste02.txt       # Arquivo de Teste N°2

└── Resultado.txt     # Resultado final

## Créditos

Este projeto foi desenvolvido como parte da disciplina de Estruturas de Dados na Universidade Católica de Brasília (UCB), sob orientação do Professor Marcelo Eustáquio.

📌 Autor: Luiz Eduardo dos Anjos De Jesus
💻 GitHub: @eduzp
