<h1>Aprende a usar listas dinámicas en C de una vez.</h1>

<p>Para crear una lista en C lo principal es : </p>
<ol type = "1">
  <li>Hacer una estructura con "struct"</li>
  
  ```c
  typedef struct nodo{
  int info; // puede ser cualquiera información
  struct NODO * siguiente; // puntero al siguiente elemento de la lista 
  }NODO;
```
<li>La función crea nodo que devuelve un puntero a ese nuevo nodo, guardado dinámicamente.</li>

 ```c
// le pasaremos los parámetros que queremos introducir
  NODO * CreaNodo(int inf){

  NODO * p = (NODO * )malloc(sizeof(NODO)); // Reserva de memoria de tamaño NODO.
  if(p != NULL){

    pnuevo->info = inf;
    p->siguiente = NULL; // se le dará la direccion del primero en la listA 
}
return p; 
}
```
<li>Tenemos que enlazar el nuevo puntero a la lista.</li>

```c
void enlaza ( NODO * pnuevo, NODO ** pprimero){ // pprimero se pasa como parametro por referencia

if(pprimero == NULL) // LISTA VACIA 
  pprimero = pnuevo;

if(pnuevo != NULL){
  pnuevo->siguiente = *pprimero;
  *pprimero = pnuevo; 
}
}
```
</ol>
<p>Luego creando funciones con bucles, podemos recorrer la lista elemento a elemento, borrar elementos y añadir nuevos 
elementos. Con cuidado de acceder a memorias que no existen o no están reservadas. </p>

<h1>Más de una lista</h1>
<p>En el código presento como hago un una lista <b>"LISTA flota"</b>, esto es para indicar que de la misma forma podríamos 
hacer <b>"LISTA flota2"</b> y ya tendríamos dos listas totalmente independiente en nuestro código.</p>
