#include <stdio.h>
#include <string.h>

char minusculaParaMaiuscula (char letra){
    if (letra>= 97 && letra<=122) {
        letra -= 32;
    } 
    return letra;
}

char maiusculaParaMinuscula (char letra){
    if (letra>= 65 && letra<=90) {
        letra += 32;
    }
    return letra;
}

int main() {

    char frase[50];

    printf ("Digite uma frase: ");
    gets (frase);

    int tamanho = strlen(frase);

    for (int i=0; i<tamanho; i++){
        frase[i] = minusculaParaMaiuscula(frase[i]);
    }

    printf ("%s\n", frase);

    for (int i=0; i<tamanho; i++) {
        frase[i] = maiusculaParaMinuscula(frase[i]);
    }

    printf ("%s\n", frase);
    
 return 0;   
}

