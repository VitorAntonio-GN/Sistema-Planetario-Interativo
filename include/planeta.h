#ifndef PLANETA_H
#define PLANETA_H

#include "./estruturas.h"

// Gerenciamento de planetas
int adicionarPlaneta(SistemaPlanetario* sistema);
int removerPlaneta(SistemaPlanetario* sistema, int indice);
void redimensionarArrayPlanetas(SistemaPlanetario* sistema, int aumentoCapacidade);
void gerarCodigoPlaneta(SistemaPlanetario* sistema, DescricaoInfos* buscaDescricao);

#endif