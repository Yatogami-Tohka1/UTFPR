#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() {
    int e;
    scanf("%i", &e);

    for (size_t i = 1; i <=e; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("*");
        }            
    printf("\n");
    }

    for (size_t i = e - 1; i > 0; i--)
    {
    for (size_t j = 0; j < i; j++)
        {
            printf("*");
        }            
    printf("\n");
    }
    
}