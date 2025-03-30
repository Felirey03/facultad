#include<stdio.h>

// Funcion que pone en 0 el primer elemento 
// de un array.
// set_first: Int[] -> Void
// El parametro es un array de enteros.
void set_first (int a[]){

    a[0] = 0;
}

int main(){

    int a[4];

    //a[0] = 2;
    //printf("%d \n" , a);

    set_first(a);

    for(int i = 0; i < 4; i++){
        printf("%d \n", a[i]);
    }

    printf("%d \n", a[0]);
    
    return 0;
}

