# Meu Treinamento de 3 Meses em Linguagem C

Este repositório documenta minha jornada de aprendizado da linguagem C, seguindo um plano de estudos de 3 meses. Aqui estarão todos os meus códigos, anotações e o projeto final.

---

## Diário de Aprendizado

### Mês 1: Fundamentos

**Semana 1: Introdução e Conceitos Básicos**

* **Dia 1 (17/08/2025):** Aprendi sobre a história da linguagem C e sua importância. Configurei meu ambiente de desenvolvimento com o compilador Clang.
    * **O que aprendi:** C é um linguagem de programação procedural (organizados em procedimentos/funções), compilada (é necessário que o compiladoor, neste caso o clang no MacOs, transforme o código em um executável) de propósito geral.
    
    Foi criada por Dennis Ritchie no bell Labs em 1972 para o desenvolvimento do sistema operacional Unix. É uma evolução da linguagem B.

    C permite o controle de hardware de forma muito direta, especialmente o gerenciamento de memória através de ponteiros.

    Aprendi a estrutura básica de um programa em C: a diretiva `#include` para usar bibliotecas, a função `main()` como ponto de entrada, a função `printf()` para exibir texto e a importância do `return 0;`. Também entendi o processo de compilação (transformar código `.c` em um executável) e execução.

    **Ação Prática:** Revisei a instalação das ferramentas de linha de comando do Xcode no meu Mac. O compilador `clang` e o `git` estão instalados e funcionando corretamente. O VS Code com a extensão C/C++ também está pronto.

    Criei o arquivo `ola_mundo.c`, compilei com `clang -o ola_mundo ola_mundo.c` e executei com `./ola_mundo`. O programa funcionou perfeitamente!

    * **Código:** [Link para o código](mes01_fundamentos/sem01_introducao_basicos/ola_mundo.c)

    * **Dificuldades:** Prestar atenção para não esquecer o ponto e vírgula `;` no final das instruções.

* **Dia 02 (18/08/2025): Variáveis, Tipos de Dados e Uma Profunda Análise da Memória**

    * **Tópico Planejado - O Básico:**
        * Aprendi o que é uma variável e como declará-la e inicializá-la em C.
        * Estudei os tipos de dados fundamentais: `int` para inteiros, `float`/`double` para decimais e `char` para caracteres.
        * Pratiquei o uso de especificadores de formato (`%d`, `%f`, `%.2f`, `%c`) para imprimir os valores das variáveis com `printf`.

    * **Exploração Avançada (Investigação Pessoal):**
        * **Comportamento Indefinido:** Através de um experimento prático, descobri o que acontece ao tentar imprimir uma variável `float` usando o especificador `%d`. O resultado foi um número inteiro gigante, o que me levou a investigar a causa.
        * **Representação de Inteiros:** Aprendi como os números inteiros (`int`) são armazenados na memória. Para números positivos, é uma conversão direta para binário. Para números negativos, utiliza-se o sistema de **Complemento de Dois**, que envolve inverter os bits e somar 1.
        * **Representação de Ponto Flutuante (O Grande Mergulho):** Aprofundei-me no complexo padrão **IEEE 754** para entender como um `float` é armazenado. Aprendi a dividir os 32 bits em suas três partes constituintes:
            1.  **Sinal (1 bit):** `0` para positivo, `1` para negativo.
            2.  **Expoente (8 bits):** Usa um "bias" (127) para representar a magnitude do número.
            3.  **Mantissa (23 bits):** Armazena a precisão (os dígitos) do número, utilizando um "1" implícito para economizar espaço.
        * **Aplicação Prática:** Realizei a conversão manual completa do número `1.82` para sua representação binária de 32 bits, incluindo o cálculo da mantissa e do expoente com bias, e discuti as regras de arredondamento.
        * **A Grande Síntese:** Concluí o dia entendendo que uma mesma sequência de 32 bits pode representar tanto o número `1.82` (se lida como `float`) quanto o número `1.072.833.859` (se lida como `int`). Isso solidificou o conceito de que os **bits não têm significado próprio; o tipo de dado é a regra que lhes dá significado.**

    * **Código:** [Link para o código de variáveis](Mês1_Fundamentos/Semana1_Introducao_Basicos/variaveis.c)
    * **Dificuldades:** A complexidade inicial do padrão IEEE 754, mas a conversão manual passo a passo tornou o conceito muito mais claro.

*(Continue o diário aqui a cada dia)*