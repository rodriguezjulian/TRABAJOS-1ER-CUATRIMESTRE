/*
 * salidas.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Julian Rodriguez
 */

#ifndef SALIDAS_H_
#define SALIDAS_H_

void mostrarMenuPrincipal();
int selec_imprimirSeleccion(LinkedList* pArrayListSeleccion, int index);
int jug_imprimirJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, int referenciaDeUso);
void jug_MostrarNacionalidades(void);
#endif /* SALIDAS_H_ */
