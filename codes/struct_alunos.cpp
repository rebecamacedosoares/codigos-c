#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM_CPF  14
#define TAM_NOME 40
#define TRUE     1

typedef struct {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
} DATA;

typedef struct {
    int matricula;
    char cpf[TAM_CPF + 1];
    char nome[TAM_NOME + 1];
    DATA dataNasc;
} ALUNO;


// Variáveis Globais

int     tamArquivo;

//---------------------------------------------------------------------------------------------------//

void escreverRegistros() {
    FILE*   arquivo = fopen("alunos.dat","ab"); // "ab" -> 'append' 'binary'
    while(TRUE) {
        ALUNO umAluno;
       
        printf("Entre com os dados do Aluno ou tecle [0] na matrícula para terminar\n");
        printf("===================================================================\n");

        printf("Entre com a matricula do Aluno: ");
        scanf("%d",&umAluno.matricula);
        fflush(stdin);
       
        if(umAluno.matricula == 0)
            break;
           
        printf("Entre com o cpf do Aluno: ");
        gets(umAluno.cpf);
        fflush(stdin);
       
        printf("Entre com o nome do Aluno: ");
        gets(umAluno.nome);        
        fflush(stdin);
       
        printf("Entre com o dia de nascimento do Aluno: ");
        scanf("%d",&umAluno.dataNasc.dia);
        fflush(stdin);
   
        printf("Entre com o mes de nascimento do Aluno: ");
        scanf("%d",&umAluno.dataNasc.mes);
        fflush(stdin);
   
        printf("Entre com o ano de nascimento do Aluno: ");
        scanf("%d",&umAluno.dataNasc.ano);
        fflush(stdin);
       
        fwrite(&umAluno, sizeof(ALUNO), 1, arquivo);
    }
    fclose(arquivo);
}

//---------------------------------------------------------------------------------------------------//

int tamanhoArquivo(char* nomeArquivo) {
    FILE*   arquivo = fopen(nomeArquivo,"rb");
    fseek(arquivo,0,SEEK_END);
    int tamanho = ftell(arquivo);    
    fclose(arquivo);
    return tamanho;
}

//---------------------------------------------------------------------------------------------------//

void lerRegistros(ALUNO* atual) {
    FILE*   arquivo = fopen("alunos.dat","rb");
    int     pos = 0;
    while(TRUE) {
        int tam = fread(atual, sizeof(ALUNO), 1, arquivo);
        if(tam == 0)
            break;
        pos++;
        atual++;
    }
    fclose(arquivo);
}

//---------------------------------------------------------------------------------------------------//

void imprimirRegistros(ALUNO* atual) {
    int numRegistros = tamArquivo / sizeof(ALUNO);
   
    printf("========================================================================\n");
    printf("O arquivo tem %d bytes, logo tem %d registros\n", tamArquivo, numRegistros);
    printf("========================================================================\n\n");

    for(int i = 0; i < numRegistros; i++) {        
        printf("Matricula: %d\nCpf: %s\nNome: %s\nData de Nascimento: %02d/%02d/%4d\n",
            atual->matricula, atual->cpf, atual->nome,
            atual->dataNasc.dia, atual->dataNasc.mes,atual->dataNasc.ano);
        printf("========================================================================\n");
        atual++;
    }
}
//---------------------------------------------------------------------------------------------------//

void ordenar(ALUNO* lista) {

    int numRegistros = tamArquivo / sizeof(ALUNO);
    for(int i = 0; i < numRegistros; i++) {
        int posMenor = i;
        for(int j = i + 1; j < numRegistros; j++) {
            if(strcmp(lista[j].nome, lista[posMenor].nome) < 0)
                posMenor = j;
        }
        ALUNO aux;
       
        memcpy(&aux, &lista[i], sizeof(ALUNO));
        memcpy(&lista[i], &lista[posMenor], sizeof(ALUNO));
        memcpy(&lista[posMenor], &aux, sizeof(ALUNO));
    }
}

//---------------------------------------------------------------------------------------------------//

int main() {
    escreverRegistros();
    tamArquivo = tamanhoArquivo("alunos.dat");
   
    // Alocação Estática usando variável para determinar o tamanho do array
    ALUNO  listaAlunos[tamArquivo / sizeof(ALUNO)];
   
    lerRegistros((ALUNO*)&listaAlunos);
   
    imprimirRegistros((ALUNO*)&listaAlunos);
   
    ordenar((ALUNO*)&listaAlunos);
   
    imprimirRegistros((ALUNO*)&listaAlunos);
}


