#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/ordenar.h"
#include "../include/sistema.h"
#include "../include/arquivo.h"

int salvarSistemaPlanetario(SistemaPlanetario* sistema)
{
    /*Verifica se não está ordenado as estrelas*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                               // -> Se as estrelas não estiverem ordenadas, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                        // | 
    }
    
    /*Verifica se não está ordenado os planetas*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                               // -> Se os planetas não estiverem ordenados, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                        // | 
    }
    
    /*Variáveis*/
    FILE* fileSistema = NULL;                                                                                   // -> Arquivo
    char enderecoFileSistema[63] = {};                                                                          // -> Endereço do file
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                                       // -> Variáveis auxiliares
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                                       // | 
    DescricaoInfos* buscaDescricao = NULL;                                                                      // | 

    /*Função para atribuir o início do endereço*/
    strcat(enderecoFileSistema, "./dados/");                                                                      // -> Atribui o início do endereço

    /*Loop para deixar minúsculo, trocar ' ' por '_' e atribuir ao endereço*/
    for(int i = 8, j = 0; i < strlen(sistema->nomeSistema) + 8; i++, j++)
    {
        if(isupper(sistema->nomeSistema[j])) enderecoFileSistema[i] = tolower(sistema->nomeSistema[j]);         // -> Formata e atribui o nome ao endereço
        else if(sistema->nomeSistema[j] == ' ') enderecoFileSistema[i] = '_';                                   // | 
        else enderecoFileSistema[i] = sistema->nomeSistema[j];                                                  // | 
    }

    /*Função para atribuir o fim do endereço*/
    strcat(enderecoFileSistema, ".bin\0");                                                                      // -> Atribui o final do endereço

    /*Abre o arquivo para gravação em binário e o verifica se abriu*/
    if((fileSistema = (FILE*) fopen(enderecoFileSistema, "wb")) == NULL)
    {
        printf("\nErro ao abrir o arquivo \"%s\" para escrita\n", enderecoFileSistema);                         // -> Abre e verifica se o arquivo abriu
        return 1;                                                                                               // | 
    }


    /*Grava o sistema*/
    fwrite(sistema->nomeSistema, 50, 1, fileSistema);                                                           // -> Grava informações do sistema
    fwrite(&sistema->quantidadeEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fwrite(&sistema->capacidadeEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fwrite(&sistema->quantidadePlanetas, sizeof(int), 1, fileSistema);                                          // | 
    fwrite(&sistema->capacidadePlanetas, sizeof(int), 1, fileSistema);                                          // | 
    fwrite(&sistema->indexControleEstrelas, sizeof(int), 1, fileSistema);                                       // | 
    fwrite(&sistema->indexControlePlanetas, sizeof(int), 1, fileSistema);                                       // | 
    fwrite(&sistema->isOrdenadoEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fwrite(&sistema->isOrdenadoPlanetas, sizeof(int), 1, fileSistema);                                          // | 
    
    /*Grava as estrelas*/
    for(int i = 0; i < sistema->indexControleEstrelas; i++)
    {
        fwrite(buscaEstrela[i].nomeEstrela, 50, 1, fileSistema);                                                // -> Grava informações de cada estrela
        fwrite(&buscaEstrela[i].massa, sizeof(unsigned long long int), 1, fileSistema);                         // | 
        fwrite(&buscaEstrela[i].raio, sizeof(unsigned long long int), 1, fileSistema);                          // | 
        fwrite(&buscaEstrela[i].temperaturaSuperficie, sizeof(float), 1, fileSistema);                          // | 
        fwrite(&buscaEstrela[i].luminosidade, sizeof(float), 1, fileSistema);                                   // | 
        fwrite(buscaEstrela[i].tipoEstelar, 10, 1, fileSistema);                                                // | 
        fwrite(buscaEstrela[i].cor, 20, 1, fileSistema);                                                        // | 
        fwrite(&buscaEstrela[i].idade, sizeof(float), 1, fileSistema);                                          // | 
    }

    /*Grava os planetas*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        fwrite(buscaPlaneta[i].nomePlaneta, 50, 1, fileSistema);                                                // -> Grava informações gerais de cada planeta
        fwrite(&buscaPlaneta[i].temperaturaMedia, sizeof(float), 1, fileSistema);                               // | 
        fwrite(&buscaPlaneta[i].quantidade_SatelitesNaturais, sizeof(int), 1, fileSistema);                     // | 
        fwrite(&buscaPlaneta[i].quantidade_SatelitesArtificiais, sizeof(int), 1, fileSistema);                  // | 
        fwrite(&buscaPlaneta[i].quantidade_Aneis, sizeof(int), 1, fileSistema);                                 // | 
        fwrite(&buscaPlaneta[i].umidadeMedia, sizeof(float), 1, fileSistema);                                   // | 
        fwrite(&buscaPlaneta[i].massa, sizeof(unsigned long long int), 1, fileSistema);                         // | 
        fwrite(&buscaPlaneta[i].raio, sizeof(unsigned long long int), 1, fileSistema);                          // | 
        fwrite(&buscaPlaneta[i].duracaoAno, sizeof(float), 1, fileSistema);                                     // | 
        fwrite(&buscaPlaneta[i].duracaoDia, sizeof(float), 1, fileSistema);                                     // | 
        fwrite(&buscaPlaneta[i].distanciaEstrela, sizeof(float), 1, fileSistema);                               // | 

        buscaDescricao = (DescricaoInfos*) &buscaPlaneta->infos;                                                // -> Reatribui o endereço do auxiliar

        fwrite(buscaDescricao->sobrePlaneta, 500, 1, fileSistema);                                              // -> Grava informações da descrição de cada planeta
        fwrite(buscaDescricao->descobridor, 100, 1, fileSistema);                                               // | 
        fwrite(buscaDescricao->dataDescoberta, 20, 1, fileSistema);                                             // | 
        fwrite(buscaDescricao->codigoPlaneta, 20, 1, fileSistema);                                              // | 
    }

    /*Fecha e salva o arquivo*/
    fclose(fileSistema);                                                                                        // -> Fecha e salva o arquivo

    /*Fim*/
    return 0;                                                                                                   // -> Marca como operação bem sucedida
}

SistemaPlanetario* carregarSistemaPlanetario(SistemaPlanetario* sistema, char* enderecoFileSistema)
{
    /*Verifica se há um sistema alocado*/
    if(sistema != NULL) liberarMemoriaSistemaPlanetario(sistema);                                              // -> Verifica se há um sistema aberto, se houver, o fecha

    /*Aloca o sistema para a leitura*/
    sistema = (SistemaPlanetario*) calloc(1, sizeof(SistemaPlanetario));                                       // -> Aloca dinâmicamente o sistema

    /*Variáveis do arquivo*/
    FILE* fileSistema = NULL;                                                                                  // -> Variáveis do arquivo

    /*Abre o arquivo para leitura em binário e o verifica se abriu*/
    if((fileSistema = (FILE*) fopen(enderecoFileSistema, "rb")) == NULL)
    {
        printf("\nErro ao abrir o arquivo \"%s\" para leitura\n", enderecoFileSistema);                        // -> Abre e verifica se o arquivo abriu
        return NULL;                                                                                           // | 
    }

    /*Lê e atribui os valores ao sistema*/
    fread(sistema->nomeSistema, 50, 1, fileSistema);                                                           // -> Lê e atribui as informações do sistema
    fread(&sistema->quantidadeEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fread(&sistema->capacidadeEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fread(&sistema->quantidadePlanetas, sizeof(int), 1, fileSistema);                                          // | 
    fread(&sistema->capacidadePlanetas, sizeof(int), 1, fileSistema);                                          // | 
    fread(&sistema->indexControleEstrelas, sizeof(int), 1, fileSistema);                                       // | 
    fread(&sistema->indexControlePlanetas, sizeof(int), 1, fileSistema);                                       // | 
    fread(&sistema->isOrdenadoEstrelas, sizeof(int), 1, fileSistema);                                          // | 
    fread(&sistema->isOrdenadoPlanetas, sizeof(int), 1, fileSistema);                                          // | 

    /*Aloca espaço para estrelas e planetas*/
    sistema->estrelas = calloc(sistema->capacidadeEstrelas, sizeof(Estrela));                                  // -> Redimensiona os arrays 
    sistema->planetas = calloc(sistema->capacidadePlanetas, sizeof(Planeta));                                  // | 

    /*Variáveis auxiliares*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                                      // -> Variáveis auxiliares
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                                      // | 
    DescricaoInfos* buscaDescricao = NULL;                                                                     // | 

    /*Lê e atribui os valores às estrelas, com base no index*/
    for(int i = 0; i < sistema->indexControleEstrelas; i++)
    {
        fread(buscaEstrela[i].nomeEstrela, 50, 1, fileSistema);                                                // -> Lê e atribui as informações para cada estrela
        fread(&buscaEstrela[i].massa, sizeof(unsigned long long int), 1, fileSistema);                         // | 
        fread(&buscaEstrela[i].raio, sizeof(unsigned long long int), 1, fileSistema);                          // | 
        fread(&buscaEstrela[i].temperaturaSuperficie, sizeof(float), 1, fileSistema);                          // | 
        fread(&buscaEstrela[i].luminosidade, sizeof(float), 1, fileSistema);                                   // | 
        fread(buscaEstrela[i].tipoEstelar, 10, 1, fileSistema);                                                // | 
        fread(buscaEstrela[i].cor, 20, 1, fileSistema);                                                        // | 
        fread(&buscaEstrela[i].idade, sizeof(float), 1, fileSistema);                                          // | 
    }

    /*Grava os planetas*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        fread(buscaPlaneta[i].nomePlaneta, 50, 1, fileSistema);                                                // -> Lê e atribui as informações gerais para cada planeta
        fread(&buscaPlaneta[i].temperaturaMedia, sizeof(float), 1, fileSistema);                               // | 
        fread(&buscaPlaneta[i].quantidade_SatelitesNaturais, sizeof(int), 1, fileSistema);                     // | 
        fread(&buscaPlaneta[i].quantidade_SatelitesArtificiais, sizeof(int), 1, fileSistema);                  // | 
        fread(&buscaPlaneta[i].quantidade_Aneis, sizeof(int), 1, fileSistema);                                 // | 
        fread(&buscaPlaneta[i].umidadeMedia, sizeof(float), 1, fileSistema);                                   // | 
        fread(&buscaPlaneta[i].massa, sizeof(unsigned long long int), 1, fileSistema);                         // | 
        fread(&buscaPlaneta[i].raio, sizeof(unsigned long long int), 1, fileSistema);                          // | 
        fread(&buscaPlaneta[i].duracaoAno, sizeof(float), 1, fileSistema);                                     // | 
        fread(&buscaPlaneta[i].duracaoDia, sizeof(float), 1, fileSistema);                                     // | 
        fread(&buscaPlaneta[i].distanciaEstrela, sizeof(float), 1, fileSistema);                               // | 

        buscaDescricao = (DescricaoInfos*) &buscaPlaneta->infos;                                               // -> Reatribui o endereço do auxiliar

        fread(buscaDescricao->sobrePlaneta, 500, 1, fileSistema);                                              // -> Lê e atribui a descrição para cada planeta
        fread(buscaDescricao->descobridor, 100, 1, fileSistema);                                               // | 
        fread(buscaDescricao->dataDescoberta, 20, 1, fileSistema);                                             // | 
        fread(buscaDescricao->codigoPlaneta, 20, 1, fileSistema);                                              // | 
    }

    /*Fecha e salva o arquivo*/
    fclose(fileSistema);                                                                                       // -> Fecha e salva o arquivo

    /*Fim*/
    return sistema;
}