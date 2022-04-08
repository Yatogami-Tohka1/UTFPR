#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
} atleta;

void Organizar(atleta Atletas[5])
{
    atleta aux;
    for (size_t i = 4; i > 0; i--)
    {
        for (size_t j = 4; j > 0; j--)
        {
            if (Atletas[j].idade < Atletas[j - 1].idade)
            {

                aux = Atletas[j];
                Atletas[j] = Atletas[j - 1];
                Atletas[j - 1] = aux;
            }
        }
    }
}

int main()
{
    atleta Atletas[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Qual o nome do %i° atleta: ", i + 1);
        setbuf(stdin, NULL);
        fgets(Atletas[i].nome, 50, stdin);
        Atletas[i].nome[strcspn(Atletas[i].nome, "\n")] = '\0';
        printf("Qual o esporte que %s pratica: ", Atletas[i].nome);
        setbuf(stdin, NULL);
        fgets(Atletas[i].esporte, 50, stdin);
        Atletas[i].esporte[strcspn(Atletas[i].esporte, "\n")] = '\0';
        printf("Quantos anos %s tem: ", Atletas[i].nome);
        scanf("%i", &Atletas[i].idade);
        printf("Qual a altura de %s: ", Atletas[i].nome);
        scanf("%f", &Atletas[i].altura);
    }

    Organizar(Atletas);

    for (size_t i = 0; i < 5; i++)
    {
        printf("Nome do atleta mais velho: %-20s | Idade: %i | Altura %.2f | Esporte praticado: %-20s\n", Atletas[i].nome, Atletas[i].idade, Atletas[i].altura, Atletas[i].esporte);
    }
}