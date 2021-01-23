#include <stdio.h>
#include "estruturas.h"

int gravaFicheiroBinario(dadosUC arrayUC[MAX_UCS], int posIndiceArray)
{

    FILE *ficheiro;
    int quantEscrito = -1;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro != NULL)
    {//conseguiu abrir o ficheiro

        quantEscrito = fwrite(&posIndiceArray, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf("Erro ao escrever a quantidade de uc's no ficheiro\n");
        }
        else
        {
            quantEscrito = fwrite(arrayUC, sizeof(dadosUC), posIndiceArray, ficheiro);
            if (quantEscrito != posIndiceArray)
            {
                printf("Erro ao escrever a informacao do vetor\n");
            }
        }

        fclose(ficheiro);
        printf("Gravado com sucesso no ficheiro binario\n");
    }

    return quantEscrito;
}

void carregarDadosFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *posIndiceArray) //nao esquecer de fazer tambem para o array dinamico das aulas
{
    FILE *ficheiro;
    int quantLido = -1;

    //procurar o ficheiro primeiro, se n o encontrar cria e avisa
    ficheiro = fopen("dados.dat", "rb");
    if (ficheiro != NULL)
    {
        quantLido = fread(posIndiceArray, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf("Erro ao ler a quantidade de UCs a partir do ficheiro\n");
        }
        else
        {
            quantLido = fread(arrayUC, sizeof(dadosUC), *posIndiceArray, ficheiro);
            if (quantLido != *posIndiceArray)
            {
                printf("Erro ao ler a informacao do vetor\n");
            }
        }
        fclose(ficheiro);
    }
    else
    {
        printf("Novo ficheiro\n");
        ficheiro = fopen("dados.dat", "wb");
        fclose(ficheiro);
    }
}
