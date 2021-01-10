#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_dadosUC.h"
#include "func_ficheiros.h"


int main()
{
    dadosUC arrayDadosUC[MAX_UCS];
    int posIndiceArrayUC = 0;

    if (lerFicheiroBinario(arrayDadosUC,&posIndiceArrayUC) == -1)
    {
        gravaFicheiroBinario(arrayDadosUC,posIndiceArrayUC);
    }

    listarDadosUC(arrayDadosUC,posIndiceArrayUC);


    gravaFicheiroBinario(arrayDadosUC,posIndiceArrayUC);

    return 0;
}

