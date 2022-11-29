/*
 * jugadores.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "jugadores.h"
#include "confederaciones.h"
#include "ingresos.h"
#include "informes.h"
#include "nexo.h"

#define VACIO 1
#define OCUPADO 0

int inicializarIsEmptyEjugador(eJugador* jugadores, int tam, int estado)
{
	int retorno=-1;

	if(jugadores!=NULL  && tam>0)
	{

		for(int i=0;i<tam;i++)
		{
			(*(jugadores+i)).isEmpty=VACIO;//EN UNO PARA QUE DE VERDADERO, ES DECIR SE PUEDE USAR.
		}

		retorno=0;
	}
	return retorno;

}
int jug_IngresarPosicion(char* posicion)
{
	int retorno=-1;
	int opcion;
	if(posicion!=NULL)
	{
		printf("+=========================+\n");
		printf("|%*s|\n+=========================+\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n%s",
				-25,"POSICIONES.",
				-25,"1.Defensa central.",
				-25,"2.Delantero centro.",
				-25,"3.Extremo derecho.",
				-25,"4.Extremo izquierdo.",
				-25,"5.Lateral derecho.",
				-25,"6.Lateral izquierdo.",
				-25,"7.Mediocentro.",
				-25,"8.Mediocentro ofensivo.",
				-25,"9.Pivote.",
				-25,"10.Portero.","+=========================+\n");
		ingresarIntConRango(&opcion, "Ingrese posicion del jugador segun corresponda.\n", "ERROR,Ingrese opcion valida", 1, 10);

		switch(opcion)
		{
		case 1:
			strcpy(posicion,"Defensa central");
		break;
		case 2:
			strcpy(posicion,"Delantero centro");
		break;
		case 3:
			strcpy(posicion,"Extremo derecho");
		break;
		case 4:
			strcpy(posicion,"Extremo izquierdo");
		break;
		case 5:
			strcpy(posicion,"Lateral derecho");
		break;
		case 6:
			strcpy(posicion,"Lateral izquierdo");
		break;
		case 7:
			strcpy(posicion,"Mediocentro");
		break;
		case 8:
			strcpy(posicion,"Mediocentro ofensivo");
		break;
		case 9:
			strcpy(posicion,"Pivote");
		break;
		case 10:
			strcpy(posicion,"Portero");
		break;
		}
		retorno=0;
	}
	return retorno;
}
int loguearJugador(eJugador* jugadores,eConfederacion* confederaciones, int* id,int* contadorJugadores,int tamJugadores, int tamConfederaciones, int contadorConf)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;
	if(jugadores!=NULL && confederaciones!=NULL)
	{
		if(*contadorJugadores<tamJugadores)
		{
			*id=*id+1;//CADA VEZ QUE INGRESE TOMO AL VALOR QUE LLEGA COMO PARAMETRO PARA SUMARLE UNO Y ASI QUEDE AUTOINCREMENTAL
			jugadorAuxiliar.id=*id;

			*contadorJugadores=*contadorJugadores+1;

			 ingresarCadenaCaracteres( 50,jugadorAuxiliar.nombre,"Ingrese nombre del jugador\n","ERROR, Ingrese nombre valido\n");

			 //ingresarCadenaCaracteres( 50,jugadorAuxiliar.posicion,"Ingrese posicion del jugador\n","ERROR, Ingrese posicion valida\n");
			 jug_IngresarPosicion(jugadorAuxiliar.posicion);
			 ingresarShortConRango(&jugadorAuxiliar.numeroCamiseta,"Ingrese numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);

			 //MOSTRAR LISTADO DE CONFEDERACIONES.
			 listarConfederaciones(confederaciones,tamConfederaciones,contadorConf);
			 ingresarIntConRango(&jugadorAuxiliar.idConfederacion, "Ingrese ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);

			 ingresarFloatConMinimo(&jugadorAuxiliar.salario,"Ingrese salario\n","ERROR, ingrese salario valido\n",1);

			 ingresarShortConRango(&jugadorAuxiliar.aniosContrato,"Ingrese anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);

			 jugadorAuxiliar.isEmpty=OCUPADO;

			for(int i=0;i<tamJugadores;i++)
			 {
				 if((*(jugadores+i)).isEmpty==VACIO)
				 {
					 (*(jugadores+i))=jugadorAuxiliar;
					 retorno=0;
					 break;
				 }
			 }
		}
		else
		{
			printf("ERROR,SIN ESPACIO EN MEMORIA");
		}
	}
	return retorno;
}
int asignarDescripcionConfederacion(eJugador* jugadores,eConfederacion* confederaciones,int tamConfederaciones, char* descripcion ,int posicion)
{
	int retorno=-1;


		if(jugadores!=NULL && confederaciones!=NULL)
		{
			retorno=0;
			for(int i=0;i<tamConfederaciones;i++)
			{
				if((*(jugadores+posicion)).idConfederacion==(*(confederaciones+i)).id)
				{
					strcpy(descripcion,(*(confederaciones+i)).nombre);
				}
			}
		}
	return retorno;
}
int ordenarJugadoresAlfabeticamente(eJugador* jugadores,eConfederacion* confederaciones,int tam)
{
	int retorno=-1;
	char descripcionUno[50];
	char descripcionDos[50];

	eJugador jugadorAuxiliar; //PARA EL SWAP

	if(jugadores!=NULL && confederaciones!=NULL)
	{
		for(int i=0;i<tam-1;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				retorno=0;
				for(int j=i+1;j<tam;j++)
				{
					if((*(jugadores+j)).isEmpty==OCUPADO)
					{
						asignarDescripcionConfederacion(jugadores,confederaciones,6, descripcionUno ,i);
						asignarDescripcionConfederacion(jugadores,confederaciones,6, descripcionDos ,j);

						if(strcmp(descripcionUno, descripcionDos)>0)
						{
							jugadorAuxiliar=(*(jugadores+i));
							(*(jugadores+i))=(*(jugadores+j));
							(*(jugadores+j))=jugadorAuxiliar;
						}
						else
						{	if(strcmp(descripcionUno, descripcionDos)==0)
							{
								if(strcmp( (*(jugadores+i)).nombre,(*(jugadores+j)).nombre)>0)
								{
									jugadorAuxiliar=(*(jugadores+i));
									(*(jugadores+i))=(*(jugadores+j));
									(*(jugadores+j))=jugadorAuxiliar;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
int ordenarJugadoresXId(eJugador* jugadores, int tam)
{
	int retorno=-1;
	eJugador jugadorAuxiliar;

	if(jugadores!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{
				for(int j=i+1;j<tam;j++)
				{
					if((*(jugadores+j)).isEmpty==OCUPADO)
					{
						if((*(jugadores+i)).id>(*(jugadores+j)).id)
						{
								jugadorAuxiliar=(*(jugadores+i));
								(*(jugadores+i))=(*(jugadores+j));
								(*(jugadores+j))=jugadorAuxiliar;
						}
					}
				}
			}
		}
	}
	return retorno;
}
int buscarIndiceJugador(eJugador* jugadores,int* iteraciones, int tam, int idModificar)
{
	int flag=0;

	int retorno=-1;
	if(jugadores!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).id==idModificar && (*(jugadores+i)).isEmpty==OCUPADO)
			{
				flag=1;
				retorno=0;
				*iteraciones=i;
				break;
			}
		}
		if(flag==0)
		{
			printf("ERROR, Ingrese ID valido\n");
		}
	}

	return retorno;
}
int modificarJugador(eJugador* jugadores,eConfederacion* confederaciones, int tam , int contadorJugadores ,int tamConfederaciones, int contadorConf)
{
	int retorno=-1;
	int opcion;
	int idModificar;
	int i;

	//SI EL LISTAR ME RETORNA 0 ES PORQUE HAY JUGADORES CARGADOS YA!
	//EN CASO QUE NO EXISTA JUGADOR CARGADO, DIRECTAMENTE EL AVISO LO IMPRIME LA FUINCION listarJugadores.
	//NO VERIFICO POR NULL PORQUE YA LO HACE listarJugadores
	if(listarJugadores(jugadores,confederaciones,tam, contadorJugadores,2)==0)
	{

		do
		{
			ingresarIntConRango(&idModificar, "Ingrese ID a modificar", "ERROR, Ingrese ID valido\n",1,5000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(buscarIndiceJugador(jugadores,&i, tam, idModificar)==-1);

		printf("+=========================+\n|%*s|\n+=========================+\n",-25,"SUB MENU - MODIFICACIONES");
		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n",-25,"1.NOMBRE",-25,"2.POSICION",-25,"3.NUMERO DE CAMISETA",-25,"4.CONFEDERACION",-25,"5.SALARIO",-25,"6.ANIOS DE CONTRATO");

		ingresarIntConRango(&opcion, "Ingrese opcion segun desee operar", "ERROR, Ingrese opcion valida\n",1,7);

		switch(opcion)
		{
		case 1:
			ingresarCadenaCaracteres( 50,(*(jugadores+i)).nombre,"Ingrese nuevo nombre del jugador\n","ERROR, Ingrese nombre valido\n");
		break;
		case 2:
			//ingresarCadenaCaracteres( 50,(*(jugadores+i)).posicion,"Ingrese nueva posicion del jugador\n","ERROR, Ingrese posicion valida\n");
			jug_IngresarPosicion((*(jugadores+i)).posicion);
		break;
		case 3:
			ingresarShortConRango(&(*(jugadores+i)).numeroCamiseta,"Ingrese nuevo numero de camiseta entre 1 y 100\n", "Ingrese numero valido\n", 1,  100);
		break;
		case 4:
			 listarConfederaciones(confederaciones,tamConfederaciones,contadorConf);
			 ingresarIntConRango(&(*(jugadores+i)).idConfederacion, "Ingrese nuevo ID de confederacion\n", "ERROR,Ingrese ID valido\n", 100, 105);
		break;
		case 5:
			ingresarFloatConMinimo(&(*(jugadores+i)).salario,"Ingrese nuevo salario","ERROR, ingrese salario valido\n",1);
		break;
		case 6:
			ingresarShortConRango(&(*(jugadores+i)).aniosContrato,"Ingrese nueva cantidad de anios de contrato entre 1 y 10\n", "Ingrese cantidad valida\n", 1, 10);
		break;

		}
		printf("<<<<<<<<<< ID %d MODIFICADO SATISFACTORIAMENTE >>>>>>>>>>\n",(*(jugadores+i)).id);
		retorno=0;
	}

	return retorno;
}
int darLaBajaJugador(eJugador* jugadores,int tam, int* contadorJugadores, eConfederacion* confederaciones)
{
	int retorno=-1;
	int idDarBaja;
	int i;

	if(jugadores!=NULL && listarJugadores(jugadores,confederaciones,tam, *contadorJugadores,2)==0)
	{
		do
		{
			ingresarIntConRango(&idDarBaja, "Ingrese ID a dar de baja", "ERROR, Ingrese ID valido\n",1,3000);
			//EN CONTAR ITERACIONES, SI HAY PROBLEMAS CON EL ID, RETORNO -1
		}while(buscarIndiceJugador(jugadores,&i, tam, idDarBaja)==-1);

		(*(jugadores+i)).isEmpty=VACIO;
		*contadorJugadores=*contadorJugadores-1;
		printf("<<<<<<<<<< ID %d DADO DE BAJA SATISFACTORIAMENTE>>>>>>>>>>\n ",(*(jugadores+i)).id);
		retorno=0;
	}

	return retorno;
}

int listarJugadoresXUnaConf(eJugador* jugadores,eConfederacion* confederaciones,int tam, int idConf, int tamConfederaciones)
{
	int retorno=-1;
	int flag=0;
	char descripcionConf[50];
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO && (*(jugadores+i)).idConfederacion==idConf)
		{
			retorno=0;
			if(flag==0)
			{
				flag=1;
				printf("+==========================================================================================================================+\n");
				asignarDescripcionConfederacion(jugadores,confederaciones,6, descripcionConf ,i);
				printf("|                                                     %*s|\n",-69,descripcionConf);
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
				//printf("+==========================================================================================================================+\n");
				printf("|%*s|%*s|%*s|\n",-50,"                     NOMBRE",-50,"                     POSICION",-21,"     N° CAMISETA");
				//printf("+==========================================================================================================================+\n");
				printf("+--------------------------------------------------------------------------------------------------------------------------+\n");
			}
			printf("|%*s|%*s|         %*d|\n",-50,(*(jugadores+i)).nombre,-50,(*(jugadores+i)).posicion,-11,(*(jugadores+i)).numeroCamiseta);
		}
	}
	if(flag==0)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			if((*(confederaciones+i)).id==idConf)
			{
				printf("+==========================================================================================================================+\n");
				printf("                                   NO EXISTEN JUGADORES EN LA CONDEFERACION:%s                                      \n",(*(confederaciones+i)).nombre);
				printf("+==========================================================================================================================+\n");
			}
		}
	}
	return retorno;
}
int acumularTotalSalarios(eJugador* jugadores,int tam, float* totalSalarios)
{
	//NO VALIDO POR NULL PORQUE YA SE HIZO AL INGRESAR AL INFORME
	int retorno=-1;
	float totalAux=0;
	for(int i=0;i<tam;i++)
	{
		if((*(jugadores+i)).isEmpty==OCUPADO)
		{
			retorno=0;
			totalAux=totalAux+(*(jugadores+i)).salario;
		}
	}
	*totalSalarios=totalAux;
	return retorno;
}
int calcularJugPorArribaDeLaMedia(eJugador* jugadores, float promedioSalarios, int* total, int tam)
{
	int totalAux=0;
	int retorno=-1;
	if(jugadores!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO && (*(jugadores+i)).salario> promedioSalarios)
			{
				totalAux=totalAux+1;
			}
		}
		*total=totalAux;
		retorno=0;
	}

	return retorno;
}
int calcConfConMasAniosDeContrato(eJugador* jugadores,int tamConfederaciones, int tamJugadores, int* resultadoAnios, eConfederacion* confederaciones)
{
	int retorno=-1;
	int acumulador=0;
	int resultadoAux=0;
	if(jugadores!=NULL && confederaciones!=NULL)
	{

		for(int i=0;i<tamConfederaciones;i++)
		{
			acumulador=0;
			for(int j=0;j<tamJugadores;j++)
			{

				if((*(jugadores+j)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
				{
					acumulador=acumulador+(*(jugadores+j)).aniosContrato;

				}
			}

			if(resultadoAux<acumulador)
			{
				resultadoAux=acumulador;
				retorno=0;
			}
		}
		*resultadoAnios=resultadoAux;
	}
	return retorno;
}
int contarAniosDeContratoPorConf(eJugador* jugadores, int tam, int tamConfederaciones,int* arrayAniosAcumulados, eConfederacion* confederaciones )
{
	int retorno=-1;
	int acumulador;

	//INICIALIZO EN 0 AL ARRAY
	inicializarArray(arrayAniosAcumulados, tamConfederaciones);

	for(int i=0;i<tamConfederaciones;i++)
	{
		acumulador=0;
		for(int j=0;j<tam;j++)
		{
			if((*(jugadores+j)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
			{
				retorno=0;
				acumulador=acumulador+(*(jugadores+j)).aniosContrato;
			}
		}
		(*(arrayAniosAcumulados+i))=acumulador;
	}
	return retorno;
}
int calcPorcentajePorConf(eJugador* jugadores,int contJugadores, int tam, float* arrayPorcentajes, int tamConfederaciones)
{
	int retorno=-1;
	//LOS INICIALIZO PORQUE SON CONTADORES
	int contConmebol=0;
	int contUefa=0;
	int contAfc=0;
	int contCaf=0;
	int contConcacaf=0;
	int contOfc=0;
	inicializarArrayFloat(arrayPorcentajes,tamConfederaciones);

	if(jugadores!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if((*(jugadores+i)).isEmpty==OCUPADO)
			{

				switch((*(jugadores+i)).idConfederacion)
				{
					case 100:
						contConmebol=contConmebol+1;
						//*porcentajeConmebol=calcPorcentaje(contJugadores, contConmebol);
						(*(arrayPorcentajes+0))=calcPorcentaje(contJugadores, contConmebol);
					break;
					case 101:
						contUefa=contUefa+1;
						(*(arrayPorcentajes+1))=calcPorcentaje(contJugadores, contUefa);
					break;
					case 102:
						contAfc=contAfc+1;
						(*(arrayPorcentajes+2))=calcPorcentaje(contJugadores, contAfc);
					break;
					case 103:
						contCaf=contCaf+1;
						(*(arrayPorcentajes+3))=calcPorcentaje(contJugadores, contCaf);
					break;
					case 104:
						contConcacaf=contConcacaf+1;
						(*(arrayPorcentajes+4))=calcPorcentaje(contJugadores, contConcacaf);
					break;
					case 105:
						contOfc=contOfc+1;
						(*(arrayPorcentajes+5))=calcPorcentaje(contJugadores, contOfc);
					break;
				}
			}
		}
		retorno=0;
	}
	return retorno;
}
int buscarNumJugPorRegion(eJugador* jugadores, int tam, int tamConfederaciones,int* arrayCantidadAcumulados, eConfederacion* confederaciones)
{
	int retorno=-1;
	int acumulador;

	for(int i=0;i<tamConfederaciones;i++)
	{
		acumulador=0;
		for(int j=0;j<tam;j++)
		{
			if((*(jugadores+j)).isEmpty==OCUPADO && (*(jugadores+j)).idConfederacion==(*(confederaciones+i)).id)
			{	retorno=0;
				acumulador=acumulador+1;
			}
		}
		(*(arrayCantidadAcumulados+i))=acumulador;

	}
	return retorno;
}
int buscarMaxJugEnUnaRegion (int tamConfederaciones, int* arrayCantidadAcumulados, int* maxContador)
{
	int retorno=-1;
	int flag=0;
	int maximoContador;

	if(arrayCantidadAcumulados!=NULL)
	{
		for(int i=0;i<tamConfederaciones;i++)
		{
			if(flag==0)
			{
				flag=1;
				retorno=0;
				maximoContador=(*(arrayCantidadAcumulados+i));
			}
			else
			{
				if(maximoContador<(*(arrayCantidadAcumulados+i)))
				{
					maximoContador=(*(arrayCantidadAcumulados+i));
				}
			}
		}
		*maxContador=maximoContador;
	}

	return retorno;
}











