#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED


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
#define MAX_QUANT_TIPO_AULAS_TP 999 //maximo de quantidade de tipos de aulas Te�rico-Pr�ticas
#define MIN_QUANT_TIPO_AULAS_TP 0   //minimo de quantidade de tipos de aulas Te�rico-Pr�ticas
#define MAX_QUANT_TIPO_AULAS_PL 999 //maximo de quantidade de tipos de aulas Pr�tico-Laboratorial
#define MIN_QUANT_TIPO_AULAS_PL 0   //minimo de quantidade de tipos de aulas Pr�tico-Laboratorial
#define MAX_DURAC_TIPO_AULAS_T 999  //maximo da dura��o de tipos de aulas teoricas
#define MIN_DURAC_TIPO_AULAS_T 0    //minimo da dura��o de tipos de aulas teoricas
#define MAX_DURAC_TIPO_AULAS_TP 999 //maximo da dura��o de tipos de aulas Te�rico-Pr�ticas
#define MIN_DURAC_TIPO_AULAS_TP 0   //minimo da dura��o de tipos de aulas Te�rico-Pr�ticas
#define MAX_DURAC_TIPO_AULAS_PL 999 //maximo da dura��o de tipos de aulas Pr�tico-Laboratorial
#define MIN_DURAC_TIPO_AULAS_PL 0   //minimo da dura��o de tipos de aulas Pr�tico-Laboratorial

#define MAX_ESTUDANTES 100          //maximo estudantes
#define MAX_STRING_NOME_AULA 20     // nome UC
#define MAX_STRING_NOME_DOCENTE 50  //nome do docente
#define MIN_SEMESTRES 1             //minimo de semestres
#define MAX_SEMESTRES 6             //maximo de semestres

#define MAX_STRING 50               //maximo da string � sempre o numero maior declarado antes

//enum declaration
enum enumTipoUC {obrigatoria,opcional};
enum enumRegime {diurno,poslaboral};
enum enumTipoAula {T,TP,PL};
enum enumEstadoAula {agendada,decorrer,realizada};
enum bool {false,true};

#endif // CONSTANTES_H_INCLUDED
