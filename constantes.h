#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

//Constantes declaradas para maximos

#define MAX_UCs 40                  //maximo de ucs
#define MAX_ESTUDANTES 100          //maximo estudantes
#define MAX_STRING_NOME_AULA 20     // nome UC
#define MAX_STRING_NOME_DOCENTE 50  //nome do docente

#define MAX_STRING 50               //maximo da string é sempre o numero maior declarado antes

//enum declaration
enum enumTipoUC {obrigatoria,opcional};
enum enumRegime {diurno,poslaboral};
enum enumTipoAula {T,TP,PL};
enum enumEstadoAula {agendada,decorrer,realizada};
enum bool {false,true};

#endif // CONSTANTES_H_INCLUDED
