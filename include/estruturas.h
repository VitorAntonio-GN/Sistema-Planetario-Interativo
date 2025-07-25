#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/* ---------------------- Structs ---------------------- */

typedef struct {
    char sobrePlaneta[500];                     // Descrição geral do planeta
    char descobridor[100];                      // Nome do descobridor
    char dataDescoberta[20];                    // Data da descoberta (formato: DD/MM/AAAA)
    char codigoPlaneta[20];                     // Código científico do planeta
} DescricaoInfos;           

typedef struct {            
    char nomeEstrela[50];                       // Nome da estrela
    unsigned long long int massa;               // Massa da estrela em kg
    unsigned long long int raio;                // Raio da estrela em km
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
    unsigned long long int massa;               // Massa em kg
    unsigned long long int raio;                // Raio em km
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

#endif