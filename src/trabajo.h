#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRABAJO_H_
#define TRABAJO_H_

//Defines
#define MAX_C_CADENA 40
#define MAX_OPCIONES_MENU 4
#define LIBRE 0
#define OCUPADO 1

//Estructura
typedef struct {
	char marcaBicicleta[MAX_C_CADENA];
	int dia;
	int mes;
	int anio;
	int rodadoBicicleta;
	int idServicio;
	int idTrabajo;
	int isEmpty;
} eTrabajo;

// Cabeceras de funciones
void menu(int* opcion);
void eTrabajo_Inicializar(eTrabajo array[], int TAM);
int eTrabajo_ObtenerID(void);
int eTrabajo_ObtenerIndexLibre(eTrabajo array[], int TAM);

eTrabajo eTrabajo_CargarDatos(void);
eTrabajo eTrabajo_ModificarUno(eTrabajo Trabajo);
int eTrabajo_Alta(eTrabajo array[], int TAM);
int eTrabajo_Baja(eTrabajo array[], int TAM);
int eTrabajo_Modificacion(eTrabajo array[], int TAM);
//Fin de cabeceras

#endif /* TRABAJO_H_ */
