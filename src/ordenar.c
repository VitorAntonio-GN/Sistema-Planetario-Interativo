#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/ordenar.h"

void ordenarEstrelas(SistemaPlanetario* sistema)
{
    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                               // -> Cria variáveis auxiliares
    Estrela aux = {};                                                                                   // | 

    /*Ordena o vetor alocado*/
    for(int i = 0; i < sistema->indexControleEstrelas - 1; i++)
    {
        for(int j = i + 1; j < sistema->indexControleEstrelas; j++)
        {
            if(strcmp(buscaEstrela[j].nomeEstrela, buscaEstrela[i].nomeEstrela) == -1)                  // -> Verifica se a estrela posterior vem primeiro alfabeticamente
            {
                aux = buscaEstrela[i];                                                                  // -> Troca a estrela se ela vier alfabeticamente primeiro
                buscaEstrela[i] = buscaEstrela[j];                                                      // | 
                buscaEstrela[j] = aux;                                                                  // | 
            }
        }
    }

    /*Fim*/
    return;
}

void ordenarPlanetas(SistemaPlanetario* sistema)
{
    /*Variáveis*/
    int matrizVerificacao[25] = {};                                                                     // -> Matriz que guarda a análise da verificação no código do planeta -> sem o 'a' <- regra
    int indexMaxCodigoPlaneta = 0;                                                                      // -> Variáveis para vericação da letra no código do planeta 
    int letraCodigoPlaneta = 0;                                                                         // | 
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                               // -> Auxiliar para a escrita do código
    Planeta* matrizForma = NULL;                                                                        // -> Matriz que guarda a ordenação e substitui a original

    /*Analisa o vetor alocado*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        indexMaxCodigoPlaneta = strlen(buscaPlaneta[i].infos.codigoPlaneta) - 1;                        // -> Pega o index max, ou seja, o local da letra

        letraCodigoPlaneta = buscaPlaneta[i].infos.codigoPlaneta[indexMaxCodigoPlaneta];                // -> Pega a letra

        matrizVerificacao[letraCodigoPlaneta - 98] = i;                                                 // -> Armazena na matriz de análise por meio da letra -> 'b' = 0
    }

    /*Aloca a matriz para o uso*/
    matrizForma = (Planeta*) calloc(sistema->indexControlePlanetas + 1, sizeof(Planeta));               // -> Aloca a matriz que irá substituir

    /*Ordena a matriz com base na matriz verificação*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)                                            
    {
        matrizForma[i] = sistema->planetas[matrizVerificacao[i]];                                       // -> Armazena de acordo com a ordem na matriz de análise
    }

    /*Libera a memória alocada da matriz original*/
    free(sistema->planetas);                                                                            // -> Libera a memória da matriz original

    /*A matriz forma se torna a original*/
    sistema->planetas = matrizForma;                                                                    // -> Troca o endereço pelo da matriz de molde (substitui a original)

    /*Fim*/
    return;
}