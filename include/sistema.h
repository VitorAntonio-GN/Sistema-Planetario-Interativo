#ifndef SISTEMA_H
#define SISTEMA_H

#include "./estruturas.h"

// Gerenciamento de memória
SistemaPlanetario* gerarSistemaPlanetario();
void liberarMemoriaSistemaPlanetario(SistemaPlanetario* sistema);

#endif