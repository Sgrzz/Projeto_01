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


int lerFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *posIndiceArray)
{
    FILE *ficheiro;
    int quantLido = -1;

    ficheiro = fopen("dados.dat", "rb");


    if (ficheiro != NULL)
    {//conseguiu abrir o ficheiro

        quantLido = fread(posIndiceArray, sizeof(int), 1, ficheiro);
        // ou quantLido = fread(&*quantEstudantes, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf("Erro ao ler a quantidade de UCs a partir do ficheiro");
        }
        else
        {
            quantLido = fread(arrayUC, sizeof(dadosUC), *posIndiceArray, ficheiro);
            if (quantLido != *posIndiceArray)
            {
                printf("Erro ao ler a informacao do vetor");
            }
        }
        fclose(ficheiro);
        printf("Leitura de ficheiro com sucesso \n");
        printf("Dados de estudantes importados \n");
    }
}
