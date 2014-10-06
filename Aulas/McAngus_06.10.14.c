#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define col 20
#define lines 10

void printArray(int a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %d", a[i]);
		printf("]\n");
	}
	else printf("\n[]\n");
}

void printMatrix(int a[lines][col]) {
	if (lines > 0 && col > 0) {
		printf("\n[");
		printf("%d", a[0][0]);
		for (int i = 0; i < lines; i++){
			for (int j = 1; j < col; j++)
				printf(", %d", a[i][j]);
			printf("]\n");
			if (i + 1 < lines)	printf("[%d", a[i][0]);
		}
	}
	else printf("\n[]\n");
}

void randMatrix(int arr[lines][col], int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = 0; k < lines; k++){
		for (int j = 0; j < col; j++)
			arr[k][j] = rand() % max + min;
	}
}

void matrixSwap(int arr[lines][col], int ia, int ib, int ic){
	int aux = arr[ia][ic];
	arr[ia][ic] = arr[ia][ib];
	arr[ia][ib] = aux;
}

void matrixSort(int arr[lines][col]){
	for (int h = 0; h < lines; h++){
		for (int i = 0; i < col; i++){
			for (int k = i; k > 0; k--){
				if (arr[h][k] < arr[h][k - 1])
					matrixSwap(arr, h, k, k-1);
			}
		}
	}
}

void sumLine(int arrIn[lines][col], int arrOut[lines]){
	for (int k = 0; k < lines; k++){
		for (int j = 0; j < col; j++)
			arrOut[k] += arrIn[k][j];
	}
}

void multLine(int arr1[lines][col], int arr2[lines]){
	for (int k = 0; k < lines, k++){
		for (int j = 0; j < col; j++)

	}
}

int main(){
	int m[lines][col], res[lines] = {0};
	randMatrix(m, 100, 0);
	matrixSort(m);
	sumLine(m, res);
	printArray(res, lines);
	printMatrix(m);
}
