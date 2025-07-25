#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "./estruturas.h"

// Manipulação de arquivos
int salvarSistemaPlanetario(SistemaPlanetario* sistema);
SistemaPlanetario* carregarSistemaPlanetario(SistemaPlanetario* sistema, char* enderecoFileSistema);

#endif