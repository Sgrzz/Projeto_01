#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_aux.h"
#include "func_dadosUC.h"
#include "func_dadosAulas.h"


//pede e verifica se o codigoUC é unico
int lerDadosCodigoUC(dadosUC dadosDaUC[MAX_UCS], int posIndiceArray)
{
    int codigoUC;
    if(posIndiceArray == 0)
    {
        codigoUC = 1;
    }
    else
    {
        codigoUC = dadosDaUC[posIndiceArray-1].codigoUC + 1;
    }
        printf("%d",posIndiceArray);
    return codigoUC;
}

void lerDadosNomeUC(char nome[MAX_STRING_NOME_UC])
{
    //ler nome da uc
    printf("\nInsira o nome da Unidade Curricular -> ");
    lerString(nome,MAX_STRING_NOME_UC);
}

int lerTipoUC()
{
    //ler tipo (obrigatorio ou opcional)
    printf("\nInsira o tipo da Unidade Curricular 0-obrigatorio ou 1-opcional -> ");
    return lerInteiro(MIN_TIPO_UCS,MAX_TIPO_UCS);
}

int lerSemestreUC()
{
    printf("\nInsira o semestre correspondente (1 - 6) ->");
    return lerInteiro(MIN_SEMESTRES,MAX_SEMESTRES);
}

int lerRegimeUC()
{
    //regime diurno ou pos laboral
    printf("\nInsira o tipo de regime 0-diurno ou 1-pos-laboral ->");
    return lerInteiro(MIN_REGIME_UCS,MAX_REGIME_UCS);
}

int lerQuantTipoAulas_T()
{
    printf("\nInsira o numero de aulas Teoricas ->");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_T,MAX_QUANT_TIPO_AULAS_T);
}

int lerQuantTipoAulas_TP()
{
    printf("\nInsira o numero de aulas Teorico-Praticas ->");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_TP,MAX_QUANT_TIPO_AULAS_TP);
}

int lerQuantTipoAulas_PL()
{
    printf("\nInsira o numero de aulas Pratico-Laboratorial ->");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_PL,MAX_QUANT_TIPO_AULAS_PL);
}

int lerDuracaoAulas_T()
{
    printf("\nInsira a duracao das aulas Teoricas (em minutos) ->");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_T,MAX_DURAC_TIPO_AULAS_T);
}

int lerDuracaoAulas_TP()
{
    printf("\nInsira a duracao das aulas Teorico-Praticas (em minutos) ->");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_TP,MAX_DURAC_TIPO_AULAS_TP);
}

int lerDuracaoAulas_PL()
{
    printf("\nInsira a durancao das aulas Pratico-Laboratoriais (em minutos) ->");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_PL,MAX_DURAC_TIPO_AULAS_PL);
}



//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosUC
//e devolve a mesma por o array uc, requer a posIndiceArray para verificar se o codigo é unico e para o incrementar
void inserirDadosUC(dadosUC dadosDaUC[MAX_UCS], int *posIndiceArray)
{
    if (*posIndiceArray==MAX_UCS)
    {
        printf("\nMaximo de uc's alcancado");
    }
    else
    {

        //ler codigo UC
        dadosDaUC[*posIndiceArray].codigoUC=lerDadosCodigoUC(dadosDaUC,*posIndiceArray);

        //ler nome da uc
        lerDadosNomeUC(dadosDaUC[*posIndiceArray].nome);

        //ler tipo (obrigatorio ou opcional)
        dadosDaUC[*posIndiceArray].tipoUC=lerTipoUC();

        //semestre de 1 a 6
        dadosDaUC[*posIndiceArray].semestre=lerSemestreUC();

        //regime diurno ou pos laboral
        dadosDaUC[*posIndiceArray].regime=lerRegimeUC();

        //pedir quantidade de aulas para cada tipo T TP PL
        dadosDaUC[*posIndiceArray].quantTipoAulas.T = lerQuantTipoAulas_T();
        dadosDaUC[*posIndiceArray].quantTipoAulas.TP = lerQuantTipoAulas_TP();
        dadosDaUC[*posIndiceArray].quantTipoAulas.PL = lerQuantTipoAulas_PL();

        //pedir a duracao das aulas em minutos
        dadosDaUC[*posIndiceArray].duracaoAulas.T = lerDuracaoAulas_T();
        dadosDaUC[*posIndiceArray].duracaoAulas.TP = lerDuracaoAulas_TP();
        dadosDaUC[*posIndiceArray].duracaoAulas.PL = lerDuracaoAulas_PL();

        (*posIndiceArray)++;
    }
}


