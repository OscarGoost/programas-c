#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, numeroDado, cociente, numeroAux, numeroBase, numeroResultado[100];

    printf("¿A que base quieres pasar? ");
    scanf(" %i", &numeroBase);

    printf("¿Qué numero quieres pasar? ");
    scanf(" %i", &numeroDado);

    cociente = numeroDado;

    for(i=0 ; cociente >= numeroBase ; i++){
        numeroResultado[i] = cociente%numeroBase;
        numeroAux = cociente;
        cociente = cociente/numeroBase;
    }

    numeroResultado[i] = numeroAux/numeroBase;

    printf("\nEl numero %i en base %i es:   ",numeroDado ,numeroBase);
    while(i>=0){

        if(numeroBase == 16)
            printf("%X", numeroResultado[i]);

        else{
            printf("%i ", numeroResultado[i]);

        if(i)
            printf("| ");
        }

        i--;
    }

    printf("\n\n");

    return EXIT_SUCCESS;
}
