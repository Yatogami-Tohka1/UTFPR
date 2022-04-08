#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Faça uma função que receba um inteiro N como parâmetro. Calcule e retorne o resultado da seguinte série S:
//n² + 1 / n + 3
 
void sequencia(int n) {
    for (size_t i = 1; i <= n; i++)
    {
        double x = pow(i, 2) + 1;
        int y = i + 3;
        printf("%lf / %i\n", x, y);
    }
    
}

int main() {
    int n;
    scanf("%i", &n);

    sequencia(n);
}