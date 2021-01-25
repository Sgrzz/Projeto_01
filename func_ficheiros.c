#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

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
void registarLog(dadosAula *vAulasOnline, int indiceAulaOnline, int numEstudante)
{
    //abrir ficheiro log.txt e log.dat (texto e binário)
    //declaraçao das variaveis
    FILE *ficheiroTexto, *ficheiroBinario;


    //abrir fecheiro de texto
    ficheiroTexto = fopen("log.txt", "a");
    if(ficheiroTexto ==NULL)
    {
        //nao conseguiu abrir o ficheiro
        printf("Erro ao abrir ficheiro de texto\n");
    }
    else
    {
        fprintf(ficheiroTexto, "Nome da aula: %s\n", vAulasOnline[indiceAulaOnline].nome);
        fprintf(ficheiroTexto, "Numero do Estudante: %d\n", numEstudante);

        if(vAulasOnline[indiceAulaOnline].estado == decorrer)
        {
            fprintf(ficheiroTexto, "Tipo de acesso: %s\n", "online");

        }
        else if(vAulasOnline[indiceAulaOnline].estado == realizada && vAulasOnline[indiceAulaOnline].gravacao == sim)
        {
            fprintf(ficheiroTexto, "Tipo de acesso: %s\n", "offline");
        }
    }
    fclose(ficheiroTexto);
    printf("Gravado com sucesso no ficheiro de texto!\n");



    //abrir ficheiro binario
    ficheiroBinario = fopen("log.dat", "ab");
    if(ficheiroBinario == NULL)
    {
        //nao conseguiu abir o ficheiro binario
        printf("Erro ao abrir ficheiro binario\n");
    }
    else
    {
        fprintf(ficheiroBinario, "Nome da aula: %s\n", vAulasOnline[indiceAulaOnline].nome);
        fprintf(ficheiroBinario, "Numero do Estudante: %d\n", numEstudante);
        if(vAulasOnline[indiceAulaOnline].estado == decorrer)
        {
            fprintf(ficheiroBinario, "Tipo de acesso: %s\n", "online");
        }
        else if(vAulasOnline[indiceAulaOnline].estado == realizada && vAulasOnline[indiceAulaOnline].gravacao == sim)
        {
            fprintf(ficheiroBinario, "Tipo de acesso: %s\n", "offline");
        }
    }
    fclose(ficheiroBinario);
    printf("Gravado com sucesso no ficheiro binario!\n");
    //fechar ficheiro
}
