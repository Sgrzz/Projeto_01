#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_dadosUC.h"
#include "func_menu.h"
#include "estruturas.h"
#include "func_dadosAulas.h"


int main()
{

    dadosUC vDadosUC[MAX_UCS];

    int escolha, indiceVetUC = 0, escolhaSubMenu, indiceVetAulas = 0;
    dadosAula *vAulasOnline = NULL;
    do
    {


    carregarDadosFicheiroBinario(arrayDadosUC,&posIndiceArrayUC);

        switch (escolha)
        {
        case 1://Lista das Ucs
            escolhaSubMenu = menu_listaUcs(vDadosUC, indiceVetUC);
            if(escolhaSubMenu!=0)
            {

            }
            break;

        case 2://Inserir UC
            inserirDadosUC(vDadosUC, &indiceVetUC);
            break;

        case 3://Alterar UC
            escolhaSubMenu = menu_alterarUC(vDadosUC, indiceVetUC);
            if(escolhaSubMenu!=0)
            {
                alterarDadosUC(vDadosUC, indiceVetUC, escolhaSubMenu,0);
            }
            //alterarDadosUC();
            break;

        case 4://Eliminar UC

            break;
        case 5://Agedar aula online
            vAulasOnline = agendarAula(vAulasOnline, &indiceVetAulas, vDadosUC, indiceVetUC);
            break;
        case 6://Registar acesso a aula online

            break;
        case 7://Eliminar aula online

            break;
        case 8://Alterar aula Agendada

            break;
        case 9://Lista das aulas online

            break;
        case 10://Estatisticas

            break;
        case 11://Sair do programa
            gravaFicheiroBinario(vDadosUC, indiceVetUC);
            printf("Fim do programa\n");
        }
    }
    while (escolha!=11);

    return 0;
}

