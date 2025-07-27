# 🛸 Sistema-Planetario-Interativo 🌌
_Projeto desenvolvido para praticar conceitos de structs, ponteiros, alocação dinâmica de memória e manipulação de arquivos em C. O programa permite criar, gerenciar, salvar e carregar sistemas solares compostos por estrelas e planetas com dados personalizados via menu interativo._ 

## Contexto Acadêmico 🎓
Este projeto foi desenvolvido como parte das atividades da **monitoria de Algoritmos e Estruturas de Dados I,** no curso de **Engenharia da Computação** da **UEMG, Unidade Divinópolis.**

> [!NOTE]
> **Acesse o diretório completo do projeto aqui:** [Sistema Solar Interativo](https://github.com/DiegoAntonio-M/Monitoria-AEDS1/blob/main/Projetos%20Sugeridos/SistemaSolar.md), no GitHub, sugerido pelo monitor [Diego Antônio](https://github.com/DiegoAntonio-M).

## Conceitos envolvidos 📘
- Structs compostas;
- Arrays dinâmicos;
- Alocação de memória;
- Manipulação de arquivos binários;
- Organização modular por cabeçalhos.

## Objetivos 🎯
- Praticar `structs` e `ponteiros`;
- Gerenciar memória com `calloc`/`realloc`/`free`;
- Trabalhar com arquivos binários (`fwrite`, `fread`);
- Criar um `menu interativo` com `persistência de dados`.

## Aprendizados 📚
Durante o desenvolvimento aprendi a:
- Manipular `ponteiros de structs`;
- Trabalhar com `arrays dinâmicos` realocados;
- Usar `arquivos binários` para salvar dados complexos.

## Estrutura de Diretórios 🗂️

<pre>
Sistema-Planetario-Interativo/
├── dados/
│   └── sistema_planetario.bin      // -> Arquivo binário do sistema
│
├── include/
│   └── arquivo.h                   // -> Headers do sistema
│   └── entrada.h                   // |
│   └── estrela.h                   // |
│   └── estruturas.h                // |
│   └── ordenar.h                   // |
│   └── planeta.h                   // |
│   └── saida.h                     // |
│   └── sistema.h                   // |
│
├── src/
│   └── arquivo.c                   // -> Executáveis dos headers
│   └── entrada.c                   // |
│   └── estrela.c                   // |
│   └── estruturas.c                // |
│   └── ordenar.c                   // |
│   └── planeta.c                   // |
│   └── saida.c                     // |
│   └── sistema.c                   // |
│
├── LICENSE                         // -> Licença do MIT
├── README.md                       // -> Documentação do projeto
└── main.c                          // -> Programa principal com todas as funções
</pre>

## Autor ✍️
Desenvolvido por [Vítor Antônio](https://github.com/VitorAntonio-GN).

## Licença 📄
MIT License, veja o arquivo LICENSE para mais detalhes.

## Extras 📦
<details>

<summary>Configuração da task para o VScode 🔧</summary>  
<br/> <!-- Quebra de linha, só funciona assim -->
Cole o seguinte trecho em <strong>${workspaceFolder}/.vscode/tasks.json</strong> para realizar a compilação e depuração no VScode:

<br/> <!-- Quebra de linha, só funciona assim  -->

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "HC/HC++: gcc.exe build com headers e src",
            "command": "C:\\msys64\\ucrt64\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/arquivo.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/entrada.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/estrela.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/estruturas.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/ordenar.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/planeta.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/saida.c",
                "${workspaceFolder}/Sistema-Planetario-Interativo/src/sistema.c",
                "-I${workspaceFolder}/Sistema-Planetario-Interativo/include",
                "${file}",
                "-o",
                "${workspaceFolder}/Sistema-Planetario-Interativo/${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Compila o arquivo atual com headers da pasta include e fontes auxiliares da pasta src."
        }
    ],
    "version": "2.0.0"
}
```

</details>
