#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
void printArray(int a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %d", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void ex1(){
	int n, sum = 0;
	printf("Digite quantos números perfeitos deseja saber: ");
	scanf("%d", &n);
	for (int k = 2, count = 0; count < n; k++){
		sum = 1;
		for(int j = 2, l = sqrt(k) + 1;j < l;j++){
			if(k%j==0)
				sum+= j + k/j;
		}
		if(sum==k){
			printf("%d é um número perfeito.\n", sum);
			count++;
		}
	}
}

void ex2(){
	int n, temp;
	printf("あなたが入力しただろうどのように多くの数字を入力: ");
	scanf("%d", &n);
	int numb[n];
	for (int k = 0; k<n; k++){
		numb[k] = rand() % 100000 + 1;
	}
	printArray(numb,n);
	for(int e = 0; e<n; e++){
		for(int j = 1; j<n; j++){
			if(numb[e] < numb[j - 1]){
				temp = numb[j - 1];
				numb[j - 1] = numb[e];
				numb[e] = temp;
			}
		}
	}
	printArray(numb,n);
}

int main(){
	srand(20);
	setlocale(LC_ALL, "");
	printf("\n\nこのプログラムの使用に心より感謝申し上げます。\n\n");
}
