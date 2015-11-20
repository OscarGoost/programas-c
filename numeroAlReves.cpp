#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>

int main(){
    int cantidad, numeroDado, cociente, numeroAux=0, numeroAlReves=0, numeroResultado[100];
    const int numeroBase = 10;

    printf("¿Qué número quieres pasar? ");
    scanf("%i", &numeroDado);
    while(!numeroDado || numeroDado > 32500){   /* Mientras que introduzca un entero */
        __fpurge(stdin);
        system("clear");
        printf("¡EL NÚMERO DEBE SER DECIMAL O MÁS PEQUEÑO!\n");
        printf("¿Qué número quieres pasar? ");
        scanf("%i", &numeroDado);
    }

    cociente = numeroDado;

    /* Pasos:
     * 1- Dividir hasta que el cociente sea menor que la base e ir guardando los restos.
     * 2- Guardar el ultimo cociente.
     * 3- Coger cada numero separado, multiplicarlo por 10 elevado a su respectivo exponente y sumarlos entre ellos.
     * 4- Guardarlo en una sola variable.
     * 5- Imprimir variable
     */

    for(cantidad=0 ; cociente >= numeroBase ; cantidad++){    /* Paso 1 */
        numeroResultado[cantidad] = cociente%numeroBase;
        numeroAux = cociente;
        cociente /= numeroBase;
    }

    numeroResultado[cantidad] = numeroAux/numeroBase;         /* Paso 2 */

    for(int j=cantidad, i=0 ; j>=0 ; j--, i++)
        numeroAlReves += numeroResultado[i]*pow(10,j);          /* Paso 3 y 4 */

    printf("\nEl numero %i al revés es %i\n\n", numeroDado, numeroAlReves); /* Paso 5 */

    return EXIT_SUCCESS;
}
