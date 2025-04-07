#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *direccion;
    int capacidad;
}   ArregloEnteros;


//a
ArregloEnteros *arreglo_enteros_crear(int capacidad){
    if(capacidad < 0){
        printf("La capacidad del arreglo no puede ser menor a 0 \n");
        return NULL;
    }
    ArregloEnteros *arreglo = malloc(sizeof(ArregloEnteros));
    if(arreglo == NULL){
        printf("El arreglo no se pudo crear \n");
        return NULL;
    }

    arreglo->direccion = malloc(sizeof(int) * capacidad);
    if(arreglo->direccion == NULL){
        printf("La direccion del arreglo no se pudo asignar \n");
        return NULL;
    }

    arreglo->capacidad = capacidad;
    

    return arreglo;


}

//b
void arreglo_enteros_destruir(ArregloEnteros *arreglo){
    if(arreglo != NULL){
        free(arreglo->direccion);
        free(arreglo);
    }
}

//c
int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    if(arreglo == NULL || arreglo->direccion == NULL){
        return 0;
    }
    if(pos > arreglo->capacidad){
        return 0;
    }
    return arreglo->direccion[pos];
}

//d
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
    if(arreglo == NULL){
        printf("arreglo == NULL \n");
    }
    if(pos > arreglo->capacidad){
        printf("La posicion es incorrecta \n");
    }
    else{
        arreglo->direccion[pos] = dato;
    }
}


int arreglo_capacidad(ArregloEnteros *arreglo){
    if(arreglo == NULL){
        printf("El arreglo es NULL \n");
        return 0;
    }
    return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    if(arreglo == NULL){
        printf("El arreglo es NULL, por lo tanto no se puede imprimir \n");
    }
    for(int i = 0; i < arreglo->capacidad; i++){
        printf("%d \n", arreglo_enteros_leer(arreglo,i));
    }
}

int main(){
    ArregloEnteros *arreglo = arreglo_enteros_crear(5);

    if(arreglo == NULL){
        printf("No se pudo crear el arreglo \n");
    }
    printf("Capacidad de arreglo: %d\n", arreglo->capacidad);

    arreglo_enteros_escribir(arreglo, 2, 3);

    printf("El dato agregado es: %d \n", arreglo_enteros_leer(arreglo, 2));

    int capacidad_arreglo = arreglo_capacidad(arreglo);
    printf("Capacidad de arreglo %d \n", capacidad_arreglo);

    arreglo_enteros_imprimir(arreglo);

    free(arreglo->direccion);
    free(arreglo);
    
}