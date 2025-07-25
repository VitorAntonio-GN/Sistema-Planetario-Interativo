#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/entrada.h"
#include "../include/ordenar.h"
#include "../include/planeta.h"

int adicionarPlaneta(SistemaPlanetario* sistema)
{
    /*Verifica se já atingiu o limite*/
    if(sistema->indexControlePlanetas >= sistema->capacidadePlanetas)
    {
        printf("\nAtingiu-se a capacidade maxima de planetas\n");                                       // -> Verifica se já atingiu a capacidade máxima de planetas alocados
        return 1;                                                                                       // | 
    }

    /*Variáveis*/
    Planeta novoPlaneta = {};                                                                           // -> Cria o auxiliar para a leitura

    /*Lê os inputs do planeta*/
    lerTerminalPlaneta(&novoPlaneta);                                                                   // -> Lê os inputs do terminau e atribui ao auxiliar
    lerTerminalDescricaoPlaneta(&novoPlaneta.infos);                                                    // | 
    gerarCodigoPlaneta(sistema, &novoPlaneta.infos);                                                    // | 

    /*Adiciona o planeta ao vetor*/
    sistema->planetas[sistema->indexControlePlanetas] = novoPlaneta;                                    // -> Atribui o planeta ao array

    /*Atualiza o valor do controle*/
    sistema->indexControlePlanetas++;                                                                   // -> Passa para o "próximo" planeta
    sistema->quantidadePlanetas++;                                                                      // -> incrementa o planeta inserido

    /*Fim*/
    return 0;                                                                                           // -> Marca como operação bem sucedida
}

int removerPlaneta(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControlePlanetas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nO planeta de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return 1;                                                                                       // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta aux = {};                                                                                   // -> Auxiliar para a limpeza do planeta

    /*Remoção do planeta*/                                                                                  // -> Obs: index controle está sempre "apontando" para o próximo termo do array, por isso foi decrementado
    sistema->planetas[indice - 1] = sistema->planetas[sistema->indexControlePlanetas - 1];              // -> Troca o planeta a ser removido pela último
    sistema->planetas[sistema->indexControlePlanetas - 1] = aux;                                        // -> Limpa a matriz que foi trocada, ficando um "buraco"

    /*Atualiza a ordenação*/
    sistema->isOrdenadoPlanetas = 0;                                                                    // -> Atualiza a ordenação, planeta deixa de ser ordenado

    /*Atualização das variáveis*/                                       
    sistema->indexControlePlanetas--;                                                                   // -> Remove o planeta do valor de controle
    sistema->quantidadePlanetas--;                                                                      // -> Decrementa o planeta

    return 0;                                                                                           // -> Marca como operação bem sucedida
}

void redimensionarArrayPlanetas(SistemaPlanetario* sistema, int aumentoCapacidade)
{
    /*Atribui aumento à capacidade*/
    sistema->capacidadePlanetas += aumentoCapacidade;                                                              // -> Aumenta a capacidade com base no aumento

    /*Realoca o array*/
    sistema->planetas = (Planeta*) realloc(sistema->planetas, sizeof(Planeta) * sistema->capacidadePlanetas);      // -> Realoca o array de acordo com a capacidade de planetas

    /*Fim*/
    return;
}

void gerarCodigoPlaneta(SistemaPlanetario* sistema, DescricaoInfos* buscaDescricao)
{
    /*Limpa o código para não causar erro*/
    for(int i = 0; i < 20; i++) buscaDescricao->codigoPlaneta[i] = '\0';                                                                            // -> Limpa o código

    /*Verifica se é apenas uma estrela*/
    if(sistema->quantidadeEstrelas == 1)
    {
        strcat(buscaDescricao->codigoPlaneta, sistema->estrelas[0].nomeEstrela);                                                                    // -> Adiciona o nome da estrela
    }
    else
    {
        int indiceEstrela = 0;                                                                                                                      // -> Cria a estrela para o uso
        lerIndiceEstrela(&indiceEstrela);                                                                                                           // -> Pega a estrela em que estiver em orbita
        strcasecmp(buscaDescricao->codigoPlaneta, sistema->estrelas[indiceEstrela - 1].nomeEstrela);                                                // -> Adiciona o nome da estrela
    }

    /*Atribui o '-' para separação*/
    strcat(buscaDescricao->codigoPlaneta, "-");                                                                                                     // -> Dá o espaçamento

    /*Adiciona o ano da descoberta*/
    for(int i = strlen(buscaDescricao->codigoPlaneta), j = 0; j < 4; i++ ,j++) 
    {
        buscaDescricao->codigoPlaneta[i] = buscaDescricao->dataDescoberta[strlen(buscaDescricao->dataDescoberta) - 4 + j];  // -> Adiciona a data
    }

    /*Atribui o '-' para separação*/
    strcat(buscaDescricao->codigoPlaneta, "-");                                                                                                     // -> Dá o espaçamento

    /*Atribui a letra com base na ordem dos adicionados*/
    buscaDescricao->codigoPlaneta[strlen(buscaDescricao->codigoPlaneta)] = sistema->indexControlePlanetas + 98;                                     // -> Adiciona a letra

    /*Fim*/
    return;
}