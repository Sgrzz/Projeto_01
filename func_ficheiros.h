#ifndef FUNC_FICHEIROS_H_INCLUDED
#define FUNC_FICHEIROS_H_INCLUDED

int gravaFicheiroBinario(dadosUC arrayUC[MAX_UCS], int indiceArrayUC, dadosAula *vAulasOnline,int indiceAulaOnline);
dadosAula *carregarDadosFicheiroBinario(dadosUC arrayUC[MAX_UCS], int *indiceDadosUC, dadosAula *vAulasOnline,int *indiceAulaOnline) ;

#endif // FUNC_FICHEIROS_H_INCLUDED
