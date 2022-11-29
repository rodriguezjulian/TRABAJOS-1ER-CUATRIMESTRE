#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include <string.h>
#include <ctype.h>
#include "ingresos.h"
#include "salidas.h"
/// \fn Jugador jug_new*()
/// \brief Reserva espacio de memoria para una estructura de tipo Jugador.
///
/// \return
Jugador* jug_new()
{
	Jugador* pJugador;
	//RESERVO ESPACIO DE MEMORIA E INICIALIZO LOS CAMPOS
	//EL 1 EN CALLOC ES EL NUMERO DE ELEMENTOS
	pJugador=(Jugador*)calloc(1,sizeof(Jugador)*1);
	return pJugador;
}
/// \fn void jug_delete(Jugador*)
/// \brief Libero espacio de memoria de un puntero a estructura Jugador recibido.
///
/// \param this
void jug_delete(Jugador* this)
{
	free(this);
}
/// \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// \brief Recibe por parametro valores para completar los campos de una estructa de tipo Jugador, habiendo
/// reservado memoria anteriormente.
///
/// \param idStr
/// \param nombreCompletoStr
/// \param edadStr
/// \param posicionStr
/// \param nacionalidadStr
/// \param idSelccionStr
/// \return
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	//RESERVO EL ESPACIO DE MEMORIA
	pJugador=jug_new();
	if(pJugador!=NULL)
	{
		//CASTEO A INT LO QUE HACE FALTA
		if(jug_setId(pJugador,atoi(idStr))!=0 ||
		jug_setNombreCompleto(pJugador, nombreCompletoStr)!=0 ||
		jug_setPosicion(pJugador, posicionStr)!=0 ||
		jug_setNacionalidad(pJugador, nacionalidadStr)!=0 ||
		jug_setEdad(pJugador, atoi(edadStr))!=0 ||
		jug_setIdSeleccion(pJugador, atoi(idSelccionStr))!=0)
		{
			jug_delete(pJugador);
			pJugador=NULL;
		}
	}
	return pJugador;
}
/// \fn int jug_setId(Jugador*, int)
/// \brief Se le asigna  a this el valor que se reciba por parametro en el campo id.
///
/// \param this puntero a estructura  Jugador
/// \param id
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}
/// \fn int jug_getId(Jugador*, int*)
/// \brief  Asigno valor del campo id de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param id variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;
	if(this!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
/// \fn int jug_setNombreCompleto(Jugador*, char*)
/// \brief  Se le asigna  a this el valor que se reciba por parametro en el campo nombreCompleto.
///
/// \param this puntero a estructura  Jugador
/// \param nombreCompleto descripcion tipo char
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->nombreCompleto,nombreCompleto);
	}

	return retorno;
}
/// \fn int jug_getNombreCompleto(Jugador*, char*)
/// \brief Asigno valor del campo nombreCompleto de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param nombreCompleto variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(nombreCompleto,this->nombreCompleto);
	}
	return retorno;
}
/// \fn int jug_setPosicion(Jugador*, char*)
/// \brief Se le asigna  a this el valor que se reciba por parametro en el campo posicion.
///
/// \param this puntero a estructura  Jugador
/// \param posicion descripcion tipo char
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->posicion,posicion);
	}
	return retorno;
}
/// \fn int jug_getPosicion(Jugador*, char*)
/// \brief  Asigno valor del campo posicion de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param posicion variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		strcpy(posicion,this->posicion);
	}
	return retorno;
}
/// \fn int jug_setNacionalidad(Jugador*, char*)
/// \brief  Se le asigna  a this el valor que se reciba por parametro en el campo nacionalidad.
///
/// \param this puntero a estructura  Jugador
/// \param nacionalidad descripcion tipo char
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL)
	{

		strcpy(this->nacionalidad,nacionalidad);
		retorno=0;
	}
	return retorno;
}
/// \fn int jug_getNacionalidad(Jugador*, char*)
/// \brief  Asigno valor del campo nacionalidad de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param nacionalidad variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL)
	{

		strcpy(nacionalidad,this->nacionalidad);
		retorno=0;
	}
	return retorno;
}
/// \fn int jug_setEdad(Jugador*, int)
/// \brief Se le asigna  a this el valor que se reciba por parametro en el campo edad.
///
/// \param this puntero a estructura  Jugador
/// \param edad entero que se recibe
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		this->edad=edad;
	}
	return retorno;

}
/// \fn int jug_getEdad(Jugador*, int*)
/// \brief Asigno valor del campo edad de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param edad variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		*edad=this->edad;
	}
	return retorno;
}
/// \fn int jug_setIdSeleccion(Jugador*, int)
/// \brief  Se le asigna  a this el valor que se reciba por parametro en el campo idSeleccion.
///
/// \param this this puntero a estructura  Jugador
/// \param idSeleccion entero que se recibe
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		this->idSeleccion=idSeleccion;
	}
	return retorno;

}
/// \fn int jug_getSIdSeleccion(Jugador*, int*)
/// \brief Asigno valor del campo idSeleccion de una estructura de tipo Jugador a una variable.
///
/// \param this
/// \param idSeleccion variable a la que se le pasara el valor por referencia.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;
	if(this!=NULL)
	{
		retorno=0;
		*idSeleccion=this->idSeleccion;
	}
	return retorno;
}
/// \fn int jug_IngresarPosicion(char*)
/// \brief Muestro posiciones que puede llegar a elegir el usuario, pido que elija segun precise (valido) y
/// paso por referencia la cadena de caracteres que representan al campo posicion.
///
/// \param posicion
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
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

