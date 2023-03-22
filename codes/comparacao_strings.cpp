#include <stdio.h>
#include <string.h>

int ehIgual(char* ptrA, char* ptrB){
	int pos = 0;
	
	while(ptrA[pos] != 0 || ptrB[pos] != 0){
		if(ptrA[pos] != ptrB[pos]){
			return 1;
		}
		pos++;
	}	
	return 0;
}

int main(void) {
	char ptrA[20];
	char ptrB[20];
	
	printf("Digite algo para ser lido: ");
	gets(ptrA);
	printf("Digite outra coisa: ");
	gets(ptrB);
	
	if(ehIgual(ptrA, ptrB) == 1){
		printf("Diferente");
	}
	else{
		printf("Igual");
	}	
		
	return 0;
}



