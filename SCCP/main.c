/*
    ANDRE AUGUSTO MIGUEL
    ANDRE RAMOS NEVES
    VINICIUS SANTOS NUNES
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    //Implementação do Corman
	char x[10] = "ABCBDAB";
	int m = strlen(x);
	char y[10] = "BDCABA";
	int n = strlen(y);

//  printf("m = %i , n = %i \n", m,n);

	int i,j;
	int b[m][n];
	int c[m + 1][n + 1];

	for( i = 1; i <= m; i++){
		c[i][0] = 0;
	}
	for( j = 0; j <= n + 1; j ++){
		c[0][j] = 0;
	}

	for( i = 1; i <= m ; i++){
		for( j = 1; j <= n; j++){

			if(x[i - 1] == y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}else if(c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}else{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}

    //Imprimo a matriz, como está no Livro do Corman.
		printf("  ");
	for( i = 0; i <= m; i++){
        if(i == 0){
            printf("y ");
        }
		printf("%c",y[i]);
		printf(" ");
	}
		printf("\n");

    for(i = 0; i <= m; i++)	{
        if(i == 0){
            printf("x ");
        }
        printf("");
		for(j = 0; j <= n; j++){

            if( i >= 1 && j == 0){
                printf("%c",x[i - 1]);
                printf(" ");
            }
			printf("%i ",c[i][j]);
		}
        printf("\n");
	}
/*
        printf("\n");
        printf("MATRIZ B");
        printf("\n");
    for(i = 1; i <= m; i++)	{
		for(j = 0; j <= n; j++){
			printf("%i ",b[i][j]);
		}
		printf("\n");
	}
        printf("\n");
*/



	/*  A implementção é do corman, porém aqui usei iterativamente */
    printf("Palavra: ");
	int temp = n;
    for ( i = m ; i >= 0; i--){
        for ( j = temp ; j >= 0; j--){

            if (b[i][j] == 0){
                printf("%c",x[i - 1]);
                temp = j - 1;
                break;
            }else if(b[i][j] == 1){
                i = i - 1;
                j = j + 1;
                temp = j;
            }else {
                temp = j;
            }
        }
    }



	return 0;
}
