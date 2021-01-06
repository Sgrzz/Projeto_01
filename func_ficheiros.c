#include <stdio.h>
#include "estruturas.h"

void gravaFicheiroBinario(dadosUC arrayUC[MAX_UCS], int posIndiceArray)
{

    FILE *ficheiro;
    int quantEscrito;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");
    }
    else{//conseguiu abrir o ficheiro

        quantEscrito = fwrite(&posIndiceArray, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf("Erro ao escrever a quantidade de estudantes no ficheiro\n");
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
}


void lerFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *posIndiceArray)
{
    FILE *ficheiro;
    int quantLido;

    ficheiro = fopen("dados.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro");
    }
    else
    {//conseguiu abrir o ficheiro

        quantLido = fread(posIndiceArray, sizeof(int), 1, ficheiro);
        // ou quantLido = fread(&*quantEstudantes, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf("Erro ao ler a quantidade de estudantes a partir do ficheiro");
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
