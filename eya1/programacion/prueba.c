#include<stdio.h>


int Suma(int a, int b){
    return a + b;
    }


int main(){
    int a, b, resultado;
    printf("Ingrese dos numeros: ");
    scanf("%d%d", &a, &b);

    resultado = Suma(a,b);

    printf("El resultado de la suma es: %d \n", resultado);
    return 0;
}