#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* ---------------------- Structs ---------------------- */

typedef struct {
    char sobrePlaneta[500];                     // Descrição geral do planeta
    char descobridor[100];                      // Nome do descobridor
    char dataDescoberta[20];                    // Data da descoberta (formato: DD/MM/AAAA)
    char codigoPlaneta[20];                     // Código científico do planeta
} DescricaoInfos;           

typedef struct {            
    char nomeEstrela[50];                       // Nome da estrela
    long long int massa;                        // Massa da estrela em kg
    long long int raio;                         // Raio da estrela em km
    float temperaturaSuperficie;                // Temperatura da superfície em Kelvin
    float luminosidade;                         // Luminosidade relativa ao Sol
    char tipoEstelar[10];                       // Tipo estelar (G, K, M, etc.)
    char cor[20];                               // Cor da estrela
    float idade;                                // Idade em bilhões de anos
} Estrela;          

typedef struct {            
    char nomePlaneta[50];                       // Nome do planeta
    float temperaturaMedia;                     // Temperatura média em Celsius
    int quantidade_SatelitesNaturais;           // Número de satélites naturais (luas)
    int quantidade_SatelitesArtificiais;        // Número de satélites artificiais
    int quantidade_Aneis;                       // Número de anéis
    float umidadeMedia;                         // Umidade média em porcentagem
    long long int massa;                        // Massa em kg
    long long int raio;                         // Raio em km
    float duracaoAno;                           // Duração do ano em dias terrestres
    float duracaoDia;                           // Duração do dia em horas
    float distanciaEstrela;                     // Distância da estrela em UA (Unidades Astronômicas)
    DescricaoInfos infos;                       // Informações descritivas
} Planeta;          

typedef struct {            
    char nomeSistema[50];                       // Nome do sistema planetario
    int quantidadeEstrelas;                     // Número atual de estrelas
    int capacidadeEstrelas;                     // Capacidade máxima atual do array de estrelas
    Estrela* estrelas;                          // Array dinâmico de estrelas
    int quantidadePlanetas;                     // Número atual de planetas
    int capacidadePlanetas;                     // Capacidade máxima atual do array de planetas
    Planeta* planetas;                          // Array dinâmico de planetas
    int indexControleEstrelas;                  // Controle de index do array dinâmico
    int indexControlePlanetas;                  // Controle de index do array dinâmico
    int isOrdenadoEstrelas;                     // Controle de ordenação do array dinâmico
    int isOrdenadoPlanetas;                     // Controle de ordenação do array dinâmico
} SistemaPlanetario;

/* ---------------------- Protótipos das funções ---------------------- */

// Gerenciamento de memória
SistemaPlanetario* gerarSistemaPlanetario();
void liberarMemoriaSistemaPlanetario(SistemaPlanetario* sistema);

// Gerenciamento de estrelas
int adicionarEstrela(SistemaPlanetario* sistema);
int removerEstrela(SistemaPlanetario* sistema, int indice);
void redimensionarArrayEstrelas(SistemaPlanetario* sistema, int aumentoCapacidade);

// Gerenciamento de planetas
int adicionarPlaneta(SistemaPlanetario* sistema);
int removerPlaneta(SistemaPlanetario* sistema, int indice);
void redimensionarArrayPlanetas(SistemaPlanetario* sistema, int aumentoCapacidade);

// Entrada de dados
void lerTerminalSistemaPlanetario(SistemaPlanetario* sistema);
void lerTerminalEstrela(Estrela* novaEstrela);
void lerTerminalPlaneta(Planeta* novoPlaneta);
void lerTerminalDescricaoPlaneta(DescricaoInfos* novaDescricao);
void lerIndice(int* indice);
void lerNomeFile(char enderecoFile[]);
void lerAumentoCapacidade(int* aumentoCapacidade);

