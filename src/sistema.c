#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/entrada.h"
#include "../include/sistema.h"

SistemaPlanetario* gerarSistemaPlanetario()
{
    /*Cria o sistema*/
    SistemaPlanetario* sistema = NULL;                                                              // -> Ponteiro de sistema planetario

    /*Aloca o sistema*/
    sistema = (SistemaPlanetario*) calloc(1, sizeof(SistemaPlanetario));                            // -> Aloca dinamicamente um sistema planetario

    /*Lê o sistema planetario no terminal*/
    lerTerminalSistemaPlanetario(sistema);                                                          // -> Lê os inputs e atribui ao endereço alocado

    /*Aloca com base nos inputs*/
    sistema->planetas = (Planeta*) calloc(sistema->capacidadePlanetas, sizeof(Planeta));            // -> Aloca planeta
    sistema->estrelas = (Estrela*) calloc(sistema->capacidadeEstrelas, sizeof(Estrela));            // -> Aloca estrela

    /*Fim*/
    return sistema;                                                                                 // -> Retorna o endereço da memória alocada
}

void liberarMemoriaSistemaPlanetario(SistemaPlanetario* sistema)
{
    /*Libera a memória*/
    free(sistema->estrelas);                                                                        // -> Libera a memória do vetor dinâmico estrelas
    free(sistema->planetas);                                                                        // -> Libera a memória do vetor diâmico planetas
    free(sistema);                                                                                  // -> Libera a memória do sistema planetario

    /*Atualiza o ponteiro*/
    sistema = NULL;                                                                                 // -> Garante que o ponteiro aponte para NULL

    /*Fim*/
    return;
}   