#ifndef ENTRADA_H
#define ENTRADA_H

#include "./estruturas.h"

// Entrada de dados
void lerTerminalSistemaPlanetario(SistemaPlanetario* sistema);
void lerTerminalEstrela(Estrela* novaEstrela);
void lerTerminalPlaneta(Planeta* novoPlaneta);
void lerTerminalDescricaoPlaneta(DescricaoInfos* novaDescricao);
void lerIndice(int* indice);
void lerNomeFile(char enderecoFile[]);
void lerAumentoCapacidade(int* aumentoCapacidade);
void lerIndiceEstrela(int* indiceEstrela);

#endif