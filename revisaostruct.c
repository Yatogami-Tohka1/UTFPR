#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char NomeCidade[30];
    int ServidoresAtivos;
    int ServidoresFalhos;
    int TotalServidores;
} Cidade;

void EntrarDados(Cidade Cidades[5]) {
     for(size_t i = 0; i < 5; i++) {
   printf("Insira o nome da %i° cidade: ", i + 1);
   fgets(Cidades[i].NomeCidade,30,stdin);
   Cidades[i].NomeCidade[strcspn(Cidades[i].NomeCidade,"\n")] = '\0';
   setbuf(stdin, NULL);
   do {
       printf("Quantos servidores operantes tem em %s: ",Cidades[i].NomeCidade);
       scanf("%i", &Cidades[i].ServidoresAtivos);
       setbuf(stdin, NULL);
   } while(Cidades[i].ServidoresAtivos < 0);
   do {
       printf("Quantos servidores falhos tem em %s: ",Cidades[i].NomeCidade);
       scanf("%i", &Cidades[i].ServidoresFalhos);
       setbuf(stdin, NULL);
   } while(Cidades[i].ServidoresFalhos < 0);
   }  
}

void TotalServidores(Cidade Cidades[5]) {
   for(size_t  i = 0; i < 5; i++) {
       Cidades[i].TotalServidores = Cidades[i].ServidoresAtivos + Cidades[i].ServidoresFalhos;
   }
}

void ExibirTodasCidades(Cidade Cidades[5]) {
       printf("\n");
   for(size_t  i = 0; i < 5; i++) {
       printf("Nome: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i\n", Cidades[i].NomeCidade, Cidades[i].ServidoresAtivos, Cidades[i].ServidoresFalhos, Cidades[i].TotalServidores);
   } 
}

void Busca(Cidade Cidades[5]) {
   char Busca[20];
   int Found = 0;
   do {
   printf("\nInsira uma cidade para buscar seus dados: ");
   setbuf(stdin, NULL);
   fgets(Busca,20,stdin);
   Busca[strcspn(Busca,"\n")] = '\0';
   for(size_t  i = 0; i < 5; i++) {
       if(!strcasecmp(Busca, Cidades[i].NomeCidade)) {
           printf("\nNome: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i\n", Cidades[i].NomeCidade, Cidades[i].ServidoresAtivos, Cidades[i].ServidoresFalhos, Cidades[i].TotalServidores);
           Found = 1;          
       }
   }
   if(!Found) { printf("Cidade %s não encontrada tente novamente."); } 
   } while(!Found);
}

void ExibirPorcentagem(Cidade Cidades[5]) {
   int IndiceCidadeMaisProblemas = 0;
   int TProblemas = 0;
   int Problemas = 0;
   int Total = 0;
   printf("\n");
   for(size_t  i = 0; i < 5; i++) {
       Problemas += Cidades[i].ServidoresFalhos;
       Total += Cidades[i].ServidoresFalhos;
   }
   for(size_t  i = 0; i < 5; i++) {
       Total += Cidades[i].ServidoresAtivos;
   }
   for(size_t  i = 0; i < 5; i++) {
       if(Cidades[i].ServidoresFalhos > TProblemas) { IndiceCidadeMaisProblemas = i; TProblemas = Cidades[i].ServidoresFalhos; }
   }
   printf("Nome da cidade com mais problemas: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i | Porcentagem de problemas: %.2f%%\n", Cidades[IndiceCidadeMaisProblemas].NomeCidade, Cidades[IndiceCidadeMaisProblemas].ServidoresAtivos, Cidades[IndiceCidadeMaisProblemas].ServidoresFalhos, Cidades[IndiceCidadeMaisProblemas].TotalServidores,  (float)(Cidades[IndiceCidadeMaisProblemas].ServidoresFalhos * 100) / Total); 
}
 
void ExibirPorcentagemGeral(Cidade Cidades[5]) {
   int Ativos = 0;
   int Problemas = 0;
   int Total = 0;
 
   for(size_t  i = 0; i < 5; i++) {
       Ativos += Cidades[i].ServidoresAtivos;
       Total += Cidades[i].ServidoresAtivos;
   }
   for(size_t  i = 0; i < 5; i++) {
       Problemas += Cidades[i].ServidoresFalhos;
       Total += Cidades[i].ServidoresFalhos;
   }

   printf("\nFalhos: %.2f%%\nOperantes: %.2f%%\n", (float)(Problemas * 100) / Total, (float)(Ativos * 100) / Total);
}

 
    void defeated(Cidade Cidades[5]) {
        for(size_t i = 0; i < 5; i++) {
            if(Cidades[i].ServidoresFalhos > Cidades[i].ServidoresAtivos) {
                strcat(Cidades[i].NomeCidade, " defeated");
            }
        }
    }

int main() {
    Cidade Cidades[5];
    EntrarDados(Cidades);
    TotalServidores(Cidades);
    ExibirTodasCidades(Cidades);
    Busca(Cidades);
    ExibirPorcentagem(Cidades);
    ExibirPorcentagemGeral(Cidades);
    defeated(Cidades);
    ExibirTodasCidades(Cidades);
}
