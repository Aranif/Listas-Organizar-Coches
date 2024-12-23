/* Arán Iglesias Fernández
** Fichero: gestionVehiculos.c
*/

#include <stdio.h>
#include "funciones.h"

int main() {
  Lista flota;
  inicializarLista(&flota);

  int opcion;
  char marca[MAX_MARCA];

  do {
    printf("\n--- Menú de Gestión de Flota ---\n");
    printf("1. Agregar vehículo\n");
    printf("2. Editar vehículo\n");
    printf("3. Mostrar vehículos\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      // RELLENAR: llamada a la función agregarVehiculo
      agregarVehiculo(&flota);          
      break;
    case 2:
      printf("Ingrese la marca del vehículo a editar: ");
      scanf(" %49s", marca);
      // RELLENAR: llamada a la función editarVehiculo
      editarVehiculo(&flota, marca);
      break;
    case 3:
      // RELLENAR: llamada a la función mostrarVehiculos
      mostrarVehiculos(&flota);  
      break;
    case 4:
      // RELLENAR: llamada a la función liberarLista
      liberarLista(&flota);
      printf("Saliendo del programa...\n");
      break;

    default:
      printf("Opción no válida.\n");
    }
  } 
  while (opcion != 4);

  return 0;
}