// Exibição
void exibirSistemaPlanetario(SistemaPlanetario* sistema);
void exibirEstrela(SistemaPlanetario* sistema, int indice);
void exibirPlaneta(SistemaPlanetario* sistema, int indice);
void listarEstrelas(SistemaPlanetario* sistema);
void listarPlanetas(SistemaPlanetario* sistema);

// Ordenação
void ordenarEstrelas(SistemaPlanetario* sistema);
void ordenarPlanetas(SistemaPlanetario* sistema);

// Manipulação de arquivos
int salvarSistemaPlanetario(SistemaPlanetario* sistema);
SistemaPlanetario* carregarSistemaPlanetario(SistemaPlanetario* sistema, char* enderecoFileSistema);

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

/* ---------------------- Funções ---------------------- */

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

int adicionarEstrela(SistemaPlanetario* sistema)
{
    /*Verifica se já atingiu o limite*/
    if(sistema->indexControleEstrelas >= sistema->capacidadeEstrelas)
    {
        printf("\nAtingiu-se a capacidade maxima de estrelas\n");                                   // -> Verifica se já atingiu a capacidade máxima de estrelas alocadas
        return 1;                                                                                   // | 
    }

    /*Variáveis*/
    Estrela novaEstrela = {};                                                                       // -> Auxiliar usado para a leitura da estrela

    /*Lê a estrela no terminal*/
    lerTerminalEstrela(&novaEstrela);                                                               // -> Lê a estrela no terminal e atrela ao auxiliar

    /*Endereçamento do estrela na memória do array*/                                                    // -> Obs: index controle está sempre "apontando" para o próximo termo do array 
    sistema->estrelas[sistema->indexControleEstrelas] = novaEstrela;                                // -> Atribui a estrela ao array

    /*Atualiza os controles*/
    sistema->indexControleEstrelas++;                                                               // -> Passa para o próximo termo do array
    sistema->quantidadeEstrelas++;                                                                  // -> Aumenta a quantidade de estrelas

    /*Fim*/
    return 0;                                                                                       // -> Indica operação bem sucedida
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
    scanf("%lld", &novaEstrela->massa);                                                              // -> Lê e atribui a massa e limpa o buffer
    getchar();                                                                                       // | 
    scanf("%lld", &novaEstrela->raio);                                                               // -> Lê e atribui o raio e limpa o buffer
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

int removerEstrela(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControleEstrelas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nA estrela de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return 1;                                                                                       // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela aux = {};                                                                                   // -> Auxiliar para a limpeza da estrela

    /*Remoção da estrela*/                                                                                  // -> Obs: index controle está sempre "apontando" para o próximo termo do array, por isso foi decrementado
    sistema->estrelas[indice - 1] = sistema->estrelas[sistema->indexControleEstrelas - 1];              // -> Troca a estrela a ser removida pela última
    sistema->estrelas[sistema->indexControleEstrelas - 1] = aux;                                        // -> Limpa a matriz que foi trocada, ficando um "buraco"

    /*Atualiza a ordenação*/
    sistema->isOrdenadoEstrelas = 0;                                                                    // -> Atualiza a ordenação, estrela deixa de ser ordenada

    /*Atualização das variáveis*/                                       
    sistema->indexControleEstrelas--;                                                                   // -> Remove a estrela do valor de controle
    sistema->quantidadeEstrelas--;                                                                      // -> Remove uma estrela

    return 0;                                                                                           // -> Marca como operação bem sucedida
}

void redimensionarArrayEstrelas(SistemaPlanetario* sistema, int aumentoCapacidade)
{   
    /*Atribui aumento à capacidade*/
    sistema->capacidadeEstrelas += aumentoCapacidade;                                                              // -> Aumenta a capacidade com base no aumento

    /*Realoca o array*/
    sistema->estrelas = (Estrela*) realloc(sistema->estrelas, sizeof(Estrela) * sistema->capacidadeEstrelas);      // -> Realoca o array de acordo com a capacidade de estrelas

    /*Fim*/
    return;
}

int adicionarPlaneta(SistemaPlanetario* sistema)
{
    /*Verifica se já atingiu o limite*/
    if(sistema->indexControlePlanetas >= sistema->capacidadePlanetas)
    {
        printf("\nAtingiu-se a capacidade maxima de planetas\n");                                       // -> Verifica se já atingiu a capacidade máxima de planetas alocados
        return 1;                                                                                       // | 
    }

    /*Variáveis*/
    Planeta novoPlaneta = {};                                                                           // -> Cria o auxiliar para a leitura

    /*Lê os inputs do planeta*/
    lerTerminalPlaneta(&novoPlaneta);                                                                   // -> Lê os inputs do terminau e atribui ao auxiliar
    lerTerminalDescricaoPlaneta(&novoPlaneta.infos);                                                    // | 

    /*Adiciona o planeta ao vetor*/
    sistema->planetas[sistema->indexControlePlanetas] = novoPlaneta;                                    // -> Atribui o planeta ao array

    /*Atualiza o valor do controle*/
    sistema->indexControlePlanetas++;                                                                   // -> Passa para o "próximo" planeta
    sistema->quantidadePlanetas++;                                                                      // -> incrementa o planeta inserido

    /*Fim*/
    return 0;                                                                                           // -> Marca como operação bem sucedida
}

void lerTerminalPlaneta(Planeta* novoPlaneta)
{
    /*Pede os inputs*/
    printf("\n/- Digite: -/\n");                                                                        // -> Pede os inputs para o planeta
    printf("- O nome do planeta\n");                                                                    // |  <- REVISAR NO EXERCÍCIO
    printf("- A temperatura media do planeta em Celsius\n");                                            // | 
    printf("- A quantidade de satelites naturais do planeta (luas)\n");                                 // | 
    printf("- A quantidade de satelites artificiais do planeta\n");                                     // | 
    printf("- A quantidade de aneis do planeta\n");                                                       // | 
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
    scanf("%lld", &novoPlaneta->massa);                                                                  // | 
    getchar();                                                                                           // | 
    scanf("%lld", &novoPlaneta->raio);                                                                   // | 
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
    printf("- Uma descricao geral do planeta\n");                                                       // -> Pede os inputs
    printf("- O nome do descobridor do planeta\n");                                                     // | 
    printf("- A data da descoberta do planeta (formato: DD/MM/AAAA)\n");                                // | 
    printf("- O codigo cientifico do planeta\n");                                                       // | 

    fgets(novaDescricao->sobrePlaneta, 500, stdin);                                                     // -> Lê, atribui e formata o input
    novaDescricao->sobrePlaneta[strcspn(novaDescricao->sobrePlaneta, "\n")] = '\0';                     // | 
    fgets(novaDescricao->descobridor, 100, stdin);                                                      // -> Lê, atribui e formata o input
    novaDescricao->descobridor[strcspn(novaDescricao->descobridor, "\n")] = '\0';                       // | 
    fgets(novaDescricao->dataDescoberta, 20, stdin);                                                    // -> Lê, atribui e formata o input
    novaDescricao->dataDescoberta[strcspn(novaDescricao->dataDescoberta, "\n")] = '\0';                 // | 
    fgets(novaDescricao->codigoPlaneta, 20, stdin);                                                     // -> Lê, atribui e formata o input
    novaDescricao->codigoPlaneta[strcspn(novaDescricao->codigoPlaneta, "\n")] = '\0';                   // |   <- REVISAR NO EXERCÍCIO
}

int removerPlaneta(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControlePlanetas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nO planeta de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return 1;                                                                                       // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta aux = {};                                                                                   // -> Auxiliar para a limpeza do planeta

    /*Remoção do planeta*/                                                                                  // -> Obs: index controle está sempre "apontando" para o próximo termo do array, por isso foi decrementado
    sistema->planetas[indice - 1] = sistema->planetas[sistema->indexControlePlanetas - 1];              // -> Troca o planeta a ser removido pela último
    sistema->planetas[sistema->indexControlePlanetas - 1] = aux;                                        // -> Limpa a matriz que foi trocada, ficando um "buraco"

    /*Atualiza a ordenação*/
    sistema->isOrdenadoPlanetas = 0;                                                                    // -> Atualiza a ordenação, planeta deixa de ser ordenado

    /*Atualização das variáveis*/                                       
    sistema->indexControlePlanetas--;                                                                   // -> Remove o planeta do valor de controle
    sistema->quantidadePlanetas--;                                                                      // -> Decrementa o planeta

    return 0;                                                                                           // -> Marca como operação bem sucedida
}

void redimensionarArrayPlanetas(SistemaPlanetario* sistema, int aumentoCapacidade)
{
    /*Atribui aumento à capacidade*/
    sistema->capacidadePlanetas += aumentoCapacidade;                                                              // -> Aumenta a capacidade com base no aumento

    /*Realoca o array*/
    sistema->planetas = (Planeta*) realloc(sistema->planetas, sizeof(Planeta) * sistema->capacidadePlanetas);      // -> Realoca o array de acordo com a capacidade de planetas

    /*Fim*/
    return;
}

void exibirSistemaPlanetario(SistemaPlanetario* sistema)
{
    /*Printa os dados*/
    printf("\n/* %s */\n", sistema->nomeSistema);                                                       // -> Printa os dados mais relevantes do sistema planetario (planetas e estrelas é no listar)
    printf("- %d estrelas\n", sistema->quantidadeEstrelas);                                             // | 
    printf("    >> Com capacidade para %d estrelas\n", sistema->capacidadeEstrelas);                    // | 
    printf("- %d planetas\n", sistema->quantidadePlanetas);                                             // | 
    printf("    >> Com capacidade para %d planetas\n", sistema->capacidadePlanetas);                    // | 

    /*Exibe as estrelas*/
    listarEstrelas(sistema);                                                                            // -> Imprime as estrelas

    /*Exibe os planetas*/
    listarPlanetas(sistema);                                                                            // -> Imprime os planetas

    /*Fim*/
    return;
}

void exibirEstrela(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControleEstrelas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nA estrela de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return;                                                                                         // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) &sistema->estrelas[indice - 1];                                  // -> Variável auxiliar para a impressão

    /*Printa os dados*/
    printf("\n/* %s */\n", buscaEstrela->nomeEstrela);                                                  // -> Printa os dados da estrela
    printf("- Massa de %lldkg\n", buscaEstrela->massa);                                                 // | 
    printf("- Raio de %lldkm\n", buscaEstrela->raio);                                                   // | 
    printf("- Superficie com temperatura de %0.2fK\n", buscaEstrela->temperaturaSuperficie);            // | 
    printf("- Luminosidade relativa ao Sol de %0.2f\n", buscaEstrela->luminosidade);                    // | 
    printf("- Tipo estelar %s\n", buscaEstrela->tipoEstelar);                                           // | 
    printf("- Cor predominantemente %s\n", buscaEstrela->cor);                                          // | 
    printf("- Idade de %0.2f bilhões de anos\n", buscaEstrela->idade);                                  // | 

    /*Fim*/
    return;
}

void exibirPlaneta(SistemaPlanetario* sistema, int indice)
{
    /*Verifica se o indice existe*/
    if(indice - 1 >= sistema->indexControlePlanetas)
    {                                                                                                       // -> Obs: Como o index é para o "proximo", não sendo alocado ainda, ser maior ou igual -> não existe
        printf("\nO planeta de indice %d nao existe\n", indice);                                        // -> Verifica se o indice existe para não causar erro
        return;                                                                                         // | 
    }

    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta* buscaPlaneta = (Planeta*) &sistema->planetas[indice - 1];                                              // -> Variáveis auxiliares para a impressão
    DescricaoInfos* buscaDescricao = (DescricaoInfos*) &buscaPlaneta->infos;                                        // | 

    /*Printa os dados*/
    printf("\n/* %s */\n", buscaPlaneta->nomePlaneta);                                                              // -> Imprime as propriedades do planeta
    printf("- Temperatura media de %0.2f Celsius\n", buscaPlaneta->temperaturaMedia);                               // | 
    printf("- %d satelites naturais\n", buscaPlaneta->quantidade_SatelitesNaturais);                                // | 
    printf("- %d satelites artificiais\n", buscaPlaneta->quantidade_SatelitesArtificiais);                          // | 
    printf("- %d aneis em sua orbita\n", buscaPlaneta->quantidade_Aneis);                                           // | 
    printf("- Umidade media de %0.2f%%\n", buscaPlaneta->umidadeMedia);                                             // | 
    printf("- Massa de %lldkg\n", buscaPlaneta->massa);                                                             // | 
    printf("- Raio de %lldkm\n", buscaPlaneta->raio);                                                               // | 
    printf("- Ano com duracao de %0.2f dias terrestres\n", buscaPlaneta->duracaoAno);                               // | 
    printf("- Dia com duracao de %0.2f horas\n", buscaPlaneta->duracaoDia);                                         // | 
    printf("- Distancia ate a estrela de %0.2f UA (Unidades Astronomicas)\n", buscaPlaneta->duracaoDia);            // | 

    printf("\n>> Descricao geral -> %s\n", buscaDescricao->sobrePlaneta);                                           // -> Imprime a descrição do planeta
    printf(">> Descobridor -> %s\n", buscaDescricao->descobridor);                                                  // | 
    printf(">> Data da descoberta -> %s\n", buscaDescricao->dataDescoberta);                                        // | 
    printf(">> Codigo do planeta -> %s\n", buscaDescricao->codigoPlaneta);                                          // | 

    /*Fim*/
    return;
}

void listarEstrelas(SistemaPlanetario* sistema)
{
    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoEstrelas == 0) 
    {
        ordenarEstrelas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoEstrelas = 1;                                                                // | 
    }

    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                               // -> Cria o auxiliar

    /*Imprime o título*/
    printf("\n/- Estrelas -/\n");                                                                       // -> Imprime o título

    /*Loop para imprimir as estrelas*/
    for(int i = 0; i < sistema->indexControleEstrelas; i++)
    {
        printf("%d - %s\n", i + 1, buscaEstrela[i].nomeEstrela);                                        // -> Imprime estrela por estrela
    }

    /*Imprime o formato*/
    printf("\n[indice] - [nome da estrela]\n\n");                                                       // -> Imprime o formato

    /*Fim*/
    return;
}

