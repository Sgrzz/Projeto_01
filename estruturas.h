#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include "constantes.h"

typedef struct
{
    int T;
    int TP;
    int PL;
} tipoAulas;

typedef struct
{
    int dia;
    int mes;
    int ano;
} tipoData;

typedef struct
{
    int hora;
    int minuto;
} tipoHora;

typedef struct
{
    int codigoUC;
    char nome[MAX_STRING_NOME_AULA];            //temporario declarar constantes
    enum enumTipoUC tipoUC;                     //obrigatoria ou opcional
    int semestre;                               //1 - 6
    enum enumRegime regime;                     //Diurno ou Pos-laboral
    tipoAulas quantTipoAulas;                   //quantidade de tipo de aulas
    tipoAulas duracaoAulas;                     //em minutos
} dadosUC;                                      //main struct #todo

typedef struct
{
    char nome[MAX_STRING_NOME_AULA];            //nome da aula
    int codigoUC;                               //codigo da UC associada a aula
    enum enumTipoAula tipoAula;                 //tipo aula enum (T  TP PL)
    char nomeDocente[MAX_STRING_NOME_DOCENTE];  //nome do docente
    tipoData data;                              //data da aula lecionada online
    tipoHora horaInicio;                        //hora do inicio da aula
    tipoHora horaFim;                           //hora do fim da aula
    enum enumEstadoAula estado;                 //estado da aula (agendada, a decorrer ou realizada)
    enum enumGravacao gravacao;                 //gravada? nao/Sim
    int numEstudantesOnline;                    //contador de estudantes online
    int numEstudantesOffline;                   //contador de estudantes offline
} dadosAula;



#endif // ESTRUTURAS_H_INCLUDED
