#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Cripto(char letra){
    switch (letra){
    case 'z': return 'p'; break;
    case 'e': return 'o'; break;
    case 'n': return 'l'; break;
    case 'i': return 'a'; break;
    case 't': return 'r'; break;

    case 'p': return 'z'; break;
    case 'o': return 'e'; break;
    case 'l': return 'n'; break;
    case 'a': return 'i'; break;
    case 'r': return 't'; break;

    case 'Z': return 'P'; break;
    case 'E': return 'O'; break;
    case 'N': return 'L'; break;
    case 'I': return 'A'; break;
    case 'T': return 'R'; break;

    case 'P': return 'Z'; break;
    case 'O': return 'E'; break;
    case 'L': return 'N'; break;
    case 'A': return 'I'; break;
    case 'R': return 'T'; break;

    default: return letra;
        break;
    }
}
int main(){
    char criptografia[10];
    printf("Digite ZENIT ou POLAR: ");
    gets(criptografia);

    for (int i = 0; i < strlen(criptografia); i++){
        criptografia[i] = Cripto(criptografia[i]);
    }

    printf("String: %s", criptografia);
}

