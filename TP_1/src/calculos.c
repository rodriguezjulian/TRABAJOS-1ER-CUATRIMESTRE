/*
 * calculos.c
 *
 *  Created on: 14 sep. 2022
 *      Author: Julian Rodriguez
 */
#include <stdio.h>
#include <stdlib.h>

int calcularPromedioArray(int tam, int* array, float* promedio)
{
	int retorno=-1;
	int acumulador;
	acumulador=0;

	if(tam>0 && array!=NULL && promedio!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			acumulador=acumulador+array[i];
		}
		*promedio=(float)acumulador/tam;
		retorno=0;
	}
	return retorno;
}
void inicializarArray(int array[],int tam)
{
	if(array!=NULL)
	{
		for (int i = 0; i < tam; ++ i)
		{
			array[i]=0;
		}
	}
}
int calcularMaximoArray(int* array, int* valorMaximo)
{
	int retorno=-1;
	if(array!=NULL && valorMaximo!=NULL)
	{
		*valorMaximo=array[0];
		for(int i=0;i<5;i++)
		{
			//ENTRA Y COMPARA EL VALOR MAXIMO QUE DIJIMOS QUE ES EL DE LA POSICION 0 CON CADA UNA DE LAS POSICIONES DEL ARRAY
			if(*valorMaximo<array[i])
			{
					*valorMaximo=array[i];
			}
		}
		retorno=0;
	}

	return retorno;
}

int contarImparesDeArray(int* array,int tam)
{
	int retorno=0;
	if(array!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
		 	if(array[i]%2==1)
			{
				retorno=retorno+1;
			}
		}
	}

	return retorno;
}
int contarNegativosArray(int* array,int tam)
{
	int retorno=0;
	if(array!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
		 	if(array[i]<0)
			{
				retorno=retorno+1;
			}
		}
	}
	return retorno;
}
int sumarImparesDeArray(int array[],int tam)
{
	int retorno=0;
	if(array!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
		 	if(array[i]%2==1 || array[i]%2==-1)
			{
				retorno=retorno+array[i];
			}
		}
	}

	return retorno;
}
int calcularMaximoArrayPar(int* array, int* valorMaximo)
{
	int retorno=-1;
	if(array!=NULL && valorMaximo!=NULL)
	{
		*valorMaximo=array[0];
		for(int i=0;i<5;i++)
		{
			if(array[i]%2==0)
			{
				if(*valorMaximo<array[i])
				{
						*valorMaximo=array[i];
				}
			}

		}
		retorno=0;
	}

	return retorno;
}
int imprimirArrayInt(int* array,int tam, char* mensaje)
{
	int retorno=-1;
	if(array!=NULL && tam>0)
	{
		printf("%s",mensaje);
		for(int i=0;i<tam;i++)
		{
			printf("%d | ",array[i]);
			retorno=0;
		}
		printf("\n");
	}
	return retorno;
}
int imprimirArrayIntConMinimo(int* array,int tam, char* mensaje, int minimo)
{
	int retorno=-1;
	if(array!=NULL && tam>0 && mensaje!=NULL)
	{
		printf("%s",mensaje);
		for(int i=0;i<tam;i++)
		{
			if(array[i]>minimo)
			{
				printf("%d | ",array[i]);
				retorno=0;
			}
		}
		printf("\n");
	}
	return retorno;
}
int imprimirIntEnPosicionImpar( int* array, int tam, char* mensaje)
{
	int retorno=-1;
	printf("%s",mensaje);
	if(array!=NULL && mensaje!=NULL && tam>0)
	{
		for(int i=0;i<5;i++)
		{
			if(i%2==1)
			{
				printf("%d | ",array[i]);
			}
		}
		retorno=0;
	}
	return retorno;
}
int calcularPromedioPositivosArray(int tam, int* array, float* promedio, int contadorPositivos)
{
	int retorno=-1;
	int acumulador;
	acumulador=0;

	if(tam>0 && array!=NULL && promedio!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(array[i]>0)
			{
				acumulador=acumulador+array[i];
			}
		}
		*promedio=(float)acumulador/contadorPositivos;
		retorno=0;
	}
	return retorno;
}
int contarPositivosArray(int* array,int tam)
{
	int retorno=0;
	if(array!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
		 	if(array[i]>0)
			{
				retorno=retorno+1;
			}
		}
	}
	return retorno;
}
int calcularMinimoArray(int* array, int* valorMinimo, int tam)
{

	int retorno=-1;
	if(array!=NULL && valorMinimo!=NULL)
	{
		*valorMinimo=array[0];
		for(int i=0;i<tam;i++)
		{
			//ENTRA Y COMPARA EL VALOR MINIMO QUE DIJIMOS QUE ES EL DE LA POSICION 0 CON CADA UNA DE LAS POSICIONES DEL ARRAY
			if(*valorMinimo>array[i])
			{
				*valorMinimo=array[i];
			}
		}
		retorno=0;
	}

	return retorno;
}

int ordenarArrayAscendente(int* array, int tam)
{
	int retorno=-1;
	int auxiliar;

	if(array!=NULL && tam>0)
	{
		retorno=0;
		for(int i=0;i<tam-1;i++)
		{
			for(int j=i+1;j<tam;j++)
			{
				if(array[i]>array[j])
				{
					auxiliar=array[i];
					array[i]=array[j];
					array[j]=auxiliar;
				}
			}
		}
	}
	return retorno;
}

int imprimirArrayIntSinCero(int* array,int tam, char* mensaje)
{
	int retorno=-1;
	if(array!=NULL && tam>0)
	{
		printf("%s",mensaje);
		for(int i=0;i<tam;i++)
		{
			if(array[i]!=0)
			{
				printf("%d | ",array[i]);
			}
			retorno=0;
		}
		printf("\n");
	}
	return retorno;
}

int ordenarArrayDescendente(int* array, int tam)
{
	int retorno=-1;
	int auxiliar;

	if(array!=NULL && tam>0)
	{
		retorno=0;
		for(int i=0;i<tam-1;i++)
		{
			for(int j=i+1;j<tam;j++)
			{
				if(array[i]<array[j])
				{
					auxiliar=array[i];
					array[i]=array[j];
					array[j]=auxiliar;
				}
			}
		}
	}
	return retorno;
}

int limitarContador(int *contador ,int maxContar,char* mensaje)
{
	int retorno=-1;
	if(*contador < maxContar)
	{
		*contador=*contador+1;
		retorno=0;
	}
	else
	{
		printf("%s", mensaje);
	}
	return retorno;
}
float calcularPromedio(int numeroB, int numeroA)
{
	float retorno;
	retorno=(float)numeroA/numeroB;
	return retorno;
}
