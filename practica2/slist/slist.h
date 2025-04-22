#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Determina la longitud de la lista.
 */
int slist_longitud(SList lista);

/**
 * Devuelve la concatenación de dos listas, modificando la primera.
 */

SList slist_concatenar(SList lista1, SList lista2);

/**
 * Inserta un dato en una posicion arbitraria.
 */
SList slist_insertar(SList lista, int dato, int pos);

/**
 * Elimina un dato en una posicion arbitraria.
 */
SList slist_eliminar(SList lista, int pos);

/**
 * Determina si un elemento esta o no en la lista.
 */
int slist_contiene(SList lista, int elem);

/**
 * Determina si el elemento esta en la lista y devuelve su indice
 */
int slist_indice(SList lista, int elem);

/**
 * Dadas dos listas devuelve una lista con elementos en comun
 */
SList slist_intersecar(SList lista1, SList lista2);

/**
 * 
 */
SList slist_intersecar_custom(SList lista1, SList lista2, )

#endif /* __SLIST_H__ */
