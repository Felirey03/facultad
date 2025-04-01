#include<stdio.h>
#include<stdlib.h>

int string_len(char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

//b 

void string_reverse(char *str){
    int length = string_len(str);
    char *arr = malloc(sizeof(float) * length);
    //copiamos array
    for(int i = 0; i < length; i++){
        arr[i] = str[i];
    }

    for(int i = 0; i <= length; i++){
        str[i] = arr[length - i];
    }
    free(arr);
}


//c 
int string_concat(char *str1, char *str2, int max){
    
}




int main(){
    char pal[] = "hola";
    int tamaño = string_len(pal);
    printf("El tamaño del arreglo es: %d \n", tamaño);
    string_reverse(pal);
    for (int i = 0; i <= tamaño; i++){
        printf("%c \n", pal[i]);
    }
}