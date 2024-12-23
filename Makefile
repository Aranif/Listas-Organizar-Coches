#RELLENAR
#Makefile del programa practica 7 ejercicio1
COM = gcc -g -Wall -Wextra -c
OBJ = gcc -g -Wall -Wextra -o

gestionVehiculos: gestionVehiculos.o funciones.o funciones.h
	$(OBJ) gestionVehiculos gestionVehiculos.o funciones.o

gestionVehiculos.o: gestionVehiculos.c  funciones.o funciones.h
	$(COM) gestionVehiculos.c 

funciones.o: funciones.c funciones.h
	$(COM) funciones.c

borra: *.o
	rm -r *.o gestionVehiculos  *.c~
