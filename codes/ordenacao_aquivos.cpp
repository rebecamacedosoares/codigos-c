#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define TAMANHO_ARRAY 80
#define TAMANHO_PALAVRA 80

int main() {
    FILE*   arquivoLeitura;
   	FILE* arquivoOrdenado;

    
	char palavras[TAMANHO_ARRAY][TAMANHO_PALAVRA];
	
	int numPalavras = 0;
	
	arquivoLeitura = fopen("C:\\path\\file.txt","r");    

    while(TRUE) {
        if(fgets(palavras[numPalavras], TAMANHO_PALAVRA, arquivoLeitura) == NULL)
            break;
        numPalavras++;
    }
    fclose(arquivoLeitura);


	arquivoOrdenado = fopen("C:\\path\\new_file.txt","w");

	for(int i=0; i<numPalavras; i++){
		int posMenor = i;
		for(int j=i+1; j<numPalavras; j++){
			if(strcmp(palavras[j], palavras[posMenor]) < 0)
				posMenor = j;
		}
		char aux[TAMANHO_PALAVRA];
		
		strcpy(aux, palavras[i]);
		strcpy(palavras[i], palavras[posMenor]);
		strcpy(palavras[posMenor], aux);
	}
	
	printf("\n======================================\n");
    printf("\nO arquivo tem %d palavras!\n", numPalavras);
	printf("\n======================================\n\n");
	
	for(int i=0; i<numPalavras; i++){
		fprintf(arquivoOrdenado, "%s\n", palavras[i]);
		printf("%s\n", palavras[i]);
	}
	
	fclose(arquivoOrdenado);

}