/// \fn int jug_IngresarNacionalidad(char*)
/// \brief Listo nacionalidades (jug_MostrarNacionalidades), doy a elegir opcion y retorno por referencia segun
/// el usuario eligio.
///
/// \param nacionalidad
/// \return return int return=0 SALIO BIEN / return=-1 SALIO MAL
int jug_IngresarNacionalidad(char* nacionalidad)
{
	int retorno=-1;
	int opcion;
	if(nacionalidad!=NULL)
	{
		jug_MostrarNacionalidades();
		ingresarIntConRango(&opcion, "Ingrese nacionalidad del jugador.\t", "ERROR,Ingrese opcion valida.\n", 1,32);

		 switch(opcion)
		 {
			case 1:
				 strcpy(nacionalidad, "Arabe");
			break;
			case 2:
				 strcpy(nacionalidad, "Australiano");
			break;
			case 3:
				 strcpy(nacionalidad, "Coreano");
			break;
			case 4:
				 strcpy(nacionalidad, "Iranie");
			break;
			case 5:
				 strcpy(nacionalidad, "Japones");
			break;
			case 6:
				 strcpy(nacionalidad, "Qatari");
			break;
			case 7:
				 strcpy(nacionalidad, "Camerunes");
			break;
			case 8:
				 strcpy(nacionalidad, "Ghanes");
			break;
			case 9:
				 strcpy(nacionalidad, "Marroqui");
			break;
			case 10:
				 strcpy(nacionalidad, "Senagales");
			break;
			case 11:
				 strcpy(nacionalidad, "Tunéz");
			break;
			case 12:
				 strcpy(nacionalidad, "Canadiense");
			break;
			case 13:
				 strcpy(nacionalidad, "Costarriquense");
			break;
			case 14:
				 strcpy(nacionalidad, "Estadounidense");
			break;
			case 15:
				 strcpy(nacionalidad, "Mexicano");
			break;
			case 16:
				 strcpy(nacionalidad, "Argentino");
			break;
			case 17:
				 strcpy(nacionalidad, "Brasilero");
			break;
			case 18:
				 strcpy(nacionalidad, "Ecuatoriano");
			break;
			case 19:
				 strcpy(nacionalidad, "Uruguayo");
			break;
			case 20:
				 strcpy(nacionalidad, "Aleman");
			break;
			case 21:
				 strcpy(nacionalidad, "Belga");
			break;
			case 22:
				 strcpy(nacionalidad, "Croata");
			break;
			case 23:
				 strcpy(nacionalidad, "Dinamarques");
			break;
			case 24:
				 strcpy(nacionalidad, "Espaniol");
			break;
			case 25:
				 strcpy(nacionalidad, "Frances");
			break;
			case 26:
				 strcpy(nacionalidad, "Gales");
			break;
			case 27:
				 strcpy(nacionalidad, "Holandes");
			break;
			case 28:
				 strcpy(nacionalidad, "Ingles");
			break;
			case 29:
				 strcpy(nacionalidad, "Polaco");
			break;
			case 30:
				 strcpy(nacionalidad, "Portugues");
			break;
			 case 31:
				 strcpy(nacionalidad, "Serbio");
			break;
			 case 32:
				 strcpy(nacionalidad, "Suizo");
			break;

		 }
		retorno=0;
	}
	return retorno;
}
/// \fn int jug_OrdenarPorNacionalidad(void*, void*)
/// \brief Obtengo dos valores para el campo nacionalidad de una estructura tipo Jugador, los comparo y retorno
/// segun corresponda.
///
/// \param unJugador
/// \param otroJugador
/// \return return=0 si son iguales / return=1 si el primero es mayor / return=-1 si el segundo es mayor
int jug_OrdenarPorNacionalidad(void* unJugador, void* otroJugador)
{
	int retorno=-1;
	char nacionalidadUno[30];
	char nacionalidadDos[30];
	int compara;
	//ASIGNO
	jug_getNacionalidad(unJugador, nacionalidadUno);
	jug_getNacionalidad(otroJugador, nacionalidadDos);
	compara=strcmp(nacionalidadUno,nacionalidadDos);
	if(compara>0)//UNO MAYOR
	{
		retorno=1;
	}
	else
	{
		if(compara<0)//2 MAYOR
		{
			retorno=-1;
		}
	}
	return retorno;
}
/// \fn int jug_OrdenarPorNombre(void*, void*)
/// \brief Obtengo dos valores para el campo nombreCompleto de una estructura tipo Jugador, los comparo y retorno
/// segun corresponda.
///
/// \param unJugador
/// \param otroJugador
/// \return return=0 si son iguales / return=1 si el primero es mayor / return=-1 si el segundo es mayor
int jug_OrdenarPorNombre(void* unJugador, void* otroJugador)
{
	int compara;
	int retorno=0;//son iguales
	char nombreUno[100];
	char nombreDos[100];
	jug_getNombreCompleto(unJugador, nombreUno);
	jug_getNombreCompleto(otroJugador, nombreDos);

	compara=strcmp(nombreUno,nombreDos);
	if(compara>0)//UNO MAYOR
	{
		retorno=1;
	}
	else
	{
		if(compara<0)//2 MAYOR
		{
			retorno=-1;
		}
	}
	return retorno;
}
/// \fn int jug_OrdenarPorEdad(void*, void*)
/// \brief Obtengo dos valores para el campo edad de una estructura tipo Jugador, los comparo y retorno
/// segun corresponda.
///
/// \param unJugador
/// \param otroJugador
/// \return return=0 si son iguales / return=1 si el primero es mayor / return=-1 si el segundo es mayor
int jug_OrdenarPorEdad(void* unJugador, void* otroJugador)
{
	int retorno=0; //IGUALES
	int edadUno;
	int edadDos;

	jug_getEdad(unJugador, &edadUno);
	jug_getEdad(otroJugador, &edadDos);

	if(edadUno>edadDos)//UNO MAYOR
	{
		retorno=1;
	}
	else
	{
		if(edadUno<edadDos)//2 MAYOR
		{
			retorno=-1;
		}
	}

	return retorno;
}


