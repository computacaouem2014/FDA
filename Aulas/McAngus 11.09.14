#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
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

void randNum(int arr[], int size, int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = size - 1; k>=0; k--)
		arr[k] = rand() % max + min;
}

void selection(int arr[], int arrSize){
	for(int i=0; i<arrSize-1; i++){
		int min = i;
		for(int k=(i+1); k<arrSize; k++){
			if(arr[k]<arr[min])
				min=k;
		}
		if (min != i){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int repetido(int arr[], int arrSize){
	int count = 0;
	for (int k=arrSize-1; k>=0; k--){
		if(arr[arrSize]==arr[k])
			count++;
	}
	return count;
}

void ex1(){
	int n;
	printf("Digite um número: ");
	scanf("%d",&n);
	int vec1[n], vec2[n], vec3[2*n];
	for (int i=0; i<n; i++){
		printf("Digite um valor: ");
		scanf("%d", &vec1[i]);
		vec3[2*i] = vec1[i];
	}
	for(int k=1; k<n+1; k++){
		printf("Digite um valor: ");
		scanf("%d", &vec2[k]);
		vec3[2*k-1] = vec2[k];
	}
	printArray(vec3,2*n);
	selection(vec3,2*n);
	printArray(vec3,2*n);
}


void ex2(){
	int n;
	printf("Digite um número: ");
	scanf("%d",&n);
	int vec1[n], vec2[n];
	for (int i=0; i<n; i++){
		printf("Digite um valor: ");
		scanf("%d", &vec1[i]);
		while (repetido(vec1,i)!=0){
			printf("Valor repetido, entre com outro número: ");
			scanf("%d", &vec1[i]);
		}
	}
	for(int k=0; k<n; k++){
		printf("Digite um valor: ");
		scanf("%d", &vec2[k]);
		while (repetido(vec2,k)!=0){
			printf("Valor repetido, entre com outro número: ");
			scanf("%d", &vec2[k]);
		}
	}
	printArray(vec1, n);
	printArray(vec2,n);
}


int main(){
	ex1();
	ex2();
}
