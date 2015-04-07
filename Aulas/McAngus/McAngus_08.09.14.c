#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void ex1(){
	int n, i;
	printf("Digite quantos números serão digitados: ");
	scanf("%d", &n);
	float arr[n];
	for (int k = n; k>0; k--){
		printf("Digite um número: ");
		scanf("%f", &arr[k]);
	}
	printf("Digite um índice para obter seu valor correspondente: ");
	scanf("%d", &i);
	while (i < 0 || i > n) {
		printf("Digite um índice para obter seu valor correspondente: ");
		scanf("%d", &i);
	}
	printf("O valor armazenado na posição %d é %f.", i, arr[i-1]);
	system("pause");
}

void ex2(){
	int n, i;
	printf("Digite quantos números deseja dar entrada: ");
	scanf("%d", &n);
	int array[n];
	for (int k = 0; k<n; k++){
		printf("Digite um número: ");
		scanf("%d", &array[k]);
	}
	printf("Digite qual número deseja que seja exibido: ");
	scanf("%d", &i);
	if (i > n || i <= 0)
		printf("O número na posição %d não existe.", i);
	else
		printf("O número na posição %d é %d", i, array[i-1]);
	system("pause");
}

void ex3(){
	int n, i;
	printf("Digite quantos números serão digitados: ");
	scanf("%d", &n);
	float arr[n], temp;
	for (int k = 0; k < n; k++){
		printf("Digite um número: ");
		scanf("%f", &arr[k]);
		for(int x = 1; x < n; x++){
			if (arr[x - 1] > arr[k]){
				temp = arr[x - 1];
				arr[x - 1] = arr[k];
				arr[k] = temp;
			}
		}
	}
	for (int z = 0; z < n; z++)
		printf("%f\n", arr[z]);
	system("pause");
}

int main(){
	setlocale(LC_ALL, "");
	int menu;
	while (menu != 0){
		printf("Escolha um exercício, digite 0 para sair: ");
		scanf("%d", &menu);
		switch (menu){
			case 1: ex1(); break;
			case 2: ex2(); break;
			case 3: ex3(); break;
			default : break;
		}
		system("clear");
	}
}
