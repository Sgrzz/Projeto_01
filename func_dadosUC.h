#ifndef FUNC_DADOSUC_H_INCLUDED
#define FUNC_DADOSUC_H_INCLUDED


//func ler dados para a struct dadosUC
int lerDadosCodigoUC(dadosUC dadosDaUC[MAX_UCS], int posArray);
void lerDadosNomeUC(char nome[MAX_STRING_NOME_AULA]);
int lerTipoUC();
int lerSemestreUC();
int lerRegimeUC();
int lerQuantTipoAulas_T();
int lerQuantTipoAulas_TP();
int lerQuantTipoAulas_PL();
int lerDuracaoAulas_T();
int lerDuracaoAulas_TP();
int lerDuracaoAulas_PL();
//func que chama cada uma das func atraz
void inserirDadosUC(dadosUC dadosDaUC[MAX_UCS], int *posArray);
//func que altera o valor dos dados especificado
void alterarDadosUC(dadosUC dadosDaUC[MAX_UCS],int posArray,int codigoUC, int opcao);

int procurarDadosUC(dadosUC arrayUC[MAX_UCS], int posArray, int codigoUC);
void ordenarDadosUC(dadosUC arrayUC[MAX_UCS], int posArray);
void listarDadosUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray);
void removerDadosUC(dadosUC arrayUC[MAX_UCS], int *posIndiceArray, int codigoUC);
void listarNomeAulasUC(dadosUC arrayUC[MAX_UCS], int posIndiceArray, int codigoUC);
void listarRankingUC(dadosUC arrayUC[MAX_UCS], int indiceUC, dadosAula *arrayAula, int indiceAula);
#endif // FUNC_DADOSUC_H_INCLUDED
