/********************************************************

   TAD-VETOR
   =======

   Rotinas basicas de manipulacao de Vetores Estáticos:
   - Estruturas de dados com alocacao estatica
   - Insercao no final do vetor
   - Remocao logica dos elementos

   Aplicacao tipica:
   - Pequenos cadastros

   Por: Fernando Osorio
   Data de Criacao: Jan/2000
   Data de Atualizacao: Ago/2018

*********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VETOR 100

#define FALSO      0
#define VERDADEIRO 1

#define EXCLUIDO   1

#define OK         1
#define ERRO       0

typedef double Tipo_Dado;

typedef struct
        {
           Tipo_Dado Dado    [MAX_VETOR];
           int       Excluido[MAX_VETOR];
           int       Inicio,Fim;
        }  Tipo_Vetor;

/***

=> Rotinas de Manipulacao de Vetores - Lista Linear Sequencial

***

void inicializa_vetor (Tipo_Vetor *V);
int  insere_vetor     (Tipo_Vetor *V; Tipo_Dado Dado);
int  consulta_vetor   (Tipo_Vetor  V; int Indice; Tipo_Dado *Dado);
int  acha_vetor       (Tipo_Vetor  V; Tipo_Dado Dado; int Indice);
void lista_vetor      (Tipo_Vetor  V);
int  exclui_vetor     (Tipo_Vetor *V; int Indice);
int  atualiza_vetor   (Tipo_Vetor *V; int Indice; Tipo_Dado Novo_Dado);
void compacta_vetor   (Tipo_Vetor *V);
int  vazio_vetor      (Tipo_Vetor  V);
int  quantidade_vetor (Tipo_Vetor  V);

***/

void inicializa_vetor (V)
Tipo_Vetor *V;
{
  int cont;

  V->Inicio=0;
  V->Fim=0;
  for (cont=0; cont < MAX_VETOR; cont++)
  {
      V->Excluido[cont]=FALSO;
      V->Dado[cont]=cont;
  }
}

int insere_vetor (V, Dado)
Tipo_Vetor *V;
Tipo_Dado Dado;
{
  if (V->Fim < MAX_VETOR)           /* Vetor nao esta cheio ? */
  {
     V->Dado[V->Fim]=Dado;
     V->Excluido[V->Fim]=FALSO;
     (V->Fim)++;
     return(OK);
  }
  else
     return(ERRO);
}

int consulta_vetor (V, Indice, Dado)
Tipo_Vetor V;
int Indice;
Tipo_Dado *Dado;
{
  if ((Indice < V.Inicio) || (Indice >= V.Fim) || (V.Excluido[Indice] == EXCLUIDO))
     return(ERRO);
  *Dado=V.Dado[Indice];
  return(OK);
}

int acha_vetor(V, Dado, Indice)
Tipo_Vetor V;
Tipo_Dado Dado;
int *Indice;
{
  int cont;
  int achou;

  achou=FALSO;
  for (cont=V.Inicio; cont < V.Fim; cont++)
      if ((V.Dado[cont] == Dado) && (V.Excluido[cont] != EXCLUIDO))
      {
         achou=VERDADEIRO;
         *Indice=cont;
         return(OK);
      }
  return(ERRO);
}

void lista_vetor(V)
Tipo_Vetor V;
{
  Tipo_Dado dado;
  int cont;

  printf("\n");
  for (cont=V.Inicio; cont < V.Fim; cont++)
      if (consulta_vetor(V,cont,&dado))
         printf("Vetor[%d]=%lf\n",cont,dado);
      else
         printf("Vetor[%d]= <Excluido>\n",cont);
  printf("\n");
}

int exclui_vetor(V,Indice)
Tipo_Vetor *V;
int Indice;
{
  if ((Indice < V->Inicio) || (Indice >= V->Fim))
     return(ERRO);
  V->Excluido[Indice]=EXCLUIDO;
  return(OK);
}

int atualiza_vetor(V,Indice,Novo_Dado)
Tipo_Vetor *V;
int Indice;
Tipo_Dado Novo_Dado;
{
   if ((Indice < V->Inicio) || (Indice >= V->Fim) || (V->Excluido[Indice] == EXCLUIDO))
      return(ERRO);
   V->Dado[Indice]=Novo_Dado;
   return(OK);
}

void compacta_vetor (V)
Tipo_Vetor *V;
{
  int cont;

  cont=V->Inicio;
  while (cont <= V->Fim)
  {
     if (V->Excluido[cont] == EXCLUIDO)
     {
        V->Excluido[cont]=V->Excluido[V->Fim];
        V->Dado[cont]=V->Dado[V->Fim];
        V->Excluido[V->Fim]=0;
        V->Fim=V->Fim-1;
        if (V->Excluido[cont] != EXCLUIDO)
           cont++;
     }
     else
        cont++;
  }
}

int vazio_vetor(V)
Tipo_Vetor V;
{
  if (V.Fim == V.Inicio)
     return(OK);
  else
     return(ERRO);
}

int quantidade_vetor(Tipo_Vetor V)
{
  return(V.Fim);  /* ou... v.fim-v.inicio */
}

int main(void)
{
  Tipo_Vetor vet;
  Tipo_Dado  valor;
  int        qual;

  printf("\n>>> ROTINAS DE MANIPULACAO DE VETORES - ALOCACAO ESTATICA <<<\n\n");

  inicializa_vetor(&vet);

  if (vazio_vetor(vet))
     printf("=> Vetor vazio...\n");

  if (!insere_vetor(&vet,2.1))
     printf(">>> Erro: insere vetor\n");
  if (!insere_vetor(&vet,4.1))
     printf(">>> Erro: insere vetor\n");
  if (!insere_vetor(&vet,6.1))
     printf(">>> Erro: insere vetor\n");

  printf("=> Elementos do vetor... %d\n",quantidade_vetor(vet));
  lista_vetor(vet);
/*
  if (acha_vetor(vet,4,&qual))
     printf("=> O valor 4 esta no vetor na posicao %d\n",qual);

  if (!acha_vetor(vet,10,&qual))
     printf("=> O valor 10 nao foi encontrado no vetor\n");

  if (exclui_vetor(&vet,1))
     printf("=> O valor da posicao 1 foi excluido do vetor\n");

  if (!acha_vetor(vet,4,&qual))
     printf("=> O valor 4 nao foi encontrado no vetor\n");
*/
  printf("\n\n");
  system("pause");
  return 0;
}
