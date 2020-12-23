#ifndef FUNC_DADOSUC_H_INCLUDED
#define FUNC_DADOSUC_H_INCLUDED


//func ler dados para a struct dadosUC
int lerDadosCodigoUC();
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
dadosUC inserirDadosUC();
//func que altera o valor dos dados especificado
void alterarDadosUC(dadosUC *dadosDaUC, int opcao);


#endif // FUNC_DADOSUC_H_INCLUDED
