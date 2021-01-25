#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <stdlib.h>
#include "func_menu.h"
#include "func_dadosUC.h"
#include "func_dadosAulas.h"
#include "estruturas.h"
#include "estatisticas.h"

int menu_principal(dadosAula *vAulasOnline, int indiceAulasOnline, int indiceUC)  //funcao menu principal
{
    int escolha;

    printf("\n-------------------------------------------------------\n");
    printf("---------------------Menu Principal--------------------\n");
    printf("-------------------------------------------------------\n");
    estatisticasMenuPrincipal(vAulasOnline, indiceAulasOnline, indiceUC);
    printf("-------------------------------------------------------\n");
    printf("--> Informacao das UCs\n");
    printf("        1 -> Listas das UCs\n");
    printf("        2 -> Inserir Uc\n");
    printf("        3 -> Alterar UC\n");
    printf("        4 -> Eliminar UC\n\n");

    printf("--> Aulas Online\n");
    printf("        5 -> Agendar aula online\n");
    printf("        6 -> Registar acesso a aula online\n");
    printf("        7 -> Eliminar aula online\n");
    printf("        8 -> Alterar aula Agendada\n");
    printf("        9 -> Lista das aulas\n");
    printf("       10 -> registar inicio da aula\n");
    printf("       11 -> registar fim da aula\n\n");

    printf("12 -> Estatisticas\n");
    printf("13 -> Sair do programa e gravar modificacoes\n");
    printf("-------------------------------------------------------\n");
    printf("-------------------------------------------------------\n");
    printf("Selecione a opcao desejada ->");
    escolha = lerInteiro(MIN_MENU_PRINCIPAL,MAX_MENU_PRINCIPAL);

    return escolha;
}



