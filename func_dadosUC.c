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
    printf("Insira o tipo da Unidade Curricular 0-obrigatório ou 1-opcional:");
    dadosDaUC.tipoUC=lerInteiro(0,1);

    //semestre de 1 a 6
    printf("Insira o semestre correspondente:");
    dadosDaUC.semestre=lerInteiro(1,6);//hardcoded

    //regime diurno ou pos laboral
    printf("Insira o tipo de regime 0-diurno ou 1-pós-laboral:");
    dadosDaUC.regime=lerInteiro(0,1);

    //pedir 3 numeros para T TP PL
    printf("Insira o numero de aulas Teóricas:");
    dadosDaUC.quantidadeTipoAulas.T=lerInteiro(0,999);
    printf("Insira o numero de aulas Teórico-Práticas:");
    dadosDaUC.quantidadeTipoAulas.TP=lerInteiro(0,999);
    printf("Insira o numero de aulas Prático-Laboratorial:");
    dadosDaUC.quantidadeTipoAulas.PL=lerInteiro(0,999);

    //pedir a duracao das aulas em minutos

    printf("Insira a duração das aulas Teóricas (em minutos):");
    dadosDaUC.duracaoAulas.T=lerInteiro(1,999);

    printf("Insira a duração das aulas Teórico-Práticas (em minutos):");
    dadosDaUC.duracaoAulas.TP=lerInteiro(1,999);

    printf("Insira a duranção das aulas Prático-Laboratoriais (em minutos):");
    dadosDaUC.duracaoAulas.PL=lerInteiro(1,999);

    return dadosDaUC;
}

void alterarDadosUC(dadosUC *dadosDaUC)
{
    *dadosDaUC.codigoUC=lerInteiro(1,MAX_UCs);
}
