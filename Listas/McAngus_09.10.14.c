#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void printMatrix(int m, int n, float arr[m][n]){
	if (m*n > n){
		printf("\n⎡");
		for (int j = 0; j < n; j++){
			printf("%6f ", arr[0][j]);
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
			printf("%6f ", arr[i][j]);
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
			printf("%6f ", arr[m-1][j]);
		}
		printf("⎦\n\n");
	} else if (m == 1){
		printf("\n[");
		for (int i = 0; i < n; i++){
			printf("%6f ", arr[0][i]);
		}
		printf("]\n\n");
	} else {
		printf("\n[]\n\n");
	}
}

/*void ex1(){
	int ord;
	printf("Digite a ordem da matriz desejada: "); scanf("%d", &ord);
	int mat[ord][ord];
	for (int k = 0; k<ord; k++){
		for (int j = 0; j<ord; j++){
			if (k >= j) mat[k][j] = (k+1) * (j+1);
			else mat[k][j] = 0;
		}
	}
	printMatrix(ord, ord, mat);
}*/

void ex2(){
	float not[10][3], menorG[3] = {0};
	for (int k = 0; k<10; k++){
		printf("\tPara o aluno %d: ", k+1);
		for (int j = 0; j<3; j++){
			printf("\n\t\tDigite a nota na prova %d: ", j+1);
			scanf("%f", &not[k][j]);
		}
	}
	printMatrix(10, 3, not);
	for (int k = 0; k<10; k++){
		float menor[2] = {0};
		for (int j = 0; j<3; j++){
			if (not[k][j] <= menor[0]){
				menor[0] = not[k][j];
				menor[1] = j;
			}
			if (not[k][j] <= menorG[j]) menorG[j] = not[k][j];
		}
		printf("O aluno %d teve sua pior nota na prova %.f, que foi %.2f.\n", k+1, menor[1], menor[0]);
	}
}

int main(){
	ex2();
	return 0;
}
