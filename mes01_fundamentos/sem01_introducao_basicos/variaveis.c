#include <stdio.h>

int main(){
    // Declaração e inicialização de variáveis
    int idade = 33;
    float altura = 1.82f;
    char sexo = 'M';
    double pi = 3.1415926535;
    
    // Imprimindo
    printf("---- Meus Dados ----\n");
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura); //Ver Nota 1
    printf("Sexo: %c\n", sexo);
    printf("Numero favorito: %.2lf\n", pi);

    // Tentando imprimir um float como inteiro
    printf("Altura: %d metros\n", altura); // Ver Nota 2:
    printf("%x", altura);

    return 0;
}

/*
1) %f imprime um float com uma precisão padrão (geralmente 6 casas decimais).
%.2f diz ao printf para imprimir a variável com exatamente 2 casas decimais, 
arredondando se necessário. 

2) 'altura' é uma variável de ponto flutuante de 32 bits (float). Esse número 
pode ser armazenado em uma palabra binária com três campos (+/- S x B^(+/-)E):

-> Sinal: 1 bit que diz se o número é positivo (0) ou negativo (1).
-> Expoente: 8 bits que definem a magnitude do número
-> Significado ou Mantissa: 23 bits que definem a precisão do número (os digitos em si)

_ | _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
S       Expoente                      Mantissa

Como 1.82 é positivo o sinal é 0.

1.82 tem que ser tranformado para o formato científico binário (1.algumacoisa x 2^E):
Parte Inteira = 1
Parte Fracionada
0.82 x 2 = 1.64 (Pegamos o 1)
0.64 x 2 = 1.28 (Pegamos o 1)
0.28 x 2 = 0.56 (Pegamos o 0)
0.56 x 2 = 1.12 (Pegamos o 1)
0.12 x 2 = 0.24 (Pegamos o 0)
0.24 x 2 = 0.48 (Pegamos o 0)
0.48 x 2 = 0.96 (Pegamos o 0)
0.96 x 2 = 1.92 (Pegamos o 1)
0.92 x 2 = 1.84 (Pegamos o 1)
0.84 x 2 = 1.68 (Pegamos o 1)
0.68 x 2 = 1.36 (Pegamos o 1)
0.36 x 2 = 0.72 (Pegamos o 0)
0.72 x 2 = 1.44 (Pegamos o 1)
0.44 x 2 = 0.88 (Pegamos o 0)
0.88 x 2 = 1.76 (Pegamos o 1)
0.76 x 2 = 1.52 (Pegamos o 1)
0.52 x 2 = 1.04 (Pegamos o 1)
0.04 x 2 = 0.08 (Pegamos o 0)
0.08 x 2 = 0.16 (Pegamos o 0)
0.16 x 2 = 0.32 (Pegamos o 0)
0.32 x 2 = 0.64 (Pegamos o 0)
0.64 x 2 = 1.28 (Pegamos o 1)
0.28 x 2 = 0.56 (Pegamos o 0)   -> 23º bit
0.56 x 2 = 1.12 (Pegamos o 1)   -> 24 bit

1.82 = 1.110100011110101110000101 x 2^0 em binário, assim o expoente é 0. 
Contudo o expoente não é armazenado como 0. Para poder representar expoentes 
positivos e negativos, soma-se um valor fixo chamado "bias" (deslcamento) que para 
float é 127. Assim o expoente  armazenado é 0 + 127 = 127 (0111 1111).

A mantissa são os dígitos que vêm depois da vírgula na nossa forma normalizada.
Não podemos simplismente truncar no 23º bit. O padrão IEEE 754 estabelece que 
se o primeiro bit a ser descartado é 1, arredonde o último bit mantido para cima.
Assim, como o 24º bit é 1, arredonda-se o 23º bit para 1.

0 | 0 1 1 1 1 1 1 1 | 1 1 0 1 0 0 0 1 1 1 1 0 1 0 1 1 1 0 0 0 0 1 1
 





*/