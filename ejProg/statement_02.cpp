#include <stdio.h>
#include <stdlib.h>
#define DIVISOR 10

int main(){
    int numero, resultado=0;

    for (int contador=0 ; contador < 10 ; contador++){
        printf("Número %i: ", contador+1);
        scanf("%i", &numero);
        resultado += numero;
    }

    resultado /= DIVISOR;

    printf("La media es %i\n", resultado);

    return EXIT_SUCCESS;
}
