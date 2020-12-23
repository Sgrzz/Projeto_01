#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_aux.h"

int lerDadosCodigoUC()
{
    //ler condigo da uc de 1 a 40
    printf("Insira o codigo da Unidade Curricular (de 1 a 40):\n");
    return lerInteiro(1,MAX_UCs);
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
    return lerInteiro(0,1);
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
    return lerInteiro(0,1);
}

int lerQuantTipoAulas_T()
{
    printf("Insira o numero de aulas Teóricas:");
    return lerInteiro(0,999);
}

int lerQuantTipoAulas_TP()
{
    printf("Insira o numero de aulas Teórico-Práticas:");
    return lerInteiro(0,999);
}

int lerQuantTipoAulas_PL()
{
    printf("Insira o numero de aulas Prático-Laboratorial:");
    return lerInteiro(0,999);
}

int lerDuracaoAulas_T()
{
    printf("Insira a duração das aulas Teóricas (em minutos):");
    return lerInteiro(1,999);
}

int lerDuracaoAulas_TP()
{
    printf("Insira a duração das aulas Teórico-Práticas (em minutos):");
    return lerInteiro(1,999);
}

int lerDuracaoAulas_PL()
{
    printf("Insira a duranção das aulas Prático-Laboratoriais (em minutos):");
    return lerInteiro(1,999);
}

//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosUC e devolve a mesma
//alguns dos campos estao hardcoded fix later
//corrigir os printfs
dadosUC inserirDadosUC()
{
    dadosUC dadosDaUC;

    //ler condigo da uc de 0 a 39
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
    dadosDaUC.quantidadeTipoAulas.T = lerQuantTipoAulas_T();
    dadosDaUC.quantidadeTipoAulas.TP = lerQuantTipoAulas_TP();
    dadosDaUC.quantidadeTipoAulas.PL = lerQuantTipoAulas_PL();

    //pedir a duracao das aulas em minutos
    dadosDaUC.duracaoAulas.T = lerDuracaoAulas_T();
    dadosDaUC.duracaoAulas.TP = lerDuracaoAulas_TP();
    dadosDaUC.duracaoAulas.PL = lerDuracaoAulas_PL();

    return dadosDaUC;
}

void alterarDadosUC(dadosUC *dadosDaUC, int opcao)
{
 //   printf("Deseja alterar os dados da Unidade curricular? Se sim -1, se não-0");
 //   *dadosDaUC.codigoUC=lerInteiro(1,MAX_UCs);
    switch (opcao)
    {
        case 0:
        case 1:
            dadosDaUC->codigoUC=lerDadosCodigoUC();
            if (opcao != 0) break;
        case 2:
            lerDadosNomeUC(dadosDaUC.nome);
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
            dadosDaUC->regime=lerRegimeUC();
            if (opcao != 0) break;
    }

}
