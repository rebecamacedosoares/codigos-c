#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int acharMenor(int arr[], int posInicio){
	int menorValor = arr[posInicio];
	int posMenor = posInicio;
	
	for(int i=posInicio; i<5; i++){
		if(arr[i]<menorValor){
			menorValor = arr[i];
			posMenor = i;
		}
	}
	return posMenor;
}

void troca(int arr[], int posA, int posB){
	int aux = arr[posA];
	arr[posA] = arr[posB];
	arr[posB] = aux;
}

int main(){
	int numeros[] = {220, 340, 501, 101, 303};
	
	for(int i=0; i<5; i++){
		int posMenor = acharMenor(numeros, i);
		troca(numeros, i, posMenor);
	}
	
	for(int i=0; i<5; i++){
		printf("%d\n", numeros[i]);
	}
	
	return 0;
}

