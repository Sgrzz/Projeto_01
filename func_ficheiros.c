#include <stdio.h>
#include "estruturas.h"

int gravaFicheiroBinario(dadosUC arrayUC[MAX_UCS], int indiceArrayUC, dadosAula *vAulasOnline,int indiceAulaOnline)
{

    FILE *ficheiro;
    int quantEscrito = -1;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro != NULL)
    {//conseguiu abrir o ficheiro

        quantEscrito = fwrite(&indiceArrayUC, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf("Erro ao escrever a quantidade de uc's no ficheiro\n");
        }
        else
        {
            quantEscrito = fwrite(arrayUC, sizeof(dadosUC), indiceArrayUC, ficheiro);
            if (quantEscrito != indiceArrayUC)
            {
                printf("Erro ao escrever a informacao do vetor\n");
            }
        }

        quantEscrito = -1;

        quantEscrito = fwrite(&indiceAulaOnline, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf("Erro ao escrever a quantidade de aulas no ficheiro\n");
        }
        else
        {
            quantEscrito = fwrite(vAulasOnline, sizeof(dadosAula), indiceAulaOnline, ficheiro);
            if (quantEscrito != indiceAulaOnline)
            {
                printf("Erro ao escrever a informacao do vetor\n");
            }
        }

        fclose(ficheiro);
        printf("Gravado com sucesso no ficheiro binario\n");
    }

    return quantEscrito;
}

void carregarDadosFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *indiceDadosUC, dadosAula *vAulasOnline,int *indiceAulaOnline) //nao esquecer de fazer tambem para o array dinamico das aulas
{
    FILE *ficheiro;
    int quantLido = -1;

    //procurar o ficheiro primeiro, se n o encontrar cria e avisa
    ficheiro = fopen("dados.dat", "rb");
    if (ficheiro != NULL)
    {
        quantLido = fread(indiceDadosUC, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf("Erro ao ler a quantidade de UCs a partir do ficheiro\n");
        }
        else
        {
            quantLido = fread(arrayUC, sizeof(dadosUC), *indiceDadosUC, ficheiro);
            if (quantLido != *indiceDadosUC)
            {
                printf("Erro ao ler a informacao do vetor\n");
            }
        }
        quantLido = -1;

        quantLido = fread(indiceAulaOnline, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf("Erro ao ler a quantidade de aulas a partir do ficheiro\n");
        }
        else
        {
            quantLido = fread(vAulasOnline, sizeof(dadosAula), *indiceAulaOnline, ficheiro);
            if (quantLido != *indiceAulaOnline)
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
