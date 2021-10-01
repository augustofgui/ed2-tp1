#include "geral.h"

//argv[1] = Método
//argv[2] = Quantidade
//argv[3] = Situação
//argv[4] = chave
//argv[5] = [P] -> printf chaves dos registros
int **arrayToInteger(int argc, char *argv[])
{
    for (int i = 1; i < 5; i++)
        argv[i] = atoi(argv[i]);

    return argv;
}

FILE *criarArquivo(int metodo_Pesquisa, int nro_Registros, int tipo_Ordenacao)
{
    FILE *arquivo_Binario;
    registro aux;

    arquivo_Binario = fopen("arquivo_binario.bin", "wb");
    if (!arquivo_Binario)
    {
        printf("Erro ao criar o arquivo binário de registros.\n");
        exit(1);
    }

    if (metodo_Pesquisa == 1 && tipo_Ordenacao > 2)
    {
        printf("O método de acesso sequencial indexado não admite arquivos desordenados. Por favor, corrija os parâmetros de execução.\n");
        exit(1);
    }

    printf("Arquivo binário em criação, aguarde...\n");

    switch (tipo_Ordenacao)
    {
    case 1: //Ordem Crescente.
        for (int i = 0; i < nro_Registros; i++)
        {
            aux.chave = i + 1;
            fwrite(&aux, sizeof(registro), 1, arquivo_Binario);
        }
        break;
    case 2: //Ordem Decrescente.
        for (int i = nro_Registros; i > 0; i++)
        {
            fwrite(&aux, sizeof(registro), 1, arquivo_Binario);
            aux.chave = i - 1;
        }
        break;
    case 3: //Desordenado.
        registro *array = (registro *)malloc(nro_Registros * sizeof(registro));

        srand(time(NULL));

        for (int i = 0; i < nro_Registros; i++)
        {
            int j = rand() % (nro_Registros - 1);
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }

        for (int i = 0; i < nro_Registros; i++)
            fwrite(&array, sizeof(registro), 1, arquivo_Binario);

        free(array);
        break;
    }

    printf("Arquivo binário criado! Configurações: %d (método), %d (número de registros), %d (tipo de ordenação).\n", metodo_Pesquisa, nro_Registros, tipo_Ordenacao);
    return arquivo_Binario;
}