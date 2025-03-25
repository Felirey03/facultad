#include<stdio.h>

void swap(int *ptr1, int *ptr2){
    int vt;
    vt = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = vt;
}

int main(){
    
    int *ptr1, *ptr2, v1 = 1, v2 = 2;

    ptr1 = &v1;
    ptr2 = &v2;

    printf("El valor del primer puntero es: %d y del segundo es: %d\n",*ptr1,*ptr2);

    swap(ptr1,ptr2);

    printf("El valor cambiado del primer puntero es: %d y del segundo: %d \n", *ptr1, *ptr2);
    return 0;
}