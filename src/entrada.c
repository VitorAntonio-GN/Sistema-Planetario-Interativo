#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/estruturas.h"
#include "../include/entrada.h"

void lerTerminalSistemaPlanetario(SistemaPlanetario* sistema)
{
    /*Pede inputs*/ 
    printf("\n/- Digite: -/\n");                                                                    // -> Pede os inputs
    printf("- O nome do sistema planetario\n");                                                     // | 
    printf("- A capacidade de estrelas\n");                                                         // |
    printf("- A capacidade de planetas\n\n");                                                       // |

    /*Lê os inputs*/                                    
    fgets(sistema->nomeSistema, 50, stdin);                                                         // -> Lê, atribui e formata o nome e limpa o buffer
    sistema->nomeSistema[strcspn(sistema->nomeSistema, "\n")] = '\0';                               // | 
    scanf("%d", &sistema->capacidadeEstrelas);                                                      // -> Lê e atribui os inputs e limpa o buffer
    getchar();                                                                                      // | 
    scanf("%d", &sistema->capacidadePlanetas);                                                      // |
    getchar();

    /*Atualiza as informações do controle*/
    sistema->indexControleEstrelas = 0;                                                             // -> Atualiza os indexs atuais
    sistema->indexControlePlanetas = 0;                                                             // | 

    /*Atualiza a ordenação atual*/
    sistema->isOrdenadoEstrelas = 1;                                                                // -> Atribui como ordenado, naturalmente
    sistema->isOrdenadoPlanetas = 1;                                                                // | 

    /*Atualiza a quantidade de corpos*/
    sistema->quantidadeEstrelas = 0;                                                                // -> Atribui a quantidade inicial real
    sistema->quantidadePlanetas = 0;                                                                // | 

    /*Fim*/
    return;
}

void lerTerminalEstrela(Estrela* novaEstrela)
{
    /*Pede os inputs*/
    printf("\n/- Digite: -/\n");                                                                    // -> Pede os inputs
    printf("- O nome da estrela\n");                                                                // | 
    printf("- A massa da estrela em kg\n");                                                         // | 
    printf("- O raio da estrela em km\n");                                                          // | 
    printf("- A temperatura da superficie em Kelvin\n");                                            // | 
    printf("- A luminosidade da estrela relativa ao Sol\n");                                        // | 
    printf("- O tipo estelar da estrela (G, K, M, etc.)\n");                                        // | 
    printf("- A cor da estrela\n");                                                                 // | 
    printf("- A idade da estrela em bilhões de anos\n\n");                                          // | 

    /*Lê os inputs*/
    fgets(novaEstrela->nomeEstrela, 50, stdin);                                                      // -> Lê, atribui e formata  o nome
    novaEstrela->nomeEstrela[strcspn(novaEstrela->nomeEstrela, "\n")] = '\0';                        // | 
    scanf("%llu", &novaEstrela->massa);                                                              // -> Lê e atribui a massa e limpa o buffer
    getchar();                                                                                       // | 
    scanf("%llu", &novaEstrela->raio);                                                               // -> Lê e atribui o raio e limpa o buffer
    getchar();                                                                                       // | 
    scanf("%f", &novaEstrela->temperaturaSuperficie);                                                // -> Lê e atribui temperatura e limpa o buffer
    getchar();                                                                                       // | 
    scanf("%f", &novaEstrela->luminosidade);                                                         // -> Lê e atribui a luminosidade e limpa o buffer
    getchar();                                                                                       // | 
    fgets(novaEstrela->tipoEstelar, 10, stdin);                                                      // -> Lê, atribui e formata o tipo estelar
    novaEstrela->tipoEstelar[strcspn(novaEstrela->tipoEstelar, "\n")] = '\0';                        // | 
    fgets(novaEstrela->cor, 20, stdin);                                                              // -> Lê, atribui e formata a cor
    novaEstrela->cor[strcspn(novaEstrela->cor, "\n")] = '\0';                                        // | 
    scanf("%f", &novaEstrela->idade);                                                                // -> Lê e atribui a idade e limpa o buffer
    getchar();                                                                                       // | 

    /*Fim*/
    return;
}

