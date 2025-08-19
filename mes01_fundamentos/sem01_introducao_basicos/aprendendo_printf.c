#include <stdio.h>

int main(){
    /*
    1. Protótipo
    int printf(const char *format-string, argument-list);
    
    Retorno:
    A função retorna um inteiro que representa o número de caracteres impressos
    
    Parâmetros:
    - 'const char *format-string': é um ponteiro para o primeiro caractere de 
    uma string constante. Em C, uma string nada mais é do que um array de 
    caracteres terminados por '\0'. Quando passamos "ola" para o printf, o 
    compilador converte automaticamente essa string literal em um ponteiro 
    para o primeiro caractere.
    */
    
    //char array_strig[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    int n;
    char array_strig[] = {'H', 'e', 'l', 'l', 'o', '%', 'd', '\0'};// char array_strig[] = "Hello%d"; 
    char * p_array_string = array_strig; // o nome de um array já é convertido
    // em ponteiro para seu primeiro elemento.

    n = printf(p_array_string); // Ver nota 1
    printf("\nForam impressos %d caracteres.\n", n);
    
    n = printf("%s", p_array_string);
    printf("\nForam impressos %d caracteres.\n", n);
    
}

/*
1) Imprimir dessa forma é perigoso. O mais recomendado seria:
int n = printf("%s", p_array_string)

Suponnha que queremos imprimir 'Hello%d' no terminal.

char array_strig[] = {'H', 'e', 'l', 'l', 'o', '%', 'd', '\0'};
...  
int n = printf(p_array_string)

"%s" → diz ao printf: "pegue o próximo argumento (p_array_string), interprete como 
ponteiro para char, e imprima como string até achar um \0".

Mas passando p_array_string diretamente, o printf vai interpretar a sequencia "%d" 
como “devo imprimir um inteiro”, mas como nenhum interiro foi passado, ele pode 
imprimir lixo, travar, ou até causar segmentation fault.
*/