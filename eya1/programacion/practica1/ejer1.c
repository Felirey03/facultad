#include<stdio.h>
#include<stdlib.h>


void bubble_sort(float arreglo[], int longitud) {
    for (int iter = 0 ; iter < longitud - 1 ; iter++) {
        for (int i = 0 ; i < longitud - iter - 1; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
                float aux = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = aux;
            }
        }   
    }
}




float mediana(float *arreglo, int longitud){
    float resultado;
    float *arr = malloc(sizeof(float) * longitud);
    for(int i = 0; i < longitud; i++){
        arr[i] = arreglo[i];
    }

    bubble_sort(arr, longitud);


    if(longitud % 2 == 0){
        float suma = 0;
        for (int i = 0; i < longitud; i++){
            suma = suma + arr[i];
        }
        resultado = suma / longitud;
    }else {
        float medio = 0;
        resultado = arr[longitud /2];
    }
    
    free(arr);
    return resultado;
    
}

int main(){
    float arreglo[] = {-1.0, 2.2, 2.9, 3.1, 3.5};
    float a;
    a = mediana(arreglo, 5);
    printf("La mediana de arreglo es: %f \n", a);
    return 0;
}   
