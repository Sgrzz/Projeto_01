#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "func_dadosAulas.h"
#include "estruturas.h"
#include "func_aux.h"
#include "constantes.h"
#include "func_dadosUC.h"

//recebe array tipo dadosAula, a pos do array e o nome para comparar
//devolve a pos onde encontrou o nomeAula se n devolve -1
int procurarNomeAula(dadosAula *vAulasOnline, int posIndiceArray, char nomeAula[])
{
    int i, posNomeAula=-1;

    for (i = 0; i < posIndiceArray; ++i)//percorre o array
    {
        if (strcmp(nomeAula, vAulasOnline[i].nome)==0) //se o nome da aula existir devolve a posicao do elemento ->compara o nome aula com o vAulasOnline
        {
            posNomeAula = i;
            i=posIndiceArray;
        }
    }

    return posNomeAula;
}

//verifica se o nome da aula ja existe ou nao
void lerNomeAula(char nome[MAX_STRING_NOME_AULA], dadosAula *vAulasOnline, int posIndiceArray)//precisa do array, da posicao e do nome para verificar
{
    int posNome;
    char nomeAula[MAX_STRING_NOME_AULA];

    //ler nome da aula
    printf("Insira o nome da aula:\n");

    do
    {
        lerString(nomeAula, MAX_STRING_NOME_AULA);
        posNome = procurarNomeAula(vAulasOnline, posIndiceArray, nomeAula);//chama a funcao procurarNomeAula e vê que nome está la e passa o para posNome
        if(posNome != -1)
        {
            printf("Nome ja em uso, insira um nome valido: \n");
        }
    }
    while (posNome != -1);
    strcpy(nome,nomeAula);//copia a string do nomeAula para o nome
}

int lerCodigoDaUC(dadosUC arrayUC[MAX_UCS], int posIndiceArrayUC)
{
    int posCodigo, codigoDaUC;

    //ler codigo da UC
    printf("Insira o codigo da UC correspondente a aula: \n");

    do
    {
        codigoDaUC = lerInteiro(MIN_UCS, MAX_UCS); //maximo de ler inteiro é o ultimo codigo do arrayUC
        posCodigo = procurarDadosUC(arrayUC, posIndiceArrayUC, codigoDaUC);
        printf("%d", posCodigo);
        if(posCodigo == -1)
        {
            printf("Nao existe nenhuma UC com esse codigo, insira um codigo valido:");
        }
    }
    while(posCodigo == -1);
    return codigoDaUC;
}

int lerTipoAula()
{
    //ler o tipo de aula -> T, TP ou PL
    printf("Insira o tipo de aula: 0 - T, 1 - TP, 2 - PL \n");
    return lerInteiro(MIN_TIPO_AULA, MAX_TIPO_AULA);
}

void lerNomeDocente(char nome[MAX_STRING_NOME_DOCENTE])
{
    //ler nome do docente
    printf("Insira o nome do docente: \n");
    lerString(nome,MAX_STRING_NOME_DOCENTE);
}

void lerDataAula(tipoData *data)
{
    //ler data da aula
    printf("Insira a data da aula:\n");
    lerData(data);
}

void lerHoraInicioAula(tipoHora *tempoAula)
{
    //ler hora de inicio da aula

    printf("Insira a hora de inciio da aula:\n");
    tempoAula->hora = lerInteiro(MIN_HORA_INICIO_AULA, MAX_HORA_INICIO_AULA);

    printf("Insira os minutos do inicio da aula:");
    tempoAula->minuto = lerInteiro(MIN_MINUTOS_INICIO_AULA, MAX_MINUTOS_INICIO_AULA);

}

void lerHoraFimAula(tipoHora *tempoAula)
{
    //ler hora do fim da aula

    printf("Insira a hora do fim da aula:\n");
    tempoAula->hora = lerInteiro(MIN_HORA_FIM_AULA, MAX_HORA_FIM_AULA);

    printf("Insira os minutos do fim da aula:\n");
    tempoAula->minuto = lerInteiro(MIN_MINUTOS_FIM_AULA, MAX_MINUTOS_FIM_AULA);
}

