#include <stdio.h>
#include <string.h>

#define TAM 7

int valorRomano(char c){
	char digitos[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int valores[] = {1, 5, 10, 50, 100, 500, 1000};
	
	for(int i=0; i<TAM; i++){
		if(digitos[i] == c){
			return valores[i];
		}
	}
	return 0;
}

int main() {

	char numRomano[40];
	int resultado = 0;
	int valor = 0;
	int valorDigitoAnterior = 0;
	
	printf("Digite um numero romano (em maiusculo): ");
	gets(numRomano);
	
	
	for(int i = 0; i < strlen(numRomano); i++){
		char c = numRomano[i];
		valor = valorRomano(c);
		
		if(valor == 0){
			printf("Numero invalido\n");
		}
		if(valor > valorDigitoAnterior){
			valorDigitoAnterior = -valorDigitoAnterior;
		}
		if(i>0){
			resultado += valorDigitoAnterior;
		}
		valorDigitoAnterior = valor;		
	}
	resultado += valorDigitoAnterior;
	
	if(valor != 0){
		printf("Valor: %d", resultado);
	}
	
	return 0;
}

