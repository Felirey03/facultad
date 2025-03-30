#include<stdio.h>
#include<stdlib.h>
int main(){
    

    // NO GENERA NINGUN ERROR, 
    // PERO ESTO PUEDE CAUSAR FALLAS EN EL CODIGO
    void *c = malloc(100);
    free(c);
    free(c);

    return 0;
}