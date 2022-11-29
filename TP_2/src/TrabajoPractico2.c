/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Rodriguez Julian Manuel - Div J - Turno tarde - Laboratorio.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ingresos.h"
#include "jugadores.h"
#include "confederaciones.h"
#include "informes.h"
#define TAM 3000
#define TAM_CONFEDERACIONES 6
#define VACIO 1
#define OCUPADO 0

int main(void) {

	setbuf(stdout,NULL);

	short opcionMenu;
	int idJugadores=0;//LO INICIALIZO EN 0 YA QUE EL ID SERA AUTOINCREMENTAL
	int contadorJugadores=0;//INICIALIZADO EN 0 YA QUE SE USARA COMO VARIABLE DE CONTROL EN EL MENU
	int contadorConf=6;//SE HARDCODEAN 6 ESTRUCTURAS
	int flag=0;
	eJugador jugadores[TAM];
	/*
	Si utilizan datos hardcodeados, tener en cuenta:
	1.Comentar la funcion inicializarIsEmptyEjugador en el main.
	2.Modificar el #define TAM a 15.
	3.En la variable contadorJugadores=15.
	4.Variable idJugadores=15. Por si quieren borrar y loguear nuevo jugador*/
	/*eJugador jugadores[TAM]={
	       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,OCUPADO},
	       {2,"Juan Musso","ARQUERO",12,100,80000,2,OCUPADO},
	       {3,"Leo Messi","DELANTERO",10,100,80000,4,OCUPADO},
	       {4,"Almirez Ali","DELANTERO",9,100,55000,1,OCUPADO},
	       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,OCUPADO},
	       {6,"Eric Dier","DEFENSOR",3,101,60000,2,OCUPADO},
	       {7,"Harry Kane","DELANTERO",10,101,3000,2,OCUPADO},
	       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,OCUPADO},
	       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,OCUPADO},
	       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,OCUPADO},
	       {11,"Tecatito","DELANTERO",11,104,100000,3,OCUPADO},
	       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,OCUPADO},
	       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,OCUPADO},
	       {14,"Demba Seck","DELANTERO",11,103,6000,2,OCUPADO},
	       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,OCUPADO}
	   };*/

	eConfederacion confederaciones[TAM_CONFEDERACIONES]=
	{
			{100,"CONMEBOL","SUDAMERICA",1916,OCUPADO},
			{101,"UEFA","EUROPA",1954,OCUPADO},
			{102,"AFC","ASIA",1954,OCUPADO},
			{103,"CAF","AFRICA",1957,OCUPADO},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,OCUPADO},
			{105,"OFC","OCEANIA",1966,OCUPADO}

	};
	inicializarIsEmptyEjugador(jugadores,TAM, VACIO);
	do
	{
		printf("+=========================+\n|%*s|\n+=========================+\n",-25,"     MENU PRINCIPAL");

		printf("|%*s|\n|%*s|\n|%*s|\n|%*s|\n|%*s|\n+=========================+\n",-25,
				"1.ALTA JUGADOR",-25,
				"2.BAJA JUGADOR",-25,
				"3.MODIFICACION JUGADOR",-25,
				"4.INFORMES",-25,
				"5.SALIR");

		ingresarShortConRango(&opcionMenu, "Ingrese opcion segun desee operar\n", "ERROR, ingrese opcion valida\n",  1,5);

		switch(opcionMenu)
		{
			case 1:
				 if(loguearJugador(jugadores,confederaciones, &idJugadores,&contadorJugadores, TAM,TAM_CONFEDERACIONES,contadorConf)==-1){
					 printf("<<<<<<<<<< ERROR AL LOGUEAR JUGADOR >>>>>>>>>>\n");
				 }
			break;
			case 2:
				if(darLaBajaJugador(jugadores,TAM, &contadorJugadores, confederaciones)==-1)
				{
					printf("<<<<<<<<<< ERROR AL DAR DE BAJA ID>>>>>>>>>>\n");
				}
			break;
			case 3:
				if(modificarJugador(jugadores,confederaciones, TAM , contadorJugadores,TAM_CONFEDERACIONES, contadorConf)!=0){
						printf("<<<<<<<<<< ERROR AL MODIFICAR JUGADOR >>>>>>>>>>\n");
				}
			break;
			case 4:
				if(menuInformes(jugadores,confederaciones,TAM, contadorJugadores,TAM_CONFEDERACIONES)==-1){
					printf("<<<<<<<<<< ERROR AL INFORMAR >>>>>>>>>>\n");
				}
			break;
			case 5:
				confirmarSalida(&flag);
			break;
		}

	}while(flag==0);

	return EXIT_SUCCESS;
}


