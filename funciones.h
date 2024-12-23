#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_MARCA 50
#define MAX_MODELO 50

// Unión para tipo específico de vehículo
typedef union {
  int numPuertas;         // Para automóviles
  float capacidadCarga;   // Para camiones
} TipoVehiculo;

// Estructura principal del vehículo
typedef struct Vehiculo {
  char marca[MAX_MARCA];
  char modelo[MAX_MODELO];
  int anio;
  int esAutomovil; // 1 si es automóvil, 0 si es camión
    
  // RELLENAR: crear la variable de nombre tipo para definir el tipo de vehículo
  TipoVehiculo  tipo; 

  // RELLENAR: crear la variable (siguiente) para apuntar al siguiente nodo de la lista
  struct Vehiculo * siguiente; 
} Vehiculo;

// Estructura de la lista
typedef struct {
  Vehiculo *inicio;
} Lista;

// RELLENAR: declaracion de las funciones
void inicializarLista(Lista *lista);
void agregarVehiculo(Lista *lista);
void editarVehiculo(Lista *lista, char *marca);
void mostrarVehiculos(Lista *lista);
void liberarLista(Lista *lista);




#endif
