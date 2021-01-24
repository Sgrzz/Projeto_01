#ifndef FUNC_MENUPRINCIPAL_H_INCLUDED
#define FUNC_MENUPRINCIPAL_H_INCLUDED


int menu_principal(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
int menu_listaUcs(dadosUC vDadosUC[MAX_UCS], int indiceVetUC);
int menu_alterarUC(dadosUC vDadosUC[MAX_UCS], int indiceVetUC);
int menu_eliminarUC();
int menu_agendarAula();
int menu_registarAcessoAula();
int menu_eliminarAula();
int menu_alterarAula();
int menu_listaAulas();
int menu_estatisticas();
int menu_confirmar();
void limpaEcra();
#endif // FUNC_MENUPRINCIPAL_H_INCLUDED