void listarPlanetas(SistemaPlanetario* sistema)
{
    /*Verifica se não está ordenado*/
    if(sistema->isOrdenadoPlanetas == 0) 
    {
        ordenarPlanetas(sistema);                                                                       // -> Se não estiver ordenado, ordena
        sistema->isOrdenadoPlanetas = 1;                                                                // | 
    }

    /*Variáveis*/
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                               // -> Cria o auxiliar

    /*Imprime o título*/
    printf("\n/- Planetas -/\n");                                                                       // -> Imprime o título

    /*Loop para imprimir os planetas*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        printf("%d - %s\n", i + 1, buscaPlaneta[i].nomePlaneta);                                        // -> Imprime planeta por planeta
        printf("    >> %s\n", buscaPlaneta[i].infos.codigoPlaneta);                                     // | 
    }

    /*Imprime o formato*/
    printf("\n[indice] - [nome do planeta]\n");                                                         // -> Imprime o formato
    printf("    >> [codigo do planeta]\n\n");                                                           // | 

    /*Fim*/
    return;
}   


void ordenarEstrelas(SistemaPlanetario* sistema)
{
    /*Variáveis*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                               // -> Cria variáveis auxiliares
    Estrela aux = {};                                                                                   // | 

    /*Ordena o vetor alocado*/
    for(int i = 0; i < sistema->indexControleEstrelas - 1; i++)
    {
        for(int j = i + 1; j < sistema->indexControleEstrelas; j++)
        {
            if(strcmp(buscaEstrela[j].nomeEstrela, buscaEstrela[i].nomeEstrela) == -1)                  // -> Verifica se a estrela posterior vem primeiro alfabeticamente
            {
                aux = buscaEstrela[i];                                                                  // -> Troca a estrela se ela vier alfabeticamente primeiro
                buscaEstrela[i] = buscaEstrela[j];                                                      // | 
                buscaEstrela[j] = aux;                                                                  // | 
            }
        }
    }

    /*Fim*/
    return;
}

