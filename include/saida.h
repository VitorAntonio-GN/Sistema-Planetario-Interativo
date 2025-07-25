#ifndef SAIDA_H
#define SAIDA_H

#include "./estruturas.h"

// Exibição
void exibirSistemaPlanetario(SistemaPlanetario* sistema);
void exibirEstrela(SistemaPlanetario* sistema, int indice);
void exibirPlaneta(SistemaPlanetario* sistema, int indice);
void listarEstrelas(SistemaPlanetario* sistema);
void listarPlanetas(SistemaPlanetario* sistema);

#endif