#include <limits.h>

#define TAM_AREA 20
#define MAX_NOTA 999999.99

typedef struct {
    Registro array[TAM_AREA];
    int nro_cels_ocupadas;
} TipoArea;

void quicksort_externo_main(char argv[], int nro_quantidade);
void quicksort_externo(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir);
void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j);
void LeSup(FILE **ArqLEs, Registro *UltLido, int *Ls, bool *OndeLer);
void LeInf(FILE **ArqLi, Registro *UltLido, int *Li, bool *OndeLer);
void EscreveMax(FILE **ArqLEs, Registro R, int *Es);
void EscreveMin(FILE **ArqEi, Registro R, int *Ei);
void RetiraMax(TipoArea *Area, Registro *R);
void RetiraMin(TipoArea *Area, Registro *R);
void FAVazia(TipoArea* Area);
void RetiraUltimo(TipoArea *Area, Registro *R);
void RetiraPrimeiro(TipoArea *Area, Registro *R);
void InsereItem(Registro *UltLido, TipoArea *Area);
void PrintArea(TipoArea *Area);