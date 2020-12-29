#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>

int funcMenu_Principal()  //funcao menu principal
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("----------------------Menu Principal---------------------\n");
        printf("                        Projeto p1                       \n");
        printf("Quantidade de UCs:");
        printf("Quantidade de aulas agendadas:");
        printf("Quantidade de aulas gravadas:");
        printf("----------------------------------------------------------\n");
        printf("1 - Informa��o das UCs\n");
        printf("2 - Aulas Online\n");
        printf("3 - Informa��es das aulas\n");
        printf("4 - Alterar estado de aula\n ");
        printf("5 - Estat�sticas\n");
        printf("6 - Sair do programa\n");

        escolha = lerInteiro(1,6);

        switch(escolha)
        {

        case 1: //Informa��o das UCs

            break;

        case 2: //Aulas Online

            break;

        case 3: //Informa��es das aulas

            break;

        case 4: //Alterar estado de aula

            break;

        case 5: //Estat�sticas

            break;

        case 6: //Sair do programa

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>6);


    return escolha;
}





int funcMenu_infoUcs()  // funcao menu de informacao das UCs
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {

        printf("             Informa��o das UCs                 ");
        printf("--------------------------------------------------");
        printf("1 - Lista das UCs\n");
        printf("2 - Inserir UC\n");
        printf("3 - Modificar UC\n");
        printf("4 - Voltar\n");

        escolha = lerInteiro(1,4);

        switch(escolha)
        {

        case 1: //Lista das UCs

            break;

        case 2: //Inserir UC

            break;

        case 3: //Modificar UC

            break;

        case 4: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>4);

    return 0;
}


int funcMenu_listaUcs()  // funcao menu lista das UCs
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                  Lista das UCs                   ");
        printf("--------------------------------------------------");
        printf("Para mais informa��es referentes a uma UC selecione UC pretendida\n");
        printf("1 - UC pretendida\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //UC pretendida

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_UCselecionada()  // funcao menu de informa��o referente a UC selecionada
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("             Informa��o da UC - nome da uc            ");
        printf("------------------------------------------------------");
        printf("N� de aulas online realizadas:\n");
        printf("\tAulas Te�ricas - %d\n");
        printf("\tAulas Te�rico-Pr�ticas - %d\n");
        printf("\tAulas Pr�tico-Laboratoriais - %d\n");
        printf("Aulas agendadas:\n");
        printf("\tTipo de aula -\n");
        printf("\tHora de in�cio da aula: \n");
        printf("------------------------------------------------------");
        printf("1 - Voltar");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha!=1);


    return 0;
}


int funcMenu_inserirUC()  // funcao menu inserir UC
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Inserir UC            ");
        printf("--------------------------------------------");

        // dadosUC inserirDadosUC()
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha!=1);



    return 0;
}


int funcMenu_modificarUC()  // funcao menu modificar UC
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                 Modificar UC                ");
        printf("--------------------------------------------");

        printf("1 - Alterar UC\n");
        printf("2 - Eliminar UC\n");
        printf("3 - Voltar\n");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Alterar UC

            break;

        case 2: //Eliminar UC

            break;

        case 3: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>3);


    return 0;
}


int funcMenu_alterarUC()  // funcao menu alterar UC
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Alterar UC             ");
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

        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha!=1);


    return 0;
}


int funcMenu_alterarUcConfirmada()  // funcao menu alterar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Alterar UC             ");
        printf("--------------------------------------------");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancelar e volta ao menu anterior

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_eliminarUC()  // funcao menu eliminar UC
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                 Eliminar UC                ");
        printf("--------------------------------------------");

        printf("1 - Selecione UC a eliminar\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //UC selecionada

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_eliminarUcConfirmar()  // funcao menu eliminar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Eliminar UC             ");
        printf("--------------------------------------------");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}





int funcMenu_aulasOnline()  // funcao menu aulas online
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                       Aulas Online                        ");
        printf("-----------------------------------------------------------");
        printf("1 - Agendar aulas online\n");
        printf("2 - Resgistar acesso a aula online\n");
        printf("3 - Voltar");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Agendar aulas online

            break;

        case 2: //Resgistar acesso a aula online

            break;

        case 3: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>3);


    return 0;
}


