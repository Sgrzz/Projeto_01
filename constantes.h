#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED



////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////constantes MENUS///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#define MIN_MENU_PRINCIPAL 1        //minimo no menu principal
#define MAX_MENU_PRINCIPAL 11       //maximo no menu principal

#define MIN_OPCAO_MENU_VOLTAR 0     //minimo de opcao no menu para voltar

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////constantes UCs/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_UCS 40                  //maximo de ucs
#define MIN_UCS 1                   //minimo de ucs
#define MAX_TIPO_UCS 1              //maximo de tipos de ucs
#define MIN_TIPO_UCS 0              //minimo de tipos de ucs
#define MAX_REGIME_UCS 1            //maximo de regimes ucs
#define MIN_REGIME_UCS 0            //minimo de regimes ucs
#define MAX_QUANT_TIPO_AULAS_T 999  //maximo de quantidade de tipos de aulas teoricas
#define MIN_QUANT_TIPO_AULAS_T 0    //minimo de quantidade de tipos de aulas teoricas
#define MAX_QUANT_TIPO_AULAS_TP 999 //maximo de quantidade de tipos de aulas Teórico-Práticas
#define MIN_QUANT_TIPO_AULAS_TP 0   //minimo de quantidade de tipos de aulas Teórico-Práticas
#define MAX_QUANT_TIPO_AULAS_PL 999 //maximo de quantidade de tipos de aulas Prático-Laboratorial
#define MIN_QUANT_TIPO_AULAS_PL 0   //minimo de quantidade de tipos de aulas Prático-Laboratorial
#define MAX_DURAC_TIPO_AULAS_T 999  //maximo da duração de tipos de aulas teoricas
#define MIN_DURAC_TIPO_AULAS_T 0    //minimo da duração de tipos de aulas teoricas
#define MAX_DURAC_TIPO_AULAS_TP 999 //maximo da duração de tipos de aulas Teórico-Práticas
#define MIN_DURAC_TIPO_AULAS_TP 0   //minimo da duração de tipos de aulas Teórico-Práticas
#define MAX_DURAC_TIPO_AULAS_PL 999 //maximo da duração de tipos de aulas Prático-Laboratorial
#define MIN_DURAC_TIPO_AULAS_PL 0   //minimo da duração de tipos de aulas Prático-Laboratorial

#define MAX_ESTUDANTES 100          //maximo estudantes
#define MAX_STRING_NOME_UC 20       // nome UC
#define MAX_STRING_NOME_DOCENTE 50  //nome do docente
#define MIN_SEMESTRES 1             //minimo de semestres
#define MAX_SEMESTRES 6             //maximo de semestres

#define MAX_STRING 50               //maximo da string é sempre o numero maior declarado antes

/////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////Constantes Aulas Online//////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
#define MIN_DIA 1                   //minimo do dia do mes
#define MAX_MES 12                  //maximo de meses
#define MIN_MES 1                   //minimo de meses
#define MAX_ANO 2050                //maximo de anos
#define MIN_ANO 2020                //minimo de anos
#define MIN_TIPO_AULA 0             //minimo tipo de aula
#define MAX_TIPO_AULA 2             //maximo tipo de aula
#define MAX_STRING_NOME_AULA 20     //maximo do nome da aula
#define MIN_STRING_NOME_AULA 0      //minimo do nome da aula

#define MAX_HORA 23                 //maximo da hora
#define MIN_HORA 0                  //minimo da hora
#define MAX_MINUTOS 59              //maximo de minutos
#define MIN_MINUTOS 0               //minimo de minutos

#define MAX_ESTADO_AULA 2           //maximo de estado da aula
#define MIN_ESTADO_AULA 0           //minimo de estado da aula
#define MAX_OP_GRAVACAO 1           //maximo de opcoes de gravacao
#define MIN_OP_GRAVACAO 0           //minimo de opcoes de gravcao
#define MAX_ACESSO_AULA 1           //maximo de acesso a aula -> offline /gravada
#define MIN_ACESSO_AULA 0           //minimo de acesso a aula -> online

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Estudantes///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_ESTUDANTES 100          //maximo de estudantes
#define MIN_ESTUDANTES 0            //minimo de estudantes



//enum declaration
enum enumTipoUC {obrigatoria,opcional};
enum enumRegime {diurno,poslaboral};
enum enumTipoAula {T,TP,PL};
enum enumEstadoAula {agendada,decorrer,realizada};
enum enumGravacao {nao,sim};
enum enumAcessoAula {online,gravada}; //online e onffline

#endif // CONSTANTES_H_INCLUDED
