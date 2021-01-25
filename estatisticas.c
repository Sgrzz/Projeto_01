#include <stdio.h>
#include "estruturas.h"
#include "func_aux.h"



// Presenças em cada aula online realizada
void presencasAulas(dadosAula *vAulasOnline, int quantAulas)
{
    int  i = 0;
    for(i = 0; i < quantAulas; i++)
    {
        if(vAulasOnline[i].estado == realizada)
        {
            printf("\nAula: %s presencas:%d",vAulasOnline[i].nome,vAulasOnline[i].numEstudantesOnline);
        }
    }
    printf("\n");

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
    }
    printf("\n");
}

// UC(s) com a menor quantidade de aulas online realizadas
/*
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
    printf("\n");
}*/

// o tipo(s) de aula(s) com a maior quantidade de acessos às gravações
//mostrar a uc com menor quantidade de aulas realizadas
//se estiverem empatadas mostra as 2

void ucsMenorQuantidadeAulasRealizadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC)
{
    int i,x;
    int quantRealizadas[MAX_UCS];
    int menorNum = 99999;


    for(i=0; i<indiceUC; i++)
    {
        quantRealizadas[i] = 0;
        for(x=0; x<indiceAulasOnline; x++)
        {
            if (vAulasOnline[x].codigoUC == vetUC[i].codigoUC && vAulasOnline[x].estado == realizada)
            {
                quantRealizadas[i]++;
            }
        }
    }

    //verificar qual é o menor numero
    for(i=0; i<indiceUC; i++)
    {
        if (quantRealizadas[i]<menorNum)
        {
            menorNum = quantRealizadas[i];
        }
    }

    for(i=0; i<indiceUC; i++)
    {
        if (quantRealizadas[i] == menorNum)
        {
            printf("\nUC: %s",vetUC[i].nome);
        }
    }
    printf("\n");
}

//o tipo(s) daula(s) com a maior quantidade de acessos às gravações
void quantidadeDeAulasPorTipo(dadosAula *vAulasOnline, int indiceAulasOnline)
{
    int i, maior;
    tipoAulas contador;

    contador.T = 0;
    contador.TP = 0;
    contador.PL = 0;

    for(i=0; i<indiceAulasOnline; i++)
    {
        //contar os acessos as gravacoes por tipo de aula
        switch(vAulasOnline[i].tipoAula)
        {
        case T:
            contador.T++;
            break;
        case TP:
            contador.TP++;
            break;
        case PL:
            contador.PL++;
            break;
        }
    }

    maior = contador.T;
    if (maior<contador.TP)
    {
        maior = contador.TP;
    }
    if (maior<contador.PL)
    {
        maior = contador.PL;
    }

    if (maior==contador.T)
    {
        printf("\nTipo teorica com %d aulas",contador.T);
    }
    if (maior==contador.TP)
    {
        printf("\nTipo teorica praticas com %d aulas",contador.TP);
    }
    if (maior==contador.PL)
    {
        printf("\nTipo pratica laboratorial com %d aulas",contador.PL);
    }
    printf("\n");
}

// aula(s) online realizada(s) há mais tempo

void listaDeAulasMaisVelhas(dadosAula *vAulasOnline, int indiceAulasOnline)
{
    tipoData data;

    data.dia = 31;
    data.mes = MAX_MES;
    data.ano = MAX_ANO;
    //era so subtrair uma data menos a outra pa saber qual era a menor ._.
    int i;
    for(i=0; i<indiceAulasOnline; i++)
    {
        if(vAulasOnline[i].estado == realizada)
        {
            if (vAulasOnline[i].data.ano<data.ano)//se o ano for menor entao a data passa a ficar essa
            {
                data = vAulasOnline[i].data;
            }
            else if(vAulasOnline[i].data.ano == data.ano) //se o ano for igual comparamos o mes
            {
                if(vAulasOnline[i].data.mes<data.mes)//se o mes for menor passa esse a ser a data
                {
                    data = vAulasOnline[i].data;
                }
                else if(vAulasOnline[i].data.mes==data.mes)//se o mes for igual comparamos o dia
                {
                    if(vAulasOnline[i].data.dia<data.dia)//comparamos o dia
                    {
                        data = vAulasOnline[i].data;
                    }
                }
            }
        }
    }

    for(i=0; i<indiceAulasOnline; i++)
    {
        if(compararDatas(vAulasOnline[i].data,data)==0 && vAulasOnline[i].estado==realizada)
        {
            printf("\nAula: %s na data %d-%d-%d",vAulasOnline[i].nome,vAulasOnline[i].data.dia,vAulasOnline[i].data.mes,vAulasOnline[i].data.ano);
        }
    }
    printf("\n");

}


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
