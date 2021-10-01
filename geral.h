#ifndef geral_h
#define geral_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct
{
    int chave;
    long int dado1;
    char dado2[1000];
    char dado3[500];
} registro;

FILE *criarArquivo(int metodo_Pesquisa, int nro_Registros, int tipo_Ordenacao);
int **arrayToInteger(int argc, char *argv[]);

#endif