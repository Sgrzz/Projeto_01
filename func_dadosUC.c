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
    printf("bota o codigo da uc sff (1-40)");
    dadosDaUC.codigoUC=lerInteiro(1,MAX_UCs);

    //ler nome da uc
    printf("nome da uc");
    lerString(dadosDaUC.nome,MAX_STRING_NOME_AULA);

    //ler tipo (obrigatorio ou opcional)
    printf("tipo de uc 0-obrigatorio 1-opcional");
    dadosDaUC.tipoUC=lerInteiro(0,1);

    //semestre de 1 a 6
    printf("semestre");
    dadosDaUC.semestre=lerInteiro(1,6);//hardcoded

    //regime diurno ou pos laboral
    printf("regime");
    dadosDaUC.regime=lerInteiro(0,1);

    //pedir 3 numeros para T TP PL
    printf("num T");
    dadosDaUC.quantidadeTipoAulas.T=lerInteiro(0,999);
    printf("num PL");
    dadosDaUC.quantidadeTipoAulas.PL=lerInteiro(0,999);
    printf("num TP");
    dadosDaUC.quantidadeTipoAulas.TP=lerInteiro(0,999);

    //pedir a duracao das aulas em minutos
    printf("duracao das aulas em minutos");
    dadosDaUC.duracaoAulas=lerInteiro(1,999);


    printf("A Leila esteve aqui!");

    return dadosDaUC;
}


