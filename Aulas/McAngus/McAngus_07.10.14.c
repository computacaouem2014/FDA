#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define linhas 5
#define colunas 5

void printMatrix(int m, int n, int arr[m][n]){
    if (m*n > n){
        printf("\n⎡");
        for (int j = 0; j < n; j++){
            printf("%6d ", arr[0][j]);
        }
        printf("⎤\n");
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("       ");
        }
        printf("⎥\n");
        for (int i = 1; i < m-1; i++){
            if (i != 1){
                printf("⎢");
                for (int k = 0; k < n; k++){
                    printf("       ");
                }
                printf("⎥\n");
            }
            printf("⎢");
            for (int j = 0; j < n; j++){
                printf("%6d ", arr[i][j]);
            }
            printf("⎥\n");
        }
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("       ");
        }
        printf("⎥\n");
        printf("⎣");
        for (int j = 0; j < n; j++){
            printf("%6d ", arr[m-1][j]);
        }
        printf("⎦\n\n");
    } else if (m == 1){
        printf("\n[");
        for (int i = 0; i < n; i++){
                printf("%6d ", arr[0][i]);
        }
        printf("]\n\n");
    } else {
        printf("\n[]\n\n");
    }
}



void printArray(int size, int a[size]){
    if (size > 0){
        printf("\n[%d,", a[0]);
        for (int i = 1; i < size-1; i++) printf(" %d,", a[i]);
        printf(" %d]\n", a[size-1]);
    } else printf("\n[]\n");
}

void ex1(){
	int valor, m[linhas][colunas];
	for (int k = 0; k < linhas; k++){
		for (int j = 0; j < colunas; j++){
			printf("[%d][%d]: ", k, j);
			scanf("%d", &m[k][j]);
		}
	}
	printf("Digite um valor: ");
	scanf("%d", &valor);
	for (int k = 0; k < linhas; k++){
		for (int j = k + 1; j < colunas; j++){
			m[k][j] = valor;
		}
	}
	printMatrix(linhas, colunas, m);
}

void ex2(){
	int m[3][4], b[3][4];
	for (int k = 0; k < 3; k++){
                for (int j = 0; j < 4; j++){
                        printf("[%d][%d]: ", k, j);
                        scanf("%d", &m[k][j]);
			if (m[k][j]%2 == 0)	b[k][j] = 2 * m[k][j];
			else b[k][j] = 3 * m[k][j];
                }
        }
	printf("Matriz Original:\n");
	printMatrix(3, 4, m);
	printf("Matriz B:\n");
	printMatrix(3, 4, b);
}

void ex3(){
	int l = 4, c = 4;
	int m[l][c], soma = 0;
        for (int k = 0; k < l; k++){
                for (int j = 0; j < c; j++){
                        printf("[%d][%d]: ", k, j);
                        scanf("%d", &m[k][j]);
                }
        }
        for (int k = l - 1; k >= 0; k--){
                for (int j = c - k ; j < c; j++){
                        soma += m[k][j]*m[k][j] ;
                }
        }
        printMatrix(l, c, m);
	printf("%f.\n", sqrt(soma));
}


int main(){
	ex3();
	return 0;
}
