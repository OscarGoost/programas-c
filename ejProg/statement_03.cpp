#include <stdio.h>
#include <stdlib.h>

int main(){
    int cantidad, numeroDado, resultado=0;

    for(cantidad=0 ; numeroDado > 0 ; cantidad++){
        printf("Dame número <Ò,.,Ó> ");
        scanf("%i", &numeroDado);
        if(numeroDado > 0)
            resultado += numeroDado;
    }

    resultado /= (cantidad-1);

    printf("La media es %i\n", resultado);

    return EXIT_SUCCESS;
}