void ordenarPlanetas(SistemaPlanetario* sistema)
{
    /*Variáveis*/
    int matrizVerificacao[26] = {};                                                                     // -> Matriz que guarda a análise da verificação no código do planeta
    int indexMaxCodigoPlaneta = 0;                                                                      // -> Variáveis para vericação da letra no código do planeta 
    int letraCodigoPlaneta = 0;                                                                         // | 
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                               // -> Auxiliar para a escrita do código
    Planeta* matrizForma = NULL;                                                                        // -> Matriz que guarda a ordenação e substitui a original

    /*Analisa o vetor alocado*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)
    {
        indexMaxCodigoPlaneta = strlen(buscaPlaneta[i].infos.codigoPlaneta) - 1;                        // -> Pega o index max, ou seja, o local da letra

        letraCodigoPlaneta = buscaPlaneta[i].infos.codigoPlaneta[indexMaxCodigoPlaneta];                // -> Pega a letra

        matrizVerificacao[letraCodigoPlaneta - 97] = i;                                                 // -> Armazena na matriz de análise por meio da letra -> 'a' = 0
    }

    /*Aloca a matriz para o uso*/
    matrizForma = (Planeta*) calloc(sistema->indexControlePlanetas + 1, sizeof(Planeta));               // -> Aloca a matriz que irá substituir

    /*Ordena a matriz com base na matriz verificação*/
    for(int i = 0; i < sistema->indexControlePlanetas; i++)                                            
    {
        matrizForma[i] = sistema->planetas[matrizVerificacao[i]];                                       // -> Armazena de acordo com a ordem na matriz de análise
    }

    /*Libera a memória alocada da matriz original*/
    free(sistema->planetas);                                                                            // -> Libera a memória da matriz original

    /*A matriz forma se torna a original*/
    sistema->planetas = matrizForma;                                                                    // -> Troca o endereço pelo da matriz de molde (substitui a original)

    /*Fim*/
    return;
}

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
        fwrite(&buscaEstrela[i].massa, sizeof(long long int), 1, fileSistema);                                  // | 
        fwrite(&buscaEstrela[i].raio, sizeof(long long int), 1, fileSistema);                                   // | 
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
        fwrite(&buscaPlaneta[i].massa, sizeof(long long int), 1, fileSistema);                                  // | 
        fwrite(&buscaPlaneta[i].raio, sizeof(long long int), 1, fileSistema);                                   // | 
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

    /*Variáveis auxiliares*/
    Estrela* buscaEstrela = (Estrela*) sistema->estrelas;                                                      // -> Variáveis auxiliares
    Planeta* buscaPlaneta = (Planeta*) sistema->planetas;                                                      // | 
    DescricaoInfos* buscaDescricao = NULL;                                                                     // | 

    /*Lê e atribui os valores às estrelas, com base no index*/
    for(int i = 0; i < sistema->indexControleEstrelas; i++)
    {
        fread(buscaEstrela[i].nomeEstrela, 50, 1, fileSistema);                                                // -> Lê e atribui as informações para cada estrela
        fread(&buscaEstrela[i].massa, sizeof(long long int), 1, fileSistema);                                  // | 
        fread(&buscaEstrela[i].raio, sizeof(long long int), 1, fileSistema);                                   // | 
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
        fread(&buscaPlaneta[i].massa, sizeof(long long int), 1, fileSistema);                                  // | 
        fread(&buscaPlaneta[i].raio, sizeof(long long int), 1, fileSistema);                                   // | 
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