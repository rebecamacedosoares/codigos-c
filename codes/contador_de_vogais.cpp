#include <stdio.h>
#include <string.h>

#define TAM 7

int tamanhoString(char * frase){
	int pos = 0;
	
	while(frase[pos] != 0){
		pos++;
	}
	return pos;
}

int quantidadeVogais(char c){
	char vogais[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

	for(int i=0; i<tamanhoString(vogais); i++){
		if(c == vogais [i]){
			return 1;
		}
	}
	return 0;
}

int main() {
	char frase[40];
	int contVogais = 0;
		
	printf("Digite uma frase: ");
	gets(frase);
	
	int tamanho = tamanhoString(frase);
	
	printf("Tamanho String: %d\n", tamanho);
	
	for(int i; i<tamanho; i++){
		char c = frase[i];
		contVogais += quantidadeVogais(c);
	}
	
	printf("Vogais: %d", contVogais);
	
	return 0;
}

