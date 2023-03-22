#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void troca(int arr[], int posA, int posB){
	int aux = arr[posA];
	arr[posA] = arr[posB];
	arr[posB] = aux;
}

int main(){
	int numeros[] = {13, 31, 12, 24, 15, 8, 1, 303, 80, 808};
	
	for(int i=0; i<10; i++){
		if(i>0){
			if(numeros[i-1]>numeros[i]){
				troca(numeros, i-1, i);
				i-=2;
			}
		}
	}
	
	for(int i=0; i<10; i++){
		printf("%3d\n", numeros[i]);
	}
	
	return 0;
}

