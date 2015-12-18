#include <stdio.h>
#include <stdlib.h>

int main(){
    int anchura;

    printf("dame una anchura: ");
    scanf("%i", &anchura);

    for(int i=0 ; i != anchura ; i++){
        for(int j=0 ; j <= i ; j++)
            printf("* ");
        printf("\n");
    }

    return EXIT_SUCCESS;
}
