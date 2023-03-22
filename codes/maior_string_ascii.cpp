#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 40

int strcmpIgnoreCase(char str1[], char str2[]) {
    int valor;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] >= 65 && str1[i] <= 90){
            str1[i] = str1[i] + 32;
        }
    }

    for(int i = 0; i < strlen(str2); i++){
        if(str2[i] >= 65 && str2[i] <= 90){
            str2[i] = str2[i] + 32;
        }
    }

    valor = strcmp(str1,str2);

    return valor;
}

int main(void) {
    char palavra1[TAM]; 
    char palavra2[TAM];
    int resultado;

    printf("Digite uma palavra: ");
    gets(palavra1);

    printf("Digite uma outra palavra: ");
    gets(palavra2);

    resultado = strcmpIgnoreCase(palavra1, palavra2);

    if(strcmpIgnoreCase(palavra1, palavra2) == 0){
        printf("\nAs strings sao iguais!");
    }
    
    else if(strcmpIgnoreCase(palavra1, palavra2) == -1){
        printf("\nA string da direita e maior (vem depois na tabela ASCII)");
    }
    
    else{
        printf("\nA string da esquerda e maior (vem depois na tabela ASCII)");
    }

    return 0;
}


