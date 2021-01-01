#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_aux.h"
#include "func_dadosUC.h"

int lerDadosCodigoUC()
{
    //ler condigo da uc de 1 a 40
    printf("Insira o codigo da Unidade Curricular (de 1 a 40):\n");
    return lerInteiro(MIN_UCS,MAX_UCS);
}

void lerDadosNomeUC(char nome[MAX_STRING_NOME_AULA])
{
    //ler nome da uc
    printf("Insira o nome da Unidade Curricular:\n");
    lerString(nome,MAX_STRING_NOME_AULA);
}

int lerTipoUC()
{
    //ler tipo (obrigatorio ou opcional)
    printf("Insira o tipo da Unidade Curricular 0-obrigat�rio ou 1-opcional:");
    return lerInteiro(MIN_TIPO_UCS,MAX_TIPO_UCS);
}

int lerSemestreUC()
{
    printf("Insira o semestre correspondente:");
    return lerInteiro(MIN_SEMESTRES,MAX_SEMESTRES);
}

int lerRegimeUC()
{
    //regime diurno ou pos laboral
    printf("Insira o tipo de regime 0-diurno ou 1-p�s-laboral:");
    return lerInteiro(MIN_REGIME_UCS,MAX_REGIME_UCS);
}

int lerQuantTipoAulas_T()
{
    printf("Insira o numero de aulas Teóricas:");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_T,MAX_QUANT_TIPO_AULAS_T);
}

int lerQuantTipoAulas_TP()
{
    printf("Insira o numero de aulas Teórico-Práticas:");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_TP,MAX_QUANT_TIPO_AULAS_TP);
}

int lerQuantTipoAulas_PL()
{
    printf("Insira o numero de aulas Prático-Laboratorial:");
    return lerInteiro(MIN_QUANT_TIPO_AULAS_PL,MAX_QUANT_TIPO_AULAS_PL);
}

int lerDuracaoAulas_T()
{
    printf("Insira a duração das aulas Teóricas (em minutos):");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_T,MAX_DURAC_TIPO_AULAS_T);
}

int lerDuracaoAulas_TP()
{
    printf("Insira a duração das aulas Teórico-Práticas (em minutos):");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_TP,MAX_DURAC_TIPO_AULAS_TP);
}

int lerDuracaoAulas_PL()
{
    printf("Insira a duranção das aulas Prático-Laboratoriais (em minutos):");
    return lerInteiro(MIN_DURAC_TIPO_AULAS_PL,MAX_DURAC_TIPO_AULAS_PL);
}



//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosUC e devolve a mesma
//alguns dos campos estao hardcoded fix later
//corrigir os printfs
dadosUC inserirDadosUC()
{
    dadosUC dadosDaUC;

    //ler codigo UC
    dadosDaUC.codigoUC=lerDadosCodigoUC();

    //ler nome da uc
    lerDadosNomeUC(dadosDaUC.nome);

    //ler tipo (obrigatorio ou opcional)
    dadosDaUC.tipoUC=lerTipoUC();

    //semestre de 1 a 6
    dadosDaUC.semestre=lerSemestreUC();

    //regime diurno ou pos laboral
    dadosDaUC.regime=lerRegimeUC();

    //pedir 3 numeros para T TP PL
    dadosDaUC.quantTipoAulas.T = lerQuantTipoAulas_T();
    dadosDaUC.quantTipoAulas.TP = lerQuantTipoAulas_TP();
    dadosDaUC.quantTipoAulas.PL = lerQuantTipoAulas_PL();

    //pedir a duracao das aulas em minutos
    dadosDaUC.duracaoAulas.T = lerDuracaoAulas_T();
    dadosDaUC.duracaoAulas.TP = lerDuracaoAulas_TP();
    dadosDaUC.duracaoAulas.PL = lerDuracaoAulas_PL();

    return dadosDaUC;
}


//altera os dados de uma UC por ponteiro, opcao define qual o campo que é modificado, 0 para todos
void alterarDadosUC(dadosUC *dadosDaUC, int opcao)
{
    switch (opcao)
    {
    case 0:
    case 1:
        dadosDaUC->codigoUC=lerDadosCodigoUC();
        if (opcao != 0) break;
    case 2:
        lerDadosNomeUC(dadosDaUC->nome);
        if (opcao != 0) break;
    case 3:
        dadosDaUC->tipoUC=lerTipoUC();
        if (opcao != 0) break;
    case 4:
        dadosDaUC->semestre=lerSemestreUC();
        if (opcao != 0) break;
    case 5:
        dadosDaUC->regime=lerRegimeUC();
        if (opcao != 0) break;
    case 6:
        dadosDaUC->quantTipoAulas.T = lerQuantTipoAulas_T();
        if (opcao != 0) break;
    case 7:
        dadosDaUC->quantTipoAulas.TP = lerQuantTipoAulas_TP();
        if (opcao != 0) break;
    case 8:
        dadosDaUC->quantTipoAulas.PL = lerQuantTipoAulas_PL();
        if (opcao != 0) break;
    case 9:
        dadosDaUC->duracaoAulas.T = lerDuracaoAulas_T();
        if (opcao != 0) break;
    case 10:
        dadosDaUC->duracaoAulas.TP = lerDuracaoAulas_TP();
        if (opcao != 0) break;
    case 11:
        dadosDaUC->duracaoAulas.PL = lerDuracaoAulas_PL();
        if (opcao != 0) break;
    }

}

//ordena o array do tipo dadosUC pelo codigo da uc
//requer o array de tipo dadosUC e um int com o numero de pos preenchidas
void ordenarDadosUC(dadosUC arrayUC[MAX_UCS], int posArray)
{
    dadosUC TempUC;
    int x,y;

    //percorre o array inteiro
    for (x = 0; x < posArray; ++x)
    {
        //percorre o array a começar pela ultima posição
        for (y = x + 1; y < posArray; ++y)
        {
            //se o codigo da uc for infeiror troca a posição
            if (arrayUC[x].codigoUC > arrayUC[y].codigoUC)
            {
                TempUC = arrayUC[x];
                arrayUC[x] = arrayUC[y];
                arrayUC[y] = TempUC;
            }
        }
    }
}

