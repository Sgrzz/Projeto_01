#include <stdio.h>
#include <string.h>
#include <math.h>

#include "func_aux.h"
#include "constantes.h"
#include "estruturas.h"



//funcao que compara duas horas e verifica que n se sobrepoem, devolve 0 para falso 1 para verdade
int compararHoras(tipoHora horaInicio, tipoHora horaInicio2, tipoHora duracao)
{

    int condicaoDeReturn = 0, horaInicioEmMinutos = 0, horaInicio2EmMinutos = 0, duracaoEmMinutos = 0;

    horaInicioEmMinutos = horaInicio.hora*60 + horaInicio.minuto;
    horaInicio2EmMinutos = horaInicio2.hora*60 + horaInicio2.minuto;
    duracaoEmMinutos = duracao.hora*60 + duracao.minuto;

    if (!(horaInicioEmMinutos+duracaoEmMinutos<=horaInicio2EmMinutos || horaInicio2EmMinutos + duracaoEmMinutos <= horaInicioEmMinutos)) //se a hora do inicio em minutos + a duracao em minutos for menor ou igual n se sobrepoem
    {
        condicaoDeReturn = 1;
    }

    return condicaoDeReturn;
}

//funcao para somar 2 horas devolta o somatorio
tipoHora somarHora(tipoHora hora1, tipoHora hora2)
{
    tipoHora horaAux;
    int soma = 0;
    horaAux.hora = 0;
    horaAux.minuto = 0;

    soma = hora1.hora*60 + hora2.hora*60 + hora1.minuto + hora2.minuto;

    horaAux.hora = soma/60;
    horaAux.minuto = ((soma/60.0)-horaAux.hora)*60;

    while(horaAux.hora>=24)
    {
        horaAux.hora -= 24;
    }

    return horaAux;

}

//funcao para subtrair horas devolve o resultado
/*
tipoHora subtrairHora(tipoHora hora1, tipoHora hora2)
{
    tipoHora horaAux;
    int soma = 0;

    horaAux.hora = 0;
    horaAux.minuto = 0;

    soma = hora1.hora*60 - hora2.hora*60 - hora1.minuto - hora2.minuto;

    horaAux.hora = soma/60;
    horaAux.minuto = (soma%60)*60;

    if (horaAux.hora<0)
    {
        horaAux.hora -= 24;
    }

    return horaAux;
}*/

//tipoData lerData(){
//    tipodata data;
//
//    //data.dia
//
//    return data;
//}

//OU

int compararDatas(tipoData a, tipoData b)
{
    if (a.ano != b.ano)
        return a.ano - b.ano;
    if (a.mes != b.mes)
        return a.mes - b.mes;
    return (a.dia - b.dia);
}



void lerData(tipoData *data){
    int maxDias;

    printf("Ano: ");
    data->ano = lerInteiro(MIN_ANO,MAX_ANO);//estes valores devem ser definidos como constantes
    printf("Mes: ");
    data->mes = lerInteiro(MIN_MES,MAX_MES);//estes valores devem ser definidos como constantes

    switch(data->mes){
    case 2:
        // um ano � bissexto se
        // ano % 400 == 0
        // ou
        // ano % 4 == 0 E ano % 100 != 0
        if ((data->ano%400==0) || (data->ano%4==0 && data->ano%100!=0)){
            maxDias = 29;
        }
        else{
            maxDias = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDias = 30;
        break;
    default:
        maxDias = 31;
    }

    printf("Dia: ");
    data->dia = lerInteiro(MIN_DIA,maxDias);
}


// Acrescentada vari�vel de controlo ao scanf
int lerInteiro(int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores v�lidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {
            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores v�lidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do{			// Repete leitura caso sejam obtidas strings vazias

        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1){
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n"); //vetorCaracteres tem \n e \0
        }

    } while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n'){  // ficaram caracteres no buffer....
        limpaBufferStdin();  // apenas faz sentido limpar buffer se la ficarem caracteres
    }
    else{
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

void limpaBufferStdin()
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);

}
