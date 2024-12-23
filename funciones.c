#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarLista(Lista *lista) {
  lista->inicio = NULL;
}


void agregarVehiculo(Lista *lista) {
  Vehiculo *nuevo = (Vehiculo *)malloc(sizeof(Vehiculo));
  if (nuevo != NULL) {
    printf("Ingrese la marca del vehículo: ");
    scanf(" %49s", nuevo->marca);
    printf("Ingrese el modelo: ");
    scanf(" %49s", nuevo->modelo);
    printf("Ingrese el año: ");
    scanf("%d", &nuevo->anio);
    printf("¿Es un automóvil? (1 = Sí, 0 = No): ");
    scanf("%d", &nuevo->esAutomovil);

    if (nuevo->esAutomovil) {
      printf("Ingrese el número de puertas: ");
      scanf("%d", &nuevo->tipo.numPuertas);
    } 
    else {
      printf("Ingrese la capacidad máxima de carga (en toneladas): ");
      scanf("%f", &nuevo->tipo.capacidadCarga);
    }
	//enlaza los elementos 
    nuevo->siguiente = lista->inicio;
    lista->inicio = nuevo;

    printf("Vehículo agregado con éxito.\n");
  }
  else
    printf("Error al asignar memoria.\n");
}

void editarVehiculo(Lista *lista, char *marca) {
  Vehiculo *actual = lista->inicio;

  // RELLENAR: incluir condición del bucle para encontrar el vehículo buscando por la marca
  while (strcmp(actual->marca, marca) != 0) { // si es 0 significa que es igual 
    actual = actual->siguiente;
  }

  // RELLENAR: incluir condición del if para comprobar que no se ha encontrado el vehículo con la marca proporcionada
  
  if (NULL != actual) //SI ES NULL signfica que ha llegado al final de la lista
    
    printf("Vehículo con marca '%s' no encontrado.\n", marca);

  else {
    printf("Datos actuales del vehículo:\n");
    printf("Marca: %s\n", actual->marca);
    printf("Modelo: %s\n", actual->modelo);
    printf("Año: %d\n", actual->anio);

    // RELLENAR: incluir condición del if para comprobar si es un automóvil
    if (actual->esAutomovil == 1) {
      printf("Tipo: Automóvil\n");
      printf("Número de puertas: %d\n", actual->tipo.numPuertas);
    } 
    else {
      printf("Tipo: Camión\n");
      printf("Capacidad de carga: %.2f toneladas\n", actual->tipo.capacidadCarga);
    }

    printf("\nIngrese los nuevos datos del vehículo:\n");
    printf("Nueva marca: ");

    // RELLENAR: editar el campo marca
    scanf(" %50s", actual->marca);    
    printf("Nuevo modelo: ");

    // RELLENAR: editar el campo modelo
    scanf(" %50s", actual->modelo);
    printf("Nuevo año: ");

    // RELLENAR: editar el campo anio
    scanf(" %d", &actual->anio);   
    printf("Es un automóvil? (1 = Sí, 0 = No): ");

    // RELLENAR: editar el campo esAutomovil
    scanf(" %d", &actual->esAutomovil);  

    // RELLENAR: incluir condición del if para comprobar si es un automóvil
    if (actual->esAutomovil == 1) {
      printf("Nuevo número de puertas: ");

      // RELLENAR: editar el campo del número de puertas
      scanf(" %d", &actual->tipo.numPuertas);
    } 
    else {
      printf("Nueva capacidad de carga (en toneladas): ");

      // RELLENAR: editar el campo de la capacidad de carga
      scanf(" %f", &actual->tipo.capacidadCarga);
            
    }

    printf("Vehículo editado con éxito.\n");
  }
}

void mostrarVehiculos(Lista *lista) {
  Vehiculo *actual = lista->inicio;

  if (actual != NULL) {
    while (actual != NULL) {
      printf("Marca: %s\n", actual->marca);
      printf("Modelo: %s\n", actual->modelo);
      printf("Año: %d\n", actual->anio);
      if (actual->esAutomovil) {
	printf("Tipo: Automóvil\n");
	printf("Número de puertas: %d\n", actual->tipo.numPuertas);
      } 
      else {
	printf("Tipo: Camión\n");
	printf("Capacidad de carga: %.2f toneladas\n", actual->tipo.capacidadCarga);
      }
      printf("------------------------\n");
      actual = actual->siguiente;
    }
  }
  else
    printf("No hay vehículos registrados.\n");
}

void liberarLista(Lista *lista) {
  Vehiculo *actual = lista->inicio;
  while (actual != NULL) {
    Vehiculo *temp = actual;
    actual = actual->siguiente;
    free(temp);
  }
  lista->inicio = NULL;
}
