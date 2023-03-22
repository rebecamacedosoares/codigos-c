#include <stdio.h>
#include <string.h>

int igual(char* ptrA, char* ptrB){
	int pos = 0;
	
	while(ptrA[pos] != 0 || ptrB[pos] != 0){
		if(ptrA[pos] != ptrB[pos]){
			printf("\nDiferente na posicao %d\n", pos);
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
	
	igual(ptrA, ptrB);
		
	return 0;
}
