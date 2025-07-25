#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/ordenar.h"
#include "../include/saida.h"

void exibirSistemaPlanetario(SistemaPlanetario* sistema)
{
    /*Printa os dados*/
    printf("\n/* %s */\n", sistema->nomeSistema);                                                       // -> Printa os dados mais relevantes do sistema planetario (planetas e estrelas é no listar)
    printf("- %d estrelas\n", sistema->quantidadeEstrelas);                                             // | 
    printf("    >> Com capacidade para %d estrelas\n", sistema->capacidadeEstrelas);                    // | 
    printf("- %d planetas\n", sistema->quantidadePlanetas);                                             // | 
    printf("    >> Com capacidade para %d planetas\n", sistema->capacidadePlanetas);                    // | 

    /*Exibe as estrelas*/
    listarEstrelas(sistema);                                                                            // -> Imprime as estrelas

    /*Exibe os planetas*/
    listarPlanetas(sistema);                                                                            // -> Imprime os planetas

    /*Fim*/
    return;
}

void exibirEstrela(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControleEstrelas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nA estrela de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return;                                                                                         // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) &sistema->estrelas[indice - 1];                                  // -> Variável auxiliar para a impressão

    /*Printa os dados*/
    printf("\n/* %s */\n", buscaEstrela->nomeEstrela);                                                  // -> Printa os dados da estrela
    printf("- Massa de %llukg\n", buscaEstrela->massa);                                                 // | 
    printf("- Raio de %llukm\n", buscaEstrela->raio);                                                   // | 
    printf("- Superficie com temperatura de %0.2fK\n", buscaEstrela->temperaturaSuperficie);            // | 
    printf("- Luminosidade relativa ao Sol de %0.2f\n", buscaEstrela->luminosidade);                    // | 
    printf("- Tipo estelar %s\n", buscaEstrela->tipoEstelar);                                           // | 
    printf("- Cor predominantemente %s\n", buscaEstrela->cor);                                          // | 
    printf("- Idade de %0.2f bilhões de anos\n", buscaEstrela->idade);                                  // | 

    /*Fim*/
    return;
}

void exibirPlaneta(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControlePlanetas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nO planeta de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return;                                                                                         // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta* buscaPlaneta = (Planeta*) &sistema->planetas[indice - 1];                                              // -> Variáveis auxiliares para a impressão
    DescricaoInfos* buscaDescricao = (DescricaoInfos*) &buscaPlaneta->infos;                                        // | 

    /*Printa os dados*/
    printf("\n/* %s */\n", buscaPlaneta->nomePlaneta);                                                              // -> Imprime as propriedades do planeta
    printf("- Temperatura media de %0.2f Celsius\n", buscaPlaneta->temperaturaMedia);                               // | 
    printf("- %d satelites naturais\n", buscaPlaneta->quantidade_SatelitesNaturais);                                // | 
    printf("- %d satelites artificiais\n", buscaPlaneta->quantidade_SatelitesArtificiais);                          // | 
    printf("- %d aneis em sua orbita\n", buscaPlaneta->quantidade_Aneis);                                           // | 
    printf("- Umidade media de %0.2f%%\n", buscaPlaneta->umidadeMedia);                                             // | 
    printf("- Massa de %llukg\n", buscaPlaneta->massa);                                                             // | 
    printf("- Raio de %llukm\n", buscaPlaneta->raio);                                                               // | 
    printf("- Ano com duracao de %0.2f dias terrestres\n", buscaPlaneta->duracaoAno);                               // | 
    printf("- Dia com duracao de %0.2f horas\n", buscaPlaneta->duracaoDia);                                         // | 
    printf("- Distancia ate a estrela de %0.2f UA (Unidades Astronomicas)\n", buscaPlaneta->duracaoDia);            // | 

    printf("\n>> Descricao geral -> %s\n", buscaDescricao->sobrePlaneta);                                           // -> Imprime a descrição do planeta
    printf(">> Descobridor -> %s\n", buscaDescricao->descobridor);                                                  // | 
    printf(">> Data da descoberta -> %s\n", buscaDescricao->dataDescoberta);                                        // | 
    printf(">> Codigo do planeta -> %s\n", buscaDescricao->codigoPlaneta);                                          // | 
    printf("    > [Nome da estrela em orbita] - [Ano] - [Letra na hierarquia]");                                    // | 

    /*Fim*/
    return;
}

void listarEstrelas(SistemaPlanetario* sistema)
{
    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                               // -> Cria o auxiliar

    /*Imprime o título*/
    printf("\n/- Estrelas -/\n");                                                                       // -> Imprime o título

    /*Loop para imprimir as estrelas*/
    for(int i = 0; i < sistema->indexControleEstrelas; i++)
    {
        printf("%d - %s\n", i + 1, buscaEstrela[i].nomeEstrela);                                        // -> Imprime estrela por estrela
    }

    /*Imprime o formato*/
    printf("\n[indice] - [nome da estrela]\n\n");                                                       // -> Imprime o formato

    /*Fim*/
    return;
}

void listarPlanetas(SistemaPlanetario* sistema)
{
    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                               // -> Cria o auxiliar

    /*Imprime o título*/
    printf("\n/- Planetas -/\n");                                                                       // -> Imprime o título

    /*Loop para imprimir os planetas*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        printf("%d - %s\n", i + 1, buscaPlaneta[i].nomePlaneta);                                        // -> Imprime planeta por planeta
        printf("    >> %s\n", buscaPlaneta[i].infos.codigoPlaneta);                                     // | 
    }

    /*Imprime o formato*/
    printf("\n[indice] - [nome do planeta]\n");                                                         // -> Imprime o formato
    printf("    >> [codigo do planeta]\n\n");                                                           // | 

    /*Fim*/
    return;
}   