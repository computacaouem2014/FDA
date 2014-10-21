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

void printMatrixC(int m, int n, char arr[m][n]){
    if (m > 1){
        printf("\n⎡");
        for (int j = 0; j < n; j++){
            printf("%2c ", arr[0][j]);
        }
        printf("⎤\n");
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("   ");
        }
        printf("⎥\n");
        for (int i = 1; i < m-1; i++){
            if (i != 1){
                printf("⎢");
                for (int k = 0; k < n; k++){
                    printf("   ");
                }
                printf("⎥\n");
            }
            printf("⎢");
            for (int j = 0; j < n; j++){
                printf("%2c ", arr[i][j]);
            }
            printf("⎥\n");
        }
        printf("⎢");
        for (int k = 0; k < n; k++){
            printf("   ");
        }
        printf("⎥\n");
        printf("⎣");
        for (int j = 0; j < n; j++){
            printf("%2c ", arr[m-1][j]);
        }
        printf("⎦\n\n");
    } else if (m == 1){
        printf("\n[");
        for (int i = 0; i < n; i++){
                printf("%2c ", arr[0][i]);
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

void ex3(){
	int m = 5, n = 5;
	int a[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", &a[i][j]);
			a[i][j] = rand() % 21;
		}
	}
	printMatrixI(m, n, a);
	int soma = 0, count = 0;
	for (int i = 1; i < m; i++){
		for (int j = i - 1; j >= 0; j--){
			soma += a[i][j];
			count++;
		}
	}
	printf("%d, %d\n", soma, count);
	float media = (float) soma / count;
	printf("Media da soma dos elementos abaixo da diagonal principal: %.2f\n", media);
}

void ex4(){
	int m = 3, n = 3;
	int a[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", a[i][j]);
			a[i][j] = rand() % 20;
		}
	}
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 2 != 0)
				printf("A[%d][%d] = %d\n", i+1, j+1, a[i][j]);
}

void ex5(){
	int m = 3, n = 3;
	int a[m][n];
	int b[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", a[i][j]);
//			printf("Informe o elemento B[%d][%d]: ", i+1, j+1);
//			scanf("%d", b[i][j]);
			a[i][j] = rand() % 20;
			b[i][j] = rand() % 20;
		}
	}
	printMatrixI(m, n, a);
	printMatrixI(m, n, b);
	int transposta = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] != b[j][i]){
				transposta = 0;
				break;
			}
		}
		if (!transposta) break;
	}
	printf("A matriz B %s transposta da matriz A.\n", transposta ? "e" : "nao e");
}

void ex6(){
	int m = 3;
	printf("Informe a ordem M da matriz: ");
	scanf("%d", &m);
	int a[m][m];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", a[i][j]);
			a[i][j] = rand() % 20;
		}
	}
	printMatrixI(m, m, a);
	int simetrica = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] != a[j][i]) {
				simetrica = 0;
				break;
			}
		}
		if (!simetrica) break;
	}
	printf("A matriz A %s simetrica.\n", simetrica ? "e" : "nao e");
}

void ex7(){
	int m;
	do {
		printf("Informe a ordem M da matriz: ");
		scanf("%d", &m);
	} while (m > 9 || m < 1);
	int a[m][m];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			int change = i > j ? i - j : j - i;
			a[i][j] = m - change;
		}
	}
	printMatrixI(m, m, a);
	
}

void ex8(){
	int m = 5, n = 5;
	int a[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", a[i][j]);
			a[i][j] = rand() % 20;
		}
	}
	int maior, linhamaior;
	printMatrixI(m, n, a);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] > maior){
				maior = a[i][j];
				linhamaior = i;
			}
		}
	}
	int minimax = a[linhamaior][0];
	for (int i = 1; i < m; i++) if (a[minimax][i] < minimax) minimax = a[linhamaior][i];
	printf("Minimax: %d", minimax);
}

char* toUpperCase(int size, char *str){
	char *str2 = malloc((size + 1) * sizeof(char));
	str2[size] = '\0';
	for (int i = 0; i < size; i++){		
		if (str[i] > 96 && str[i] < 123){
			str2[i] = str[i] - 32;
		}
	}
	return str2;
}

void ex9(){
	int m = 3;
	char a[m][m];
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
//			printf("Informe o elemento A[%d][%d]: ", i+1, j+1);
//			scanf("%d", a[i][j]);
			a[i][j] = rand() % 25 + 65;
		}
	}
	printMatrixC(m, m, a);
	char *s = malloc((m + 1) * sizeof(char));
	printf("Informe uma string de %d caracteres: ", m);
	fgets(s, m + 1, stdin);
	strtok(s, "\n");
	s = toUpperCase(m, s);
	for (int i = 0; i < m; i++){
		char *str = malloc(m * sizeof(char));
		char *str2 = malloc(m * sizeof(char));
		int j;
		for (j = 0; j < m; j++){
			str[j] = a[i][j];
			str2[j] = a[j][i];
		}
		if (!strcmp(s, str)) printf("A string \"%s\" e igual a coluna j = %d", str, i+1);
		if (!strcmp(s, str2)) printf("A string \"%s\" e igual a linha i = %d", str2, i+1);
	}
}

void ex10(){
	int a, b, mmmm;
//	int mi[mmmm][mmmm] = {{1, 2, 3, 4, 5}, {16, 17, 18, 19, 6}, {15, 24, 25, 20, 7}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}};
	do {
		printf("Informe a ordem M da matriz: ");
		scanf("%d", &mmmm);
	} while (mmmm > 10 || mmmm < 1);
	int mi[mmmm][mmmm];
	for (int i = 0; i < mmmm; i++){
		for (int j = 0; j < mmmm; j++){
			scanf("%d", &mi[i][j]);
		}
	}
	int count = 0;
	printMatrixI(mmmm, mmmm, mi);
	a = 0; b = mmmm;
	int inca = 1, i = 0, j = -1;
	while (count < mmmm*mmmm){
		for (i = a, j += 1; i < b; i++){
			if (mi[j][i] != ++count){
				inca = 0;
			}
		}
		for (j = a + 1, i -= 1; j < b; j++){
			if (mi[j][i] != ++count){
				inca = 0;
			}
		}
		for (i = b - 2, j -= 1; i >= a; i--){
			if (mi[j][i] != ++count){
				inca = 0;
			}
		}
		for (j = b - 2, i += 1; j >= a+1; j--){
			if (mi[j][i] != ++count){
				inca = 0;
			}
		}
		a++; b--;
	}
	printf("A matriz %s inca.\n", inca ? "e" : "nao e");
}

int main(){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	ex10();
	ex10();
	ex10();
	ex10();
	ex10();
	ex10();
	return 0;
}