int funcMenu_agendarAula()  // funcao menu agendar aula online
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                    Agendar aula               ");
        printf("-----------------------------------------------");
        printf("Insira o n� de estudante: \n");
        printf("Selecione a aula que pretende se registar:\n");
        printf("Selecione o tipo de aula: \n"); // T, TP, PL
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancela e volta � p�gina anterior

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_registarAcessoAula()  // funcao menu registar acesso a aula
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("           Registar Acesso a Aula Online       ");
        printf("-----------------------------------------------");
        printf("Insira o c�digo da UC: \n");
        printf("Indique a aula que pretende se registar:\n");
        printf("Selecione o tipo de aula: \n");
        printf("Insira o n� de estudante: \n");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancelar e vola � p�gina anterior

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}

int funcMenu_modificarAula()  // funcao menu modificar aula
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                 Modificar Aula                ");
        printf("--------------------------------------------");

        printf("1 - Alterar aula\n");
        printf("2 - Eliminar aula\n");
        printf("3 - Voltar\n");

        escolha = lerInteiro(1,3);

        switch(escolha)
        {

        case 1: //Alterar aula

            break;

        case 2: //Eliminar aula

            break;

        case 3: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>3);

    return 0;
}

int funcMenu_alterarAula()  // funcao menu alterar aula
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Alterar Aula             ");
        printf("--------------------------------------------");

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

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_alterarAulaConfirmada()  // funcao menu alterar aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Alterar Aula                ");
        printf("--------------------------------------------");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //

            break;

        case 2: //Cancela e volta � p�gina anterior

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}


int funcMenu_eliminarAula()  // funcao menu eliminar Aula
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                 Eliminar Aula                ");
        printf("--------------------------------------------");

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

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);

    return 0;
}


int funcMenu_eliminarAulaConfirmar()  // funcao menu eliminar Aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Eliminar Aula             ");
        printf("--------------------------------------------");
        printf("1 - Confirmar");
        printf("2 - Cancelar");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Confirmar

            break;

        case 2: //Cancela e volta � p�gina anterior

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}




int funcMenu_infoAulas()  // funcao menu informa�ao das aulas
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("           informa��o das UCs         \n");
        printf("------------------------------------------");
        printf("1 - Lista das aulas online\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Lista das aulas online

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);

    return 0;
}

int funcMenu_listaAulas()  // funcao menu Lista das Aulas
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("              Lista das Aulas           \n");
        printf("------------------------------------------");
        printf("\n");// apresentar lista das aulas sem as t,tp e pl
        printf("\n");
        printf("\n");
        printf("------------------------------------------");
        printf("1 - Selecione as aulas pretendidas\n");
        printf("2 - Voltar\n");

        escolha = lerInteiro(1,2);

        switch(escolha)
        {

        case 1: //Selecione as aulas pretendidas

            break;

        case 2: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha<1 && escolha>2);


    return 0;
}



int funcMenu_aulaSelecionada()  // funcao menu Aula Selecionada
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("              Aula Selecionada - X           \n");
        printf("------------------------------------------");
        printf("UC pertencente - \n");
        printf("Data:\n");
        printf("Hora de inicio:\n");
        printf("Dura��o:\n");
        printf("N� de estudantes inscritos:\n");
        printf("N� de estudantes presentes:\n");
        printf("N� de acesso �s grava��es:\n");
        //printf("N� de aulas T:\n");
        //printf("N� de aulas TP:\n");
        //printf("N� de aulas PL:\n");
        printf("------------------------------------------");
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha!=1);

    return 0;
}

int funcMenu_estatisticas()  // funcao menu das estat�sticas
{
    int escolha;

    system("cls"); // limpa ecr�

    do
    {
        printf("                Estat�sticas            \n");
        printf("------------------------------------------");
        printf("M�dia de presen�as por aula:\n");
        printf("Percentagem de UCs com aulas gravadas:\n");
        printf("UCs com menor n� de aulas realizadas:\n");
        printf("Tipo de aula com maior n� de acesso �s grava��es\n");
        printf("Aulas realizadas h� mais tempo:\n");
        printf("\n");

        printf("------------------------------------------");
        printf("1 - Voltar\n");

        escolha = lerInteiro(1,1);

        switch(escolha)
        {

        case 1: //Voltar

            break;

        //default caso o utilizador digite uma op��o inv�lida
        default:
            printf("Op��o inv�lida! Introduza nova op��o.");

        }//switch

    }
    while(escolha!=1);


    return 0;
}
