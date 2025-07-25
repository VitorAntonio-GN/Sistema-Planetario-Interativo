#ifndef ESTRELA_H
#define ESTRELA_H

#include "./estruturas.h"

// Gerenciamento de estrelas
int adicionarEstrela(SistemaPlanetario* sistema);
int removerEstrela(SistemaPlanetario* sistema, int indice);
void redimensionarArrayEstrelas(SistemaPlanetario* sistema, int aumentoCapacidade);

#endif