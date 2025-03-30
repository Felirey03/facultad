#include<stdio.h>
#include<stdlib.h>


//a
int apply(int (*func)(int), int val){
    return func(val);
}
//b
void apply_in(int (*func)(int), int *punt){
    *punt = func(*punt);
}

//c

typedef void (*VisitorFunc)(int); // conocer de que trata
void recorre(VisitorFunc func, int arr[], int size){
    for(int i = 0; i < size; i++){
        func(arr[i]);
    }
}      
//d
int sucesor (int n) {
    return n+1;
    }

void imprimir (int n) {
    printf("%d \n", n);
}   

int main(){
    int resultado = apply(sucesor, 5);
    printf("apply(sucesor,5) == %d \n", resultado);
    
    int valor = 10;
    apply_in(sucesor,&valor);
    printf("apply_in(sucesor, &valor) == %d \n", valor);

    printf("Recorremos el arreglo: \n");
    int arr[] = {1, 2, 3, 4, 5, 6};
    int tamanio = 6;

    recorre(imprimir, arr, tamanio);
    
    
    
    return 0;
}
