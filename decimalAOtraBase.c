#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, numeroDado, cociente, numeroAux, numeroBase, numeroResultado[100];

    printf("¿A qué base quieres pasar? ");
    scanf("%i", &numeroBase);
    while(!numeroBase){
        getchar();
        system("clear");
        printf("¡EL NÚMERO BASE DEBE SER DECIMAL!\n");
        printf("¿A qué base quieres pasar? ");
        scanf("%i", &numeroBase);
    }

    printf("¿Qué número quieres pasar? ");
    scanf("%i", &numeroDado);
    while(!numeroDado || numeroDado > 32500){
        getchar();
        system("clear");
        printf("¡EL NÚMERO DEBE SER DECIMAL!\n");
        printf("¿Qué número quieres pasar? ");
        scanf("%i", &numeroDado);
    }

    cociente = numeroDado;

    for(i=0 ; cociente >= numeroBase ; i++){
        numeroResultado[i] = cociente%numeroBase;
        numeroAux = cociente;
        cociente /= numeroBase;
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
