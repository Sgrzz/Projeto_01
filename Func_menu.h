#ifndef FUNC_MENUPRINCIPAL_H_INCLUDED
#define FUNC_MENUPRINCIPAL_H_INCLUDED


int menu_principal(dadosAula *vAulasOnline, int indiceAulasOnline, int indiceUC);
//menus das uc's
int menu_listaUcs(dadosUC vDadosUC[MAX_UCS], int indiceVetUC);
int menu_alterarUC(dadosUC vDadosUC[MAX_UCS], int indiceVetUC);
int menu_eliminarUC();

//menus das aulas
void menu_alterarAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA]);
int menu_listaAulasOnline(dadosAula *vAulasOnline, int indiceAulasOnline,char escolha[MAX_STRING_NOME_AULA]);
void menu_registarInicioAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA]);
void menu_registarFimAula(dadosAula *vAulasOnline, int indiceAulasOnline, char escolha[MAX_STRING_NOME_AULA]);

//estatisticas
int menu_estatisticas();
int menu_confirmar();
void limpaEcra();
#endif // FUNC_MENUPRINCIPAL_H_INCLUDED




