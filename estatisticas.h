#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

float mediaPresenAulas(dadosAula *vAulasOnline, int acessoAulas);
void percentUCAulasGravadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
void UcComMenorQuantAulasRealizadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
void estatisticasMenuPrincipal(dadosAula *vAulasOnline, int indiceAulasOnline, int indiceUC);

#endif // ESTATISTICAS_H_INCLUDED
