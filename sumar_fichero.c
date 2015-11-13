#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pf;
    int total=0, numero=0;

    pf = fopen("numeros", "r");

    while (fscanf(pf, "%i", &numero)==1){
        total = total + numero;
    }

    printf ("La suma de los numeros es %i.\n", total);
    fclose(pf);

    return EXIT_SUCCESS;
}
