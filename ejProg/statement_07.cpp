#include <stdio.h>
#include <stdlib.h>

double add(double op1,  double op2){
    return op1 + op2;
}

int main(int argc, double argd[]){
    double resultado;

    resultado = add(argd[0], argd[1]);

    printf("%lf\n", resultado);

    return EXIT_SUCCESS;
}
