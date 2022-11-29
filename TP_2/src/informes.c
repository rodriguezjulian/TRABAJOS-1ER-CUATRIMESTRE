/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Julian Rodriguez
 */

#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "nexo.h"
#include "ingresos.h"

#define VACIO 1
#define OCUPADO 0


int listarJugadores(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores,int referenciaOrdenamiento)
{
	//referenciaOrdenamiento -> 1. ordeno por orden alfabetico
	//referenciaOrdenamiento -> 2.ordeno por id
	int retorno=-1;
	char descripcion[50];
	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0)
	{
		if(referenciaOrdenamiento==1)
		{
			ordenarJugadoresAlfabeticamente(jugadores,confederaciones,tam);
		}
		else
		{
			ordenarJugadoresXId(jugadores, tam);
		}

		printf("+=====================================================================================================================================+\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",-4," ID",-30,"           NOMBRE",-30,"         POSICION",
					-13," N°CAMISETA",-16,"     SUELDO",-15," CONFEDERACION",-20,"  ANIOS DE CONTRATO");
		printf("+=====================================================================================================================================+\n");
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				asignarDescripcionConfederacion(jugadores,confederaciones,6, descripcion ,i);
				printf("| %*d|%*s|%*s|     %*d|%*.2f|%*s|         %*d|\n",-3,(*(jugadores+i)).id,-30,(*(jugadores+i)).nombre,-30,(*(jugadores+i)).posicion,-7,(*(jugadores+i)).numeroCamiseta,-16,(*(jugadores+i)).salario,-15,descripcion,-11,(*(jugadores+i)).aniosContrato);
			}
		}
		printf("+=====================================================================================================================================+\n");
		retorno=0;
	}
	else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}
	return retorno;
}
int listarJugadoresXConfederaciones(eJugador* jugadores,eConfederacion* confederaciones,int tam, int tamConfederaciones)
{
	int retorno=-1;
	int idConf=100;

	if(jugadores!=NULL && confederaciones!=NULL)
	{
		retorno=0;
		for(int i=0;i<tamConfederaciones;i++)
		{
			listarJugadoresXUnaConf(jugadores,confederaciones,tam,idConf,tamConfederaciones);

			idConf=idConf+1;
		}
	}

	return retorno;
}
int informarTotalyMediaDeSalarios(eJugador* jugadores, int tam, int contadorJugadores)
{
	int jugPorArribaDeLaMedia;
	int retorno=-1;
	float totalSalarios;
	float promedioSalarios;
	if(jugadores!=NULL)
	{
		if(acumularTotalSalarios(jugadores,tam, &totalSalarios)==0)
		{
			promedioSalarios=calcularPromedio(totalSalarios, contadorJugadores);
			if(calcularJugPorArribaDeLaMedia( jugadores,  promedioSalarios,&jugPorArribaDeLaMedia,tam)==0)
			{
				printf("%s\n|            %*s|      %*s|\n%s\n","+========================================================+",
						-23,"DESCRIPCION",-14,"RESULTADO","+========================================================+");


				printf("|%*s|   %*.2f|\n|%*s|   %*.2f|\n|%*s|         %*d|\n%s\n",-35,"TOTAL DE SALARIOS",-17,totalSalarios,-35,
						"PROMEDIO DE SALARIOS",-17,promedioSalarios,-35,"JUGADORES POR ARRIBA DEL PROMEDIO",-11,jugPorArribaDeLaMedia,
						"+========================================================+");
				retorno=0;
			}
			else
			{
				printf("ERROR al calcular jugadores por arriba de la media.\n");
			}
		}
		else
		{
			printf("ERROR al intentar acumular salarios.\n");
		}
	}

	return retorno;
}
int mostrarConfConMasAniosContrato(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{
	int retorno=-1;
	int maxAniosContrato;
	int arrayAniosAcumulados[tamConfederaciones];
	if(jugadores!=NULL)
	{
		if(calcConfConMasAniosDeContrato(jugadores, tamConfederaciones,  tam, &maxAniosContrato,confederaciones)==0 &&
				contarAniosDeContratoPorConf(jugadores,  tam,  tamConfederaciones,arrayAniosAcumulados, confederaciones)==0)
		{
			printf("+=============================================================+\n"
						"|%*s|\n%s",-60,"CONFEDERACION CON MAYOR CANTIDAD DE ANIOS DE CONTRATOS TOTAL:",
						"+=============================================================+\n");
			for(int i=0;i<tamConfederaciones;i++)
			{
				if((*(arrayAniosAcumulados+i))==maxAniosContrato)
				{
					printf("|%*s- ANIOS: %*d|\n",-40,(*(confederaciones+i)).nombre,-12, maxAniosContrato);
				}
			}
			printf("+=============================================================+\n");
			retorno=0;
		}
	}
	return retorno;
}
int informarPorcPorConf(eJugador* jugadores, int tam, int contJugadores, eConfederacion* confederaciones, int tamConfederaciones)
{
	float arrayPorcentajes[tamConfederaciones];
	int retorno=-1;
	//CALCULO PORCENTAJES
	if(jugadores!=NULL && calcPorcentajePorConf(jugadores, contJugadores,  tam, arrayPorcentajes,  tamConfederaciones)==0)
	{
		printf("%s|%*s|%*s|\n%s\n","+====================================+\n",-25,"         NOMBRE",-10,"PORCENTAJE",
				"+====================================+");

		for(int i=0;i<tamConfederaciones;i++)
		{
			printf("|%*s|   %*.2f|\n",-24,(*(confederaciones+i)).nombre,-8,(*(arrayPorcentajes+i)));
		}
		printf("+====================================+\n");
		retorno=0;
	}
	return retorno;
}
int informarRegionMasAsistida(eJugador* jugadores, int tam, int tamConfederaciones, eConfederacion* confederaciones)
{
	int retorno=-1;
	int maximoContador;
	int flag=0;
	int arrayCantidadAcumulados[tamConfederaciones];
	inicializarArray(arrayCantidadAcumulados, tamConfederaciones);

	if(buscarNumJugPorRegion(jugadores, tam,  tamConfederaciones,arrayCantidadAcumulados,confederaciones)==0)
	{
		if(buscarMaxJugEnUnaRegion(tamConfederaciones, arrayCantidadAcumulados, &maximoContador)==0)
		{
			//printf("maximoContador %d",maximoContador);
			for(int i=0;i<tamConfederaciones;i++)
			{
				//printf("array %d\n",(*(arrayCantidadAcumulados+i)));
				flag=0;
				if((*(arrayCantidadAcumulados+i))==maximoContador)
				{
					for(int j=0;j<tam;j++)
					{
						if(flag==0 && (*(jugadores+j)).isEmpty==OCUPADO  && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
						{
							retorno=0;
							flag=1;
							printf("+==================================================+\n|REGION %*s|"
									"\n+==================================================+\n",-43,(*(confederaciones+i)).region);
						}
						if((*(jugadores+j)).isEmpty==OCUPADO  && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
						{
							printf("|%*s|\n",-50,(*(jugadores+j)).nombre);
						}
					}
				}
			}
			printf("+==================================================+\n");
		}
	}
	return retorno;
}
int menuInformes(eJugador* jugadores,eConfederacion* confederaciones,int tam, int contadorJugadores, int tamConfederaciones)
{
	int retorno=-1;
	short opcionSubMenu;
	if(jugadores!=NULL && confederaciones!=NULL && contadorJugadores>0 )
	{
		retorno=0;
		printf("%s\n|%*s|\n%s\n","+====================================================================================================+"
				,-100,"                                       MENU DE INFORMES","+====================================================================================================+");

		printf("|%*s  |\n|%*s|\n|%*s  |\n|%*s  |\n|%*s |\n|%*s  |\n%s\n",-100,"1.Imprimir jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.",
				-100,"2.Listado de confederaciones con sus jugadores.",-100,"3.Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio.",
				-100,"4.Informar la confederación con mayor cantidad de años de contratos total.",-100,"5.Informar porcentaje de jugadores por cada confederación."
				,-100,"6.Informar cual es la región con más jugadores y el listado de los mismos.",
				"+====================================================================================================+\n");
		ingresarShortConRango(&opcionSubMenu,"Ingrese segun desee informar", "ERROR, Ingrese opcion valida\n", 1, 6);

		switch(opcionSubMenu)
		{
		case 1:
			if(listarJugadores(jugadores,confederaciones,tam, contadorJugadores,1)==0){
				retorno=0;
			}
		break;
		case 2:
			if(listarJugadoresXConfederaciones( jugadores, confederaciones, tam, tamConfederaciones)==0){
				retorno=0;
			}
		break;
		case 3:
			if(informarTotalyMediaDeSalarios(jugadores, tam, contadorJugadores)==0){
				retorno=0;
			}
		break;
		case 4:
			if(mostrarConfConMasAniosContrato(jugadores, tam, tamConfederaciones, confederaciones)==0){
				retorno=0;
			}
		break;
		case 5:
		if( informarPorcPorConf( jugadores,  tam,  contadorJugadores,  confederaciones,  tamConfederaciones)==0){
			retorno=0;
		}
		break;
		case 6:
			if(informarRegionMasAsistida(jugadores,  tam,  tamConfederaciones,  confederaciones)==0){
				retorno=0;
			}
		break;
		}
	}
	else
	{
		printf("ERROR, Para operar esta opcion debe existir al menos 1 jugador cargado\n");
	}
	return retorno;
}
