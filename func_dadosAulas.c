#include <stdio.h>
#include <string.h>

#include "func_dadosAulas.h"
#include "estruturas.h"
#include "func_aux.h"
#include "constantes.h"

void inserirDadosAula(){
    aulaOnline dadosAula;

   /**<  aulaOnline dadosAula; //declaraçao do tipo de aulaOnline
    tipoData teste;

    printf("Insira o nome da aula\n");
    lerString(dadosAula.nome, MAX_STRING_NOME_AULA);

    printf("Insira o codigo da UC correspondente\n");
    dadosAula.codigoUC = lerInteiro(MIN_UCS, MAX_UCS);

    //ler o tipo de aula (Teoricas, teorico-práticas ou práticas-laboratoriais)
    printf("Insira o tipo de aula: 0 - T, 1 - TP, 2 - PL \n");
    lerInteiro(MIN_TIPO_AULA, MAX_TIPO_AULA);

    printf("Insira o nome do docente\n");
    lerString(dadosAula.nomeDocente, MAX_STRING_NOME_DOCENTE); */


    lerNomeAula(dadosAulas)



}//FIM inserirDadosAula

void lerNomeAula(char nome[MAX_STRING_NOME_AULA])
{
    //ler nome da aula
    printf("Insira o nome da aula\n");
    lerString(nome, MAX_STRING_NOME_AULA);
}

int lerCodigoUC ()
{
    //ler codigo da UC
    printf("Insira o codigo da UC correspondente a aula\n");
    return lerInteiro(MIN_UCS, MAX_UCS);
}

int lerTipoAula(){
    //ler o tipo de aula -> T, TP ou PL
     printf("Insira o tipo de aula: 0 - T, 1 - TP, 2 - PL \n");
     return lerInteiro(MIN_TIPO_AULA, MAX_TIPO_AULA);
}
void lerNomeDocente(char nome[MAX_STRING_NOME_DOCENTE]){
    //ler nome do docente
    printf("Insira o nome do docente\n");
    lerString(nome,MAX_STRING_NOME_DOCENTE);
}

void lerDataAula(tipoData *data){
    //ler data da aula
    printf("Insira a data da aula\n");
    lerData(data);
}