//Informação das UCs
int menu_listaUcs(dadosUC vDadosUC[MAX_UCS], int indiceVetUC)  // funcao menu lista das UCs
{
    int escolha;

    printf("-------------------------------------------------------\n");
    printf("                  Lista das UCs                   \n");
    printf("-------------------------------------------------------\n");
    listarDadosUC(vDadosUC, indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("Selecione o codigo da UC para mais informacoes ou 0 para voltar->");

    escolha = lerInteiro(MIN_OPCAO_MENU_VOLTAR,indiceVetUC);

    return escolha;
}


int menu_alterarUC(dadosUC vDadosUC[MAX_UCS], int indiceVetUC)  // funcao menu alterar UC
{
    int escolha;

    printf("-------------------------------------------------------\n");
    printf("                Alterar UC             \n");
    printf("-------------------------------------------------------\n");
    listarDadosUC(vDadosUC, indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("Selecione o codigo da UC a alterar ou 0 para voltar->");

    escolha = lerInteiro(MIN_OPCAO_MENU_VOLTAR,indiceVetUC);

    return escolha;
}


int menu_eliminarUC(dadosUC vDadosUC[MAX_UCS], int indiceVetUC)  // funcao menu eliminar UC
{
    int escolha;

    printf("-------------------------------------------------------\n");
    printf("                 Eliminar UC                \n");
    printf("-------------------------------------------------------\n");
    listarDadosUC(vDadosUC, indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("Selecione o codigo da UC a eliminar ou 0 para voltar ->");

    escolha = lerInteiro(MIN_OPCAO_MENU_VOLTAR,indiceVetUC);

    return escolha;
}

//aula online

void menu_alterarAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA])
{
    int indice = -1;
    printf("-------------------------------------------------------\n");
    printf("                 Alterar aula                \n");
    printf("-------------------------------------------------------\n");
    listarDadosAula(vAulasOnline,indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("escreva o nome da aula a alterar->");
    do{

        lerString(escolha,MAX_STRING_NOME_AULA);
        indice = procurarNomeAula(vAulasOnline,indiceAulasOnline,escolha);
        if (indice==-1)
        {
            printf("\nNome de aula invalido, escreva o nome da aula a alterar ->");
        }

    }while(indice==-1);
}

int menu_listaAulasOnline(dadosAula *vAulasOnline, int indiceAulasOnline,char escolha[MAX_STRING_NOME_AULA])
{
    int indice;
    int doWhileFlag = 0;
    int returnValue= 0;
    printf("-------------------------------------------------------\n");
    printf("                 Lista das aulas online                \n");
    printf("-------------------------------------------------------\n");
    listarDadosAula(vAulasOnline,indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("escreva o nome da aula para mais informacoes ou 0 para sair->");

    do{
        doWhileFlag = 1;
        lerString(escolha,MAX_STRING_NOME_AULA);
        if(!strcmp(escolha,"0"))
        {
            doWhileFlag = 0;
        }
        else{
            indice = procurarNomeAula(vAulasOnline,indiceAulasOnline,escolha);
            if (indice==-1)
            {
                printf("\nNome de aula invalido, escreva o nome da aula valido ->");
            }
            else
            {
                doWhileFlag = 0;
                returnValue = vAulasOnline[indice].codigoUC;
            }
        }

    }while(doWhileFlag);

    return returnValue;
}

void menu_registarInicioAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA])
{
    int indice;
    int doWhileFlag = 1;
    printf("-------------------------------------------------------\n");
    printf("                 Iniciar aula                \n");
    printf("-------------------------------------------------------\n");
    //listar aulas
    listarDadosAula(vAulasOnline,indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("escreva o nome da aula a iniciar->");
    do{
        doWhileFlag = 0;
        lerString(escolha,MAX_STRING_NOME_AULA);
        indice = procurarNomeAula(vAulasOnline,indiceAulasOnline,escolha);
        if (indice!=-1)
        {
            if (vAulasOnline[indice].estado != agendada)
            {
                printf("\nAula invalida, aula nao esta agendada");
                doWhileFlag = 1;
            }
        }
        else
        {
            printf("\nAula nao encontrada.");
            doWhileFlag = 1;
        }

    }while(doWhileFlag);

}

void menu_registarFimAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA])
{
    int indice;
    int doWhileFlag = 1;
    printf("-------------------------------------------------------\n");
    printf("                 Finalizar aula                \n");
    printf("-------------------------------------------------------\n");
    listarDadosAula(vAulasOnline,indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("escreva o nome da aula a iniciar->");
    do{
        doWhileFlag = 0;
        lerString(escolha,MAX_STRING_NOME_AULA);
        indice = procurarNomeAula(vAulasOnline,indiceAulasOnline,escolha);
        if (indice!=-1)
        {
            if (vAulasOnline[indice].estado != decorrer)
            {
                printf("\nAula invalida, aula nao esta decorrer");
                doWhileFlag = 1;
            }
        }
        else
        {
            printf("\nAula nao encontrada.");
            doWhileFlag = 1;
        }

    }while(doWhileFlag);
}

// Estatísticas

int menu_estatisticas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceVetUC)  // funcao menu das estatísticas
{
    int escolha;

    printf("                      Estatisticas                     \n");
    printf("-------------------------------------------------------\n");
    printf("-->Media de presenças por aula:\n");
    presencasAulas(vAulasOnline, indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("-->Percentagem de UCs com aulas gravadas: \n");
    percentUCAulasGravadas(vAulasOnline, indiceAulasOnline, vetUC, indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("-->UCs com menor n de aulas realizadas: \n");
    ucsMenorQuantidadeAulasRealizadas(vAulasOnline, indiceAulasOnline, vetUC, indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("-->Tipo de aula com maior n de acesso as gravacoes: \n");
    quantidadeDeAulasPorTipo(vAulasOnline, indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("-->Aulas realizadas ha mais tempo: \n");
    listaDeAulasMaisVelhas(vAulasOnline, indiceAulasOnline);
    printf("-------------------------------------------------------\n");
    printf("-->Ranking: \n");
    listarRankingUC(vetUC,indiceVetUC,vAulasOnline,indiceAulasOnline);
    printf("\n-------------------------------------------------------\n");
    printf("0 -> Voltar\n");

    escolha = lerInteiro(0,0);

    return escolha;
}

int menu_confirmar()
{
    printf("\n0 para voltar ao menu principal ->");
    return lerInteiro(0,0);
}


void limpaEcra()
{
    int i;
    for(i=0; i<100; i++)
    {
        printf(" \n");
    }
}
