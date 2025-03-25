#include<stdio.h>
#include<stdlib.h>

char *get_new_line(){
    // char palabra;
    char *pc = malloc(sizeof(char));
    printf("Ingrese una linea por teclado hasta apretar enter: \n");
    scanf("%c", pc);
    // pc = palabra;
    free(pc);
    return pc; 
}


int main(){
    return 0;
}