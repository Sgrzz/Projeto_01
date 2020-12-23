#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>

int funcMenu_Principal()  //funcao menu principal
{


    system("cls"); // limpa ecrã

    printf("----------------------Menu Principal---------------------\n");
    printf("                        Projeto p1                       \n");
    printf("Quantidade de UCs:");
    printf("Quantidade de aulas agendadas:");
    printf("Quantidade de aulas gravadas:");
    printf("----------------------------------------------------------\n");
    printf("1 - Informação das UCs\n");
    printf("2 - Aulas Online\n");
    printf("3 - Informações das aulas\n");
    printf("4 - Alterar estado de aula\n ");
    printf("5 - Estatísticas\n");
    printf("6 - Voltar\n");

    escolha = lerInteiro(1,6);

    return escolha;
}

int funcMenu_infoUcs()  // funcao menu de informacao das UCs
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("             Informação das UCs                 ");
    printf("--------------------------------------------------");
    printf("1 - Inserir UC\n");
    printf("2 - Alterar UC\n");
    printf("3 - Eliminar aul\n");

    printf("4 - Lista das UCs\n");
    printf("5 - Voltar\n");

    return 0;
}

int funcMenu_alterarUC()  // funcao menu alterar UC
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Alterar aula             ");
    printf("--------------------------------------------");


    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");

    printf("3 - Voltar\n");

    return 0;
}


int funcMenu_alterarUcConfirmada()  // funcao menu alterar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Alterar aula             ");
    printf("--------------------------------------------");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}


int funcMenu_listaUCs()  // funcao menu da lista das UCs
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                   Informação das UCs                 ");
    printf("------------------------------------------------------");
    printf("Nº de aulas Teóricas: %d\n");
    printf("Nº de aulas Teórico-Práticas: %d\n");
    printf("Nº de aulas Prático.Laboratoriais: %d\n");
    printf("Tipo de aula:\n");
    printf("Hora de início da aula: \n");
    printf("------------------------------------------------------");
    printf("1 - Voltar");

    return 0;
}


int funcMenu_aulasOnline()  // funcao menu aulas online
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Informação das Aulas Online                ");
    printf("-----------------------------------------------------------");
    printf("Nª de estudantes: %d\n");
    printf("Quantidade de acesso às gravações: %d\n");
    printf("----------------------------------------------");
    printf("1 - Registar aulas online\n");
    printf("2 - Resgistar o acesso às aulas\n");
    printf("3 - Voltar");

    return 0;
}


int funcMenu_registarAula()  // funcao menu registar aulas online
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                    Registar aula              ");
    printf("-----------------------------------------------");
    printf("Insira o nº de estudante ");
    printf("Selecione a aula que pretende se registar");
    printf("Selecione o tipo de aula "); // T, TP, PL
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}


int funcMenu_registarAcessoAula()  // funcao menu registar acesso a aula
{

    int escolha;

    system("cls"); // limpa ecrã

    return 0;
}


int funcMenu_infoAulas()  // funcao menu informaçao das aulas
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("           informação das UCs         \n");
    printf("------------------------------------------");
    printf("1 - Inserir UC\n");
    printf("2 - Alterar UC\n");
    printf("3 - Lista das UCs");
    printf("4 - Voltar\n");

    return 0;
}


int funcMenu_alterarEstadoAula()  // funcao menu alterar estado da aula
{
    int escolha;

    system("cls"); // limpa ecrã

    return 0;
}

int funcMenu_estatísticas()  // funcao menu das estatísticas
{
    int escolha;

    system("cls"); // limpa ecrã

    return 0;
}




