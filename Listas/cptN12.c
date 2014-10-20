#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

void printArray(int a[], int size) {
	if (size > 1) {
		printf("\n[");
		printf("%d", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %d", a[i]);
		printf("]\n");
	} else if (size == 1){
		printf("\n[%d]\n", a[0]);
	} else printf("\n[]\n");
}

void printMatrixI(int m, int n, int arr[m][n]){
    if (m > 1){
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

void printMatrixF(int m, int n, float arr[m][n]){
    if (m*n > n){
        printf("\n⎡");
        for (int j = 0; j < n; j++){
            printf("% 8.2f ", arr[0][j]);
        }
        printf("⎤\n");
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("         ");
        }
        printf("⎥\n");
        for (int i = 1; i < m-1; i++){
            if (i != 1){
                printf("⎢");
                for (int k = 0; k < n; k++){
                    printf("         ");
                }
                printf("⎥\n");
            }
            printf("⎢");
            for (int j = 0; j < n; j++){
                printf("% 8.2f ", arr[i][j]);
            }
            printf("⎥\n");
        }
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("         ");
        }
        printf("⎥\n");
        printf("⎣");
        for (int j = 0; j < n; j++){
            printf("% 8.2f ", arr[m-1][j]);
        }
        printf("⎦\n\n");
    } else if (m == 1){
        printf("\n[");
        for (int i = 0; i < n; i++){
                printf("% 8.2f ", arr[0][i]);
        }
        printf("]\n\n");
    } else {
        printf("\n[]\n\n");
    }
}

void ex1(){
	int m = 3, n = 3;
	int a[m][n];
	float b[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nMatriz: ");
	printMatrixI(m, n, a);
	int maior = a[0][0];
	for (int i = 0; i < m; i++) if (a[i][i] > maior) maior = a[i][i];
	printf("Maior elemento da diagonal principal: %d\n", maior);
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) b[i][j] = (float) a[i][j] / maior;
	printMatrixF(m, n, b);
}

void ex2(){
	int m = 10, n = 10;
	int a[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", &a[i][j]);
			a[i][j] = rand() % 21;
		}
	}
	printf("Matriz: ");
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++){
		int aux = a[1][i];
		a[1][i] = a[7][i];
		a[7][i] = aux;
	}
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++){
		int aux = a[i][3];
		a[i][3] = a[i][9];
		a[i][9] = aux;
	}
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++){
		int aux = a[i][i];
		a[i][i] = a[i][m-i-1];
		a[i][m-i-1] = aux;
	}
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++){
		int aux = a[4][i];
		a[4][i] = a[i][9];
		a[i][9] = aux;
	}
	printMatrixI(m, n, a);
}

int main(){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	ex2();
	return 0;
}
