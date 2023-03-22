#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int confirmadorPalindromo(char arr[],int tamanho){
    for(int i=0, j=tamanho-1; i<j ;i++, j--){
        if(arr[i] != arr[j]){
            return 0;
            break;
        }
    }
    return 1;
}

int main(){
    int tamanho;
    char arr[100];
    int resposta;

    printf("Digite uma frase: ");
    gets(arr);

    tamanho = strlen(arr);

    resposta = confirmadorPalindromo(arr, tamanho);

    
    if(resposta == 0){
    	printf("Nao e um palindromo!");
	}
	else{
		printf("Palindromo!");
	}
}

