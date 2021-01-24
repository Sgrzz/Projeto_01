#include <stdio.h>
#include "estruturas.h"



// Média de presenças em cada aula online realizada
float mediaPresencasAulas(dadosAula *vAulasOnline, int quantAulas)
{
    int  i = 0; //, soma, somaAcessos, quantAcessos;
    float media = 0.0;

    for(i = 0; i < quantAulas; i++)
    {
        if(vAulasOnline[i].estado == realizada)
        {
            // vAulasOnline[i].tipoAula;
        }
    }

    return media;
}


// Percentagem de UCs com aulas gravadas
void percentUCAulasGravadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC)
{
    int i, j;
    int quantAulasRealizadas = 0, quantAulasGravadas = 0;
    float percAulasGravadas = 0.0;

    // percorrer as UC existentes chegando no final com o nº total de UCs
    for (i = 0; i < indiceUC; i++)
    {
        quantAulasRealizadas = 0;
        quantAulasGravadas = 0;
        percAulasGravadas = 0.0;

        // percorre o vetor aulas e conta as aulas existentes na UC
        for (j = 0; j < indiceAulasOnline; j++)
        {
            if ((vAulasOnline[j].codigoUC == vetUC[i].codigoUC) && (vAulasOnline[i].estado == realizada)) // vais comparar o codigoUC das UC com o codigoUC das aulas e ver se a aula foi realizada
            {
                quantAulasRealizadas++; // conta quantas aulas foram realizadas

                if (vAulasOnline[j].gravacao == sim) // dentro das aulas realizadas ve quantas aulas foram gravadas
                {
                    quantAulasGravadas++; // e conta-as
                }
            }
        }
        printf("\nUC: %s\n", vetUC[i].nome);

        if(quantAulasRealizadas >0)
        {
            // calcula a percentagem de aulas gravadas
            percAulasGravadas = quantAulasGravadas/quantAulasRealizadas *100.0;
            printf("Percentagem de aulas gravadas: %.0f %%\n", percAulasGravadas);
        }
        else
        {
            printf("Ainda nao tem aulas realizadas.\n");
        }
        printf("\n");
    }
}


// UC(s) com a menor quantidade de aulas online realizadas

void UcComMenorQuantAulasRealizadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC)
{
    int i, j;
    int vQuantAulasRealizadas[indiceUC];
    int quantAulasRealizadas = 0;
    int quantAulasAux, indiceMenorUC;

    // percorre as UC existentes chegando no final com o nº total de UCs
    for(i =0; i<indiceUC; i++)
    {
        quantAulasRealizadas = 0;

        // percorre o vetor aulas e conta as aulas existentes na UC
        for (j = 0; j < indiceAulasOnline; j++)
        {
            if ((vAulasOnline[j].codigoUC == vetUC[i].codigoUC) && (vAulasOnline[i].estado == realizada)) // vai comparar o codigoUC das UC com o codigoUC das aulas e ver se a aula foi realizada
            {
                quantAulasRealizadas++; // conta quantas aulas foram realizadas
            }
        }
        vQuantAulasRealizadas[i] = quantAulasRealizadas;
    }
    if(indiceUC -1 >= 0)
    {
        quantAulasAux = vQuantAulasRealizadas[indiceUC];
    }

    for(i = 0; i <indiceUC; i++) // encontra a UC com menor aulas realizadas
    {
        if(vQuantAulasRealizadas[i] < quantAulasAux)
        {
            quantAulasAux = vQuantAulasRealizadas[i];
            indiceMenorUC = i;
        }
    }
    for(i = 0; i < indiceUC; i++)
    {
        if(vQuantAulasRealizadas[i] == vQuantAulasRealizadas[indiceMenorUC]) //tem o mesmo numero
        {
            printf("UC: %s", vetUC[i].nome);
        }
    }
}

// o tipo(s) de aula(s) com a maior quantidade de acessos às gravações

//void tipoAulaMaiorAcessos(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC)





// aula(s) online realizada(s) há mais tempo
// ranking





void estatisticasMenuPrincipal(dadosAula *vAulasOnline, int indiceAulasOnline, int indiceUC)
{
    int i;
    int quantAulasRealizadas = 0, quantAulasGravadas = 0, quantAulasAgendadas = 0;

    // percorrer as UC existentes chegando no final com o nº total de UCs

    // percorre o vetor aulas e conta as aulas existentes na UC
    for (i = 0; i < indiceAulasOnline; i++)
    {
        if(vAulasOnline[i].estado == agendada) //ve se a aula agendada
        {
            quantAulasAgendadas++; // conta quantas aulas foram agendadas
        }
        else if(vAulasOnline[i].estado == realizada) // ver se a aula foi realizada
        {
            quantAulasRealizadas++; // conta quantas aulas foram realizadas

            if (vAulasOnline[i].gravacao == sim) // dentro das aulas realizadas ve quantas aulas foram gravadas
            {
                quantAulasGravadas++; // e conta-as
            }
        }
    }
    printf("Quantidade de UCs: %d", indiceUC);
    printf("\nQuantidade de aulas agendadas: %d", quantAulasAgendadas);
    printf("\nQuantidade de aulas realizadas: %d", quantAulasRealizadas);
    printf("\nQuantidade de aulas gravadas: %d\n", quantAulasGravadas);

}