int estadoAula()
{
    //ler o estado da aula (agendada, a decorrer ou realizada)
    printf("Insira o estado da aula: 0-> agendada, 1-> a decorrer ou 2-> realizada\n");
    return lerInteiro(MIN_ESTADO_AULA,MAX_ESTADO_AULA);
}

int opGravacao()
{
    //ler opcao de gravacao da aula: 0-nao , 1-sim
    printf("Deseja gravar a aula? Se nao -> 0, se sim -> 1\n");
    return lerInteiro(MIN_OP_GRAVACAO, MAX_OP_GRAVACAO);
}

//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosAula // inserir /agendar
dadosAula *agendarAula(dadosAula *vAulasOnline, int *posIndiceArrayAulas, dadosUC vDadosUC[MAX_UCS], int posIndiceArrayAulasUC)//*vAulasOnline - array dinamico
{
    dadosAula *vBackup; // declaraçao do vBackup
    vBackup = vAulasOnline;

    vAulasOnline=realloc(vAulasOnline, *posIndiceArrayAulas+1*sizeof(dadosAula));
    if (vAulasOnline == NULL)//se for == NULL nao aloca na memoria e faz backup da info
    {
        printf("Erro ao alocar memoria\n");
        vAulasOnline = vBackup;
    }
    else  //vamos fazer a reserva
    {

        //ler nome da aula
        lerNomeAula(vAulasOnline[*posIndiceArrayAulas].nome,vAulasOnline,*posIndiceArrayAulas);

        //ler codigo da UC
        vAulasOnline[*posIndiceArrayAulas].codigoUC = lerCodigoDaUC(vDadosUC, posIndiceArrayAulasUC);

        //ler o tipo de aula -> T, TP ou PL
        vAulasOnline[*posIndiceArrayAulas].tipoAula = lerTipoAula();

        //ler nome do docente
        lerNomeDocente(vAulasOnline[*posIndiceArrayAulas].nomeDocente);

        //ler data da aula
        lerDataAula(&(vAulasOnline[*posIndiceArrayAulas].data));

        //ler hora de inicio da aula
        lerHoraInicioAula(&(vAulasOnline[*posIndiceArrayAulas].horaInicio));

        //ler hora do fim da aula
        lerHoraFimAula(&(vAulasOnline[*posIndiceArrayAulas].horaFim));

        //ler o estado da aula (agendada, a decorrer ou realizada)
        vAulasOnline[*posIndiceArrayAulas].estado = enumEstadoAula.agendada;

        //ler opcao de gravacao da aula: 0-nao , 1-sim
        vAulasOnline[*posIndiceArrayAulas].gravacao = opGravacao();

        (*posIndiceArrayAulas)++;//adiciona nova informacao ao array
    }
    return vAulasOnline;
}//FIM inserirDadosAula



void listarDadosAula(dadosAula *vAulasOnline, int posIndiceArray)
{
    int i;
    printf("Nome: \t Codigo: \tTipo: \tDocente: \tData: \tHora Inicio: \tHora Fim:\tEstado: \tGrava: \n");

    for(i=0; i<posIndiceArray; i++)
    {
        printf("%s\t %d\t %d\t %s\t %d\t%d\t%d\t %d\t%d\t %d\t%d\t %d\t %d\n",vAulasOnline[i].nome, vAulasOnline[i].codigoUC, vAulasOnline[i].tipoAula, vAulasOnline[i].nomeDocente,
               vAulasOnline[i].data.dia, vAulasOnline[i].data.mes, vAulasOnline[i].data.ano, vAulasOnline[i].horaInicio.hora, vAulasOnline[i].horaInicio.minuto, vAulasOnline[i].horaFim.hora,
               vAulasOnline[i].horaFim.minuto, vAulasOnline[i].estado, vAulasOnline[i].gravacao);
    }
}


