#include <stdio.h>
#include <string.h>
#include "func_aux.h"
#include <conio.h>
#include <stdlib.h>
#include "Func_menu.h"
#include "func_dadosUC.h"

int funcMenu_principal()  //funcao menu principal
{
    int escolha;
    void limpaBufferStdin(void);

    printf("\n---------------------Menu Principal--------------------\n");
    //printf("\n                        Projeto p1                       \n");
    printf("Quantidade de UCs: \n");
    printf("Quantidade de aulas agendadas: \n");
    printf("Quantidade de aulas gravadas: \n");
    printf("-------------------------------------------------------\n");
    printf("--> Informação das UCs\n");
    printf("        1 -> Listas das UCs\n");
    printf("        2 -> Inserir Uc\n");
    printf("        3 -> Alterar UC\n");
    printf("        4 -> Eliminar UC\n");
    printf("--> Aulas Online\n");
    printf("        5 -> Agendar aula online\n");
    printf("        6 -> Registar acesso a aula online\n");
    printf("        7 -> Eliminar aula online\n");
    printf("        8 -> Alterar aula Agendada\n");
    printf("        9 -> Lista das aulas\n");
    printf("10 -> Estatisticas\n");
    printf("1 -> Sair do programa\n");
    printf("-------------------------------------------------------\n");
    printf("Selecione a opção desejada.\n");
    escolha = lerInteiro(1,6);

    return escolha;
}



//Informação das UCs
int  funcMenu_listaUcs()  // funcao menu lista das UCs
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                  Lista das UCs                   \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("1 -> Voltar\n");

    escolha = lerInteiro(1,1);
    return escolha;
}


int funcMenu_inserirUC()  // funcao menu inserir UC
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                Inserir UC            \n");
    printf("-------------------------------------------------------\n");

    // dadosUC inserirDadosUC()
    printf("1 -> Voltar\n");

    escolha = lerInteiro(1,1);

    return escolha;
}


int funcMenu_alterarUC()  // funcao menu alterar UC
{
    int escolha;
    void limpaBufferStdin(void)

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
    printf("-------------------------------------------------------\n");
    printf("1 -> Selecione UC a alterar\n");
    printf("2 -> Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}


int funcMenu_eliminarUC()  // funcao menu eliminar UC
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                 Eliminar UC                \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("-> Selecione o código da UC a eliminar\n");
    printf("-1 -> Selecione -1 para voltar\n");

    escolha = lerInteiro(-1,40);

    return escolha;
}



// Aula Online

int  funcMenu_agendarAula()  // funcao menu agendar aula online
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                    Agendar aula               \n");
    printf("-------------------------------------------------------\n");
    printf("Insira o nº de estudante: \n");
    printf("Selecione a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n"); // T, TP, PL
    printf("-------------------------------------------------------\n");
    printf("1 - Confirmar\n");
    printf("2 - Cancelar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int funcMenu_registarAcessoAula()  // funcao menu registar acesso a aula
{
    int escolha;
    void limpaBufferStdin(void)

    printf("           Registar Acesso a Aula Online       \n");
    printf("-------------------------------------------------------\n");
    printf("Insira o código da UC: \n");
    printf("Indique a aula que pretende se registar:\n");
    printf("Selecione o tipo de aula: \n");
    printf("Insira o nº de estudante: \n");
    printf("-------------------------------------------------------\n");
    printf("1 - Confirmar\n");
    printf("2 - Cancelar\n");

    escolha = lerInteiro(1,2);
    return escolha;
}

int funcMenu_eliminarAula()  // funcao menu eliminar Aula
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                 Eliminar Aula                \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("Selecione a aula que pretende eliminar:\n");
    printf("1 - Eliminar aula\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int funcMenu_alterarAula()  // funcao menu alterar aula
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                Alterar Aula             \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("1 - Aula selecionada\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

int funcMenu_listaAulas()  // funcao menu Lista das Aulas
{
    int escolha;
    void limpaBufferStdin(void)

    printf("              Lista das Aulas           \n");
    printf("-------------------------------------------------------\n");

    printf("-------------------------------------------------------\n");
    printf("1 - Selecione as aulas pretendidas\n");
    printf("2 - Voltar\n");

    escolha = lerInteiro(1,2);

    return escolha;
}

// Estatísticas
int funcMenu_estatisticas()  // funcao menu das estatísticas
{
    int escolha;
    void limpaBufferStdin(void)

    printf("                Estatísticas            \n");
    printf("-------------------------------------------------------\n");
    printf("-->Média de presenças por aula:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Percentagem de UCs com aulas gravadas:\n");

    printf("-------------------------------------------------------\n");
    printf("-->UCs com menor nº de aulas realizadas:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Tipo de aula com maior nº de acesso às gravações\n");

    printf("-------------------------------------------------------\n");
    printf("-->Aulas realizadas há mais tempo:\n");

    printf("-------------------------------------------------------\n");
    printf("-->Ranking:\n");

    printf("-------------------------------------------------------\n");
    printf("1 -> Voltar\n");

    escolha = lerInteiro(1,1);

    return escolha;
}
