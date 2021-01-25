#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
    printf("\nInsira o nome da aula ->");

    do
    {
        lerString(nomeAula, MAX_STRING_NOME_AULA);
        posNome = procurarNomeAula(vAulasOnline, posIndiceArray, nomeAula);//chama a funcao procurarNomeAula e v� que nome est� la e passa o para posNome
        if(posNome != -1)
        {
            printf("\nNome ja em uso, insira um nome valido: ->");
        }
    }
    while (posNome != -1);
    strcpy(nome,nomeAula);//copia a string do nomeAula para o nome
}

int lerCodigoDaUC(dadosUC arrayUC[MAX_UCS], int posIndiceArrayUC)
{
    int posCodigo, codigoDaUC;

    //ler codigo da UC
    printf("\nInsira o codigo da UC correspondente a aula ->");

    do
    {
        codigoDaUC = lerInteiro(MIN_UCS, MAX_UCS); //maximo de ler inteiro � o ultimo codigo do arrayUC
        posCodigo = procurarDadosUC(arrayUC, posIndiceArrayUC, codigoDaUC);
        printf("%d", posCodigo);
        if(posCodigo == -1)
        {
            printf("\nNao existe nenhuma UC com esse codigo, insira um codigo valido ->");
        }
    }
    while(posCodigo == -1);
    return codigoDaUC;
}

int lerTipoAula()
{
    //ler o tipo de aula -> T, TP ou PL
    printf("\nInsira o tipo de aula: 0 - T, 1 - TP, 2 - PL ->");
    return lerInteiro(MIN_TIPO_AULA, MAX_TIPO_AULA);
}

void lerNomeDocente(char nome[MAX_STRING_NOME_DOCENTE])
{
    //ler nome do docente
    printf("\nInsira o nome do docente ->");
    lerString(nome,MAX_STRING_NOME_DOCENTE);
}

