#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define TAM_PALAVRAS 40

int main(void) {
	FILE* arquivoLeitura;
	FILE* arquivoOrdenado;
	
	int numPalavras = 0;
	
    arquivoLeitura = fopen("C:\\path\\file.txt","r");

	while(TRUE)	{
		char aux[TAM_PALAVRAS];
		
		if(fgets(aux,TAM_PALAVRAS,arquivoLeitura) == NULL){
			break;
		}
		numPalavras++;
	}
	fclose(arquivoLeitura);
	printf("Numero de palavras: %d\n\n", numPalavras);
	
	char palavras[numPalavras][TAM_PALAVRAS];
	
    arquivoLeitura = fopen("C:\\path\\file.txt","r");
    
	int i = 0;
	
	while(TRUE) {
		if(fgets(palavras[i], TAM_PALAVRAS, arquivoLeitura) == NULL){
			break;
		}
		i++;
	}
	fclose(arquivoLeitura);
	
	//--------------------------------------------------------------------------------------------------------------------
	
	arquivoOrdenado = fopen("C:\\path\\new_file.txt","w");
	
	for(int i = 0; i < numPalavras; i++){
		int posMenor = i;
		for(int j = i + 1; j < numPalavras; j++){
			if(strcmp(palavras[j],palavras[posMenor]) < 0){
				posMenor = j;
			}
		}
		char aux[TAM_PALAVRAS];
		
		strcpy(aux,palavras[i]);
		strcpy(palavras[i],palavras[posMenor]);
		strcpy(palavras[posMenor],aux);
	}
	
	for(int i = 0; i < numPalavras; i++){
		fprintf(arquivoOrdenado, "%s", palavras[i]);
		printf("%s\n", palavras[i]);
	}
	
	fclose(arquivoOrdenado);
	
	return 0;
}
