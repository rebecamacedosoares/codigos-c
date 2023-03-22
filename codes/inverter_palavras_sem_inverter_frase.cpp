#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char frase[50];
	char fraseInvertida[50];
	int inicio = 0;
	int espaco = 0;
	
	printf("Digite uma frase: ");
	gets(frase);
	
	int tam = strlen(frase);
	
	for(int i=0; i<=tam; i++){
		if(frase[i] == ' ' || i == tam){
			int cont = inicio;
			espaco = i;
			
			for(int j=i-1; j>=inicio; j--){
				fraseInvertida[cont] = frase[j];
				cont++;
			}
			
			fraseInvertida [i] = ' ';
			inicio = espaco + 1;
		}
	}
	
	fraseInvertida[tam] = '\0';
	printf("%s", fraseInvertida);
	
	return 0;
}