//altera os dados de uma UC, opcao define qual o campo que é modificado, 0 para todos
//requer o array dos dados, a pos dos elementos, o codigo da uc a ser alterada
void alterarDadosUC(dadosUC arrayDadosDaUC[MAX_UCS],int posIndiceArray,int codigoUC, int opcao)
{
    dadosUC dadosDaUC;
    int posIndiceArrayDadosUC;

    //verifica se a pos existe no array
    posIndiceArrayDadosUC = procurarDadosUC(arrayDadosDaUC,posIndiceArray,codigoUC);

    if (posIndiceArrayDadosUC != -1)
    {
        dadosDaUC = arrayDadosDaUC[posIndiceArrayDadosUC];

        switch (opcao)
        {
        case 0:
            lerDadosNomeUC(dadosDaUC.nome);
            dadosDaUC.tipoUC=lerTipoUC();
            dadosDaUC.semestre=lerSemestreUC();
            dadosDaUC.regime=lerRegimeUC();
            dadosDaUC.quantTipoAulas.T = lerQuantTipoAulas_T();
            dadosDaUC.quantTipoAulas.TP = lerQuantTipoAulas_TP();
            dadosDaUC.quantTipoAulas.PL = lerQuantTipoAulas_PL();
            dadosDaUC.duracaoAulas.T = lerDuracaoAulas_T();
            dadosDaUC.duracaoAulas.TP = lerDuracaoAulas_TP();
            dadosDaUC.duracaoAulas.PL = lerDuracaoAulas_PL();
            break;
        case 1:
            lerDadosNomeUC(dadosDaUC.nome);
            break;
        case 2:
            dadosDaUC.tipoUC=lerTipoUC();
            break;
        case 3:
            dadosDaUC.semestre=lerSemestreUC();
            break;
        case 4:
            dadosDaUC.regime=lerRegimeUC();
            break;
        case 5:
            dadosDaUC.quantTipoAulas.T = lerQuantTipoAulas_T();
            break;
        case 6:
            dadosDaUC.quantTipoAulas.TP = lerQuantTipoAulas_TP();
            break;
        case 7:
            dadosDaUC.quantTipoAulas.PL = lerQuantTipoAulas_PL();
            break;
        case 8:
            dadosDaUC.duracaoAulas.T = lerDuracaoAulas_T();
            break;
        case 9:
            dadosDaUC.duracaoAulas.TP = lerDuracaoAulas_TP();
            break;
        case 10:
            dadosDaUC.duracaoAulas.PL = lerDuracaoAulas_PL();
            break;
        }

        arrayDadosDaUC[posIndiceArrayDadosUC] = dadosDaUC;
    }
}

//recebe array tipo dadosUC a pos do array e o codigo para comparar
//devolve a pos onde encontrou o codigoUC, se n devolve -1
int procurarDadosUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray, int codigoUC)
{
    int i,posDadosUC=-1;

    for (i = 0; i < posIndiceArray; ++i)//percorre o array
    {
        if (codigoUC==arrayUC[i].codigoUC) //se o codigo da uc existir devolve a pos do elemento
        {
            posDadosUC = i;
            i=posIndiceArray;
        }
    }

    return posDadosUC;
}

//ordena o array do tipo dadosUC pelo codigo da uc
//requer o array de tipo dadosUC e um int com o numero de pos preenchidas
void ordenarDadosUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray)
{
    dadosUC auxUC;
    int x,y;

    //percorre o array inteiro
    for (x = 0; x < posIndiceArray; ++x)
    {
        //percorre o array a começar pela ultima posição
        for (y = x + 1; y < posIndiceArray; ++y)
        {
            //se o codigo da uc for infeiror troca a posição
            if (arrayUC[x].codigoUC > arrayUC[y].codigoUC)
            {
                auxUC = arrayUC[x];
                arrayUC[x] = arrayUC[y];
                arrayUC[y] = auxUC;
            }
        }
    }
}

