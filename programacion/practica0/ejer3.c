#include<stdio.h>



// set_in recibe un puntero a entero, y devuelve 
// 1 si el valor de la variable apuntada es distinta de 0
// 0 en caso contrario.
// set_in : int* -> void.
void set_in(int *ptr){
    if(*ptr != 0){
        *ptr = 1;
    } else{
        *ptr = 0;
    }
}
int main(){
    int *p, v = 1;
    p = &v;

    set_in(p);

    printf("%d\n", *p);
}