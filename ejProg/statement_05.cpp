#include <stdio.h>
#include <stdlib.h>

int main(){
    int contador;
    const char *list[] = {"bread", "toast", "bacon"};

    for(contador = 0 ; list[contador] != NULL ; contador++)
        printf("%s\n", list[contador]);

    printf("El numero de palabras es %lu\n", sizeof(list)/sizeof(list[0]));

    return EXIT_SUCCESS;
}
