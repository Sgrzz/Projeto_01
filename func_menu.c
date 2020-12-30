#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>
#include "Func_menu.h"
#include "func_dadosUC.h"

void funcMenu_principal()  //funcao menu principal
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("\n---------------------Menu Principal--------------------\n");
        //printf("\n                        Projeto p1                       \n");
        printf("Quantidade de UCs: \n");
        printf("Quantidade de aulas agendadas: \n");
        printf("Quantidade de aulas gravadas: \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Informação das UCs\n");
        printf("2 - Aulas Online\n");
        printf("3 - Informações das aulas\n");
        printf("4 - Alterar estado de aula\n");
        printf("5 - Estatisticas\n");
        printf("6 - Sair do programa\n");
        printf("Selecione a opção desejada.\n");
        escolha = lerInteiro(1,6);

        switch(escolha)
        {

        case 1: //Informação das UCs
            funcMenu_infoUcs();
            break;

        case 2: //Aulas Online
            funcMenu_aulasOnline();
            break;

        case 3: //Informações das aulas
            funcMenu_infoAulas();
            break;

            //case 4: //Alterar estado de aula

            break;
        case 5: //Estatísticas
            funcMenu_estatisticas();
            break;

        case 6: //Sair do programa

            break;

            //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch


    }
    while(escolha!=6);
}




void funcMenu_infoUcs()  // funcao menu de informacao das UCs
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("             Informação das UCs                 \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Lista das UCs\n");
        printf("2 - Inserir UC\n");
        printf("3 - Modificar UC\n");
        printf("4 - Voltar\n");
        escolha = lerInteiro(1,4);

        switch(escolha)
        {

        case 1: // Lista das UCs
            funcMenu_listaUcs();
            break;

        case 2: //Inserir UC
            funcMenu_inserirUC();
            break;

        case 3: //Modificar UC
            funcMenu_modificarUC();
            break;

        case 4: //Voltar
            funcMenu_principal();
            break;

            //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=4);
}


void funcMenu_listaUcs()  // funcao menu lista das UCs
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                  Lista das UCs                   \n");
        printf("-------------------------------------------------------\n");
        printf("Selecione uma UC para mais ifnromações\n");
        printf("1 - UC pretendida\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //UC pretendida

            break;

        case 2: //Voltar para o menu inf das UCs
            funcMenu_infoUcs();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_UCselecionada()  // funcao menu de informação referente a UC selecionada
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("             Informação da UC - nome da uc            \n");
        printf("-------------------------------------------------------\n");
        printf("Nº de aulas online realizadas:\n");
        printf("\tAulas Teóricas - %d\n");
        printf("\tAulas Teórico-Práticas - %d\n");
        printf("\tAulas Prático-Laboratoriais - %d\n");
        printf("Aulas agendadas:\n");
        printf("\tTipo de aula -\n");
        printf("\tHora de início da aula: \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Voltar");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar para a lista das UCs
            funcMenu_listaUcs();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=1);
}


void funcMenu_inserirUC()  // funcao menu inserir UC
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Inserir UC            \n");
        printf("-------------------------------------------------------\n");

        // dadosUC inserirDadosUC()
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Volta para o menu info das UCs
            funcMenu_infoUcs();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=1);
}


void funcMenu_modificarUC()  // funcao menu modificar UC
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                 Modificar UC                \n");
        printf("-------------------------------------------------------\n");

        printf("1 - Alterar UC\n");
        printf("2 - Eliminar UC\n");
        printf("3 - Voltar\n");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Alterar UC
            funcMenu_alterarUC();
            break;

        case 2: //Eliminar UC
            funcMenu_eliminarUC();
            break;

        case 3: //Volta para o menu info das UCs
            funcMenu_infoUcs();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=3);
}


void funcMenu_alterarUC()  // funcao menu alterar UC
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Alterar UC             \n");
        printf("-------------------------------------------------------\n");


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

        printf("1 - Selecione UC a alterar\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //UC selecionada a alterar
            //alterarDadosUC(*dadosDaUC);
            break;

        case 2: //Volta para o menu modificar UC
            funcMenu_modificarUC();
            break;


        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_alterarUcConfirmada()  // funcao menu alterar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Alterar UC             \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Confirmar\n");
        printf("2 - Cancelar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar
            funcMenu_alterarUcConfirmada();
            break;

        case 2: //Cancelar e volta ao menu anterior
            funcMenu_alterarUC();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_eliminarUC()  // funcao menu eliminar UC
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                 Eliminar UC                \n");
        printf("-------------------------------------------------------\n");

        printf("1 - Selecione UC a eliminar\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //UC selecionada
            funcMenu_eliminarUcConfirmar();
            break;

        case 2: //Voltar
            funcMenu_modificarUC();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_eliminarUcConfirmar()  // funcao menu eliminar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Eliminar UC             \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Confirmar\n");
        printf("2 - Cancelar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancela e volta para a página anterior
            funcMenu_eliminarUC();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}





void funcMenu_aulasOnline()  // funcao menu aulas online
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                       Aulas Online                        \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Agendar aulas online\n");
        printf("2 - Resgistar acesso a aula online\n");
        printf("3 - Voltar\n");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Agendar aulas online
            funcMenu_agendarAula();
            break;

        case 2: //Resgistar acesso a aula online
            funcMenu_registarAcessoAula();
            break;

        case 3: //Voltar
            funcMenu_principal();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=3);
}


void funcMenu_agendarAula()  // funcao menu agendar aula online
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                    Agendar aula               \n");
        printf("-------------------------------------------------------\n");
        printf("Insira o nº de estudante: \n");
        printf("Selecione a aula que pretende se registar:\n");
        printf("Selecione o tipo de aula: \n"); // T, TP, PL
        printf("1 - Confirmar\n");
        printf("2 - Cancelar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancela e volta à página anterior
            funcMenu_aulasOnline();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_registarAcessoAula()  // funcao menu registar acesso a aula
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("           Registar Acesso a Aula Online       \n");
        printf("-------------------------------------------------------\n");
        printf("Insira o código da UC: \n");
        printf("Indique a aula que pretende se registar:\n");
        printf("Selecione o tipo de aula: \n");
        printf("Insira o nº de estudante: \n");
        printf("1 - Confirmar\n");
        printf("2 - Cancelar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar
            funcMenu_aulasOnline();
            break;

        case 2: //Cancelar e volta á página anterior
            funcMenu_aulasOnline();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}

void funcMenu_modificarAula()  // funcao menu modificar aula
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                 Modificar Aula                \n");
        printf("-------------------------------------------------------\n");

        printf("1 - Alterar aula\n");
        printf("2 - Eliminar aula\n");
        printf("3 - Voltar\n");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Alterar aula
            funcMenu_alterarAula();
            break;

        case 2: //Eliminar aula
            funcMenu_eliminarAula();
            break;

        case 3: //Voltar
            funcMenu_aulasOnline();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=3);
}

