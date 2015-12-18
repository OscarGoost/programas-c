#include <stdio.h>
#include <stdlib.h>

int main(){
    int lado;

    printf("Dame el lado: ");
    scanf("%i", &lado);

    for(int i=0 ; i < lado ; i++)
        printf("* ");
    printf("\n");

    for(int i=0 ; i != (lado-2) ; i++){
        printf("* ");
        for(int j=0 ; j != (lado-2) ; j++)
            printf("  ");
        printf("*\n");
    }

    for(int i=0 ; i < lado ; i++)
        printf("* ");
    printf("\n");

    return EXIT_SUCCESS;
}
