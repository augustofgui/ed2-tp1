#include "../headers/geral.h"
#include "../headers/sequencial_indexado.h"
#include "../headers/arvore_b.h"

int main(int argc, char *argv[])
{
    verificar_parametros(argc, argv);

    int nro_metodo = atoi(argv[1]);
    int nro_registros = atoi(argv[2]);
    int nro_situacao = atoi(argv[3]);
    int nro_chave = atoi(argv[4]);

    FILE *arquivo_binario = criar_arquivo(nro_metodo, nro_registros, nro_situacao);

    switch (nro_metodo)
    {
    case 1:
        if (!sequencial_indexado(arquivo_binario, nro_metodo, nro_registros, nro_situacao, nro_chave, argv[5]))
            imprimir_nao_encontrado(nro_chave);
        break;
    case 2:
        if (!arvore_externa(arquivo_binario, nro_metodo, nro_registros, nro_situacao, nro_chave, argv[5]))
            imprimir_nao_encontrado(nro_chave);
        break;
    case 3:
        if (!arvore_b(arquivo_binario, nro_metodo, nro_registros, nro_situacao, nro_chave, argv[5]))
            imprimir_nao_encontrado(nro_chave);
        break;
    case 4:
        if (!arvore_bx(arquivo_binario, nro_metodo, nro_registros, nro_situacao, nro_chave, argv[5]))
            imprimir_nao_encontrado(nro_chave);
        break;
    }

    return 0;
}