void funcMenu_alterarAula()  // funcao menu alterar aula
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Alterar Aula             \n");
        printf("-------------------------------------------------------\n");

        printf("Selecione aula a alterar: \n");
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

        printf("1 - Aula selecionada\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Aula selecionada
            funcMenu_alterarAulaConfirmada();
            break;

        case 2: //Voltar
            funcMenu_modificarAula();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_alterarAulaConfirmada()  // funcao menu alterar aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Alterar Aula                \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Confirmar\n");
        printf("2 - Cancelar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //
            funcMenu_alterarAula();
            break;

        case 2: //Cancela e volta á página anterior
            funcMenu_modificarAula();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_eliminarAula()  // funcao menu eliminar Aula
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                 Eliminar Aula                \n");
        printf("-------------------------------------------------------\n");

        printf("");
        printf("");
        printf("");
        printf("");


        printf("Selecione a aula que pretende eliminar:\n");
        printf("1 - Eliminar aula\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Eliminar aula
            funcMenu_eliminarAulaConfirmar();
            break;

        case 2: //Voltar
            funcMenu_modificarAula();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}


void funcMenu_eliminarAulaConfirmar()  // funcao menu eliminar Aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Eliminar Aula             \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar
            funcMenu_eliminarAula();
            break;

        case 2: //Cancela e volta á página anterior
            funcMenu_modificarAula();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}




void funcMenu_infoAulas()  // funcao menu informaçao das aulas
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("           informação das UCs         \n");
        printf("-------------------------------------------------------\n");
        printf("1 - Lista das aulas online\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Lista das aulas online
            funcMenu_listaAulas();
            break;

        case 2: //Voltar
            funcMenu_principal();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}

void funcMenu_listaAulas()  // funcao menu Lista das Aulas
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("              Lista das Aulas           \n");
        printf("-------------------------------------------------------\n");
        printf("\n");// apresentar lista das aulas sem as t,tp e pl
        printf("\n");
        printf("\n");
        printf("-------------------------------------------------------\n");
        printf("1 - Selecione as aulas pretendidas\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Selecione as aulas pretendidas
            funcMenu_aulaSelecionada();
            break;

        case 2: //Voltar
            funcMenu_infoAulas();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=2);
}



void funcMenu_aulaSelecionada()  // funcao menu Aula Selecionada
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("              Aula Selecionada - X           \n");
        printf("-------------------------------------------------------\n");
        printf("UC pertencente - \n");
        printf("Data:\n");
        printf("Hora de inicio:\n");
        printf("Duração:\n");
        printf("Nº de estudantes inscritos:\n");
        printf("Nº de estudantes presentes:\n");
        printf("Nº de acesso às gravações:\n");
        //printf("Nº de aulas T:\n");
        //printf("Nº de aulas TP:\n");
        //printf("Nº de aulas PL:\n");
        printf("-------------------------------------------------------\n");
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar
            funcMenu_listaAulas();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=1);
}

void funcMenu_estatisticas()  // funcao menu das estatísticas
{
    int escolha;

    do
    {
        system("cls"); // limpa ecrã

        printf("                Estatísticas            \n");
        printf("-------------------------------------------------------\n");
        printf("Média de presenças por aula:\n");
        printf("Percentagem de UCs com aulas gravadas:\n");
        printf("UCs com menor nº de aulas realizadas:\n");
        printf("Tipo de aula com maior nº de acesso às gravações\n");
        printf("Aulas realizadas há mais tempo:\n");
        printf("\n");

        printf("-------------------------------------------------------\n");
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar
            funcMenu_principal();
            break;

        //default caso o utilizador digite uma opção inválida
        default:
            printf("Opção inválida! Introduza nova opção.");

        }//switch

    }
    while(escolha!=1);
}