void lerTerminalPlaneta(Planeta* novoPlaneta)
{
    /*Pede os inputs*/
    printf("\n/- Digite: -/\n");                                                                        // -> Pede os inputs para o planeta
    printf("- O nome do planeta\n");                                                                    // |  
    printf("- A temperatura media do planeta em Celsius\n");                                            // | 
    printf("- A quantidade de satelites naturais do planeta (luas)\n");                                 // | 
    printf("- A quantidade de satelites artificiais do planeta\n");                                     // | 
    printf("- A quantidade de aneis do planeta\n");                                                     // | 
    printf("- A umidade media do planeta em porcentagem\n");                                            // | 
    printf("- A massa do planeta em kg\n");                                                             // | 
    printf("- O raio do planeta em km\n");                                                              // | 
    printf("- A diracao do ano no planeta em dias terrestres\n");                                       // | 
    printf("- A duracao do dia no planeta em horas\n");                                                 // | 
    printf("- A distancia entre o planeta e a estrela em UA (Unidades Astronômicas)\n");                // | 

    /*Lê os inputs*/
    fgets(novoPlaneta->nomePlaneta, 50, stdin);                                                          // -> Lê, atribui e formata o input
    novoPlaneta->nomePlaneta[strcspn(novoPlaneta->nomePlaneta, "\n")] = '\0';                            // | 
    scanf("%f", &novoPlaneta->temperaturaMedia);                                                         // -> Lê e atribui os inputs e limpa o buffer
    getchar();                                                                                           // | 
    scanf("%d", &novoPlaneta->quantidade_SatelitesNaturais);                                             // | 
    getchar();                                                                                           // | 
    scanf("%d", &novoPlaneta->quantidade_SatelitesArtificiais);                                          // | 
    getchar();                                                                                           // | 
    scanf("%d", &novoPlaneta->quantidade_Aneis);                                                         // | 
    getchar();                                                                                           // | 
    scanf("%f", &novoPlaneta->umidadeMedia);                                                             // | 
    getchar();                                                                                           // | 
    scanf("%llu", &novoPlaneta->massa);                                                                  // | 
    getchar();                                                                                           // | 
    scanf("%llu", &novoPlaneta->raio);                                                                   // | 
    getchar();                                                                                           // | 
    scanf("%f", &novoPlaneta->duracaoAno);                                                               // | 
    getchar();                                                                                           // | 
    scanf("%f", &novoPlaneta->duracaoDia);                                                               // | 
    getchar();                                                                                           // | 
    scanf("%f", &novoPlaneta->distanciaEstrela);                                                         // | 
    getchar();                                                                                           // | 

    /*Fim*/
    return;
}

void lerTerminalDescricaoPlaneta(DescricaoInfos* novaDescricao)
{
    printf("\n- Uma descricao geral do planeta\n");                                                     // -> Pede os inputs
    printf("- O nome do descobridor do planeta\n");                                                     // | 
    printf("- A data da descoberta do planeta (formato: DD/MM/AAAA)\n");                                // | 

    fgets(novaDescricao->sobrePlaneta, 500, stdin);                                                     // -> Lê, atribui e formata o input
    novaDescricao->sobrePlaneta[strcspn(novaDescricao->sobrePlaneta, "\n")] = '\0';                     // | 
    fgets(novaDescricao->descobridor, 100, stdin);                                                      // -> Lê, atribui e formata o input
    novaDescricao->descobridor[strcspn(novaDescricao->descobridor, "\n")] = '\0';                       // | 
    fgets(novaDescricao->dataDescoberta, 20, stdin);                                                    // -> Lê, atribui e formata o input
    novaDescricao->dataDescoberta[strcspn(novaDescricao->dataDescoberta, "\n")] = '\0';                 // | 

    /*Fim*/
    return;
}

void lerIndice(int* indice)
{
    /*Loop do input*/
    do{
        /*Pede o input*/
        printf("\nDigite o indice: ");                                                                         // -> Pede o indice

        /*Lê e atribui o indice*/
        scanf("%d", indice);                                                                                   // -> Lê e atribui o indice e limpa o buffer
        getchar();                                                                                             // | 

    } while(indice < 0);

    /*Fim*/
    return;
}

void lerNomeFile(char enderecoFile[])
{
    /*Loop para resetar o endereço*/
    if(enderecoFile[0] != '\0') for(int i = 0; i < 63; i++) enderecoFile[i] = '\0';                      // -> Loop para reset

    /*Variáveis*/
    char nomeSistema[50] = {};                                                                           // -> Variável auxiliar

    /*Pede o input*/
    printf("\nDigite o nome do sistema planetario: ");                                                   // -> Pede o nome do sistema

    /*Função para atribuir o início do endereço*/
    strcat(enderecoFile, "./dados/");                                                                    // -> Atribui o início do endereço

    /*Lê, formata e atribui o input*/
    fgets(nomeSistema, 50, stdin);                                                                       // -> Lê e formata o nome 
    nomeSistema[strcspn(nomeSistema, "\n")] = '\0';                                                      // | 

    strcat(enderecoFile, nomeSistema);                                                                   // -> Atribui o endereço formatado

    /*Loop para deixar minúsculo, trocar ' ' por '_' e atribuir ao endereço*/
    for(int i = 8; i < strlen(enderecoFile); i++)
    {
        if(isupper(enderecoFile[i])) enderecoFile[i] = tolower(enderecoFile[i]);                         // -> Formata e atribui o nome ao endereço
        else if(enderecoFile[i] == ' ') enderecoFile[i] = '_';                                           // | 
    }

    /*Função para atribuir o fim do endereço*/
    strcat(enderecoFile, ".bin\0");                                                                      // -> Atribui o final do endereço

    /*Fim*/
    return;
}

void lerAumentoCapacidade(int* aumentoCapacidade)
{
    /*Loop do inputs*/
    do{
        /*Pede o input*/
        printf("\nDigite o aumento: ");                                                                        // -> Pede o input

        /*Lê e atribui o aumento*/
        scanf("%d", aumentoCapacidade);                                                                        // -> Atribui ao endereço e limpa o buffer
        getchar();                                                                                             // | 

    } while(aumentoCapacidade < 0);

    /*Fim*/
    return;
}

void lerIndiceEstrela(int* indiceEstrela)
{
    /*Loop do input*/
    do{
        /*Pede o input*/
        printf("\nDigite o indice da estrela em que este planeta orbita: ");

        /*Lê e atribui o input*/
       scanf("%d", indiceEstrela);

    } while(*indiceEstrela < 1);

    /*Fim*/
    return;
}