#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"

int compararDatas(tipoData a, tipoData b);
int compararHoras(tipoHora horaInicio, tipoHora horaInicio2, tipoHora duracao);
tipoHora somarHora(tipoHora hora1, tipoHora hora2);
void lerData(tipoData *data);
int lerInteiro(int minimo, int maximo);
float lerFloat(float minimo, float maximo);
void lerString(char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin();

#endif // FUNCOES_AUXILIARES_H_INCLUDED
