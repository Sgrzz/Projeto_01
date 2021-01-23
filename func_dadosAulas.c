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
        posNome = procurarNomeAula(vAulasOnline, posIndiceArray, nomeAula);//chama a funcao procurarNomeAula e v� que nome est� la e passa o para posNome
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
        codigoDaUC = lerInteiro(MIN_UCS, MAX_UCS); //maximo de ler inteiro � o ultimo codigo do arrayUC
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

//ler hora e verifca se essa hora est� dentro do permitido (somar o tempo de aula da uc para ver se est� dentro)
//verifica se aula sobrepoem-se  com outra aula do mesmo tipo (T TP PL)
//da UC -> regime (diurno ou pos laboral)
//da aulaOnline -> tipo (T TP PL)
//do array AulasOnline para comparar se a mais aulas com a mesma hora

//devolve
//horaInicio
//horaFim
void lerHoraAula(tipoHora *horaInicio, tipoHora *horaFim,dadosAula *vDadosAula, int indiceDadosAula, enum enumRegime regime, enum enumTipoAula tipoAula,tipoTempoAulas tempoAulas, int codigoUC)
{
    int horaCompInicio = 0, horaCompFim = 0, i, duracao;
    tipoHora tempo, horaDuracao;

    horaDuracao.hora = 0;
    horaDuracao.minuto = 0;

    switch (tipoUC)
    {
        case 0:
            horaCompInicio = 8;
            horaCompFim = 18;
            break;
        case 1:
            horaCompInicio = 18;
            horaCompFim = 24;
            break;
    }

    switch(tipoAula)
    {
        case 0:
            duracao = tempoAulas.T;
            break;
        case 1:
            duracao = tempoAulas.TP;
            break;
        case 2:
            duracao = tempoAulas.PL;
            break;
    }

    //1- dividir os minutos por 60
    //2- a parte inteira sao as horas, a parte dos minutos � o resto a multiplicar por 60
    horaDuracao.hora = duracao/60;
    horaDuracao.minuto = (duracao%60)*60;

    do{

        printf("Insira a hora de inciio da aula:\n");
        tempo.hora = lerInteiro(MIN_HORA_INICIO_AULA, MAX_HORA_INICIO_AULA);

        printf("Insira os minutos do inicio da aula:");
        tempo.minuto = lerInteiro(MIN_MINUTOS_INICIO_AULA, MAX_MINUTOS_INICIO_AULA);



        for(i = 0; i<indiceDadosAula;i++)
        {
            if (vDadosAula[i].codigoUC = codigoUC)
            {
                if ()
                {

                }
            }

        }


        if (!(tempo.hora>=horaCompInicio && tempo.hora<=horaCompFim))
        {
            printf("hora invalida para o regime especificado na UC");
        }

    }while((tempo.hora<horaCompInicio || tempo.hora>horaCompFim));


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
    dadosAula *vBackup; // declara�ao do vBackup
    vBackup = vAulasOnline;
    int codigoUC, indiceUC;


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
        codigoUC = lerCodigoDaUC(vDadosUC, posIndiceArrayAulasUC);
        vAulasOnline[*posIndiceArrayAulas].codigoUC = codigoUC;

        indiceUC = procurarDadosUC(vDadosUC,posIndiceArrayAulasUC,codigoUC);

        //ler o tipo de aula -> T, TP ou PL
        vAulasOnline[*posIndiceArrayAulas].tipoAula = lerTipoAula();

        //ler nome do docente
        lerNomeDocente(vAulasOnline[*posIndiceArrayAulas].nomeDocente);

        //ler data da aula
        lerDataAula(&(vAulasOnline[*posIndiceArrayAulas].data));

        //ler hora de inicio da aula
        lerHoraInicioAula(&(vAulasOnline[*posIndiceArrayAulas].horaInicio),vDadosUC[indiceUC].tipoUC);

        //ler hora do fim da aula
        //lerHoraFimAula(&(vAulasOnline[*posIndiceArrayAulas].horaFim));


        //ler o estado da aula (agendada, a decorrer ou realizada)
        vAulasOnline[*posIndiceArrayAulas].estado = agendada;

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
    dadosAula *vBackup; // declara�ao do vBackup
    char nomeAula[MAX_STRING_NOME_AULA];

    if(*quantAulas == 0)
    {
        printf("Ainda nao existem aulas registadas\n");
    }
    else
    {
        printf("Insira o nome da aula a eliminar\n");
        lerString(nomeAula, MAX_STRING_NOME_AULA);
        posNome = procurarNomeAula(vAulasOnline, *quantAulas, nomeAula); //devolve a posi�ao do nome

        if(posNome == -1)
        {
            printf("Nao existe uma aula com esse nome\n");
        }
        else
        {
            vBackup = vAulasOnline;

            for(i = posNome; i < *quantAulas; i++)
            {
                // Copia todas as aulas uma posi��o para tr�s - i+1 porque acrescenta logo na itera�ao
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
    int posNome,codigoUC,indiceUC;

    //verifica se a pos existe no vetor
    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula); //devolve a posi�ao do nome

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
            //fim de aula n esquecer
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
        if(vAulasOnline[posNome].estado == T)
        {
            vAulasOnline[posNome].estado = decorrer;
        }
    }
}

void registarFimAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA])
{
    int posNome;

    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula);

    if(posNome != -1)
    {
        if(vAulasOnline[posNome].estado == decorrer)
        {
            vAulasOnline[posNome].estado = realizada;
        }
    }

}
