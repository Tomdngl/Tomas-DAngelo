//Set up de github
#include "trabajo.h"
#include "servicio.h"
#define TAM_TRABAJO 10000
#define TAM_SERVICIOS 4

int main(void) {
	setbuf(stdout, NULL);

	int opc;

	//Creo los arrays de las estructuras
	eTrabajo Trabajo[TAM_TRABAJO];
	eServicio Servicios[TAM_SERVICIOS];

	//Inicializo el array
	eTrabajo_Inicializar(Trabajo, TAM_TRABAJO);

	//Inicio bucle del menu
	do {
		//Llamo a la impresion del menu
		menu(&opc);
		hardcodearServicios(Servicios);

		//Switch del menu
		switch (opc)
		{
		case 1:
			//ALTA
			if (eTrabajo_Alta(Trabajo, TAM_TRABAJO)) {
				puts("Trabajo dado de alta exitosamente");
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 9:
			opc = 9;
			break;
		}
	}while(opc != 9);

	puts("\n Salio del programa.");

	return 0;
}
