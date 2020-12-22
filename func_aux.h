#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"

void lerData(tipoData *data);
int lerInteiro(int minimo, int maximo);
float lerFloat(float minimo, float maximo);
void lerString(char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);

#endif // FUNCOES_AUXILIARES_H_INCLUDED
