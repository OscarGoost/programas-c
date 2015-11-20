#include <stdio.h>
#include <stdlib.h>

int main (){
    int origen, destino =0;

    printf("Introduce un número: ");
    scanf(" %i", &origen);

    do{
        destino *= 10;
        destino += origen % 10;
        origen /= 10;
    } while(origen != 0);

    printf("El numero invertido es %i\n", destino);

    return EXIT_SUCCESS;
}
