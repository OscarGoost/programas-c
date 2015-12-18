#include <stdio.h>
#include <stdlib.h>

int main(){
    int cantidad;
    int * numeros;

    numeros = (int*) malloc(cantidad * sizeof(int));

    if(numeros==NULL){
        printf("Error de memoria\n");
        return 1;
    }

    for(cantidad=1 ; numeroDado<=0 ; cantidad++){
        numeros = (int*) realloc (numeros, cantidad * sizeof (int));
        printf("Dame numero: ");
        scanf("%i", &numeroDado);
        if(numeroDado>0)
            numeros[cantidad-1] = numeroDado;
    }



    free(numeros);

    return EXIT_SUCCESS;
}
