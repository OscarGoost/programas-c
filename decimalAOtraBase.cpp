#include <stdio.h>
#include <stdlib.h>

int main(){
    int cantidad, numeroDado, cociente, numeroAux=0, numeroBase, numeroResultado[100];

    printf("¿A qué base quieres pasar? ");
    scanf("%i", &numeroBase);
    while(!numeroBase || numeroBase==1){    /* Mientras que introduzca un entero o introduce 1 */
        getchar();
        fflush(stdout);
        system("clear");
        printf("¡EL NÚMERO BASE DEBE SER DECIMAL!\n");
        printf("¿A qué base quieres pasar? ");
        scanf("%i", &numeroBase);
    }

    printf("¿Qué número quieres pasar? ");
    scanf("%i", &numeroDado);
    while(!numeroDado || numeroDado > 32500){   /* Mientras que introduzca un entero */
        getchar();
        fflush(stdout);
        system("clear");
        printf("¡EL NÚMERO DEBE SER DECIMAL!\n");
        printf("¿Qué número quieres pasar? ");
        scanf("%i", &numeroDado);
    }

    cociente = numeroDado;

    /* Pasos:
     * 1- Dividir hasta que el cociente sea menor que la base e ir guardando los restos.
     * 2- Guardar el ultimo cociente.
     * 3- Imprimir el resultado de final a principio.
     */

    for(cantidad=0 ; cociente >= numeroBase ; cantidad++){    /* Paso 1 */
        numeroResultado[cantidad] = cociente%numeroBase;
        numeroAux = cociente;
        cociente /= numeroBase;
    }

    numeroResultado[cantidad] = numeroAux/numeroBase;         /* Paso 2 */

    printf("\nEl numero %i en base %i es:   ",numeroDado ,numeroBase);

    while(cantidad>=0){     /* Paso 3 */
        if(numeroBase>numeroDado){
            printf("%i", numeroDado);   /* Caso en el que la base sea mayor que el numero dado */
            break;
        }
        if(numeroBase == 16)    /* Caso en el que la base sea en hexadecimal */
            printf("%X", numeroResultado[cantidad]);

        else{                   /* El resto de bases */
            printf("%i ", numeroResultado[cantidad]);

        if(cantidad)
            printf("| ");
        }

        cantidad--;
    }

    printf("\n\n");

    return EXIT_SUCCESS;
}
