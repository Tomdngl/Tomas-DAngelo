#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EServicio_H_
#define EServicio_H_

//Defines
#define MAX_C_CADENA 40
#define LIBRE 0
#define OCUPADO 1

//Estructura
typedef struct {
	int idServicio;
	char descripcionServicio[MAX_C_CADENA];
	float precioServicio;
	int isEmpty;
} eServicio;
//***

/** INICIO CABECERAS DE FUNCION*/
void hardcodearServicios(eServicio array[]);
void eServicio_Inicializar(eServicio array[], int TAM);
int eServicio_ObtenerID(void);
int eServicio_ObtenerIndexLibre(eServicio array[], int TAM);
int eServicio_BuscarPorID(eServicio array[], int TAM, int ID);
void eServicio_MostrarUno(eServicio Servicio);
int eServicio_MostrarTodos(eServicio array[], int TAM);

//ABM
eServicio eServicio_CargarDatos(void);
eServicio eServicio_ModificarUno(eServicio Servicio);
int eServicio_Alta(eServicio array[], int TAM);
int eServicio_Baja(eServicio array[], int TAM);
int eServicio_Modificacion(eServicio array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