/// \fn int jug_BuscarPorId(LinkedList*, int, int*)
/// \brief Recibo un id y busco el indice en donde se encuentra la estructura.
///
/// \param pArrayListJugador
/// \param idBuscado
/// \param indice posicion retornada por referencia
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_BuscarPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice)
{
	int retorno=-1;
	Jugador* AuxJugador;
	int idAux;
	if(pArrayListJugador!=NULL)
	{
		int tam= ll_len(pArrayListJugador);
		//printf("tam %d",tam);
		for(int i=0;i<tam;i++)
		{
			//printf("ENTRE AL FOR DE BUSCAR POR ID\n");
			AuxJugador=ll_get(pArrayListJugador, i);
			//NO DEBO HACER (*(AuxJugador+i).id PORQUE YA ll_get me retorna puntero a indice especificado, ademas el tema de trabajar con posiciones consecutivas o no.
			//if((*(AuxJugador)).id==idBuscado)
			if(jug_getId(AuxJugador, &idAux)==0)
			{
				if(idAux==idBuscado)
				{
					*indice=i;
					//printf("POSICION %d\n",*posicion);
					retorno=0;
					break;
				}
			}

		}
	}
	return retorno;
}
/// \fn int jug_Solicitar_Id(LinkedList*, int*, char*)
/// \brief Solicito id, valido que exista y retorno el indice en el que se encuentra (funcion jug_BuscarPorId).
///
/// \param pArrayListJugador
/// \param indice posicion del id
/// \param mensaje descripcion para solicitar el id
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Solicitar_Id(LinkedList* pArrayListJugador, int * indice ,char * mensaje)
{
	int retorno=-1;
	int idBuscado;

	//BUSCO EL ULTIMO ID PARA DARLE UN MAXIMO AL INGRESAR EL ID.

	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarIntConMinimo(&idBuscado, mensaje, "ERROR, Ingrese ID existente\n", 1);
			//ESTE PRINT ES POR SI EL USUARIO CARGA UN ID QUE ESTA POR DEBAJO DEL MAXIMO PERO QUE YA FUE BORRADO.
			if(jug_BuscarPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1)
			{
				printf("ERROR, Ingrese ID existente.\n");
			}
			//printf("POSICION %d\n",posicion);
		}while(jug_BuscarPorId(pArrayListJugador, idBuscado, &(*(indice)))==-1);
		retorno=0;
	}
	return retorno;
}
/// \fn int jug_Editar_NombreCompleto(LinkedList*, int)
/// \brief Recibo el indice de la estructura a modificarle el campo nombreCompleto, valido que el nuevo nombre sea distinto al anterior y
/// seteo el nuevo nombre a la estructura.
///
/// \param pArrayListJugador
/// \param indice
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Editar_NombreCompleto(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.
	char nuevoNombre[100];
	char viejoNombre[100];
	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarCadenaCaracteres(100, nuevoNombre, "Ingrese nuevo nombre completo del jugador.\t", "ERROR, Ingrese nombre completo valido\n");

			if(jug_getNombreCompleto(pJugador, viejoNombre)==0)
			{
				//retornoSrtcmp=strcmp((*(pJugador)).nombreCompleto, nuevoNombre);
				retornoSrtcmp=strcmp(viejoNombre, nuevoNombre);
				if(retornoSrtcmp==0)
				{
					printf("ERROR, El nombre ingresado es exactamente igual al existente\n");
				}
				else
				{
					jug_setNombreCompleto(pJugador, nuevoNombre);
					printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVO NOMBRE: %s >>>>>>>>>\n\n",nuevoNombre);
					//printf("\n<<<<<<<<<<NUEVO NOMBRE %s>>>>>>>>>>\n", nuevoNombre);
					retorno=0;
				}
			}
		}while(retornoSrtcmp==0);
	}
	if(retorno==-1)
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
/// \fn int jug_Editar_Edad(LinkedList*, int)
/// \brief Recibo el indice de la estructura a modificarle el campo edad, valido que la nueva edad sea distinta a la anterior y
/// seteo la nueva edad a la estructura.
///
/// \param pArrayListJugador
/// \param indice
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Editar_Edad(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	int nuevaEdad;
	int viejaEdad;
	if(pArrayListJugador!=NULL)
	{
		do
		{
			ingresarIntConRango(&nuevaEdad, "Ingrese nueva edad del jugador.(De 16 a 50 anios)\t", "ERROR, Ingrese edad valida.", 16, 50);
			if(jug_getEdad(pJugador, &viejaEdad)==0)
			{
				//if((*(pJugador)).edad==nuevaEdad)
				if(viejaEdad==nuevaEdad)
				{
					printf("ERROR, La edad ingresada debe ser distinta a la existente actualmente.\n");
				}
				else
				{
					jug_setEdad(pJugador, nuevaEdad);
					printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA EDAD %d>>>>>>>>>>\n",nuevaEdad);
					retorno=0;
				}
			}
			else
			{
				printf("ERROR,al intentar acceder a la anterior edad.\n");
			}


		}while(retorno==-1);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
/// \fn int jug_Editar_Posicion(LinkedList*, int)
/// \brief Recibo el indice de la estructura a modificarle el campo posicion, valido que la nueva posicion sea distinta a la anterior y
/// seteo la nueva posicion a la estructura.
///
/// \param pArrayListJugador
/// \param indice
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Editar_Posicion(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	char nuevaPosicion [30];
	//int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.
	char viejaPosicion[30];

	if(pArrayListJugador!=NULL)
	{
		do
		{
			//ingresarCadenaCaracteres(30, nuevaPosicion, "Ingrese nueva posicion del jugador.\nArquero - Defensor - Delantero - Mediocampista\t", "ERROR, Ingrese posicion valida\n");
			//retornoSrtcmp=strcmp((*(pJugador)).posicion, nuevaPosicion);
			jug_IngresarPosicion(nuevaPosicion);
			if(jug_getPosicion(pJugador, viejaPosicion)==0)
			{
				if(strcmp(viejaPosicion, nuevaPosicion)==0)
				{
					printf("ERROR, La posicion ingresada es exactamente igual a la existente\n");
				}
				else
				{
					jug_setPosicion(pJugador, nuevaPosicion);
					printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA POSICION %s >>>>>>>>>>\n",nuevaPosicion);
					retorno=0;
				}
			}
			else
			{
				printf("ERROR al inentar acceder a la anterior posicion.\n");
			}

		}while(retorno==-1);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}
	return retorno;
}
/// \fn int jug_Editar_Nacionalidad(LinkedList*, int)
/// \brief Recibo el indice de la estructura a modificarle el campo nacionalidad, valido que la nueva nacionalidad sea distinta a la anterior y
/// seteo la nueva nacionalidad a la estructura.
///
/// \param pArrayListJugador
/// \param indice
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Editar_Nacionalidad(LinkedList* pArrayListJugador , int indice)
{
	int retorno=-1;
	Jugador* pJugador;
	pJugador=ll_get(pArrayListJugador, indice);
	char nuevaNacionalidad[30];
	char nacionalidadVieja[30];
	//int retornoSrtcmp=0;//LO INICIALIZO POR SI EL USUARIO MODIFICA MAS DE UNA VEZ EL CAMPO.

	if(pArrayListJugador!=NULL)
	{
		do
		{
			//ingresarCadenaCaracteres(30, nuevaNacionalidad, "Ingrese nueva nacionalidad del jugador.\t", "ERROR, Ingrese nacionalidad valida.\n");
			jug_IngresarNacionalidad(nuevaNacionalidad);
			if(jug_getNacionalidad(pJugador, nacionalidadVieja)==0)
			{
				if(strcmp(nacionalidadVieja, nuevaNacionalidad)==0)
				{
					printf("ERROR, La nacionalidad ingresada es exactamente igual a la existente\n");
				}
				else
				{
					if(jug_setNacionalidad(pJugador, nuevaNacionalidad)==0)
					{
						printf("\n<<<<<<<<<< MODIFICACION SATISFACTORIA - NUEVA NACIONALIDAD %s >>>>>>>>>\n",nuevaNacionalidad);
						retorno=0;
					}
					else
					{
						printf("ERROR al setear la nueva nacionalidad.\n");
					}
				}
			}
			else
			{
				printf("ERROR al intentar acceder a la anterior nacionalidad.\n");
			}

		}while(retorno==-1);
	}
	else
	{
		printf("ERROR AL INTENTAR MODIFICAR");
	}

	return retorno;
}
/// \fn int jug_Confirmar_Baja(LinkedList*, int, char*)
/// \brief Se solicita que usuario ingre S o N para confirmar la baja de un jugador, se retorna segun
/// lo elegido por el mismo.
///
/// \param pArrayListJugador
/// \param indice
/// \param nombreJugador
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Confirmar_Baja(LinkedList* pArrayListJugador, int indice, char* nombreJugador)
{
	int retorno=-1;
	char confirmacion;
	char auxMayus;
	do
	{
		printf("Para confirmar la baja del jugador %s presione 'S', caso contrario 'N'.\n",nombreJugador);
		fflush(stdin);
		gets(&confirmacion);
		auxMayus=toupper(confirmacion);
		if(auxMayus=='S')
		{
			printf("<<<<<<<<<< BAJA CONFIRMADA >>>>>>>>>\n");
			retorno=0;

		}
	}while(verificarCaracterSN(confirmacion)==-1);
	//ARMO UN NUEVO IF PARA ESTE MSJ YA QUE SI LO PONGO COMO ELSE DENTRO DEL do{}while(), CADA VEZ QUE EL USUARIO INGRESE
	//CUALQUIER LETRA, APARECERIA
	if(retorno==-1)
	{
		printf("<<<<<<<<< BAJA CANCELADA >>>>>>>>>>\n");
	}
	return retorno;
}

/// \fn int jug_convocar(LinkedList*, LinkedList*)
/// \brief Se listan selecciones, se da a elegir 1 (validacion - selec_Solicitar_Id), en caso que el jugador pueda ser convocado se
/// le setea el id de seleccion y se suma 1 convocado al campo convocados de la estructura de tipo Seleccion del pais.
///Imprimo el nombre del jugador convocado y el del pais convocante.
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int idSeleccion;
	int jugIdSeleccion;
	int indiceSeleccion;
	int indiceJugador;
	int convocados;//SI SE CONFIRMA LA CONVOCACION DEBO SUMAR 1 A LA CANTIDAD DE CONVOCADOS EXISTENTES
	Seleccion* pSeleccion;
	Jugador* pJugador;
	char nombreCompleto[100];
	char pais[30];
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//LISTO A LAS SELECCIONES
		//jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 3);
		controller_listarSelecciones(pArrayListSeleccion);
		//SOLICITO ID VALIDANDO DESDE ESTA MISMA FUNCION A TRAVEZ DE LLAMAR A selec_Solicitar_Id QUE EL PAIS NO HAYA LLEGADO A 22 CONVOCADOS.
		if(selec_Solicitar_Id(pArrayListSeleccion, &indiceSeleccion)==0)
		{
			jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 3);
			jug_Solicitar_Id(pArrayListJugador, &indiceJugador, "Ingrese ID de jugador que desea convocar\t");
			//PIDO EL PUNTERO AL JUGADOR TENIENDO EN CUENTA EL INDICE.
			pJugador=ll_get(pArrayListJugador, indiceJugador);
			//if((*(pJugador)).idSeleccion==0)

			//APUNTO A LA ESTRUCUTRA DE SELECCION.
			pSeleccion=ll_get(pArrayListSeleccion, indiceSeleccion);

			if(jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0 && selec_getConvocados(pSeleccion, &convocados)==0 && selec_getId(pSeleccion, &idSeleccion)==0)
			{
				//printf("ID SELECCION: %d\n",idSeleccion);
				if(jugIdSeleccion==0)
				{
					//SUMO 1 A LOS CONVOCADOS YA EXISTENTES.
					convocados=convocados+1;
					//SETEO A LA SELECCION 1 CONVOCADO + Y AL JUGADOR EL ID DE LA SELECCION
					if(selec_setConvocados(pSeleccion, convocados)==0 && jug_setIdSeleccion(pJugador, idSeleccion)==0 &&
							jug_getNombreCompleto(pJugador, nombreCompleto)==0 && selec_getPais(pSeleccion, pais)==0)
					{
						//printf("<<<<<<<<<< %s fue CONVOCADO exitosamente por %s >>>>>>>>>>\n\n",(*(pJugador)).nombreCompleto,(*(pSeleccion)).pais);
						printf("<<<<<<<<<< %s fue CONVOCADO exitosamente por %s >>>>>>>>>>\n\n",nombreCompleto,pais);
						retorno=0;
					}
				}
				else
				{
					printf("ERROR, el jugador ya se encuentra convocado.\n");
				}
			}
		}
	}

	return retorno;
}
/// \fn int jug_Quitar_Convocado(LinkedList*, LinkedList*)
/// \brief Previa verificacion de la existencia de al menos 1 convocado, se listan jugadores convocados (jug_imprimirJugadores) , se
/// solicita id (jug_Solicitar_Id), en caso que el jugador se encuentre convocado se pondra en 0 al campo de idSeleccion y se
/// restara a la seleccion que convocante un convocado.
///
/// \param pArrayListJugador
/// \param pArrayListSeleccion
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_Quitar_Convocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int indice;
	int indiceSeleccion;
	Jugador* pJugador;
	int jugIdSeleccion;
	char nombreCompleto[100];
	int selecConvocados;
	Seleccion* pSeleccion;
	int flag=0;
	char jug_NombreCompleto[100];
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		//jug_Listar_Convocados(pArrayListJugador, pArrayListSeleccion, 2);
		jug_imprimirJugadores(pArrayListJugador, pArrayListSeleccion, 2);
		do
		{
			jug_Solicitar_Id(pArrayListJugador, &indice, "Ingrese ID del jugador que desar quitar de la convocatoria.\n");

			pJugador=ll_get(pArrayListJugador, indice);
			if(jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0 && jug_getNombreCompleto(pJugador, nombreCompleto)==0)
			{
				if(jugIdSeleccion!=0)
				{
					if(selec_buscarPorId(pArrayListSeleccion, jugIdSeleccion, &indiceSeleccion)==0)
					{
						pSeleccion=ll_get(pArrayListSeleccion, indiceSeleccion);
						if(selec_getConvocados(pSeleccion, &selecConvocados)==0)
						{
							//printf("CANTIDAD DE CONVOCADOS ANTES DE BAJAR %d\n",selecConvocados);
							//1 CONVOCADO MENOS - LUEGO SETEO ESTE CAMBIO
							selecConvocados=selecConvocados-1;
							//(*(seleccion)).convocados=(*(seleccion)).convocados-1

							//PONGO EN 0 AL ID DE SELECCION DEL JUGADOR
							//(*(pJugador)).idSeleccion=0;
							jugIdSeleccion=0;
							//SETEO NUEVOS VALORES PARA EL JUGADOR (idSeleccion) y para la seleccion 1 convocado menos
							if(jug_setIdSeleccion(pJugador, jugIdSeleccion)==0 && selec_setConvocados(pSeleccion, selecConvocados)==0)
							{
								if(jug_getNombreCompleto(pJugador, jug_NombreCompleto)==0)
								{
									retorno=0;
									flag=1;
									printf("<<<<<<<<<< %s bajado de la convocatoria exitosamente. >>>>>>>>>>\n",jug_NombreCompleto);
								}
							}
							else
							{
								printf("ERROR al setear el id de seleccion del jugador en 0 / al setear la cantidad de convocados nueva de la seleccion.\n");
							}
						}
						else
						{
							printf("ERROR al buscar el index por desde el ID.\n");
						}
					}
				}
				else
				{
					printf("ERROR, El id ingresado pertenece a un jugador NO convocado por ninguna seleccion.\n");
				}
			}
			else
			{
				printf("ERROR al intentar acceder al id de la seleccion / al nombre del jugador.\n");
			}
		}while(flag==0);
	}
	return retorno;
}
/// \fn int jug_verificarCambios(LinkedList*, LinkedList*, int*)
/// \brief Se compara el tamanio y campo a campo, de una lista sin modificar de jugadores y de otra potencialmente modificable de
/// jugadores. En caso de existir un cambio se retorna por referencia un 1.
///
/// \param pArrayListJugador
/// \param pArrayListJugadorOriginal
/// \param jug_Flag
/// \return return return int return=0 SALIO BIEN / return=-1 SALIO MAL.
int jug_verificarCambios(LinkedList* pArrayListJugador ,LinkedList* pArrayListJugadorOriginal, int* jug_Flag)
{
	int retorno=-1;
	Jugador* pJugador;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Jugador* pJugadorOriginal;
	char nombreCompletoOriginal[100];
	int edadOriginal;
	char posicionOriginal[30];
	char nacionalidadOriginal[30];
	int idSeleccionOriginal;

	int tamJugadores;
	tamJugadores=ll_len(pArrayListJugador);
	int tamJugadoresOriginal;
	tamJugadoresOriginal=ll_len(pArrayListJugadorOriginal);
	if(pArrayListJugador!=NULL && pArrayListJugadorOriginal!=NULL)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			pJugador=ll_get(pArrayListJugador, i);
			pJugadorOriginal=ll_get(pArrayListJugadorOriginal, i);
			if(jug_getEdad(pJugador, &edad)==0 && jug_getEdad(pJugadorOriginal, &edadOriginal)==0 &&
					jug_getNacionalidad(pJugador, nacionalidad)==0 && jug_getNacionalidad(pJugadorOriginal, nacionalidadOriginal)==0 &&
					jug_getNombreCompleto(pJugador, nombreCompleto)==0 && jug_getNombreCompleto(pJugadorOriginal, nombreCompletoOriginal)==0 &&
					jug_getPosicion(pJugador, posicion)==0 && jug_getPosicion(pJugadorOriginal, posicionOriginal)==0 &&
					jug_getSIdSeleccion(pJugador, &idSeleccion)==0 && jug_getSIdSeleccion(pJugadorOriginal, &idSeleccionOriginal)==0)
			{
				retorno=0;
				if(edad!=edadOriginal || strcmp(nacionalidad,nacionalidadOriginal)!=0 || strcmp(nombreCompleto,nombreCompletoOriginal)!=0 ||
						strcmp(posicion,posicionOriginal)!=0 || idSeleccion!=idSeleccionOriginal || tamJugadores!=tamJugadoresOriginal)
				{
					*jug_Flag=1;
					break;
				}
			}
		}
	}
	return retorno;
}
/// \fn int jug_guardarJugadores(LinkedList*, char*, LinkedList*, char*)
/// \brief
///
/// \param pArrayListSeleccion
/// \param nombreConfederacion
/// \param pArrayListJugador
/// \param path
/// \return
int jug_guardarJugadores(LinkedList* pArrayListSeleccion, char* nombreConfederacion, LinkedList* pArrayListJugador, char* path)
{
	int retorno=-1;
	Jugador* pJugador;
	int tamJugadores;
	int tamSelecciones;
	Seleccion* pSeleccion;
	tamJugadores=ll_len(pArrayListJugador);
	tamSelecciones=ll_len(pArrayListSeleccion);
	char selecConfederacion[30];
	int selecId;
	int jugIdSeleccion;

	FILE* pArchivo;

	if(pArrayListSeleccion!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo=fopen(path,"wb");
		for(int i=0;i<tamSelecciones;i++)
		{
			pSeleccion=ll_get(pArrayListSeleccion, i);
			if(selec_getConfederacion(pSeleccion, selecConfederacion)==0 && selec_getId(pSeleccion, &selecId)==0)
			{
			//	printf("CONFEDERACION %s\n LA OTRA CONFEDERACION %s\n ID %d",nombreConfederacion,selecConfederacion,selecId);
				if(strcmp(nombreConfederacion,selecConfederacion)==0)
				{
					//INGRESE A UN PAIS DE LA CONFEDERACION
					for(int i=0;i<tamJugadores;i++)
					{
						pJugador=ll_get(pArrayListJugador, i);
						if(jug_getSIdSeleccion(pJugador, &jugIdSeleccion)==0)
						{
							//EL JUGADOR PERTENECE A LA CONFEREDACION
							if(selecId==jugIdSeleccion)
							{
								retorno=0;
								fwrite(pJugador,sizeof(Jugador),1,pArchivo);
							}
						}
					}
				}
			}

		}
		fclose(pArchivo);
	}
	return retorno;
}