//escreve no ecra todos os dados do array tipo dadosUC por odem do seu indice
//
void listarDadosUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray)
{
    int i;

    char stringTipo[MAX_STRING],stringRegime[MAX_STRING];

    if (posIndiceArray)
    {


        printf("Codigo\tNome\t\ttipo\tsemestre\tregime\tquantidade: T\tTP\tPL\tduracao: T\tTP\tPL\n");
        for (i=0; i<posIndiceArray; i++)
        {

            switch(arrayUC[i].tipoUC)
            {
                case obrigatoria:
                    strcpy(stringTipo,"obrigatorio");
                    break;
                case opcional:
                    strcpy(stringTipo,"opcional");
                    break;
            }

            switch(arrayUC[i].regime)
            {
                case diurno:
                    strcpy(stringRegime,"diurno");
                    break;
                case poslaboral:
                    strcpy(stringRegime,"pos laboral");
                    break;
            }


            printf("%6d \t %8s \t %s \t \t %d \t %s \t %d \t %d \t %d \t %d \t %d \t %d \n",
                   arrayUC[i].codigoUC, arrayUC[i].nome, stringTipo, arrayUC[i].semestre, stringRegime, arrayUC[i].quantTipoAulas.T,
                   arrayUC[i].quantTipoAulas.TP, arrayUC[i].quantTipoAulas.PL, arrayUC[i].duracaoAulas.T,arrayUC[i].duracaoAulas.TP,arrayUC[i].duracaoAulas.PL);
        }
    }
    else
    {
        printf("\nAinda nao existem UC's");
    }
}


void removerDadosUC(dadosUC arrayUC[MAX_UCS], int *posIndiceArray, int codigoUC)
{
    int indiceDadosUC;
    indiceDadosUC = procurarDadosUC(arrayUC,*posIndiceArray,codigoUC);

    if (indiceDadosUC != -1)
    {
        arrayUC[indiceDadosUC] = arrayUC[*posIndiceArray-1];
        (*posIndiceArray)--;
        ordenarDadosUC(arrayUC,*posIndiceArray);
    }
}

void listarNomeAulasUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray, int codigoUC)
{
    int indice;

    indice = procurarDadosUC(arrayUC,posIndiceArray,codigoUC);

    if (indice==-1)
    {
        printf("\nindice invalido.");
    }
    else
    {
        printf("\nNome: %s Por agendar: T:%d TP:%d PL:%d",arrayUC[indice].nome,arrayUC[indice].quantTipoAulas.T,arrayUC[indice].quantTipoAulas.TP,arrayUC[indice].quantTipoAulas.PL);
    }
}

void listarRankingUC(dadosUC arrayUC[MAX_UCS], int indiceUC, dadosAula *arrayAula, int indiceAula)
{
    //somar os acessos as gravacoes
    //por cada uc
    //reorder an array of ints with the index

    typedef struct{
        int totalV;
        int indice;
    }somaGravacoesUC;

    int i,x,indice;

    somaGravacoesUC soma[MAX_UCS],somaAux;

    for(i=0;i<MAX_UCS;i++)
    {
        soma[i].totalV = 0;
        soma[i].indice = i;
    }

    for(i=0;i<indiceAula;i++)
    {
        indice = procurarDadosUC(arrayUC,indiceUC,arrayAula[i].codigoUC);
        soma[indice].totalV += arrayAula[i].numEstudantesOffline;
        soma[indice].indice = indice;
    }

    for(i=0;i<indiceUC;i++)
    {

        for(x=i;x<indiceUC;x++)
        {
            if(soma[i].totalV<soma[x].totalV)
            {
                somaAux = soma[x];
                soma[x] = soma[i];
                soma[i] = somaAux;
            }
        }
    }

    for(i=0;i<indiceUC;i++)
    {
        printf("\nUC: %s total de visualizacoes:%d",arrayUC[soma[i].indice].nome,soma[i].totalV);
    }
    printf("\n");

}
