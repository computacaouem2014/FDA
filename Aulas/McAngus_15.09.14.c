#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void printArray(int a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]);
	for (int i = 1; i < size; i++)
		printf(", %d", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void printSoma(int a[], int b[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]+b[0]);
	for (int i = 1; i < size; i++)
		printf(", %d", a[i]+b[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void printMult(int a[], int b[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]*b[0]);
	for (int i = 1; i < size; i++)
		printf(", %d", a[i]*b[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void randNum(int arr[], int size, int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = size - 1; k>=0; k--)
		arr[k] = rand() % max + min;
}

void merge(int vec[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;
	tmp = (int*) malloc(vecSize * sizeof(int));
	if (tmp == NULL)
		exit(1);
	mid = vecSize / 2;
	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vec[i] <= vec[j])
			tmp[k] = vec[i++];
	else
		tmp[k] = vec[j++];
	++k;
	}

	if (i == mid) {
		while (j < vecSize)
			tmp[k++] = vec[j++];
	}
	else {
		while (i < mid)
			tmp[k++] = vec[i++];
	}
	for (i = 0; i < vecSize; ++i)
		vec[i] = tmp[i];
	free(tmp);
}

void mergeSort(int vec[], int vecSize) {
	int mid;
	if (vecSize > 1) {
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
}

int repetido(int arr[], int arrSize){
	int count = 0;
	for (int k=arrSize-1; k>=0; k--){
		if(arr[arrSize]==arr[k]){
			count++;
		}
	}
	return count;
}

void intersecArray(int arr1[], int arr2[], int arrSize){
	int count = 0, temp[arrSize];
	for (int k = 0; k<arrSize; k++){
		for (int j = 0; j<arrSize; j++){
			if (arr1[k] == arr2[j]){
				temp[count] = arr1[k];
				count++;
				break;
			}
		}
	}
	if (count > 0)
		printArray(temp, count);
}

void unionArray(int arr1[], int arr2[], int arrSize){
	int  temp[arrSize*2];
	for (int k = 0; k<arrSize; k++){
		temp[arrSize*2] = arr1[k];
		temp[arrSize*2+1] = arr2[k];
	}
	printArray(temp, arrSize*2);
}

void dif(int arr1[], int arr2[], int arrSize){
	int count = 0, temp[arrSize];
	for (int k = 0; k<arrSize; k++){
		for (int j = 0; j<arrSize; j++){
			if (arr1[k] != arr2[j]){
				temp[count] = arr1[k];
				count++;
				break;
			}
		}
	}
	if (count > 0)
		printArray(temp, count);
}

void ex1(){
	int n;
	printf("Digite um n¨²mero: ");
	scanf("%d",&n);
	int vec1[n], vec2[n];
	for (int i=0; i<n; i++){
		printf("Digite um valor: ");
		scanf("%d", &vec1[i]);
		while (repetido(vec1,i)!=0){
			printf("Valor repetido, entre com outro n¨²mero: ");
			scanf("%d", &vec1[i]);
		}
	}
	for(int k=0; k<n; k++){
		printf("Digite um valor: ");
		scanf("%d", &vec2[k]);
		while (repetido(vec2,k)!=0){
			printf("Valor repetido, entre com outro n¨²mero: ");
			scanf("%d", &vec2[k]);
		}
	}
	printArray(vec1, n);
	printArray(vec2,n);
	printSoma(vec1, vec2, n);
	printMult(vec1, vec2, n);
	intersecArray(vec1, vec2, n);
	dif(vec1, vec2, n);
	unionArray(vec1, vec2, n);
}

int main(){
	setlocale(LC_ALL, "");
	ex1();
}
