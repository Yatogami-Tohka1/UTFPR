#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
} atleta;

atleta MaisVelho(atleta Atletas[5]) {
    int indice = 0;
    int idade = 0;
    for (size_t i = 0; i < 2; i++)
    {
        if(Atletas[i].idade > idade) {
            indice = i;
            idade = Atletas[i].idade;
        }
    }
    return Atletas[indice];
}

atleta MaisAlto(atleta Atletas[5]) {
    int indice = 0;
    float altura = 0;
    for (size_t i = 0; i < 2; i++)
    {
        if(Atletas[i].altura > altura) {
            indice = i;
            altura = Atletas[i].altura;
        }
    }
    return Atletas[indice];
}

int main() {
atleta Atletas[5];
for (size_t i = 0; i < 2; i++)
{
    printf("Qual o nome do %i° atleta: ", i + 1);
    setbuf(stdin, NULL);
    fgets(Atletas[i].nome, 50, stdin);
    Atletas[i].nome[strcspn(Atletas[i].nome,"\n")] = '\0';
    printf("Qual o esporte que %s pratica: ", Atletas[i].nome);
    setbuf(stdin, NULL);
    fgets(Atletas[i].esporte, 50, stdin);
    Atletas[i].esporte[strcspn(Atletas[i].esporte,"\n")] = '\0';
    printf("Quantos anos %s tem: ", Atletas[i].nome);
    scanf("%i", &Atletas[i].idade);
    printf("Qual a altura de %s: ", Atletas[i].nome);
    scanf("%f", &Atletas[i].altura);
}

atleta AtletaMaisAlto = MaisAlto(Atletas);
atleta AtletaMaisVelho = MaisVelho(Atletas);

printf("Nome do atleta mais velho: %-20s | Idade: %i | Altura %.2f | Esporte praticado: %-20s |\n", AtletaMaisVelho.nome, AtletaMaisVelho.idade, AtletaMaisVelho.altura, AtletaMaisVelho.esporte);
printf("Nome do atleta mais alto: %-20s | Idade: %i | Altura %.2f | Esporte praticado: %-20s |\n", AtletaMaisAlto.nome, AtletaMaisAlto.idade, AtletaMaisAlto.altura, AtletaMaisAlto.esporte);
}