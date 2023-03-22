#include <stdio.h>

int main(){
    int n = 0;
           //[linha][coluna]
    int quadrado[n][n];

    printf("Digite um valor para formar o quadrado latino: ");
    scanf("%d", &n);


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" []");
        }
        printf("\n");
    }

    return 0;
}

