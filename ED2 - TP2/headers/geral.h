#ifndef GERAL_H
#define GERAL_H

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ANSI_BOLD "\x1b[1m"
#define ANSI_COLOR_RED "\e[1;91m"
#define ANSI_COLOR_YELLOW "\e[1;93m"
#define ANSI_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\e[1;94m"
#define ANSI_COLOR_GREEN "\e[1;92m"

/* 
    ED2 - TP 2 -> https://github.com/augustofgui/ed2-tp1
    - Augusto Guilarducci (20.1.4012)
    - Caio Monteiro (20.1.4110)
    - Paulo Correa (20.1.4036)
    - Pedro Lucas Damasceno (20.1.4003)
*/

typedef struct registro
{
    long int inscricao;
    float nota;
    char estado_cidade_curso[87];
} Registro;

void verificar_parametros(int argc, int nro_metodo, int nro_quantidade, int nro_situacao);
FILE *abrir_arquivo(char nome_arquivo[], char modo_abertura[]);
void converter_para_binario(FILE *arquivo_texto, char *nome_binario, char *nome_txt);
void converter_para_txt(FILE *arquivo_binario, char* argv);
void merge_sort(Registro *vetor, int margem_esquerda, int n);
void merge_sort_ascendente(Registro *vetor, int margem_esquerda, int nova_margem, int n);
void selection_sort_ascendente(Registro *array, int n);
void print_estatisticas(int nro_comparacoes, int nro_leituras, int nro_escritas, double tempo_execucao);
void PrintFRead(Registro *R);
void PrintFWrite(Registro *R);

#endif // GERAL_H