dadosAula *eliminarAula (dadosAula *vAulasOnline, int *quantAulas)
{
    int posNome,i;
    dadosAula *vBackup; // declaraçao do vBackup
    char nomeAula[MAX_STRING_NOME_AULA];

    if(*quantAulas == 0)
    {
        printf("Ainda nao existem aulas registadas\n");
    }
    else
    {
        printf("Insira o nome da aula a eliminar\n");
        lerString(nomeAula, MAX_STRING_NOME_AULA);
        posNome = procurarNomeAula(vAulasOnline, *quantAulas, nomeAula); //devolve a posiçao do nome

        if(posNome == -1)
        {
            printf("Nao existe uma aula com esse nome\n");
        }
        else
        {
            vBackup = vAulasOnline;

            for(i = posNome; i < *quantAulas; i++)
            {
                // Copia todas as aulas uma posição para trás - i+1 porque acrescenta logo na iteraçao
                vAulasOnline[i] = vAulasOnline[i+1];
            }
            vAulasOnline=realloc(vAulasOnline, *quantAulas-1*sizeof(dadosAula));
            if (vAulasOnline == NULL)//se for == NULL nao aloca na memoria e faz backup da info
            {
                printf("Erro ao alocar memoria\n");
                vAulasOnline = vBackup;
            }
            (*quantAulas)--;
            //ficheiroLogs(vAulasOnline[posNome],"Aula eliminada");
        }
    }
    return vAulasOnline;
}


void alterarAula(dadosAula *vAulasOnline, int quantAulas,dadosUC dadosDaUC[MAX_UCS], int indiceArrayUC, char nomeAula[MAX_STRING_NOME_AULA], int opcao)
{
    int posNome;

    //verifica se a pos existe no vetor
    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula); //devolve a posiçao do nome

    if(posNome == -1)
    {
        printf("Ainda nao existem aulas registadas\n");
    }
    else
    {
        switch(opcao)
        {
        case 0: //altera tudo
            lerNomeAula(vAulasOnline[posNome].nome, vAulasOnline, quantAulas);
            vAulasOnline[posNome].codigoUC = lerCodigoDaUC(dadosDaUC, indiceArrayUC);
            vAulasOnline[posNome].tipoAula = lerTipoAula();
            lerNomeDocente(vAulasOnline[posNome].nomeDocente);
            lerDataAula(&vAulasOnline[posNome].data);
            lerHoraInicioAula(&vAulasOnline[posNome].horaInicio);
            lerHoraFimAula(&vAulasOnline[posNome].horaFim);
            vAulasOnline[posNome].estado = estadoAula();
            vAulasOnline[posNome].gravacao = opGravacao();
            break;

        //altera campo a campo
        case 1:
            lerNomeAula(vAulasOnline[posNome].nome, vAulasOnline, quantAulas);
            break;
        case 2:
            vAulasOnline[posNome].codigoUC = lerCodigoDaUC(dadosDaUC, indiceArrayUC);
            break;
        case 3:
            vAulasOnline[posNome].tipoAula = lerTipoAula();
            break;
        case 4:
            lerNomeDocente(vAulasOnline[posNome].nomeDocente);
            break;
        case 5:
            lerDataAula(&vAulasOnline[posNome].data);
            break;
        case 6:
            lerHoraInicioAula(&vAulasOnline[posNome].horaInicio);
            break;
        case 7:
            lerHoraFimAula(&vAulasOnline[posNome].horaFim);
            break;
        case 8:
            vAulasOnline[posNome].estado = estadoAula();
            break;
        case 9:
            vAulasOnline[posNome].gravacao = opGravacao();
            break;
        }
    }
}

void registarIncioAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA])
{
    int posNome;

    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula);

    if(posNome != -1)
    {
        if(vAulasOnline[posNome].estadoAula == enumEstadoAula.agendada)
        {
            vAulasOnline[posNome].estadoAula = enumEstadoAula.decorrer;
        }
    }
}

void registarFimAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA])
{
    int posNome;

    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula);

    if(posNome != -1)
    {
        if(vAulasOnline[posNome].estadoAula == enumEstadoAula.decorrer)
        {
            vAulasOnline[posNome].estadoAula = enumEstadoAula.realizada;
        }
    }

}
