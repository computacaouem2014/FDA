#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void printArray(float *a, int size) {
	if (size > 0) {
		printf("\n[");
		printf("%f", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %f", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void printSub(float *a, float *b, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++)
			printf("[ %f ]\n", a[i] - b[i]);
	} else printf("\n[]\n");
}

double fact(int n){
	return n < 2 ? 1 : n * fact(n - 1);
}

void ex1(){
	int v[10];
	double w[10];
	for (int k = 0; k < 10; k++){
		printf("Digite um numero: ");
		scanf("%d", &v[k]);
		w[k] = fact(v[k]);
	}
	//printArray(w, 10);
}

void ex2(){
	float a[10], b[10], dif[10];
	for (int k = 0; k < 10; k++){
		printf("Digite um numero(VETOR A): ");
		scanf("%f", &a[k]);
		printf("Digite um numero(VETOR B): ");
		scanf("%f", &b[k]);
		dif[k] = a[k] - b[k];
	}
	system("clear");
	printSub(a, b, 10);
	printArray(dif, 10);
}

void ex3(){
	int a[10], b[20], c[20] = {0};
	for (int k = 0; k<10; k++){
		printf("Vetor A:");
		scanf("%d", &a[k]);
	}
	for (int k = 0; k<20; k++){
		printf("Vetor B:");
		scanf("%d", &b[k]);
	}
	for (int k = 0; k<10; k++){
		for (int j = 0; j<20; j++){
			if (a[k] == b[j])
				c[j] = a[k];
		}
	}
	for (int k = 0; k<20; k++){
		for (int j = k + 1; j<20; j++){
			if(c[k] == c[j]){
				c[j] = 0;
			}
		}
	}
	for (int k = 0; k<20; k++){
		if (c[k] != 0)
			printf("%d\n", c[k]);
	}
}

void ex4(){
	float temp[12][2] = {0}, aux;
	for (int k = 0; k<12; k++){
		printf("Digite a temperatura do mes %d: ", k + 1);
		scanf("%f", &temp[k][0]);
		temp[k][1] = k + 1;
		printf("%d || %d\n", temp[k][0], temp[k][1]);
	}
	for (int k = 0; k<11; k++){
		for (int j = 1; j<12; j++){
			if (temp[k][0] > temp[j][0]){
				aux = temp[k][0];
				temp[j][0] = temp[k][0];
				temp[k][0] = aux;

				aux = temp[k][1];
				temp[j][1] = temp[k][1];
				temp[k][1] = aux;
			}
		}
	}
	for (int k = 0; k<12; k++)
		printf("%d || %d\n", temp[k][0], temp[k][1]);
}

int main(){
	ex4();
}
