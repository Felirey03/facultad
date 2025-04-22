#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  SList lista2 = slist_crear();


  int longitud = slist_longitud(lista2);

  lista = slist_concatenar(lista,lista2);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  //printf("%d \n", longitud);

  lista = slist_insertar(lista, 3, 2);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  lista = slist_eliminar(lista, 3);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  slist_contiene(lista, 2);

  SList lista3 = slist_crear();

  int indice = slist_indice(lista3, 3);
  printf("El indice en donde se encuentra el 3 es: %d \n", indice);

  lista2 = slist_agregar_inicio(lista2, 9);
  lista2 = slist_agregar_inicio(lista2, 7);
  lista2 = slist_agregar_inicio(lista2, 1);
  lista2 = slist_agregar_final(lista2, 10);

  slist_recorrer(lista2, imprimir_entero);
  puts("");

  SList nuevaLista = slist_intersecar(lista, lista2);
  slist_recorrer(nuevaLista, imprimir_entero);
  puts("");


  slist_destruir(lista);
  slist_destruir(lista2);
  slist_destruir(lista3);
  slist_destruir(nuevaLista);
  
  return 0;
}