void lerDataAula(tipoData *data)
{
    //ler data da aula
    printf("\nInsira a data da aula ->");
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
void lerHoraAula(tipoHora *horaInicio, tipoHora *horaFim,dadosAula *vDadosAula, int indiceDadosAula, enum enumRegime regime, enum enumTipoAula tipoAula,tipoAulas tempoAulas, int codigoUC)
{
    int horaCompInicio = 0, horaCompFim = 0, i, duracao, condicaoSobrepoem = 0, podeSairWhile = 1;
    tipoHora tempo, horaDuracao;

    horaDuracao.hora = 0;
    horaDuracao.minuto = 0;

    switch (regime)
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
    horaDuracao.minuto = (((duracao/60.0)-horaDuracao.hora)*60);

    do
    {

        printf("\nInsira a hora de inicio da aula ->");
        tempo.hora = lerInteiro(MIN_HORA, MAX_HORA);

        printf("\nInsira os minutos do inicio da aula ->");
        tempo.minuto = lerInteiro(MIN_MINUTOS, MAX_MINUTOS);

        podeSairWhile = 1;

        for(i = 0; i<indiceDadosAula; i++)
        {
            if (vDadosAula[i].codigoUC == codigoUC)
            {
                condicaoSobrepoem = compararHoras(tempo,vDadosAula[i].horaInicio,horaDuracao);
                if (condicaoSobrepoem)
                {
                    printf("\nJa existe uma aula agendada para esta hora.");
                    podeSairWhile = 0;
                    i = indiceDadosAula;
                }
            }

        }

        if (!(tempo.hora >= horaCompInicio && tempo.hora <= horaCompFim))
        {
            printf("\nhora invalida para o regime especificado na UC");
            podeSairWhile = 0;
        }

    }
    while(!podeSairWhile);

    *horaInicio = tempo;
    *horaFim = somarHora(*horaInicio,horaDuracao);

}

int estadoAula()
{
    //ler o estado da aula (agendada, a decorrer ou realizada)
    printf("\nInsira o estado da aula: 0-agendada, 1-a decorrer ou 2-realizada ->");
    return lerInteiro(MIN_ESTADO_AULA,MAX_ESTADO_AULA);
}

int opGravacao()
{
    //ler opcao de gravacao da aula: 0-nao , 1-sim
    printf("\nDeseja gravar a aula? Se nao - 0, se sim - 1 ->");
    return lerInteiro(MIN_OP_GRAVACAO, MAX_OP_GRAVACAO);
}

//pede todos os dados ao utilizador para preencher uma variavel do tipo estrutura dadosAula // inserir /agendar
dadosAula *agendarAula(dadosAula *vAulasOnline, int *posIndiceArrayAulas, dadosUC vDadosUC[MAX_UCS], int posIndiceArrayAulasUC)//*vAulasOnline - array dinamico
{
    dadosAula *vBackup; // declara�ao do vBackup
    vBackup = vAulasOnline;
    int codigoUC, indiceUC;

    vAulasOnline=realloc(vAulasOnline, (*posIndiceArrayAulas+1)*sizeof(dadosAula));
    if (vAulasOnline == NULL)//se for == NULL nao aloca na memoria e faz backup da info
    {
        printf("\nErro ao alocar memoria");
        vAulasOnline = vBackup;
    }
    else if (!posIndiceArrayAulasUC)
    {
        printf("\nNao existem UC's para agendar aulas.");
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
        lerHoraAula(&vAulasOnline[*posIndiceArrayAulas].horaInicio,&vAulasOnline[*posIndiceArrayAulas].horaFim,vAulasOnline,
                    *posIndiceArrayAulas,vDadosUC[indiceUC].regime,vAulasOnline[*posIndiceArrayAulas].tipoAula,vDadosUC[indiceUC].duracaoAulas,codigoUC);

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
        printf("\nAinda nao existem aulas registadas");
    }
    else
    {
        printf("\nInsira o nome da aula a eliminar");
        lerString(nomeAula, MAX_STRING_NOME_AULA);
        posNome = procurarNomeAula(vAulasOnline, *quantAulas, nomeAula); //devolve a posi�ao do nome

        if(posNome == -1)
        {
            printf("\nNao existe uma aula com esse nome");
        }
        else
        {
            vBackup = vAulasOnline;

            for(i = posNome; i < *quantAulas; i++)
            {
                // Copia todas as aulas uma posi��o para tr�s - i+1 porque acrescenta logo na itera�ao
                vAulasOnline[i] = vAulasOnline[i+1];
            }
            vAulasOnline=realloc(vAulasOnline, (*quantAulas-1)*sizeof(dadosAula));
            if (vAulasOnline == NULL)//se for == NULL nao aloca na memoria e faz backup da info
            {
                printf("\nErro ao alocar memoria");
                vAulasOnline = vBackup;
            }
            else
            {
                (*quantAulas)--;
            }
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
        printf("\nAinda nao existem aulas registadas");
    }
    else
    {
        switch(opcao)
        {
        case 0: //altera tudo
            lerNomeAula(vAulasOnline[posNome].nome, vAulasOnline, quantAulas);
            codigoUC = lerCodigoDaUC(dadosDaUC, indiceArrayUC);
            vAulasOnline[posNome].codigoUC = codigoUC;
            indiceUC = procurarDadosUC(dadosDaUC,indiceArrayUC,codigoUC);
            vAulasOnline[posNome].tipoAula = lerTipoAula();
            lerNomeDocente(vAulasOnline[posNome].nomeDocente);
            lerDataAula(&vAulasOnline[posNome].data);

            lerHoraAula(&vAulasOnline[posNome].horaInicio,&vAulasOnline[posNome].horaFim,vAulasOnline,
                        quantAulas,dadosDaUC[indiceUC].regime,vAulasOnline[posNome].tipoAula,dadosDaUC[indiceUC].duracaoAulas,codigoUC);

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
            codigoUC = vAulasOnline[posNome].codigoUC;
            indiceUC = procurarDadosUC(dadosDaUC,indiceArrayUC,codigoUC);
            lerHoraAula(&vAulasOnline[posNome].horaInicio,&vAulasOnline[posNome].horaFim,vAulasOnline,
                        quantAulas,dadosDaUC[indiceUC].regime,vAulasOnline[posNome].tipoAula,dadosDaUC[indiceUC].duracaoAulas,codigoUC);
            break;
        case 7:
            vAulasOnline[posNome].estado = estadoAula();
            break;
        case 8:
            vAulasOnline[posNome].gravacao = opGravacao();
            break;
        }
    }
}

void registarInicioAula(dadosAula *vAulasOnline, int quantAulas, char nomeAula[MAX_STRING_NOME_AULA])
{
    int posNome;

    posNome = procurarNomeAula(vAulasOnline, quantAulas, nomeAula);

    if(posNome != -1)
    {
        if(vAulasOnline[posNome].estado == agendada)
        {
            vAulasOnline[posNome].estado = decorrer;
        }
    }
}
// ver se � chamado algum sitio da vida
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

void infoAulasOnline(dadosAula *vAulasOnline, int indiceAulasOnline,int codigoUC)
{
    int i;
    char tipo[MAX_STRING];
    tipoAulas quantAulas;
    quantAulas.T = 0;
    quantAulas.TP = 0;
    quantAulas.PL = 0;
    for (i=0; i<indiceAulasOnline; i++)
    {
        if ((vAulasOnline[i].codigoUC == codigoUC) && (vAulasOnline[i].estado == realizada))
        {
            switch(vAulasOnline[i].tipoAula)
            {
            case 0:
                quantAulas.T++;
                break;
            case 1:
                quantAulas.TP++;
                break;
            case 2:
                quantAulas.PL++;
                break;
            }
        }
    }

    printf("\nAulas realizadas teoricas: %d | teorico praticas: %d | pratico laboratoriais: %d",quantAulas.T,quantAulas.TP,quantAulas.PL);
    printf("\nAulas agendadas:");
    for (i=0; i<indiceAulasOnline; i++)
    {
        if ((vAulasOnline[i].codigoUC == codigoUC) && (vAulasOnline[i].estado == agendada))
        {
            switch(vAulasOnline[i].tipoAula)
            {
            case 0:
                strcpy(tipo,"teorica");
                break;
            case 1:
                strcpy(tipo,"teorico pratica");
                break;
            case 2:
                strcpy(tipo,"pratico laboratorial");
                break;
            }
            printf("Tipo: %s",tipo);
        }
    }
}


/**< // Registar o acesso (online ou offline) de um estudante a uma aula (online ou gravada).
 A informa��o do acesso (n�mero do estudante, identifica��o da aula e tipo de acesso)
 dever� ser acrescentado num log, em ficheiro de texto e em ficheiro bin�rio. */

void RegistarAcessoAula(dadosAula *vAulasOnline, int indiceAulas)
{

    int numEstudante, indice;
    char nomeAula[MAX_STRING_NOME_AULA];

    if(indiceAulas == 0) //ve se pode registar a aula
    {
        printf("Ainda nao existem aulas para aceder\n");// nao da para registar
    }
    else // existem aulas logo vai pedir o nome da aula
    {
        do
        {
            // vai pedir o nome da aula, le-o, procura e v� se existe um nome igual e devolve o indice,
                //se nao encontrar devolve-1
            printf("Insira o nome da aula\n");
            lerString(nomeAula, MAX_STRING_NOME_AULA);
            indice = procurarNomeAula(vAulasOnline, indiceAulas, nomeAula);

            if(indice == -1) //verifica se o indice � valido se nao encontrou diz que � invalido
            {
                printf("Nome invalido. Insira nome da aula valido\n");
            }
            else if(vAulasOnline[indice].estado == agendada) // vai verificar se a aula esta agendada, se estiver agendada manda msg de erro
            {
                printf("Nao e possivel aceder a aula\n");
            }
        }
        while (indice == -1 && vAulasOnline[indice].estado == agendada);

        //aula esta a decorrer (online)
        if(vAulasOnline[indice].estado == decorrer)
        {
            vAulasOnline[indice].numEstudantesOnline++;
        }


        //e se esta terminada (se foi gravada) (offline)


        if(vAulasOnline[indice].estado == realizada && vAulasOnline[indice].gravacao == sim)
        {
             vAulasOnline[indice].numEstudantesGravacao++;
        }
        //nome � valido logo vai pedir as infos
        printf("Insira o numero de estudante\n");
        numEstudante = lerInteiro(MIN_ESTUDANTES, MAX_ESTUDANTES);

        //gravar o n de acessos
        //gravar no log o n do aluno, o codigo e o tipo de acessoAula


    }



}




