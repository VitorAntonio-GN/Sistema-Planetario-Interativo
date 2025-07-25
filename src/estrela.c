#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/entrada.h"
#include "../include/ordenar.h"
#include "../include/estrela.h"

int adicionarEstrela(SistemaPlanetario* sistema)
{
    /*Verifica se já atingiu o limite*/
    if(sistema->indexControleEstrelas >= sistema->capacidadeEstrelas)
    {
        printf("\nAtingiu-se a capacidade maxima de estrelas\n");                                   // -> Verifica se já atingiu a capacidade máxima de estrelas alocadas
        return 1;                                                                                   // | 
    }

    /*Variáveis*/
    Estrela novaEstrela = {};                                                                       // -> Auxiliar usado para a leitura da estrela

    /*Lê a estrela no terminal*/
    lerTerminalEstrela(&novaEstrela);                                                               // -> Lê a estrela no terminal e atrela ao auxiliar

    /*Endereçamento do estrela na memória do array*/                                                    // -> Obs: index controle está sempre "apontando" para o próximo termo do array 
    sistema->estrelas[sistema->indexControleEstrelas] = novaEstrela;                                // -> Atribui a estrela ao array

    /*Atualiza os controles*/
    sistema->indexControleEstrelas++;                                                               // -> Passa para o próximo termo do array
    sistema->quantidadeEstrelas++;                                                                  // -> Aumenta a quantidade de estrelas

    /*Fim*/
    return 0;                                                                                       // -> Indica operação bem sucedida
}

int removerEstrela(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControleEstrelas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nA estrela de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return 1;                                                                                       // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela aux = {};                                                                                   // -> Auxiliar para a limpeza da estrela

    /*Remoção da estrela*/                                                                                  // -> Obs: index controle está sempre "apontando" para o próximo termo do array, por isso foi decrementado
    sistema->estrelas[indice - 1] = sistema->estrelas[sistema->indexControleEstrelas - 1];              // -> Troca a estrela a ser removida pela última
    sistema->estrelas[sistema->indexControleEstrelas - 1] = aux;                                        // -> Limpa a matriz que foi trocada, ficando um "buraco"

    /*Atualiza a ordenação*/
    sistema->isOrdenadoEstrelas = 0;                                                                    // -> Atualiza a ordenação, estrela deixa de ser ordenada

    /*Atualização das variáveis*/                                       
    sistema->indexControleEstrelas--;                                                                   // -> Remove a estrela do valor de controle
    sistema->quantidadeEstrelas--;                                                                      // -> Remove uma estrela

    return 0;                                                                                           // -> Marca como operação bem sucedida
}

void redimensionarArrayEstrelas(SistemaPlanetario* sistema, int aumentoCapacidade)
{   
    /*Atribui aumento à capacidade*/
    sistema->capacidadeEstrelas += aumentoCapacidade;                                                              // -> Aumenta a capacidade com base no aumento

    /*Realoca o array*/
    sistema->estrelas = (Estrela*) realloc(sistema->estrelas, sizeof(Estrela) * sistema->capacidadeEstrelas);      // -> Realoca o array de acordo com a capacidade de estrelas

    /*Fim*/
    return;
}