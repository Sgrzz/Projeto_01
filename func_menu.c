#include <stdio.h>
#include <string.h>

int funcMenuPrincipal(){
    int escolha = 1;


    printf("----------------------Menu Principal---------------------\m");
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

