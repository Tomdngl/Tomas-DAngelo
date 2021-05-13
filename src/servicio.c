#include "servicio.h"
#include "utn.h"

int Servicio_idIncremental = 20000;
void hardcodearServicios(eServicio array[]){
	int auxId[4]={20000, 20001, 20002, 20003};
	char auxDescripcion[4][MAX_C_CADENA]={"Limpieza", "Parche", "Centrado", "Cadena"};
	int i;

	for(i=0; i<4; i++){
		array[i].idServicio=auxId[i];
		strcpy(array[i].descripcionServicio, auxDescripcion[i]);
	}
}

int eServicio_ObtenerID() {
	return Servicio_idIncremental += 1;
}

void eServicio_Inicializar(eServicio array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eServicio_ObtenerIndexLibre(eServicio array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eServicio_BuscarPorID(eServicio array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idServicio == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eServicio_MostrarUno(eServicio Servicio) {
	//PRINTF DE UN SOLO Servicio
	printf("%5d\n", Servicio.idServicio);
}

int eServicio_MostrarTodos(eServicio array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Servicio");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Servicio
				eServicio_MostrarUno(array[i]);
				//CONTADOR DE Servicio
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Servicio PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eServicio eServicio_CargarDatos(void) {
	eServicio auxiliar;
	utn_getDescripcion(auxiliar.descripcionServicio, MAX_C_CADENA, "Ingrese la fecha" , "Error\n", 5);
	utn_getNumeroFlotante(&auxiliar.precioServicio, "Ingrese el precio del servicio", "Error\n", 0, 0, 5);
	return auxiliar;
}

eServicio eServicio_ModificarUno(eServicio Servicio) {
	eServicio auxiliar = Servicio;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eServicio_Alta(eServicio array[], int TAM) {
	int rtn = 0;
	eServicio auxServicio;

	//BUSCO ESPACIO EN ARRAY
	int index = eServicio_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Servicio AUXILIAR
		auxServicio = eServicio_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxServicio.idServicio = eServicio_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxServicio.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxServicio;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

