/*
 * ingresos.h
 *
 *  Created on: 8 sep. 2022
 *      Author: Julian Rodriguez
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_

/// \fn int ingresarFloat2(float*, char*)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi".
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarFloat(float* resultado,char* mensaje);

/// \fn int ingresarFloatConMinimo(float*, char*, char*, int)
/// \brief Se llama a la funcion "ingresarFloat", para luego validar si esta por encima del rango minimo.
///
/// \param resultado ,se pasara por referencia el numero ingresado una vez validado a esta variable.
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,usado como referencia, su valor se utilizara como rango inferior.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarFloatConMinimo(float* resultado, char* mensaje,char*mensajeError,int minimo);


/// \fn int ingresarNumIntConRango(int*, char*, char*, int, int)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi", para luego verificar si se
/// cumple con el rango.
///
///
/// \param resultado ,tipo de dato short (pasa por referencia).
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// \fn int confirmarSalida(void)
/// \brief Cuando el usuario ingresa una opcion para dejar de operar un programa,
/// esta funcion verifica que es lo que realmente quiere y no que se equivoco.
/// \return return en 0 cuando se confirma la salida del usuario.
//int confirmarSalida(void);


/// \fn int ingresarCadenaCaracteres(int, char*, char*, char*)
/// \brief Ingresar una cadena de caracteres verificando el tamanio, y que no se encuentren numeros.
///
/// \param tam ,tamaño de la cadena
/// \param textoIngresado ,el resultado se pasara por referencia.
/// \param mensaje ,mensaje utilizado para solicitar la cadena.
/// \param mensajeError ,mensaje de error por si el usuario excede la cantidad de caracteres.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError);

/// \fn int ingresarShortConRango(short*, char*, char*, short, short)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi", para luego verificar si se
/// cumple con el rango.
///
/// \param resultado , tipo de dato short (pasa por referencia).
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarShortConRango(short* resultado, char* mensaje, char* mensajeError, short minimo, short maximo);


/// \fn int ingresarShortConRango(short*, char*, char*, int, int,int)
/// \brief Ingreso texto, verifico que sean numeros efectivamente (isDigit), y paso a numeros con "atoi", para luego verificar si se
/// cumple con el rango.
/// \param resultado , tipo de dato int (pasa por referencia).
/// \param mensaje ,mensaje utilizado para solicitar el numero.
/// \param mensajeError ,mensaje de error por si el usuario ingresa un numero por debajo del minimo.
/// \param minimo ,limite inferior del rango.
/// \param maximo ,limite superior del rango.
/// \param reintentos
/// \return return=0 SALIO BIEN / return=-1 SALIO MAL
int ingresarIntConRangoReintentos(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// \fn void confirmarSalida(int*)
/// \brief Pide confirmacion de salida, en caso de ser positiva modifica el valor de la variable recibida por parametro, en caso de
/// quedarse sin reintentos tambien se modifica el valor de la variable recibida por parametro.
/// \param flag
void confirmarSalida(int* flag);

#endif /* INGRESOS_H_ */
