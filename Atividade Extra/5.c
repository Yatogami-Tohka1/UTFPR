#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[40];
    int quantidade;
    float preco;
} material;

void InserirMaterial(material Materiais[15], int MateriaisControle[15])
{
    int PosicaoLivre;

    for (size_t i = 14; i >= 0; i--)
    {
        if (MateriaisControle[i] == 0)
        {
            PosicaoLivre = i;
        }
    }

    printf("Insira o nome do material: ");
    setbuf(stdin, NULL);
    fgets(Materiais[PosicaoLivre].nome, 50, stdin);
    Materiais[PosicaoLivre].nome[strcspn(Materiais[PosicaoLivre].nome, "\n")] = '\0';
    printf("Quantos %s tem: ", Materiais[PosicaoLivre]);
    scanf("%i", &Materiais[PosicaoLivre].quantidade);
    printf("Qual o preço: ");
    scanf("%.2f", &Materiais[PosicaoLivre].preco);
    MateriaisControle[PosicaoLivre] = 1;
}

int main()
{
    char e;
    int c = 0;
    material Materiais[15];
    int MateriaisControle[15];

    for (size_t i = 0; i < 15; i++)
    {
        MateriaisControle[i] = 0;
    }

    while (!0)
    {

        printf("I - Inserir Material\nR - Remover um material pelo índice\nL - Listar todos os materiais não vázios\nP - Pesquisar informações de um material pelo nome\nV - Exibe os produtos que estão em falta\nS - Sair do programa\n\nEntrada: ");

        e = getchar();
        switch (e)
        {
        case 'I':
        case 'i':
            InserirMaterial(Materiais, MateriaisControle);
            break;

        default:
            printf("Opção Inválida! Tente novamente\n\n");
            break;
        }
    }
}