#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

void presencasAulas(dadosAula *vAulasOnline, int quantAulas);
void percentUCAulasGravadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
void UcComMenorQuantAulasRealizadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
void ucsMenorQuantidadeAulasRealizadas(dadosAula *vAulasOnline, int indiceAulasOnline, dadosUC vetUC[MAX_UCS], int indiceUC);
void quantidadeDeAulasPorTipo(dadosAula *vAulasOnline, int indiceAulasOnline);
void listaDeAulasMaisVelhas(dadosAula *vAulasOnline, int indiceAulasOnline);
void estatisticasMenuPrincipal(dadosAula *vAulasOnline, int indiceAulasOnline, int indiceUC);

#endif // ESTATISTICAS_H_INCLUDED
