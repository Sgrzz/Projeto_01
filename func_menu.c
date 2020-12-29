#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>

int funcMenu_Principal()  //funcao menu principal
{
    int escolha;

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
    printf("6 - Sair do programa\n");

    escolha = lerInteiro(1,6);

    return escolha;
}





int funcMenu_infoUcs()  // funcao menu de informacao das UCs
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("             Informação das UCs                 ");
    printf("--------------------------------------------------");
    printf("1 - Lista das UCs\n");
    printf("2 - Inserir UC\n");
    printf("3 - Modificar UC\n");
    printf("4 - Voltar\n");

    return 0;
}


int funcMenu_listaUcs()  // funcao menu lista das UCs
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                  Lista das UCs                   ");
    printf("--------------------------------------------------");
    printf("Para mais informações referentes a uma UC selecione UC pretendida\n");
    printf("X- UC pretendida\n");
    printf("2 - Voltar\n");

    return 0;
}

int funcMenu_UCselecionada()  // funcao menu de informação referente a UC selecionada
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("             Informação da UC - nome da uc            ");
    printf("------------------------------------------------------");
    printf("Nº de aulas online realizadas:\n");
    printf("\tAulas Teóricas - %d\n");
    printf("\tAulas Teórico-Práticas - %d\n");
    printf("\tAulas Prático-Laboratoriais - %d\n");
    printf("Aulas agendadas:\n");
    printf("\tTipo de aula -\n");
    printf("\tHora de início da aula: \n");
    printf("------------------------------------------------------");
    printf("1 - Voltar");

    return 0;
}


int funcMenu_inserirUC()  // funcao menu inserir UC
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Inserir UC            ");
    printf("--------------------------------------------");

    // dadosUC inserirDadosUC()

    printf("1 - Voltar\n");

    return 0;
}

int funcMenu_modificarUC()  // funcao menu modificar UC
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                 Modificar UC                ");
    printf("--------------------------------------------");

    printf("1 - Alterar UC\n");
    printf("2 - Eliminar UC\n");
    printf("3 - Voltar\n");

    return 0;
}


int funcMenu_alterarUC()  // funcao menu alterar UC
{
    int escolha;

    system("cls"); // limpa ecrã

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

    return 0;
}


int funcMenu_alterarUcConfirmada()  // funcao menu alterar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Alterar UC             ");
    printf("--------------------------------------------");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}


int funcMenu_eliminarUC()  // funcao menu eliminar UC
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                 Eliminar UC                ");
    printf("--------------------------------------------");



    printf("1 - Voltar\n");

    return 0;
}


int funcMenu_eliminarUcConfirmar()  // funcao menu eliminar UC, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Eliminar UC             ");
    printf("--------------------------------------------");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}





int funcMenu_aulasOnline()  // funcao menu aulas online
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                       Aulas Online                        ");
    printf("-----------------------------------------------------------");
    printf("1 - Agendar aulas online\n");
    printf("2 - Resgistar acesso a aula online\n");
    printf("3 - Voltar");

    return 0;
}


int funcMenu_agendarAula()  // funcao menu agendar aula online
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                    Agendar aula               ");
    printf("-----------------------------------------------");
    printf("Insira o nº de estudante: \n");
    printf("Selecione a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n"); // T, TP, PL
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}


int funcMenu_registarAcessoAula()  // funcao menu registar acesso a aula
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("           Registar Acesso a Aula Online       ");
    printf("-----------------------------------------------");
    printf("Insira o código da UC: \n");
    printf("Indique a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n");
    printf("Insira o nº de estudante: \n");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}

int funcMenu_modificarAula()  // funcao menu modificar aula
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                 Modificar Aula                ");
    printf("--------------------------------------------");

    printf("1 - Alterar aula\n");
    printf("2 - Eliminar aula\n");
    printf("3 - Voltar\n");

    return 0;
}

int funcMenu_alterarAula()  // funcao menu alterar aula
{
    int escolha;

    system("cls"); // limpa ecrã

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

    return 0;
}


int funcMenu_alterarAulaConfirmada()  // funcao menu alterar aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Alterar Aula                ");
    printf("--------------------------------------------");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}


int funcMenu_eliminarAula()  // funcao menu eliminar Aula
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                 Eliminar Aula                ");
    printf("--------------------------------------------");

    printf("");
    printf("");
    printf("");
    printf("");


    printf("Selecione a aula que pretende eliminar:\n");
    printf("X - Eliminar aula\n");
    printf("2 - Voltar\n");

    return 0;
}


int funcMenu_eliminarAulaConfirmar()  // funcao menu eliminar Aula, perguntar se quer confirmar ou cancelar
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Eliminar Aula             ");
    printf("--------------------------------------------");
    printf("1 - Confirmar");
    printf("2 - Cancelar");

    return 0;
}




int funcMenu_infoAulas()  // funcao menu informaçao das aulas
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("           informação das UCs         \n");
    printf("------------------------------------------");
    printf("1 - Lista das aulas online\n");
    printf("2 - Voltar\n");

    return 0;
}

int funcMenu_listaAulas()  // funcao menu Lista das Aulas
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("              Lista das Aulas           \n");
    printf("------------------------------------------");
    printf("\n");// apresentar lista das aulas sem as t,tp e pl
    printf("\n");
    printf("\n");
    printf("------------------------------------------");
    printf("X - Selecione as aulas pretendidas\n");
    printf("2 - Voltar\n");

    return 0;
}



int funcMenu_aulaSelecionada()  // funcao menu Aula Selecionada
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("              Aula Selecionada - X           \n");
    printf("------------------------------------------");
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
    printf("------------------------------------------");
    printf("1 - Voltar\n");

    return 0;
}

int funcMenu_estatisticas()  // funcao menu das estatísticas
{
    int escolha;

    system("cls"); // limpa ecrã

    printf("                Estatísticas            \n");
    printf("------------------------------------------");
    printf("Média de presenças por aula:\n");
    printf("Percentagem de UCs com aulas gravadas:\n");
    printf("UCs com menor nº de aulas realizadas:\n");
    printf("Tipo de aula com maior nº de acesso às gravações\n");
    printf("Aulas realizadas há mais tempo:\n");
    printf("\n");

    printf("------------------------------------------");
    printf("1 - Voltar\n");


    return 0;
}


