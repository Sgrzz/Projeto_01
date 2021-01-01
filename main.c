#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "constantes.h"
#include "func_dadosUC.h"



int main()
{
    dadosUC arrayUC[MAX_UCS];
    int posArrayUC = 0;

    inserirDadosUC(arrayUC,&posArrayUC);

    return 0;
}

