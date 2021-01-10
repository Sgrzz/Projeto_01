#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_dadosUC.h"
#include"Func_menu.h"



int main()
{
    int escolha;

    do
    {
        escolha = funcMenu_principal();

        switch (escolha)
        {
        case 1://Lista das Ucs
            funcMenu_listaUcs();
            break;
        case 2://Inserir UC
            funcMenu_inserirUC();
            break;
        case 3://Alterar UC
            funcMenu_alterarUC();
            break;
        case 4://Eliminar UC
            funcMenu_eliminarUC();
            break;
        case 5://Agedar aula online
            funcMenu_agendarAula();
            break;
        case 6://Registar acesso a aula online
            funcMenu_registarAcessoAula();
            break;
        case 7://Eliminar aula online
            funcMenu_eliminarAula();
            break;
        case 8://Alterar aula Agendada
            funcMenu_alterarAula();
            break;
        case 9://Lista das aulas online
            funcMenu_listaAulas();
            break;
        case 10://Estatisticas
            funcMenu_estatisticas();
            break;
        case 11://Sair do programa
            printf("Fim do programa\n");
        }
    }
    while (escolha!=11);

    return 0;
}

