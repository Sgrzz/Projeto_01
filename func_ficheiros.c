#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "constantes.h"

void gravaFicheiroBinario(dadosUC arrayUC[MAX_UCS], int indiceArrayUC, dadosAula *vAulasOnline,int indiceAulaOnline)
{

    FILE *ficheiro;
    int quantEscrito = -1;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro != NULL)
    {
        //conseguiu abrir o ficheiro

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

}

dadosAula *carregarDadosFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *indiceDadosUC, dadosAula *vAulasOnline,int *indiceAulaOnline) //nao esquecer de fazer tambem para o array dinamico das aulas
{
    FILE *ficheiro;
    int quantLido = -1;
    dadosAula *vBackup;

    vBackup = vAulasOnline;

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
        vAulasOnline=realloc(vAulasOnline, (*indiceAulaOnline+1)*sizeof(dadosAula));

        if (vAulasOnline==NULL)
        {
            printf("Erro ao alocar memoria para as aulas online\n");
            vAulasOnline = vBackup;
        }
        else
        {
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
        }

        fclose(ficheiro);
    }
    else
    {
        printf("Novo ficheiro\n");
        ficheiro = fopen("dados.dat", "wb");
        fclose(ficheiro);
    }

    return vAulasOnline;
}

//vai receber numero do estudante  o nome da aula e tipo de acesso (online ou offline)
void registarLog(char nome[MAX_STRING_NOME_AULA], int numEstudante, enum enumEstadoAula estado)
{
    //abrir ficheiro log.txt e log.dat (texto e binário)
    //declaraçao das variaveis
    FILE *ficheiroTexto, *ficheiroBinario;
    char stringEstado[MAX_STRING];
    //abrir fecheiro de texto
    ficheiroTexto = fopen("log.txt", "a");
    if(ficheiroTexto ==NULL)
    {
        //nao conseguiu abrir o ficheiro
        printf("Erro ao abrir ficheiro de texto\n");
    }
    else
    {
        fprintf(ficheiroTexto, "Nome da aula: %s\n", nome);
        fprintf(ficheiroTexto, "Numero do Estudante: %d\n", numEstudante);

        if(estado == decorrer)
        {
            fprintf(ficheiroTexto, "Tipo de acesso: %s\n", "online");

        }
        else if(estado == realizada)
        {
            fprintf(ficheiroTexto, "Tipo de acesso: %s\n", "offline");
        }
    }
    fclose(ficheiroTexto);
    printf("Gravado com sucesso no ficheiro de texto!\n");


    //ficheiro binario/////////////////////////////////////////////////////////////////////////////////

    //abrir ficheiro binario
    ficheiroBinario = fopen("log.dat", "ab");
    if(ficheiroBinario == NULL)
    {
        //nao conseguiu abir o ficheiro binario
        printf("Erro ao abrir ficheiro binario\n");
    }
    else
    {
        fwrite(nome, MAX_STRING_NOME_AULA*sizeof(char), 1, ficheiroBinario);
        fwrite(&numEstudante, sizeof(int), 1, ficheiroBinario);

        if(estado == decorrer)
        {
            strcpy(stringEstado,"online");
        }
        else if(estado == realizada)
        {
            strcpy(stringEstado,"offline");

        }
        fwrite(stringEstado, 7*sizeof(char), 1, ficheiroBinario);

    }
    fclose(ficheiroBinario);
    printf("Gravado com sucesso no ficheiro binario!\n");
    //fechar ficheiro
}

//hora de inicio as 23:12 do dia 25-01-2021
/*
void lerLogBinario()
{
    FILE *ficheiroBinario;
    long tamanhoFicheiro = 0;
    ficheiroBinario = fopen("log.dat", "rb");

    fseek(ficheiroBinario,0,SEEK_END);
    tamanhoFicheiro = ftell(ficheiroBinario);

    if(ficheiroBinario != NULL)
    {

        while(fread(nome, MAX_STRING_NOME_AULA*sizeof(char), 1, ficheiroBinario)!=0)
        {
            fread(&numEstudante, sizeof(int), 1, ficheiroBinario);
            fread(stringEstado, 7*sizeof(char), 1, ficheiroBinario);
        }

    }

}*/
