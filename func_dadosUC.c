#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_aux.h"



//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosUC e devolve a mesma
//alguns dos campos estao hardcoded fix later
//corrigir os printfs
dadosUC inserirDadosUC()
{
    dadosUC dadosDaUC;

    //ler condigo da uc de 0 a 39
    printf("Insira o codigo da Unidade Curricular (de 1 a 40):\n");
    dadosDaUC.codigoUC=lerInteiro(1,MAX_UCs);

    //ler nome da uc
    printf("Insira o nome da Unidade Curricular:\n");
    lerString(dadosDaUC.nome,MAX_STRING_NOME_AULA);

    //ler tipo (obrigatorio ou opcional)
    printf("Insira o tipo da Unidade Curricular 0-obrigat�rio ou 1-opcional:");
    dadosDaUC.tipoUC=lerInteiro(0,1);

    //semestre de 1 a 6
    printf("Insira o semestre correspondente:");
    dadosDaUC.semestre=lerInteiro(1,6);//hardcoded

    //regime diurno ou pos laboral
    printf("Insira o tipo de regime 0-diurno ou 1-p�s-laboral:");
    dadosDaUC.regime=lerInteiro(0,1);

    //pedir 3 numeros para T TP PL
    printf("Insira o numero de aulas Te�ricas:");
    dadosDaUC.quantidadeTipoAulas.T=lerInteiro(0,999);
    printf("Insira o numero de aulas Te�rico-Pr�ticas:");
    dadosDaUC.quantidadeTipoAulas.TP=lerInteiro(0,999);
    printf("Insira o numero de aulas Pr�tico-Laboratorial:");
    dadosDaUC.quantidadeTipoAulas.PL=lerInteiro(0,999);

    //pedir a duracao das aulas em minutos

    printf("Insira a dura��o das aulas Te�ricas (em minutos):");
    dadosDaUC.duracaoAulas.T=lerInteiro(1,999);

    printf("Insira a dura��o das aulas Te�rico-Pr�ticas (em minutos):");
    dadosDaUC.duracaoAulas.TP=lerInteiro(1,999);

    printf("Insira a duran��o das aulas Pr�tico-Laboratoriais (em minutos):");
    dadosDaUC.duracaoAulas.PL=lerInteiro(1,999);

    return dadosDaUC;
}

void alterarDadosUC(dadosUC *dadosDaUC)
{
    *dadosDaUC.codigoUC=lerInteiro(1,MAX_UCs);
}
