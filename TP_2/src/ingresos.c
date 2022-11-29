/*
 * ingresos.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ingresos.h"
#include "nexo.h"

int ingresarFloat(float* resultado,char* mensaje)
{
	int retorno=-1;
	int flag;
	char	numero[999999];
	int tamIngreso;
	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);
			tamIngreso=strlen(numero);
            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(numero+i)))==0)
            	{
            		flag=1;
            		printf("ERROR, Ingrese un numero\n");
            		break;
            	}
            }
            if(flag==0)
            {
            	retorno=0;
            	*resultado=atoi(numero);
            }
		}

	}while(retorno!=0);
	return retorno;
}
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo)
{
	int retorno=-1;
	float numero;
	do
	{
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
		{
			ingresarFloat(&numero,mensaje);
			if(numero>=minimo)
			{
				*resultado=numero;
				retorno=0;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}
	}while(retorno!=0);

	return retorno;
}
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno=-1;
	int flag;
	//int tamIngreso;
	char numero[999999];

	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);

			if(isdigit(*numero)==0)
			{
				flag=1;
				printf("ERROR, Ingrese un numero\n");
			}

            if(flag==0)
            {
            	*resultado=atoi(numero);
                if(*resultado>=minimo && *resultado<= maximo)
                {
                	retorno=0;
                }
                else
                {
                	printf("%s",mensajeError);
                }
            }
		}

	}while(retorno!=0);

	return retorno;
}
int ingresarIntConRangoReintentos(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int flag;
	//int tamIngreso;
	char numero[999999];

	do
	{
		flag=0;
		if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(numero);

			if(isdigit(*numero)==0)
			{
				flag=1;
				printf("ERROR, Ingrese un numero\n");
			}

            if(flag==0)
            {
            	*resultado=atoi(numero);
                if(*resultado>=minimo && *resultado<= maximo)
                {
                	retorno=0;
                }
                else
                {
                	printf("%s",mensajeError);
                }
            }
		}
		if(retorno==-1)
		{
			reintentos=reintentos-1;
			printf("ATENCION: QUEDAN %d INTENTOS\n",reintentos);
		}

	}while(retorno!=0 && reintentos>0);

	return retorno;
}
void confirmarSalida(int* flag)
{
	int aux;
	if(ingresarIntConRangoReintentos(&aux, "ADVERTENCIA, CONFIRME QUE DESEA SALIR MARCANDO 2, O 1 PARA SEGUIR OPERANDO.\n", "ERROR, INGRESE OPCION VALIDA.\n", 1, 2,3)==-1)
	{
		//SI SE QUEDA SIN REINTENTOS, SALE
		printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
		*flag=1;
	}
	else
	{
		if(aux==2)
		{
			printf("<<<<<<<<<<<<<<<<<<<<SALIR>>>>>>>>>>>>>>>>>>>");
			*flag=1;
		}
	}
}

int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int tamIngreso;
    int flag;
    if(textoIngresado!=NULL && mensaje!=NULL && mensajeError!=NULL && tam>0)
    {
    	while(retorno==-1)
    	{
    		flag=0;
            printf("%s",mensaje);
            fflush(stdin);
            gets(textoIngresado);//GETS SE AGARRA EL BUFFER DEL TECLADO, CORTA EL REGISTRO CON EL ENTER

            tamIngreso=strlen(textoIngresado);

            for(int i=0;i<tamIngreso;i++)
            {
            	if(isdigit((*(textoIngresado+i)))!=0)
            	{
            		flag=1;
            		break;
            	}
            }
            if(strlen(textoIngresado)<=tam && flag==0)
            {
            	retorno=0;
            }else
            {
            	printf("%s",mensajeError);
            }
    	}

    }
    return retorno;
}
int ingresarShortConRango(short* resultado, char* mensaje, char* mensajeError, short minimo, short maximo)
{
	short retorno=-1;
	int flag;
	int tamIngreso;
	char numero[999999];
	do
		{
			flag=0;
			if(resultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo)
			{
				printf("%s",mensaje);
				fflush(stdin);
				gets(numero);

	            tamIngreso=strlen(numero);

	            for(int i=0;i<tamIngreso;i++)
	            {
	            	if(isdigit((*(numero+i)))==0)
	            	{
	            		flag=1;
	            		printf("ERROR, Ingrese un numero\n");
	            		break;
	            	}
	            }
	            if(flag==0)
	            {
	            	*resultado=atoi(numero);
	                if(*resultado>=minimo && *resultado<= maximo)
	                {
	                	retorno=0;
	                }
	                else
	                {
	                	printf("%s",mensajeError);
	                }
	            }
			}

		}while(retorno!=0);
	return retorno;
}

