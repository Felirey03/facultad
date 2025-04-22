#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  if(lista == NULL){ return 0; }
  int i = 0;
  for(SNodo *temp = lista; temp != NULL; temp = temp->sig){
    i++;
  }
  return i;
}

SList slist_concatenar(SList lista1, SList lista2) {
  if (lista1 == NULL) {
    return lista2;
  }
  if (lista2 == NULL) {
    return lista1;
  }

  SNodo *temp = lista1;
  while (temp->sig != NULL) {
    temp = temp->sig;
  }
  temp->sig = lista2;
  return lista1; 
}

SList slist_insertar(SList lista, int dato, int pos) {
  
  int longitud = slist_longitud(lista);
  SList temp = lista;
  
  if (pos < 0 || pos > longitud) {
      return lista;
  }
  
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  if (nuevoNodo == NULL) {
      return lista; 
  }
  nuevoNodo->dato = dato;

  if (pos == 0) {
      nuevoNodo->sig = lista;
      return nuevoNodo;  
  }
  
  temp = lista;
  for (int i = 0; i < pos - 1; i++) {
      temp = temp->sig;
  }
    
  nuevoNodo->sig = temp->sig;
  temp->sig = nuevoNodo;
  return lista;
}


SList slist_eliminar(SList lista, int pos) {
  if (lista == NULL || pos < 0) return lista;

  if (pos == 0) {
    SNodo *nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
    return lista;
  }

  SNodo *temp = lista;
  for (int i = 0; i < pos - 1 && temp != NULL; i++) {
    temp = temp->sig;
  }
  if (temp == NULL || temp->sig == NULL) return lista;

  SNodo *nodoAEliminar = temp->sig;
  temp->sig = temp->sig->sig;
  free(nodoAEliminar);
  return lista;
}


int slist_contiene(SList lista, int elem){
  if(lista == NULL){
    return 0;
  }if(elem == lista->dato){
    return 1;
  }else{
    SNodo *temp = lista;
    for(; temp != NULL && temp->dato != elem; temp = temp->sig);
    if(temp == NULL){
      return 0;
    }else{
      return 1;
    }
  }


}


int slist_indice(SList lista, int elem){

  if(lista == NULL){
    return -1;
  }

  SNodo *temp = lista;
  int i = 0;

  for(;temp != NULL && temp->dato != elem; temp = temp->sig){
    i++;
  }

  if(temp!=NULL){
    return i;
  }else{
    return -1;
  }
  
}


SList slist_intersecar(SList lista1, SList lista2){
  
  if(lista1 == NULL || lista2 == NULL){
    return NULL;
  }

  SNodo *temp = lista1;
  SList nuevaLista = slist_crear();


  for(;temp != NULL; temp = temp->sig){
    if(slist_contiene(lista2, temp->dato)){
      nuevaLista = slist_agregar_inicio(nuevaLista, temp->dato);
    }
  } 
  return nuevaLista;
}