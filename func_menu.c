#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>
#include "func_menu.h"
#include "func_dadosUC.h"
#include "estruturas.h"

int menu_principal()  //funcao menu principal
{
    int escolha;
    void limpaBufferStdin(void);

    printf("\n---------------------Menu Principal--------------------\n");
    //printf("\n                        Projeto p1                       \n");
    printf("Quantidade de UCs: \n");
    printf("Quantidade de aulas agendadas: \n");
    printf("Quantidade de aulas gravadas: \n");
    printf("-------------------------------------------------------\n");
    printf("--> Informa��o das UCs\n");
    printf("        1 -> Listas das UCs\n");
    printf("        2 -> Inserir Uc\n");
    printf("        3 -> Alterar UC\n");
    printf("        4 -> Eliminar UC\n\n");

    printf("--> Aulas Online\n");
    printf("        5 -> Agendar aula online\n");
    printf("        6 -> Registar acesso a aula online\n");
    printf("        7 -> Eliminar aula online\n");
    printf("        8 -> Alterar aula Agendada\n");
    printf("        9 -> Lista das aulas\n\n");

    printf("10 -> Estatisticas\n");
    printf("11 -> Sair do programa\n");
    printf("-------------------------------------------------------\n");
    printf("Selecione a op��o desejada.\n");
    escolha = lerInteiro(1,11);

    return escolha;
}



//Informa��o das UCs
int menu_listaUcs(dadosUC vDadosUC[MAX_UCS], int indiceVetUC)  // funcao menu lista das UCs
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                  Lista das UCs                   \n");
    printf("-------------------------------------------------------\n");
    listarDadosUC(vDadosUC , indiceVetUC);
    printf("-------------------------------------------------------\n");

    printf("Selecione o codigo da UC para mais informacoes ou 0 para voltar\n");

    escolha = lerInteiro(0,40);
    return escolha;
}


int menu_alterarUC(dadosUC vDadosUC[MAX_UCS], int indiceVetUC)  // funcao menu alterar UC
{
    int escolha;
    limpaBufferStdin();

    printf("                Alterar UC             \n");
    printf("-------------------------------------------------------\n");
    listarDadosUC(vDadosUC , indiceVetUC);
    printf("-------------------------------------------------------\n");
    printf("Selecione o codigo da UC a alterar ou 0 para voltar\n");

    escolha = lerInteiro(0,40);

    return escolha;
}


int menu_eliminarUC()  // funcao menu eliminar UC
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                 Eliminar UC                \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("-> Selecione o c�digo da UC a eliminar\n");
    printf("-1 -> Selecione 0 para voltar\n");

    escolha = lerInteiro(0,40);

    return escolha;
}


// Aula Online

int menu_agendarAula()  // funcao menu agendar aula online
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                    Agendar aula               \n");
    printf("-------------------------------------------------------\n");
    printf("Insira o n� de estudante: \n");
    printf("Selecione a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n"); // T, TP, PL
    printf("-------------------------------------------------------\n");
    printf("1 - Confirmar\n");
    printf("2 - Cancelar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int menu_registarAcessoAula()  // funcao menu registar acesso a aula
{
    int escolha;
    void limpaBufferStdin(void);

    printf("           Registar Acesso a Aula Online       \n");
    printf("-------------------------------------------------------\n");
    printf("Insira o c�digo da UC: \n");
    printf("Indique a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n");
    printf("Insira o n� de estudante: \n");
    printf("-------------------------------------------------------\n");
    printf("1 - Confirmar\n");
    printf("2 - Cancelar\n");

    escolha = lerInteiro(1,2);
    return escolha;
}

int menu_eliminarAula()  // funcao menu eliminar Aula
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                 Eliminar Aula                \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("Selecione a aula que pretende eliminar:\n");
    printf("1 - Eliminar aula\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int menu_alterarAula()  // funcao menu alterar aula
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                Alterar Aula             \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("1 - Aula selecionada\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int menu_listaAulas()  // funcao menu Lista das Aulas
{
    int escolha;
    void limpaBufferStdin(void);

    printf("              Lista das Aulas           \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("1 - Selecione as aulas pretendidas\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

// Estat�sticas
int menu_estatisticas()  // funcao menu das estat�sticas
{
    int escolha;
    void limpaBufferStdin(void);

    printf("                Estat�sticas            \n");
    printf("-------------------------------------------------------\n");
    printf("-->M�dia de presen�as por aula:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Percentagem de UCs com aulas gravadas:\n");

    printf("-------------------------------------------------------\n");
    printf("-->UCs com menor n� de aulas realizadas:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Tipo de aula com maior n� de acesso �s grava��es\n");

    printf("-------------------------------------------------------\n");
    printf("-->Aulas realizadas h� mais tempo:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Ranking:\n");

    printf("-------------------------------------------------------\n");
    printf("1 -> Voltar\n");

    escolha = lerInteiro(1,1);

    return escolha;
}
