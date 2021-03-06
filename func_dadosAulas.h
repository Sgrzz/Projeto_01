#ifndef FUNC_DADOSAULAS_H_INCLUDED
#define FUNC_DADOSAULAS_H_INCLUDED

#include "constantes.h"
#include "func_dadosAulas.h"
#include "func_aux.h"
#include "estruturas.h"


int procurarNomeAula(dadosAula *vAulasOnline, int posIndiceArray, char nomeAula[]);

//verifica se o nome da aula ja existe ou nao
void lerNomeAula(char nome[MAX_STRING_NOME_AULA], dadosAula *vAulasOnline, int posIndiceArray);
int lerCodigoDaUC(dadosUC arrayUC[MAX_UCS], int posIndiceArrayUC);
int lerTipoAula(tipoAulas quantidade);
void lerNomeDocente(char nome[MAX_STRING_NOME_DOCENTE]);
void lerDataAula(tipoData *data);
void lerHoraAula(tipoHora *horaInicio, tipoHora *horaFim,dadosAula *vDadosAula, int indiceDadosAula, enum enumRegime regime, enum enumTipoAula tipoAula,tipoAulas tempoAulas, int codigoUC);
int estadoAula();
int opGravacao();

//inserirDadosAula
dadosAula *agendarAula(dadosAula *vAulasOnline, int *posIndiceArrayAulas, dadosUC vDadosUC[], int posIndiceArrayUC);
dadosAula *eliminarAula (dadosAula *vAulasOnline, int *quantAulas);
void listarDadosAula(dadosAula *vAulasOnline, int posIndiceArray);
void alterarAula(dadosAula *vAulasOnline, int quantAulas,dadosUC dadosDaUC[MAX_UCS], int indiceArrayUC, char nomeAula[MAX_STRING_NOME_AULA], int opcao);
void registarInicioAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA]);
void registarFimAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA]);

void infoAulasOnline(dadosAula *vAulasOnline, int indiceAulasOnline,int codigoUC);
void registarAcessoAula(dadosAula *vAulasOnline, int indiceAulas);
#endif // FUNC_DADOSAULAS_H_INCLUDED
