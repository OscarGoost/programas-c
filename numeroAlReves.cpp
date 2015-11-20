#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>

int main(){
    int cantidad, numeroDado, cociente, numeroAux=0, numeroBase, numeroAlReves=0, numeroResultado[100];

    printf("¿A qué base quieres pasar? ");
    scanf("%i", &numeroBase);
    while(!numeroBase || numeroBase==1){    /* Mientras que introduzca un entero o introduce 1 */
        __fpurge(stdin);
        system("clear");
        printf("¡EL NÚMERO BASE DEBE SER DECIMAL!\n");
        printf("¿A qué base quieres pasar? ");
        scanf("%i", &numeroBase);
    }

    printf("¿Qué número quieres pasar? ");
    scanf("%i", &numeroDado);
    while(!numeroDado || numeroDado > 32500){   /* Mientras que introduzca un entero */
        __fpurge(stdin);
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

    for(int j=cantidad, i=0 ; j>=0 ; j--){
        numeroAlReves += numeroResultado[i]*pow(10,j);
        i++;
    }

    printf("\nEl numero %i al revés es %i\n\n", numeroDado, numeroAlReves);

    return EXIT_SUCCESS;
}
