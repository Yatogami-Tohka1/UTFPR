#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
void Inserir(char Cidades[5][30], int Servidores[5][3]) {
   for(size_t i = 0; i < 5; i++) {
   printf("Insira o nome da %i° cidade: ", i + 1);
   fgets(Cidades[i],30,stdin);
   Cidades[i][strcspn(Cidades[i],"\n")] = '\0';
   setbuf(stdin, NULL);
   do {
       printf("Quantos servidores operantes tem em %s: ",Cidades[i]);
       scanf("%i", &Servidores[i][0]);
       setbuf(stdin, NULL);
   } while(Servidores[i][0] < 0);
   do {
       printf("Quantos servidores falhos tem em %s: ",Cidades[i]);
       scanf("%i", &Servidores[i][1]);
       setbuf(stdin, NULL);
   } while(Servidores[i][1] < 0);
   }
}
 
void ServidoresTotais(int Servidores[5][3]) {
   for(size_t  i = 0; i < 5; i++) {
       Servidores[i][2] = Servidores[i][0] + Servidores[i][1];
   }
}
void ExibirTudo(char Cidades[5][30], int Servidores[5][3]) {
   printf("\n");
   for(size_t  i = 0; i < 5; i++) {
       printf("Nome: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i\n", Cidades[i], Servidores[i][0], Servidores[i][1], Servidores[i][2]);
   } 
}
 
void Busca(char Cidades[5][30], int Servidores[5][3]) {
   char Busca[20];
   printf("\nInsira uma cidade para buscar seus dados: ");
   setbuf(stdin, NULL);
   fgets(Busca,20,stdin);
   setbuf(stdin, NULL);
   Busca[strcspn(Busca,"\n")] = '\0';
   for(size_t  i = 0; i < 5; i++) {
       if(strcasecmp(Busca, Cidades[i] == 0)) {
           printf("\nNome: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i\n", Cidades[i], Servidores[i][0], Servidores[i][1], Servidores[i][2]);          
       }
   } 
}
 
void ExibirPorcentagem(char Cidades[5][30], int Servidores[5][3]) {
   int IndiceCidadeMaisProblemas = 0;
   int TProblemas = 0;
   int Problemas = 0;
   int Total = 0;
   printf("\n");
   for(size_t  i = 0; i < 5; i++) {
       Problemas += Servidores[i][1];
       Total += Servidores[i][1];
   }
   for(size_t  i = 0; i < 5; i++) {
       Total += Servidores[i][0];
   }
   for(size_t  i = 0; i < 5; i++) {
       if(Servidores[i][1] > TProblemas) { IndiceCidadeMaisProblemas = i; TProblemas = Servidores[i][1]; }
   }
   printf("Nome da cidade com mais problemas: %-20s | Servidores Ativos: %i | Servidores Falhos: %i | Total de Servidores: %i | Porcentagem de problemas: %.2f%%\n", Cidades[IndiceCidadeMaisProblemas], Servidores[IndiceCidadeMaisProblemas][0], Servidores[IndiceCidadeMaisProblemas][1], Servidores[IndiceCidadeMaisProblemas][2],  (float)(Servidores[IndiceCidadeMaisProblemas][1] * 100) / Total); 
}
 
void ExibirPorcentagemGeral(int Servidores[5][3]) {
   int Ativos = 0;
   int Problemas = 0;
   int Total = 0;
 
   for(size_t  i = 0; i < 5; i++) {
       Ativos += Servidores[i][0];
       Total += Servidores[i][0];
   }
   for(size_t  i = 0; i < 5; i++) {
       Problemas += Servidores[i][1];
       Total += Servidores[i][1];
   }
 
   printf("\nFalhos: %.2f%%\nOperantes: %.2f%%\n", (float)(Problemas * 100) / Total, (float)(Ativos * 100) / Total);
}
 
int main() {
   char Cidades[5][30];
   int Servidores[5][3];
   Inserir(Cidades, Servidores);
   ServidoresTotais(Servidores);
   ExibirTudo(Cidades, Servidores);
   //Busca(Cidades, Servidores);
   ExibirPorcentagem(Cidades, Servidores);
   ExibirPorcentagemGeral(Servidores);
}
