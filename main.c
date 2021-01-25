#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_dadosUC.h"
#include "func_menu.h"
#include "estruturas.h"
#include "func_dadosAulas.h"
#include "func_ficheiros.h"

int main()
{

    dadosUC vDadosUC[MAX_UCS];

    int escolha, indiceVetUC = 0, escolhaSubMenu, indiceVetAulas = 0;
    dadosAula *vAulasOnline = NULL;
    char nomeAula[MAX_STRING_NOME_AULA];

    vAulasOnline = carregarDadosFicheiroBinario(vDadosUC,&indiceVetUC,vAulasOnline,&indiceVetAulas);

    do
    {
        escolha = menu_principal(vAulasOnline, indiceVetAulas, indiceVetUC);

        switch (escolha)
        {
        case 1://Lista das Ucs
            escolhaSubMenu = menu_listaUcs(vDadosUC, indiceVetUC);
            if(escolhaSubMenu!=0)
            {
                infoAulasOnline(vAulasOnline,indiceVetAulas,escolhaSubMenu);
                menu_confirmar();
            }
            break;

        case 2://Inserir UC
            inserirDadosUC(vDadosUC, &indiceVetUC);
            menu_confirmar();
            break;

        case 3://Alterar UC
            escolhaSubMenu = menu_alterarUC(vDadosUC, indiceVetUC);
            if(escolhaSubMenu!=0)
            {
                alterarDadosUC(vDadosUC, indiceVetUC, escolhaSubMenu,0);
                menu_confirmar();
            }
            break;

        case 4://Eliminar UC
            escolhaSubMenu = menu_eliminarUC(vDadosUC, indiceVetUC);
            if(escolhaSubMenu != 0)
            {
                removerDadosUC(vDadosUC, &indiceVetUC, escolhaSubMenu);
                menu_confirmar();
            }
            break;
        case 5://Agedar aula online
            vAulasOnline = agendarAula(vAulasOnline, &indiceVetAulas, vDadosUC, indiceVetUC);
            menu_confirmar();
            break;
        case 6://Registar acesso a aula online
            listarDadosAula(vAulasOnline, indiceVetAulas);
            registarAcessoAula(vAulasOnline, indiceVetAulas);
            menu_confirmar();
            break;
        case 7://Eliminar aula online
            listarDadosAula(vAulasOnline, indiceVetAulas);
            vAulasOnline = eliminarAula(vAulasOnline, &indiceVetAulas);
            menu_confirmar();
            break;
        case 8://Alterar aula Agendada
            menu_alterarAula(vAulasOnline, indiceVetAulas,nomeAula);
            alterarAula(vAulasOnline,indiceVetAulas,vDadosUC,indiceVetUC,nomeAula,0);
            menu_confirmar();
            break;
        case 9://Lista das aulas online
            escolhaSubMenu = menu_listaAulasOnline(vAulasOnline,indiceVetAulas,nomeAula);
            if (escolhaSubMenu!=0)
            {
                listarNomeAulasUC(vDadosUC,indiceVetUC,escolhaSubMenu);
            }
            break;
        case 10://registar inicio da aula
            menu_registarInicioAula(vAulasOnline, indiceVetAulas,nomeAula);
            registarInicioAula(vAulasOnline, indiceVetAulas,nomeAula);
            menu_confirmar();
            break;
        case 11://registar fim da aula
            menu_registarFimAula(vAulasOnline, indiceVetAulas,nomeAula);
            registarFimAula(vAulasOnline, indiceVetAulas,nomeAula);
            menu_confirmar();
            break;
        case 12://Estatisticas
            escolhaSubMenu = menu_estatisticas(vAulasOnline, indiceVetAulas, vDadosUC, indiceVetUC);
            break;
        case 13://Sair do programa
            gravaFicheiroBinario(vDadosUC, indiceVetUC,vAulasOnline,indiceVetAulas);
            printf("Fim do programa\n");
        }
    }
    while (escolha!=13);

    free(vAulasOnline);

    return 0;
}

