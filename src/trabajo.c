#include "trabajo.h"
#include "utn.h"
#include "servicio.h"

int Trabajo_idIncremental = 0;

void menu(int* opcion){
	//OPCIONES A MOSTRAR DEL MENU
	char opciones[MAX_OPCIONES_MENU][80]=
	  {"1. Alta de trabajo",
	   "2. Modificar trabajo",
	   "3. Baja trabajo",
	   "9. Salir"
	  };

    int i;
    for (i=0; i<MAX_OPCIONES_MENU; i++){
      printf("%s\n", opciones[i]);
    }
    utn_getNumero(opcion, "Elija una opcion: ", "Opcion incorrecta\n ", 0, 9, 9);
    fflush(stdin);
}

int eTrabajo_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Trabajo_idIncremental += 1;
}

void eTrabajo_Inicializar(eTrabajo array[], int TAM) {
	int i;

	//Verifico que exista el array y el limite sea valido
	if (array != NULL && TAM > 0) {
		//Recorro array
		for (i = 0; i < TAM; i++) {
			//Seteo el estado de las posiciones como libre
			array[i].isEmpty = LIBRE;
		}
	}
}

int eTrabajo_ObtenerIndexLibre(eTrabajo array[], int TAM) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eTrabajo_BuscarPorID(eTrabajo array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idTrabajo == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

eTrabajo eTrabajo_CargarDatos(void) {
	eTrabajo auxiliar;
	int esFecha;
	utn_getNumero(&auxiliar.idServicio,"Ingrese el id del servicio: ", "Error\n", 0, 30000, 5);
	utn_getNombre(auxiliar.marcaBicicleta, MAX_C_CADENA, "Escriba la marca de su bicicleta: ", "Error\n", 5);
	utn_getNumero(&auxiliar.rodadoBicicleta,"Ingrese el rodado de su bicicleta: ", "Error\n", 0, 100, 5);
	do{
		utn_getNumero(&auxiliar.dia, "Ingrese el dia: ", "Error\n", 0, 31, 5);
		utn_getNumero(&auxiliar.mes, "Ingrese el mes: ", "Error\n", 0, 12, 5);
		utn_getNumero(&auxiliar.anio, "Ingrese el anio: ", "Error\n", 0, 2021, 5);
		esFecha=valFecha(auxiliar.dia, auxiliar.mes, auxiliar.anio);
	}while(esFecha!=1);
	return auxiliar;
}

int eTrabajo_Alta(eTrabajo array[], int TAM) {
	int rtn = 0;
	int validacion;
	eTrabajo auxTrabajo;

	//BUSCO ESPACIO EN ARRAY
	int index = eTrabajo_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO TRABAJO AUXILIAR
		auxTrabajo = eTrabajo_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxTrabajo.idTrabajo = eTrabajo_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTrabajo.isEmpty = OCUPADO;

		utn_getNumero(&validacion, "¿Desea cargar los datos previamente ingresados? 1 = 'Si' | 2 = 'No'", "Error, ", 1, 2, 3);
		if(validacion==1){
			rtn = 1;
			array[index] = auxTrabajo;
		}
		else{
			printf("Se cancelo el alta de datos\n");
		}
	}

	return rtn;
}
