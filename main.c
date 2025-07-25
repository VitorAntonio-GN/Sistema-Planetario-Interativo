#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "./include/arquivo.h"
#include "./include/entrada.h"
#include "./include/estrela.h"
#include "./include/estruturas.h"
#include "./include/ordenar.h"
#include "./include/planeta.h"
#include "./include/saida.h"
#include "./include/sistema.h"

/* ---------------------- Main ---------------------- */

int main() {
    /*Variáveis*/
    SistemaPlanetario* sistema = NULL;                                                              // -> Variáveis para o uso
    int opcaoEscolhida = 0;                                                                         // | 
    int indice = 0;                                                                                 // | 
    char nomeFile[63] = {};                                                                         // | 
    int aumentoCapacidade = 0;                                                                      // | 
    int isSistema = 0;                                                                              // | 
    
    /*Loop da interface*/
    do{
        /*Loop do input opção*/
        do{
            /*Opções da interface*/
            printf("\n/- SISTEMA PLANETARIO INTERATIVO -/\n");
            printf("1. Criar novo sistema planetario\n");
            printf("2. Carregar sistema planetario\n");
            printf("3. Adicionar estrela\n");
            printf("4. Adicionar planeta\n");
            printf("5. Remover estrela\n");
            printf("6. Remover planeta\n");
            printf("7. Aumentar capacidade de estrelas\n");
            printf("8. Aumentar capacidade de planetas\n");
            printf("9. Exibir sistema planetario completo\n");
            printf("10. Exibir estrelas\n");
            printf("11. Exibir planetas\n");
            printf("12. Salvar sistema planetario\n");
            printf("13. Ordernar estrelas\n");
            printf("14. Ordenar planetas\n");
            printf("15. Sair\n");
            printf("Escolha uma opção: ");
            
            /*Leitura da opção*/
            scanf("%d", &opcaoEscolhida);
            getchar();

            /*Verificação de criação*/
            if(opcaoEscolhida == 1 || opcaoEscolhida == 2)
            {
                isSistema = 1;
            }

            /*Verificação para a saída*/
            if(opcaoEscolhida == 15) break;

            /*Vericações de erro*/
            if(opcaoEscolhida < 1 || opcaoEscolhida > 15) printf("\nDigite uma opcao valida\n");
            else if(opcaoEscolhida > 2 && isSistema == 0) printf("\nCrie ou carregue um sistema planetario para realizar esta operacao\n");

        } while(isSistema == 0);

        /*Switch para opção*/
        switch(opcaoEscolhida) {
            case 1: sistema = (SistemaPlanetario*) gerarSistemaPlanetario();
                    break;

            case 2: lerNomeFile(nomeFile);
                    sistema = (SistemaPlanetario*) carregarSistemaPlanetario(sistema, nomeFile);
                    break;

            case 3: if(adicionarEstrela(sistema) != 0) printf("\nErro ao adicionar uma estrela\n");
                    break;

            case 4: if(adicionarPlaneta(sistema) != 0) printf("\nErro ao adicionar um planeta\n");
                    break;

            case 5: lerIndice(&indice);
                    removerEstrela(sistema, indice);
                    break;
                
            case 6: lerIndice(&indice);
                    removerPlaneta(sistema, indice);
                    break;

            case 7: lerAumentoCapacidade(&aumentoCapacidade);
                    redimensionarArrayEstrelas(sistema, aumentoCapacidade);
                    break;
                    
            case 8: lerAumentoCapacidade(&aumentoCapacidade);
                    redimensionarArrayPlanetas(sistema, aumentoCapacidade);
                    break;
        
            case 9: exibirSistemaPlanetario(sistema);
                    break;

            case 10:lerIndice(&indice);
                    exibirEstrela(sistema, indice);
                    break;
                    
            case 11:lerIndice(&indice);
                    exibirPlaneta(sistema, indice);
                    break;

            case 12:if(salvarSistemaPlanetario(sistema) != 0) printf("\nErro ao salvar o sistema planetario\n");
                    break;
        
            case 13:ordenarEstrelas(sistema);
                    break;
    
            case 14:ordenarPlanetas(sistema);
                    break;
    
            case 15:if(isSistema == 1) liberarMemoriaSistemaPlanetario(sistema); 
                    break;

            default:printf("\nErro na interface\n");
        }

    } while(opcaoEscolhida != 15);
    
    /*Fim*/
    return 0;                                                                                       // -> Marca como operação bem sucedida
}